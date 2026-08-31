# 💣 Minesweeper

Welcome to my own version of the **Minesweeper**!

A terminal-based Minesweeper written in **C**, built and tested on a **MacBook M5**.

## Controls

| Key             | Action                        |
|-----------------|-------------------------------|
| `↑` `↓` `←` `→` | Move across the map           |
| `f`             | Add a flag (or remove it)     |
| `Space`         | Click                         |
| `Q`             | Quit                          |

Press any key at the start screen to begin — hope you enjoy it!

## Custom maps

You can also create your own personalized maps by passing arguments when launching the program:

```bash
./minesweeper A B C
```

- `A` = length
- `B` = width
- `C` = percentage of mines

### Constraints

- **Length** and **width** must be between `9` and `100` (included).
- **Mine percentage** must be between `5` and `40` (included).

## Build

```bash
make
```

## Example

```bash
./minesweeper
./minesweeper 20 15 20
```
- First case would generate a `9x9` map with `13%` of mines.
- Second would generates a personalised `20x15` map with `20%` of mines.
