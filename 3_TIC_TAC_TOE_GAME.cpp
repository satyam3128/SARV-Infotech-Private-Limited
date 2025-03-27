#include <iostream>
using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col;
char cross = 'X';
bool draw = false;
string player1, player2;

void displayBoard() {
    system("clear"); 
    cout << "    |    |    \n";
    cout << "  " << space[0][0] << " | " << space[0][1] << "  | " << space[0][2] << " \n";
    cout << "\n";
    cout << "    |    |    \n";
    cout << "  " << space[1][0] << " | " << space[1][1] << "  | " << space[1][2] << " \n";
    cout << "\n";
    cout << "    |    |    \n";
    cout << "  " << space[2][0] << " | " << space[2][1] << "  | " << space[2][2] << " \n";
    cout << "    |    |    \n";
}

void takeInput() {
    int position;
    if (cross == 'X') {
        cout << player1 << "'s turn (X), choose a position (1-9): ";
    } else {
        cout << player2 << "'s turn (O), choose a position (1-9): ";
    }
    
    cin >> position;

    if (position >= 1 && position <= 9) {
        row = (position - 1) / 3;
        col = (position - 1) % 3;

        if (space[row][col] != 'X' && space[row][col] != 'O') {
            space[row][col] = cross;
            cross = (cross == 'X') ? 'O' : 'X';
        } else {
            cout << "Position already taken! Try again.\n";
            takeInput();
        }
    } else {
        cout << "Invalid input! Choose a position between 1 and 9.\n";
        takeInput();
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2]) return true;
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) return true;
    }
    if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) return true;
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0]) return true;
    
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') return false;
        }
    }
    return true;
}

void startGame() {
    cout<<"\n\n\n";
    cout << "Enter the name of the first player (X): ";
    getline(cin, player1);
    cout << "Enter the name of the second player (O): ";
    getline(cin, player2);

    while (true) {
        displayBoard();
        takeInput();

        if (checkWin()) {
            displayBoard();
            cout << (cross == 'X' ? player2 : player1) << " wins!\n";
            break;
        }

        if (checkDraw()) {;
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
    }
}

int main() {
    startGame();
    return 0;
}