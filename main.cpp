#include "header.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    string playerName1, playerName2, winner;
    char playerMark1, playerMark2 = 'O';
    vector<char> Grid(9);

    for (int i = 0; i < 9; ++i)
        Grid.at(i) = ' ';

    cout << "Welcome to Tic-Tac-Toe!\n\n";
    cout << "The game will be played in a series of grids numbered 1 through 9. To place your mark on a grid, simply enter the corresponding number for that grid.\n\n";
    cout << "   |   |   \n 1 | 2 | 3 \n___|___|___\n   |   |   \n 4 | 5 | 6 \n___|___|___\n   |   |   \n 7 | 8 | 9 \n   |   |   \n\n";
    cout << "To begin, what is the first player's name?\n\t>> ";
    cin >> playerName1;
    cout << "\nHello, " << playerName1 << "! Welcome to the game. Now what is the second player's name?\n\t>> ";
    cin >> playerName2;
    cout << "\nWelcome, " << playerName2 << ". " << playerName1 << " gets decides his mark. What would " << playerName1 << " like his mark to be? Enter 'X' or 'O'. Default is 'X'.\n\t>> ";
    cin >> playerMark1;

    if (playerMark1 == 'O')
        playerMark2 = 'X';
    else
        playerMark1 = 'X';

    cout << "\nLet's begin!\n\n";

    while (CheckWin(Grid) != 'Q') {
        PrintGrid(Grid);

        GetPlayerInput(Grid, playerMark1, playerName1);

        if (CheckWin(Grid) == playerMark1 || CheckWin(Grid) == 'Q')
            break;

        PrintGrid(Grid);

        GetPlayerInput(Grid, playerMark2, playerName2);

        if (CheckWin(Grid) == playerMark2 || CheckWin(Grid) == 'Q')
            break;
    }

    cout << "\n\nThe winner is... ";
    if (CheckWin(Grid) == playerMark1) {
        cout << playerName1 << "! Congratulations!\n";
        winner = playerName1;
    }
    else if (CheckWin(Grid) == playerMark2) {
        cout << playerName2 << "! Congratulations!\n";
        winner = playerName2;
    }
    else if (CheckWin(Grid) == 'Q') {
        cout << "neither of you! Stalemate!\n";
        winner = "Stalemate";
    }
    else {
        cout << "This isn't supposed to happen. Thanks for playing!\n";
        return 1;
    }

    ofstream winnerFile;
    winnerFile.open("winners.txt", fstream::app);

    if (!winnerFile.is_open()) {
        cout << "This match was not recorded.\n";
        return 1;
    }
    else {
        time_t matchTime = time(0);
        string date = ctime(&matchTime);
        date.pop_back();

        winnerFile << "Winner of " << playerName1 << " vs. " << playerName2 << " on " << date << ": " << winner << endl;

        cout << "This match has been recorded in winners.txt.\n";
        winnerFile.close();
    }

    char outputChoice;

    cout << "Would you like to output all recorded matches? Enter 'y' to print and any other character to quit.\n\t>> ";
    cin >> outputChoice;
    cout << endl;

    if(outputChoice == 'y') {
        string winnerLine;
        ifstream outputFile;

        outputFile.open("winners.txt");
        if (!outputFile.is_open()) {
            cout << "Was unable to read from winners.txt.\n";
            return 1;
        }
        while (getline(outputFile, winnerLine)) {
            cout << winnerLine << endl;
        }
        outputFile.close();
    }

    return 0;
}
