# terminal-rpg

A terminal-based RPG, built as a learning project for both C++ and GitHub workflow (issues, PRs, labels, tracking issues).

MVP scope (see README.md): a player with readable stats, navigable rooms, encounters, randomly generated rooms/encounters, and stats that affect how the player interacts with the world.

Roadmap and current build order are tracked in [issue #10](https://github.com/EmpressIrulan/terminal-rpg/issues/10) — check there for "where are we."

## Build

TBD — there is no `main()` entry point yet, so nothing currently compiles into a runnable program. Tracked in [issue #8](https://github.com/EmpressIrulan/terminal-rpg/issues/8). Once that lands, this section should be updated with the real compile/run command.

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
- Everything else (environment, encounters, minotaur clock, GUI) is not yet built — see the roadmap issue for planned order.
