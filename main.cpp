#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };

int player = 1;
int choice;
int row , col;

// Display the board on screen
void display()
{
    for (int i = 0; i < 3; i++) {
        cout << " -------------" << endl;

        for (int j = 0; j < 3; j++)
		{
            cout << " | ";
            if (board[i][j]=='X' || board[i][j]=='O')
            	cout << board[i][j];
            else
             cout<<" ";
			if (j == 2)
                cout << " | ";
        }
        cout << endl;
        if (i == 2)
            cout << " -------------" << endl;
    }
    cout << endl;
}

// Check if the choice of the number is valid
bool valid()
{
	char ch = '0'+choice;
    return (choice >= 1 && choice <= 9 && board[row][col] == ch );
}

// Check if anyone wins.
bool win()
{
    return (board[row][0] == board[row][1] && board[row][1] == board[row][2]) ||
        (board[0][col] == board[1][col] && board[1][col] == board[2][col]) ||
        (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

// Check if the game draws
bool draw()
{
    for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
		{
            if (!(board[i][j] == 'X' || board[i][j] == 'O'))
                return false;
        }
    }
    return true;
}

// Human vs Human
void play_HvH() {
    while(true) {
        display();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << "  Enter a number: ";
        cin >> choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (valid())
		{
            board[row][col] = (player == 1) ? 'X' : 'O';

            if (win())
			{
                display();
                cout << "Player " << player << " WINS!" << endl;
                break;
            }

            else if (draw())
			{
                display();
                cout << "It's a Draw!" << endl;
                break;
            }

            player++;
        }
		else
            cout << endl << "Invalid Entry!" << endl << endl;

    }
}

//Human vs computer
void play_HvC() {
   // human's turn
    while(true) {
        display();
        cout<<"Enter a number: ";
        cin>>choice;

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (valid())
		{
		    board[row][col] = 'X';
		    if (win())
			{
                display();
                cout << "Congratulations! You WINS." << endl;
                break;
            }

            else if (draw())
			{
                display();
                cout << "It's a Draw!" << endl;
                break;
            }
        }
// computer's turn
        while(true) {
            choice = rand()%9+1;
            row = (choice-1)/3;
            col = (choice-1)%3;
            if (valid()) {
                board[row][col] = 'O';
                cout<<"Computer Selected position "<<choice<<endl;;
                break;
            }
        }


        if (win())
        {
            display();
            cout << "Computer WINS!" << endl;
            break;
        }
    }

}

/*------------------------------------------------
Main Program
------------------------------------------------*/

int main()
{
    int mode;
	cout << "---TIC TAC TOE---" << endl<<endl<<endl;
	cout << "'X': User 1"<<endl;      
	cout<<"'O': User 2 / Computer"<<endl<<endl ;
    cout<<"KEY : "<<"The number you enter corresponds to the game box number. "<<endl<<endl;
	cout << "Please Select the game mode" <<endl<<endl;
    
    
    cout << "1).  Human vs Human" <<endl<< "2).  Human vs Computer" <<endl<< endl;
    cout << "Enter 1 or 2: ";
    cin >> mode;

    if (mode == 1)
        play_HvH();
    else if (mode == 2)
        play_HvC();
    else
        cout << "Invalid Selection";

    return 0;
}
