*This project has been created as part of the 42 curriculum by aroduit, msuter.*
 
# cub3D
 
## Description
 
cub3D is a small first-person 3D engine written in C, inspired by the classic *Wolfenstein 3D*. The goal of the project is to render a maze from a 2D map file using **raycasting**, with the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library.
 
Overview of what the program does:
 
- Parses a `.cub` scene file: wall textures, floor and ceiling colors, and the map.
- Validates the map (closed by walls, valid characters, exactly one player, no empty line inside the map).
- Casts one ray per screen column using the DDA algorithm to find the nearest wall.
- Draws textured walls (one texture per cardinal direction), a floor and a ceiling.
- Displays a 2D minimap in the top-left corner.
- Handles movement and rotation with frame-time based speed, so the speed does not depend on the map size or the machine.
- Cleans up all memory, images and file descriptors on every exit path (errors, `ESC`, window close).
### Scene file format (`.cub`)
 
```
NO textures/north.xpm
SO textures/south.xpm
WE textures/west.xpm
EA textures/east.xpm
 
F 69, 222, 199
C 235, 198, 52
 
111111111
100000001
1000N0001
111111111
```
 
- `NO`, `SO`, `WE`, `EA`: path to the XPM texture of each wall orientation.
- `F` and `C`: floor and ceiling colors as `R,G,B`, each value in `[0, 255]`.
- Identifiers can appear in any order, each exactly once, separated by empty lines or extra spaces.
- Map characters: `0` (empty), `1` (wall), `N` `S` `E` `W` (player start and orientation), and spaces (void outside the map).
- The map must be closed by walls and must be the last element of the file. Empty lines after the map are ignored, an empty line inside the map is an error.
## Instructions
 
### Requirements
 
- Linux with X11
- `cc`, `make`
- MiniLibX for Linux (`minilibx-linux/`) and its dependencies: `libXext`, `libX11`, `libm`, `libz`

### Compilation
 
```bash
make
```
 
Other rules:
 
| Rule | Description |
|---|---|
| `make` / `make all` | Builds libft, MiniLibX and the `cub3D` executable |
| `make run` | Builds and runs with the default map |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the executable |
| `make re` | Full rebuild |
 
### Execution
 
```bash
./cub3D path/to/map.cub
valgrind --leak-check=full --show-leak-kinds=all --track-fds=all --track-origins=yes ./cub3D path/to/map.cub
```
 
### Controls
 
| Key | Action |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate the camera |
| `ESC` or window close button | Quit the game |
 
Diagonal movement is normalized, so moving with two keys is not faster than with one.
 
### Error handling
 
On any invalid input, the program prints `Error` followed by an explicit message on the standard error output, frees everything and exits with a failure status (invalid extension, missing or duplicated texture/color, invalid color, unreadable texture, open map, invalid character, no or several players, empty line in the map, etc.).
 
## Resources
 
### References
 
- [Lode's Computer Graphics Tutorial: Raycasting](https://lodev.org/cgtutor/raycasting.html): reference for the DDA algorithm, camera plane and texture mapping.
- [MiniLibX documentation (42 Docs)](https://harm-smits.github.io/42docs/libs/minilibx): window, image and event handling.
- [Youtube Tuto about trigonometric circle](https://www.youtube.com/watch?v=ECNX9hnhG9U): reviewed the trigonometric circle.
- [Youtube Tuto DDA](https://www.youtube.com/watch?v=NbSee-XM7WA): learn DDA.
### Use of AI
 
AI (Claude) was used as a support tool, not to generate the project from scratch. It was used for:
 
- **Code review**: reviewing the existing code and pointing out bugs (position and speed units depending on the map size, missing configuration checks, texture size assumptions, header dependencies in the Makefile).
- **Debugging and explanations**: understanding the cause of specific bugs and explaining how some parts work (for example the normalization of diagonal movement).
- **Documentation**: help drafting this README.
All suggestions were read, understood, tested and adapted by the authors before being integrated.
