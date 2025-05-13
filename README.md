# So Long

**So Long** is a small 2D game project from the 42 curriculum. The objective is to create a simple graphical game using the **MLX42** library, where a player must collect all collectibles and reach the exit while navigating through a maze.

---

## 🚀 Summary

- A top-down 2D game written in C using MLX42  
- Encourages mastery of basic graphics, event handling, and algorithmic logic  
- Promotes clean coding, memory management, and usage of external libraries  

---

## 🎮 Features

- Real-time player movement using **W/A/S/D** keys  
- Collectibles and exit handling  
- Movement count displayed in terminal  
- Wall collision detection  
- `.ber` map file parsing and validation  
- Window and event management using MLX42  
- Clean exit via **ESC key** or window close button  

---

## 🛠 Requirements

- GCC compiler  
- `make`  
- MLX42 library  
- `libft` (custom implementation)  
- Valid `.ber` map files  

---

## ⚙️ Compilation

```bash
make
```

---

## ▶️ Usage

```bash
./so_long maps/example.ber
```

---

## 🎮 Controls

| Key               | Action                          |
|-------------------|----------------------------------|
| W / A / S / D     | Move Up / Left / Down / Right   |
| ESC               | Exit the game                   |
| Window close (X)  | Exit the game                   |

---

## 🗺️ Map Format (`.ber`)

A valid map:
- Must be rectangular  
- Must be enclosed by walls (`1`)  
- Must include:
  - One player start (`P`)  
  - At least one collectible (`C`)  
  - One exit (`E`)  
- Only valid characters:  
  - `1` – wall  
  - `0` – empty space  
  - `C` – collectible  
  - `E` – exit  
  - `P` – player start  

### Example:
```
111111
1P0C01
100001
1E0001
111111
```

If the map is invalid (e.g. missing characters, not rectangular, not enclosed), the game exits with `"Error\n"` and an appropriate error message.

