course — here is a polished and professional **README.md** formatted for GitHub:


# 🧠 Tic-Tac-Toe Using C (With Minimax AI)

This project is a terminal-based **Tic-Tac-Toe game written in C**, where the player competes against a computer opponent powered by the **Minimax algorithm**.
The AI always plays optimally, making it extremely difficult (almost impossible) to defeat.

---

## 🎯 Objective

To demonstrate how artificial intelligence concepts—specifically **decision trees and minimax strategy**—can be applied in game development using the C programming language.

---

## 🕹️ Features

* 👤 **Player vs AI mode**
* 🧠 **Unbeatable AI using Minimax**
* 🎛️ Input-based gameplay using row and column selection
* 🔍 Automatic win, lose, and draw detection
* 🧽 Clean visual board layout in terminal
* ⚠️ Input validation to prevent overwriting moves

---

## 📌 Game Rules

* Player symbol: **X**
* Computer (AI) symbol: **O**
* The player and AI take turns placing a symbol in an empty cell.
* First to form a line of **three in a row** (horizontal, vertical, diagonal) wins.
* If all nine cells are filled without a winner → **Match Draw**.

---

## 🧠 Algorithm Explanation: Minimax

The Minimax algorithm evaluates all possible future game states and chooses the best possible move.

| Player     | Role      | Goal                    |
| ---------- | --------- | ----------------------- |
| AI (O)     | Maximizer | Achieve score **+10**   |
| Player (X) | Minimizer | Reduce score to **-10** |

This ensures optimal play by exploring:

* Winning possibilities
* Opponent’s best counters
* Strategic draw when necessary

This makes the AI **unbeatable**.

---

## 🛠️ How to Compile & Run

### 1️⃣ Compile

```sh
gcc tic_tac_toe.c -o tictactoe
```

### 2️⃣ Run

```sh
./tictactoe
```

(Windows CMD users may run `tictactoe.exe` after compiling.)

---

## 📂 Project File Structure

```
📁 Tic-Tac-Toe-AI
│── tic_tac_toe.c       # Main source code
└── README.md           # Documentation
```

---

## 🖥️ Example Gameplay

```
   |   |  
-----------
   | X |  
-----------
   |   |  

Enter your move (row and column): 1 1

   |   |  
-----------
   | X |  
-----------
   |   | O
```

---

## 🚀 Future Enhancements (Optional)

* Add **difficulty modes** (Easy, Medium, Hard)
* Implement **Graphical UI**
* Add **scoreboard tracking**
* Add **sound or animations**

---

## 📚 Learning Outcomes

By completing this project, you will understand:

* Arrays and board representation
* Game loop logic
* Recursive AI decision-making
* Applying Minimax in turn-based games
* Evaluating game states and score calculation

---

## 👤 Author

**Subham Kumar Sahoo**

---

