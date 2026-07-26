# terminal-rpg

A terminal-based RPG, built as a learning project for both C++ and GitHub workflow (issues, PRs, labels, tracking issues).

MVP scope (see README.md): a player with readable stats, navigable rooms, encounters, randomly generated rooms/encounters, and stats that affect how the player interacts with the world.

Roadmap and current build order are tracked in [issue #10](https://github.com/EmpressIrulan/terminal-rpg/issues/10) — check there for "where are we."

## Build

```
mkdir -p build
g++ src/*.cpp -o build/terminal-rpg
./build/terminal-rpg
```

Compiled output goes in `build/` (gitignored) to keep `src/` clean of build artifacts — this is the standard out-of-source-build convention. The `src/*.cpp` glob pattern compiles every `.cpp` file in the source directory automatically, so new files need no change to the command (see [issue #12](https://github.com/EmpressIrulan/terminal-rpg/issues/12) for the planned CMake upgrade).

## Conventions

- Header/implementation split: one `.h` + one `.cpp` per class (see `src/character.h` / `src/character.cpp`).
- Method naming:
  - `changeX(delta)` — adds/subtracts a value (e.g. `changeStrength(-2)`)
  - `setX(value)` — assigns a value directly
  - `getX()` — plain pass-through accessor, no derived/computed logic
- No exceptions yet. Use return values / bool checks for state and error handling (e.g. `checkAlive()` returns `bool` rather than throwing). Exceptions are intentionally deferred as a dedicated learning topic — see [issue #9](https://github.com/EmpressIrulan/terminal-rpg/issues/9) — to be tackled once the MVP prototype works, not mixed into feature work.

## Architecture

- `Character` (`src/character.h/.cpp`): player stats — strength, dodge, maxhp, reason, persuasion, currentHp — with change/get accessors and `checkAlive()`.
- `rng` (`src/rng.h/.cpp`): shared random-number generation — `seed()` (once, at startup), `rollChance(percent)`, `rollRange(min, max)`. Free functions in an `rng` namespace rather than a class, since there is no per-instance state. Call these instead of `rand()` directly, so the mechanics stay in one place.
- `MinotaurClock` (`src/minotaur.h/.cpp`): the game's ticking clock. The Minotaur itself is an ordinary `Enemy` (`EnemyType::Minotaur`, no gold drop) fought through the same `combat::resolveEncounter` path as any other enemy — this class only tracks the distance between it and the player. Starts `MINOTAUR_STARTING_DISTANCE` rooms behind; `changeDistance(delta)` closes the gap (fighting, buying, failing to find a secret door) or opens it (finding a secret door is the only thing that does). `checkCaughtPlayer()` reports whether distance has hit zero, at which point the final fight begins.
- `main.cpp` (`src/main.cpp`): entry point — instantiates a `Character`, a `Room`, and a `MinotaurClock`, walks the room's walls (adjusting the Minotaur's distance on each), resolves any encounter, then checks whether the Minotaur has caught up and — if so — fights it as an `Enemy`. Minimal by design; grows as rooms/encounters land.
- Everything else (environment traversal loop, GUI) is not yet built — see the roadmap issue for planned order.
