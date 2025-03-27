#include <cstdlib>
#include <ctime>
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif

using namespace std;

void printBorder(int length = 60, char symbol = '_') {
    cout << string(length, symbol) << endl;
}

void clearScreen() {
    system(CLEAR_SCREEN);
}

void celebrateWin() {
    cout << "\nCongratulations! You guessed the secret number!" << endl;
    cout << "You are the winner!" << endl;
    cout << "\n" << string(50, '_') << endl;
    cout << "          WELL DONE!          " << endl;
    cout << string(50, '_') << endl;
    cout << "\nThanks for playing. Play again to challenge yourself!" << endl;
}

bool playAgain() {
    char choice;
    cout << "\nDo you want to play more? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    while (true) {
        clearScreen();
        printBorder();
        cout << "\t\tWELCOME TO GUESS THE NUMBER GAME" << endl;
        printBorder();
        cout << "\nGuess a number between 1 and 100 until you find the secret number." << endl;
        cout << "Good luck and have fun!" << endl;
        printBorder();

        cout << "\nChoose the difficulty level: \n";
        cout << "1.Easy\t";
        cout << "2.Medium\t";
        cout << "3.Difficult\t";
        cout << "0.Exit the game\n";
        printBorder();

        int difficultyChoice;
        cout << "Enter your choice: ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            clearScreen();
            printBorder();
            cout << "\nExiting the game. Thanks for playing!" << endl;
            printBorder();
            exit(0);
        }

        if (difficultyChoice != 1 && difficultyChoice != 2 && difficultyChoice != 3) {
            cout << "\nInvalid choice! Please enter 0, 1, 2, or 3." << endl;
            printBorder();
            continue;
        }

        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playerChoice;

        clearScreen();
        printBorder(70, '_');
        cout << "\nStart guessing the secret number between 1 and 100" << endl;
        printBorder(70, '_');

        while (true) {
            cout << "\nEnter your guess: ";
            cin >> playerChoice;

            if (playerChoice == secretNumber) {
                celebrateWin();
                if (!playAgain()) {
                    cout << "\nExiting the game. Thanks for playing!" << endl;
                    printBorder();
                    exit(0);
                }
                break;
            } else {
                cout << "\nNo, " << playerChoice << " is not the right number." << endl;
                if (playerChoice > secretNumber) {
                    cout << "The secret number is smaller than your guess." << endl;
                } else {
                    cout << "The secret number is larger than your guess." << endl;
                }
                printBorder(70, '_');
            }
        }
    }

    return 0;
}