#include <stdio.h>
#include <stdbool.h>

char board[3][3];

// Function to initialize board
void initBoard()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to print the board
void printBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("\n-----------\n");
    }
    printf("\n\n");
}

// Check if any moves left
bool movesLeft()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return true;
    return false;
}

// Evaluate board: +10 (AI wins), -10 (Player wins), 0 otherwise
int evaluate()
{
    // Rows
    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] &&
            board[row][1] == board[row][2])
        {
            if (board[row][0] == 'O')
                return +10;
            if (board[row][0] == 'X')
                return -10;
        }
    }

    // Columns
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] &&
            board[1][col] == board[2][col])
        {
            if (board[0][col] == 'O')
                return +10;
            if (board[0][col] == 'X')
                return -10;
        }
    }

    // Diagonals
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        if (board[0][0] == 'O')
            return +10;
        if (board[0][0] == 'X')
            return -10;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        if (board[0][2] == 'O')
            return +10;
        if (board[0][2] == 'X')
            return -10;
    }

    return 0;
}

// Minimax function
int minimax(bool isAI)
{
    int score = evaluate();

    if (score == 10)
        return 10;
    if (score == -10)
        return -10;
    if (!movesLeft())
        return 0;

    if (isAI)
    { // AI turn (Maximizer)
        int best = -1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    best = (best > minimax(false)) ? best : minimax(false);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
    else
    { // Human turn (Minimizer)
        int best = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    best = (best < minimax(true)) ? best : minimax(true);
                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

// Find the best move for AI
void bestMoveAI()
{
    int bestVal = -1000;
    int row = -1, col = -1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int moveVal = minimax(false);
                board[i][j] = ' ';

                if (moveVal > bestVal)
                {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    board[row][col] = 'O';
}

// Main function
int main()
{
    int x, y;
    initBoard();

    printf("AI Based Tic-Tac-Toe (Minimax Algorithm)\n");
    printf("You are X, AI is O\n");

    while (1)
    {
        printBoard();

        // Player move
        printf("Enter your move (row and column: 0 1 2): ");
        scanf("%d %d", &x, &y);

        if (board[x][y] != ' ')
        {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[x][y] = 'X';

        if (evaluate() == -10)
        {
            printBoard();
            printf("🎉 You Win!\n");
            break;
        }

        if (!movesLeft())
        {
            printBoard();
            printf("🤝 Draw!\n");
            break;
        }

        // AI Move
        bestMoveAI();

        if (evaluate() == 10)
        {
            printBoard();
            printf("🤖 AI Wins!\n");
            break;
        }

        if (!movesLeft())
        {
            printBoard();
            printf("🤝 Draw!\n");
            break;
        }
    }

    return 0;
}