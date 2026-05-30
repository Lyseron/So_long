*This project was created as part of the 42 curriculum by **lyaberge**.*

# so_long

## Description

**so_long** is a small 2D game built in C using the **MiniLibX** graphics library.

This version of the project is configured for **macOS only**.

The goal of the project is to create a simple game where the player has to collect all collectibles and reach the exit, while respecting a valid map structure.

This project helped me understand how to work with graphics, keyboard events, map parsing, rendering, and basic game logic.

## Important note

The **MiniLibX is not included** in this repository.

To compile and run this project, you need to add the macOS version of MiniLibX yourself.

## Game rules

The player starts on a map and must:

* move around using the keyboard
* collect all collectibles
* reach the exit
* avoid walking through walls

The exit only becomes valid once every collectible has been collected.

## Map format

The map is made of characters:

| Character | Meaning                  |
| --------- | ------------------------ |
| `1`       | Wall                     |
| `0`       | Empty space              |
| `P`       | Player starting position |
| `C`       | Collectible              |
| `E`       | Exit                     |

A valid map must respect several rules:

* the map must be rectangular
* the map must be surrounded by walls
* the map must contain exactly one player
* the map must contain exactly one exit
* the map must contain at least one collectible
* all collectibles must be reachable
* the exit must be reachable

## My implementation

The program first parses and validates the map before starting the game.

To check if the map is playable, I used a flood fill algorithm.
The flood fill starts from the player position and checks whether all collectibles and the exit can be reached.

During the game, each movement checks the next tile:

* if it is a wall, the player cannot move
* if it is a collectible, it is collected
* if it is the exit, the player can leave only after collecting everything
* otherwise, the player position is updated

The number of moves is displayed each time the player moves.

## Graphics

This project uses **MiniLibX** to open a window, display images, and handle keyboard events.

Each tile of the map is rendered with a texture:

* wall
* floor
* player
* collectible
* exit

## MiniLibX setup

MiniLibX is not provided in this repository.

Before compiling, add the macOS MiniLibX folder to the project and make sure your Makefile points to it correctly.

For example, your Makefile may need something like:

```makefile id="qqc3vh"
MLX_DIR = mlx_macos
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
```

## Compilation

To compile the project:

```bash id="tngtr9"
make
```

This creates the `so_long` executable.

## Usage

```bash id="dofnuw"
./so_long maps/map.ber
```

Example:

```bash id="cw0u8x"
./so_long maps/valid.ber
```

## Controls

| Key       | Action         |
| --------- | -------------- |
| `W` / `↑` | Move up        |
| `A` / `←` | Move left      |
| `S` / `↓` | Move down      |
| `D` / `→` | Move right     |
| `ESC`     | Close the game |

## Test examples

### Valid map

```bash id="0fl580"
./so_long maps/valid.ber
```

Expected result:

* the game window opens
* the player can move
* collectibles can be collected
* the exit works after all collectibles are collected

### Invalid map

```bash id="ly0vd9"
./so_long maps/invalid.ber
```

Expected result:

* the program prints an error message
* the game does not start

## Skills practiced

* C programming
* MiniLibX
* macOS graphics setup
* 2D rendering
* Event handling
* Keyboard input
* Map parsing
* Flood fill algorithm
* File reading
* Game logic
* Memory management
* Error handling
* Makefile

## Resources

I used resources to understand the concepts behind MiniLibX, rendering, events, and map validation.

* 42 project subject
* MiniLibX documentation and examples
* Manual pages for file handling functions
* Tutorials and explanations about flood fill algorithms

## AI use

I used AI as a learning and debugging tool, never to generate the final code.

I always started my prompts with a strict no-code rule, asking only for explanations, as if another student was teaching me.

I mostly used AI to:

* better understand how MiniLibX works on macOS
* debug rendering and window issues
* understand keyboard event handling
* think about map validation edge cases
* understand and test flood fill logic
* help write this README in English
