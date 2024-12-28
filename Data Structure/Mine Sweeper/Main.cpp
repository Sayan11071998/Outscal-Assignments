#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

using namespace std;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool getInput(char& action, int& x, int& y)
{
    cout << "Enter action (R for reveal, F for flag) and coordinates (x y): ";

    if (!(cin >> action >> x >> y))
    {
        cout << "Invalid input! Please enter a valid action and coordinates.\n";
        clearInput();
        return false;
    }

    return true;
}

class Minesweeper
{
public:
    Minesweeper(int n, int mines) : size(n), totalMines(mines), firstMove(true) {
        board = vector<vector<char>>(size, vector<char>(size, '#'));
        mineBoard = vector<vector<int>>(size, vector<int>(size, 0));
        flags = vector<vector<bool>>(size, vector<bool>(size, false));
        rng = std::mt19937(std::random_device{}());
    }

    void displayBoard() const
    {
        cout << "  ";

        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
        }

        cout << endl;

        for (int i = 0; i < size; i++)
        {
            cout << i << " ";

            for (int j = 0; j < size; j++)
            {
                if (flags[i][j])
                    cout << "F ";
                else if (board[i][j] != '#')
                    cout << board[i][j] << " ";
                else
                    cout << "# ";
            }

            cout << endl;
        }
    }

    void play()
    {
        int x = 0, y = 0;
        char action = 'R';

        while (true)
        {
            displayBoard();

            if (!getInput(action, x, y)) { continue; }

            if (!isValid(x, y))
            {
                cout << "Invalid coordinates. Try again.\n";
                continue;
            }

            if (action == 'F' || action == 'f')
            {
                if (board[x][y] != '#')
                {
                    cout << "Cannot flag an already revealed cell.\n";
                    continue;
                }

                flags[x][y] = !flags[x][y];
                continue;
            }

            if (action == 'R' || action == 'r')
            {
                if (flags[x][y])
                {
                    cout << "Cell is flagged. Unflag it before revealing.\n";
                    continue;
                }

                if (firstMove)
                {
                    placeMines(x, y);
                    firstMove = false;
                }

                if (mineBoard[x][y] == -1)
                {
                    revealMines();
                    displayBoard();
                    cout << "BOOM! You hit a mine. Game Over.\n";
                    break;
                }

                reveal(x, y);

                if (checkWin())
                {
                    displayBoard();
                    cout << "Congratulations! You won the game!\n";
                    break;
                }
            }
            else
            {
                cout << "Invalid action. Use R for reveal or F for flag.\n";
            }
        }
    }

private:
    int size;
    int totalMines;
    bool firstMove;
    vector<vector<char>> board;
    vector<vector<int>> mineBoard;
    vector<vector<bool>> flags;
    std::mt19937 rng;

    vector<pair<int, int>> directions{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

    bool isValid(int x, int y) const
    {
        return x >= 0 && x < size && y >= 0 && y < size;
    }

    void placeMines(int safeX, int safeY)
    {
        int minesPlaced = 0;
        std::uniform_int_distribution<int> dist(0, size - 1);

        while (minesPlaced < totalMines)
        {
            int x = dist(rng);
            int y = dist(rng);

            if (mineBoard[x][y] == -1 || (x >= safeX - 1 && x <= safeX + 1 && y >= safeY - 1 && y <= safeY + 1))
                continue;

            mineBoard[x][y] = -1;
            minesPlaced++;

            for (auto dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isValid(nx, ny) && mineBoard[nx][ny] != -1) { mineBoard[nx][ny]++; }
            }
        }
    }

    void reveal(int x, int y)
    {
        if (!isValid(x, y) || board[x][y] != '#') return;

        board[x][y] = mineBoard[x][y] == 0 ? ' ' : mineBoard[x][y] + '0';

        if (mineBoard[x][y] == 0)
        {
            for (auto dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isValid(nx, ny)) { reveal(nx, ny); }
            }
        }
    }

    void revealMines()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (mineBoard[i][j] == -1) { board[i][j] = '*'; }
            }
        }
    }

    bool checkWin() const
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == '#' && mineBoard[i][j] != -1) return false;
            }
        }
        return true;
    }
};

void gameStartPrints()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "|                                                          |" << endl;
    cout << "|               WELCOME TO MINESWEEPER                     |" << endl;
    cout << "|                                                          |" << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << endl;

    cout << "RULES:" << endl;
    cout << "1. The board is divided into cells, with mines randomly distributed." << endl;
    cout << "2. To win, you need to open all the cells." << endl;
    cout << "3. The number on a cell shows the number of mines adjacent to it. Using this information, you can determine cells that are safe, and cells that contain mines." << endl;
    cout << "4. Interact, evolve and enjoy!" << endl;

    cout << endl;

    cout << "How to Play:" << endl;
    cout << "1. User will input x & y (Co-ordinates where they want to click)" << endl;
    cout << "2. In each step check for win or lose case" << endl;

    cout << endl;
}

int main()
{
    int n, mines;
    char choice;

    gameStartPrints();

    cout << "Enter Y/y to continue or N/n to close the game: ";
    cin >> choice;

    if (choice == 'N' || choice == 'n')
    {
        cout << "See you next time!! Goodbye." << endl;
        return 0;
    }
    else if (choice == 'Y' || choice == 'y')
    {
        cout << "\nEnter board size (n >= 9): ";
        cin >> n;
        if (n < 9)
        {
            cout << "Board size must be at least 9. Exiting..." << endl;
            return 0;
        }
    }
    else
    {
        cout << "Invalid Input!!" << endl;
        return 0;
    }

    int maxMines = static_cast<int>(0.2 * n * n);

    while (true)
    {
        cout << "Enter number of mines (max " << maxMines << "): ";
        cin >> mines;

        if (mines > 0 && mines <= maxMines) break;
        else cout << "Invalid input! The number of mines must be between 1 and " << maxMines << ".\n";
    }

    Minesweeper game(n, mines);
    game.play();

    return 0;
}