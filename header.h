#ifndef HEADER
#define HEADER

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void PrintGrid(vector<char>& Grid); // prints the grid to show user choices taken by computer and self
char CheckWin(vector<char>& Grid); // checks the grid for a win and returns the winning mark
void GetPlayerInput(vector<char>& Grid, char playerMark,string playerName); // gets and checks user square choice
#endif
