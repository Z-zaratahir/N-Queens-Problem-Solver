#include <iostream>
using namespace std;

bool is_Safe(int **board, int row, int col, int queens)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col] == 1)
            return false;
    }

    int m = row, n = col;
    while (m >= 0 && n >= 0)
    {
        if (board[m][n] == 1)
        {
            return false;
        }
        m--;
        n--;
    }

    m = row, n = col;
    while (m >= 0 && n < queens)
    {
        if (board[m][n] == 1)
        {
            return false;
        }
        m--;
        n++;
    }
    return true;
}

bool is_valid(int **&board, int queens)
{
    for (int i = 0; i < queens; ++i)
    {
        for (int j = 0; j < queens; ++j)

        {

            if (board[i][j] == 1)
            {
                if (!is_Safe(board, i, j, queens))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

bool royalHarmony(int **&board, int row, int column, int queens)
{
    if (row >= queens) // base case
    {
        return true;
    }

    for (int i = 0; i < queens; i++)
    {
        if (is_Safe(board, row, i, queens))
        {
            board[row][i] = 1;

            if (royalHarmony(board, row + 1, column, queens))
            {
                return true;
            }

            board[row][i] = 0;
        }
    }

    return false;
}

int main()
{
    int queens;
    cout << "Enter the number of queens (minimum 4): ";
    cin >> queens;
    while (queens < 4)
    {
        cout << "\n\nNo possible solution exists for queens fewer than 4..\nPlease re-enter the number of queens (minimum 4): ";
        cin >> queens;
    }
    // Dynamic allocation of the memory (board)
    int **board = new int *[queens];
    for (int i = 0; i < queens; ++i)
    {
        board[i] = new int[queens];
        for (int j = 0; j < queens; ++j)
        {
            board[i][j] = 0;
        }
    }

    if (royalHarmony(board, 0, 0, queens))
    {
        std::cout << "\n\nThe possible solution for " << queens << " queens is:\n\n";
        for (int i = 0; i < queens; ++i)
        {
            for (int j = 0; j < queens; ++j)
            {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Deallocating the memory (board)
    for (int i = 0; i < queens; ++i)
    {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}