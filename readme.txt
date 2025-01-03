# Tic Tac Toe - C++ Implementation

## Overview
This is a simple console-based implementation of the classic Tic Tac Toe game written in C++. 
It allows two players to play the game, keeping track of their scores across multiple rounds. 
The game also provides options to replay after a round ends, and it handles scenarios such as winning, tying, and invalid inputs.
Additionally, the game now features automatic screen resets after each move, providing a cleaner and more interactive experience.

---

## Features
- Two-player gameplay with customizable player names.
- Real-time display of the grid and scores.
- Input validation to prevent overwriting occupied positions.
- Automatic detection of winners, ties, and valid moves.
- Replay option after the game ends.
- Screen reset: Clears the console screen after each move to keep the game view clean and up-to-date.

---

## Code Structure
### Header Files Used
- `iostream`: For input and output.
- `cstring`: For initializing the game grid.
- `cstdlib`: For clearing the console screen (via system calls).

### Constants
- `ROW = 3`: Defines the number of rows in the grid.
- `COLUMN = 3`: Defines the number of columns in the grid.

### Key Functions
- **`drawLine()`**: Draws a horizontal separator line for the grid.
- **`drawGrid()`**: Displays the current state of the grid along with player scores.
- **`getRowColumn(int pos, int &row, int &col)`**: Converts a position (1-9) into row and column indices.
- **`playX()`**: Handles Player 1's move.
- **`playO()`**: Handles Player 2's move.
- **`winner()`**: Checks if any player has won.
- **`isTie()`**: Checks if the grid is full and the game is tied.
- **`clearScreen()`: Clears the console screen after each move to make the interface cleaner.

### Main Gameplay Loop
1. The game alternates between Player 1 and Player 2.
2. After each move, the grid is updated and displayed.
3. The program checks for a winner or a tie.
4. If a player wins, their score is updated.
5. Players are prompted to replay or exit.
6. Screen reset: After every move, the screen is cleared to enhance gameplay flow.

---

## Known Limitations
- No AI implementation; requires two players.
- The grid size is fixed at 3x3.

---

## Future Enhancements
- Add support for single-player mode with AI.
- Enhance input validation to handle non-numeric characters.
- Make the grid size dynamic (e.g., support 4x4 or 5x5 grids).
- Improve the user interface with better formatting.

---

## Acknowledgements
This project was developed as a learning exercise in C++ programming. Feedback and contributions are welcome!

---
