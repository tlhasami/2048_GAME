#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <conio.h>

#define row 4
#define column 4

using namespace std;

void game_box_printer(int game_box_2048[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (game_box_2048[i][j] == 0)
                cout << setw(4) << "-";
            else
                cout << setw(4) << game_box_2048[i][j];
        }
        cout << endl;
    }
}
void random(int game_box_2048[row][column])
{
    int new_number[2] = {rand() % row, rand() % column};
    int tried = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (game_box_2048[i][j])
            {
                tried++;
            }
        }
    }
    system("cls");
    game_box_printer(game_box_2048);
    if (row * column == tried)
    {
        cout << "U have lost" << endl;
        exit(0);
    }
    while (game_box_2048[new_number[0]][new_number[1]])
    {
        new_number[0] = rand() % row;
        new_number[1] = rand() % column;
    }
    game_box_2048[new_number[0]][new_number[1]] = 2;
}

void working(int game_box_2048[row][column], char move)
{

    switch (move)
    {
    case 'w':
    {
        for (int i = 0; i < column; i++)
        {
            for (int j = row - 1; j > 0; j--)
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (game_box_2048[j][i] == game_box_2048[k][i])
                    {
                        game_box_2048[k][i] = 2 * game_box_2048[k][i];
                        game_box_2048[j][i] = 0;
                    }
                    else if (game_box_2048[k][i] > 0)
                    {
                        break;
                    }
                }
            }
        }
        for (int i = column - 1; i >= 0; i--)
        {
            for (int j = 0; j < row; j++)
            {
                if (game_box_2048[j][i] != 0)
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (game_box_2048[k][i] == 0)
                        {
                            game_box_2048[k][i] = game_box_2048[k + 1][i];
                            game_box_2048[k + 1][i] = 0;
                        }
                    }
                }
            }
        }
        break;
    }
    case 'a':
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = column - 1; j > 0; j--)
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (game_box_2048[i][k] != 0)
                    {
                        if (game_box_2048[i][j] == game_box_2048[i][k])
                        {
                            game_box_2048[i][k] = 2 * game_box_2048[i][k];
                            game_box_2048[i][j] = 0;
                        }
                        else if (game_box_2048[i][k] > 0)
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 1; j < column; j++)
            {
                if (game_box_2048[i][j] != 0)
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (game_box_2048[i][k] == 0)
                        {
                            game_box_2048[i][k] = game_box_2048[i][k + 1];
                            game_box_2048[i][k + 1] = 0;
                        }
                    }
                }
            }
        }
        break;
    }
    case 'd':
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column - 1; j++)
            {
                for (int k = j + 1; k < column; k++)
                {
                    if (game_box_2048[i][k] != 0)
                    {
                        if (game_box_2048[i][j] == game_box_2048[i][k])
                        {
                            game_box_2048[i][k] = 2 * game_box_2048[i][k];
                            game_box_2048[i][j] = 0;
                        }
                        else if (game_box_2048[i][k] > 0)
                        {
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = column - 1; j >= 0; j--)
            {
                if (game_box_2048[i][j] != 0)
                {
                    for (int k = j + 1; k < column; k++)
                    {
                        if (game_box_2048[i][k] == 0)
                        {
                            game_box_2048[i][k] = game_box_2048[i][k - 1];
                            game_box_2048[i][k - 1] = 0;
                        }
                    }
                }
            }
        }
        break;
    }
    case 's':
    {
        for (int i = 0; i < column; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = j + 1; k < row; k++)
                {
                    if (game_box_2048[j][i] == game_box_2048[k][i])
                    {
                        game_box_2048[k][i] = 2 * game_box_2048[k][i];
                        game_box_2048[j][i] = 0;
                    }
                    else if (game_box_2048[k][i] > 0)
                    {
                        break;
                    }
                }
            }
        }
        for (int i = column - 1; i >= 0; i--)
        {
            for (int j = row - 1; j >= 0; j--)
            {
                if (game_box_2048[j][i] != 0)
                {
                    for (int k = j + 1; k < row; k++)
                    {
                        if (game_box_2048[k][i] == 0)
                        {
                            game_box_2048[k][i] = game_box_2048[k - 1][i];
                            game_box_2048[k - 1][i] = 0;
                        }
                    }
                }
            }
        }
        break;
    }
    }
}

int main()
{
    srand(time(0));
    int game_box_2048[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            game_box_2048[i][j] = 0;
        }
    }

    game_box_2048[row - 1][column - 1] = 2;
    game_box_2048[row - 2][column - 1] = 2;

    char move;
    while (1)
    {
        game_box_printer(game_box_2048);
        cout << "\nEnter the move ( w->up / d->right / s->down / a->left ) : ";
        cin >> move;
        working(game_box_2048, move);
        random(game_box_2048);
        system("cls");
    }

    return 0;
}