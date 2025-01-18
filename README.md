# Console Tic-tac-toe Game

A classic Tic-tac-toe game implemented in C++ for the console.

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Game](https://github.com/user-attachments/assets/ec3a0627-11e7-434e-b409-98264d81c877)

## 🎮 Game Features

- Two-player gameplay
- 3x3 game board
- Input validation
- Win detection for:
  - Horizontal lines
  - Vertical lines
  - Diagonals
- Draw detection
- Clear visual board display

## 🎯 How to Play

1. Players take turns placing their marks (X or O)
2. Enter row and column numbers (0-2) when prompted
3. Win by getting three marks in a row:
   - Horizontally
   - Vertically
   - Diagonally

### Game Board Layout
```
 - | - | - 
 - | - | - 
 - | - | - 
```

### Input Format
```
Index (row column): 1 1
```
This places a mark at row 1, column 1 (center of the board)

## 🎲 Gameplay Example

```
Turn for player 1
Please enter empty places to fill with X by their index
Index (row column): 0 0

 X | - | - 
 - | - | - 
 - | - | - 

Turn for player 2
Please enter empty places to fill with O by their index
Index (row column): 1 1

 X | - | - 
 - | O | - 
 - | - | - 
```

## 🔧 Implementation Details

### Board Representation
- 3x3 array of strings
- Empty cells marked with "-"
- Player 1 uses "X"
- Player 2 uses "O"

### Win Detection
Checks after each move:
```cpp
bool isCheck(string arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}
```

### Features
- Input validation
- Turn alternation
- Board state tracking
- Win/draw detection

## 🛠️ Building and Running

1. Clone the repository
```bash
git clone https://github.com/Btzel/console-tictactoe-game.git
cd console-tictactoe-game
```

2. Compile the game
```bash
g++ -o tictactoe tictactoe.cpp
```

3. Run the game
```bash
./tictactoe
```

## 📝 Code Structure

```cpp
Main Components:
- Board initialization
- Game loop
  - Player turns
  - Move validation
  - Board updates
  - Win checking
  - Draw checking
```

## 🎮 Controls

- Enter row number (0-2)
- Enter column number (0-2)
- Invalid moves are rejected and must be retried

## 🏆 Win Conditions

Three matching symbols in:
1. Any horizontal row
2. Any vertical column
3. Either diagonal

## ⚠️ Input Validation

The game checks for:
- Out of bounds inputs
- Already occupied positions
- Invalid input formats

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This is a learning implementation of the classic Tic-tac-toe game using C++ console input/output.
