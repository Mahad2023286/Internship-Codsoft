#include<iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
        
    else
        return -1;
}

void board()
{
  system("cls");
    cout << "Welcome to the tic tac toe game in C++ \n";
    cout << "Player 1 is X, Player 2 is O \n";

    cout << "	" << square[1] << "	|	" << square[2] << "	|	" << square[3] << endl;
    cout << "	" << square[4] << "	|	" << square[5] << "	|	" << square[6] << endl;
    cout << "	" << square[7] << "	|	" << square[8] << "	|	" << square[9] << endl;
}

void setBoard()
{
    for (int i = 1; i <= 9; ++i)
    {
    square[i] = '0' + i;
    }
}

int main()
{
    int player = 1, i, choice, a;
    char mark;
    int repeat = 1;

    do
    {
        setBoard();  
        do
        {
            board();
            player = player % 2 ? 1 : 2;
            cout << "Player " << player << ", Enter number \n";
            cin >> choice;

            mark = (player == 1) ? 'X' : 'O';

            if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
            {
                square[choice] = mark;
            }

            else
            {
                cout << "INVALID MOVE \n";
                player--;
                cin.ignore();
                cin.get();
            }
            
			i = checkwin();
            player++;
        } 
		while (i == -1);

        board();

        if (i == 1)
        {
            cout << "CONGRATULATIONS! \n";
            cout << "Player " << --player << " Won\n";
        }

        else
        {
            cout << "The Game is DRAW, WELL PLAYED! \n";
        }

        cout << "Do you want to play again? \n";
        cout << "Enter 1 for yes, 0 for no \n";
        cin >> repeat;

    } while (repeat == 1);

    cin.ignore();
    cin.get();
    return 0;
}

