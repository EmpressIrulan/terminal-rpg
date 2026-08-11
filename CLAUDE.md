# terminal-rpg

A terminal-based RPG, built as a learning project for both C++ and GitHub workflow (issues, PRs, labels, tracking issues).

MVP scope (see README.md): a player with readable stats, navigable rooms, encounters, randomly generated rooms/encounters, and stats that affect how the player interacts with the world.

Roadmap and current build order are tracked in [issue #10](https://github.com/EmpressIrulan/terminal-rpg/issues/10). Check there for "where are we."

## Build

```
cmake -S . -B build
cmake --build build
./build/terminal-rpg
```

Compiled output goes in `build/` (gitignored) to keep `src/` clean of build artifacts. This is the standard out-of-source-build convention. `CMakeLists.txt` at the root sets the project-wide C++ standard and compile options and descends into `src/CMakeLists.txt`, which builds every file except `main.cpp` into a static library (`terminal-rpg-lib`) and links the `terminal-rpg` executable against it. A new `.cpp` file needs a line added to `src/CMakeLists.txt`'s `add_library` call: CMake lists sources explicitly rather than globbing, so an added or removed file is picked up on the next configure instead of the build going stale silently.

## Conventions

- Header/implementation split: one `.h` + one `.cpp` per class (see `src/character.h` / `src/character.cpp`).
- Method naming:
  - `changeX(delta)`: adds/subtracts a value (e.g. `changeStrength(-2)`)
  - `setX(value)`: assigns a value directly
  - `getX()`: plain pass-through accessor, no derived/computed logic
- Exceptions are for invalid state and failed transactions, not general control flow. `checkAlive()` still returns `bool` because "is the player dead" is a normal outcome to check every turn, not a failure. Current throw sites: `Room`'s constructor throws `DeadEndRoom` when all four walls roll solid (`main.cpp` catches it to reroll); `Character::changeMaxHp` throws `InvalidStatChange` if the change would drop max HP to zero or below; `Shop::buy` throws `InsufficientGold` if the player can't afford the item (`gui::promptShopPurchase` catches it and reports the shortfall). Each exception type is a plain struct carrying the fields a catcher needs to explain the failure, not a `std::exception` subclass.

## Architecture

- `Character` (`src/character.h/.cpp`): player stats (strength, dodge, maxhp, reason, persuasion, currentHp) with change/get accessors and `checkAlive()`.
- `rng` (`src/rng.h/.cpp`): shared random-number generation, providing `seed()` (once, at startup), `rollChance(percent)` and `rollRange(min, max)`. Free functions in an `rng` namespace rather than a class, since there is no per-instance state. Call these instead of `rand()` directly, so the mechanics stay in one place.
- `MinotaurClock` (`src/minotaur.h/.cpp`): the game's ticking clock. The Minotaur itself is an ordinary `Enemy` (`EnemyType::Minotaur`, no gold drop) fought through the same `combat::resolveEncounter` path as any other enemy. This class only tracks the distance between it and the player. Starts `MINOTAUR_STARTING_DISTANCE` rooms behind; `changeDistance(delta)` closes the gap (fighting, buying, failing to find a secret door) or opens it (finding a secret door is the only thing that does). `checkCaughtPlayer()` reports whether distance has hit zero, at which point the final fight begins.
- `gui` (`src/gui.h/.cpp`): the text interface. Free functions in a `gui` namespace (same rationale as `rng`, no per-instance state), covering the printing and stdin prompts the game loop needs: `displayStats`, `examineWalls` (prints wall status, calling `minotaurClock.changeDistance` once per wall as it goes), `promptShopPurchase`, and `promptMove` (lists open walls plus a quit option, returns `std::optional<Direction>`).
- `main.cpp` (`src/main.cpp`): entry point. Instantiates a `Character` and a `MinotaurClock`, then loops: generates a new `Room` (rerolling on a `DeadEndRoom`, thrown when all four walls come up solid), examines its walls, resolves the room's encounter (trap damage, shop purchase, or combat via `combat::resolveEncounter`), checks whether the Minotaur has caught up, and prompts the player to move. The loop ends on defeat, on defeating the Minotaur, or when the player quits.
