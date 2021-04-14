#include "header.h"
using namespace std;

void PrintGrid(vector<char>& Grid) {
    cout << "   |   |   \n " << Grid.at(0) << " | " << Grid.at(1) << " | " << Grid.at(2) << " \n___|___|___\n"
         << "   |   |   \n " << Grid.at(3) << " | " << Grid.at(4) << " | " << Grid.at(5) << " \n___|___|___\n"
         << "   |   |   \n " << Grid.at(6) << " | " << Grid.at(7) << " | " << Grid.at(8) << " \n   |   |   \n\n";
}

char CheckWin(vector<char>& Grid) {
    // first row win condition
    if (Grid.at(0) == Grid.at(1) && Grid.at(1) == Grid.at(2)) {
        if (Grid.at(0) == 'X')
            return 'X';
        else if (Grid.at(0) == 'O')
            return 'O';
        else
            return 'N';
    }
    // second row win condition
    else if (Grid.at(3) == Grid.at(4) && Grid.at(4) == Grid.at(5)) {
        if (Grid.at(3) == 'X')
            return 'X';
        else if (Grid.at(3) == 'O')
            return 'O';
        else
            return 'N';
    }
    // third row win condition
    else if (Grid.at(6) == Grid.at(7) && Grid.at(7) == Grid.at(8)) {
        if (Grid.at(6) == 'X')
            return 'X';
        else if (Grid.at(6) == 'O')
            return 'O';
        else
            return 'N';
    }
    // first column win condition
    else if (Grid.at(0) == Grid.at(3) && Grid.at(3) == Grid.at(6)) {
        if (Grid.at(0) == 'X')
            return 'X';
        else if (Grid.at(0) == 'O')
            return 'O';
        else
            return 'N';
    }
    // second column win condition
    else if (Grid.at(1) == Grid.at(4) && Grid.at(4) == Grid.at(7)) {
        if (Grid.at(1) == 'X')
            return 'X';
        else if (Grid.at(1) == 'O')
            return 'O';
        else
            return 'N';
    }
    // third column win condition
    else if (Grid.at(2) == Grid.at(5) && Grid.at(5) == Grid.at(8)) {
        if (Grid.at(2) == 'X')
            return 'X';
        else if (Grid.at(2) == 'O')
            return 'O';
        else
            return 'N';
    }
    // first diagonal win condition
    else if (Grid.at(0) == Grid.at(4) && Grid.at(4) == Grid.at(8)) {
        if (Grid.at(0) == 'X')
            return 'X';
        else if (Grid.at(0) == 'O')
            return 'O';
        else
            return 'N';
    }
    // second diagonal win condition
    else if (Grid.at(2) == Grid.at(4) && Grid.at(4) == Grid.at(6)) {
        if (Grid.at(2) == 'X')
            return 'X';
        else if (Grid.at(2) == 'O')
            return 'O';
        else
            return 'N';
    }
    else {
        for (int i = 0; i < 9; ++i) {
            if (Grid.at(i) == ' ') {
                return 'N'; // grid is not full
            }
        }
        return 'Q'; // grid is full
    }
}

void GetPlayerInput(std::vector<char>& Grid, char playerMark, string playerName) {
        int choice;

        cout << playerName << ", enter a number corresponding to a grid: ";
        cin >> choice;

        while (choice < 1 || choice > 9) {
            cout << "\nInvalid option. Enter a number corresponding to a grid: ";
            cin >> choice;
        }

        if (Grid.at(choice-1) == ' ') {
            Grid.at(choice-1) = playerMark;
        }
        else {
            while (Grid.at(choice-1) != ' ') {
                cout << "\nInvalid option. Enter a number corresponding to an empty square: ";
                cin >> choice;

                while (choice < 1 || choice > 9) {
                    cout << "\nInvalid option. Enter a number corresponding to a grid: ";
                    cin >> choice;
                }
            }
            Grid.at(choice-1) = playerMark;
        }
}
