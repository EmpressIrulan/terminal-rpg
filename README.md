# terminal-rpg

A text-based dungeon crawler for the terminal. Explore rooms one at a time,
fight or avoid what's inside them, and stay ahead of a Minotaur that's
tracking you down.

## Build

```
cmake -S . -B build
cmake --build build
./build/terminal-rpg
```

## How to play

Each turn drops you into a room with four walls. A wall is either open
(leads to another room) or solid. Searching a solid wall sometimes turns up
a secret door.

The game prints the room's walls, then its encounter, then asks where to go
next. Type the number next to an option and press enter; `0` quits.

### The Minotaur

A Minotaur is chasing you and starts five rooms behind. Its distance changes
as you play:

- Fighting an enemy or buying from a shop closes the gap by one room.
- Searching a solid wall and finding nothing also closes it by one room.
- Finding a secret door behind a solid wall opens the gap by one room. It's
  the only thing that buys you distance.

When the distance hits zero, the Minotaur catches up and you fight it
directly. Win, and the game ends.

### Encounters

Every room holds one of the following.

- Empty. Nothing happens.
- Trap. Triggers automatically and deals damage.
- Shop. Spend gold on equipment that raises a stat: a Sword (Strength),
  Armour (Dodge), a Book (Reason), or a Fluffy Coat (Persuasion). Buying
  something closes the distance with the Minotaur, same as a fight.
- Enemy. Combat resolves automatically, turn by turn, based on your stats
  and the enemy's, until one side is knocked out. Defeating a non-Minotaur
  enemy drops gold.

### Stats

Your character starts with 10 HP and no bonus stats. Strength and Dodge
affect combat; Reason and Persuasion don't come into play yet. Losing all
your HP, in a trap or in combat, ends the game.

## MVP

- A player with readable stats
- Rooms that the player can navigate
- A way to have encounters
- Randomly generating these rooms and encounters
- Using the player's stats to interact with the world
