# terminal-rpg

A terminal-based RPG, built as a learning project for both C++ and GitHub workflow (issues, PRs, labels, tracking issues).

MVP scope (see README.md): a player with readable stats, navigable rooms, encounters, randomly generated rooms/encounters, and stats that affect how the player interacts with the world.

Roadmap and current build order are tracked in [issue #10](https://github.com/EmpressIrulan/terminal-rpg/issues/10) — check there for "where are we."

## Build

```
mkdir -p build
g++ src/main.cpp src/character.cpp -o build/terminal-rpg
./build/terminal-rpg
```

Compiled output goes in `build/` (gitignored) to keep `src/` clean of build artifacts — this is the standard out-of-source-build convention. There's no Makefile yet; new `.cpp` files need to be added to the `g++` command by hand until one exists (see [issue #12](https://github.com/EmpressIrulan/terminal-rpg/issues/12) for the planned CMake upgrade).

Compiler: use `g++`, not plain `gcc` — `g++` auto-links the C++ standard library, `gcc` does not.

## Conventions

- Header/implementation split: one `.h` + one `.cpp` per class (see `src/character.h` / `src/character.cpp`).
- Method naming:
  - `changeX(delta)` — adds/subtracts a value (e.g. `changeStrength(-2)`)
  - `setX(value)` — assigns a value directly
  - `getX()` — plain pass-through accessor, no derived/computed logic
- No exceptions yet. Use return values / bool checks for state and error handling (e.g. `checkAlive()` returns `bool` rather than throwing). Exceptions are intentionally deferred as a dedicated learning topic — see [issue #9](https://github.com/EmpressIrulan/terminal-rpg/issues/9) — to be tackled once the MVP prototype works, not mixed into feature work.

## Architecture

- `Character` (`src/character.h/.cpp`): player stats — strength, dodge, maxhp, reason, persuasion, currentHp — with change/get accessors and `checkAlive()`.
- `main.cpp` (`src/main.cpp`): entry point — instantiates a `Character` and prints its stats to the terminal. Minimal by design; grows as rooms/encounters land.
- Everything else (environment, encounters, minotaur clock, GUI) is not yet built — see the roadmap issue for planned order.
