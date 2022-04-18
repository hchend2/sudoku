#include <iostream>
#include <string>
#define N 9
#define rows 9
#define cols 9
using std::cout;
using std::cin;
using std::string;
using std::endl;

string sudoGrid[N][N] = {
   {"3", "0", "6", "5", "0", "8", "4", "0", "0"},
   {"5", "2", "0", "0", "0", "0", "0", "0", "0"},
   {"0", "8", "7", "0", "0", "0", "0", "3", "1"},
   {"0", "0", "3", "0", "1", "0", "0", "8", "0"},
   {"9", "0", "0", "8", "6", "3", "0", "0", "5"},
   {"0", "5", "0", "0", "9", "0", "6", "0", "0"},
   {"1", "3", "0", "0", "0", "0", "2", "5", "0"},
   {"0", "0", "0", "0", "0", "0", "0", "7", "4"},
   {"0", "0", "5", "2", "0", "6", "3", "0", "0"}
};

string tempGrid[N][N] = {""};

void printsudoGrid() {
    int count1 = 1;
    int count2 = 1;
    cout << "************************************************************************" << std::endl;
    for (int i = 0; i < N; i++) {
        cout << "*      |       |       *       |       |       *       |       |       *\n"
             << "* ";
        for (int j = 0; j < N; j++) {
            if (sudoGrid[i][j] == "0") {
                sudoGrid[i][j] = " ";
            }
            std::cout << " " << sudoGrid[i][j] << " ";
            if (count1%3 == 0) {
                std::cout << "  *  ";
            } else {
                std::cout << "  |  ";
            }
            count1++;
        }
        cout << endl << "*      |       |       *       |       |       *       |       |       *" << endl;
        if (count2%3 == 0) {
            cout << endl << "************************************************************************" << endl;
            } else {
                cout << endl << "------------------------------------------------------------------------" << endl;
            }
            count2++;
    }
}


void swapRows(string tempGrid[rows][cols], int row1, int row2) {
    tempGrid = sudoGrid;
    string tmp = "";
    for (int i = 0; i < cols; i++) {
        tmp = tempGrid[row1][i];
        tempGrid[row1][i] = tempGrid[row2][i];
        tempGrid[row2][i] = tmp;
    }
}

int main() {
    int m;
    int n;
    
  cout << endl << "Generate a SUDOKU " << endl << endl;
    printsudoGrid();
  cout << endl << "New sudoku..." << endl << endl;
    m = 3;
    n = 5;
    swapRows(tempGrid, 1, 3);
    printsudoGrid();
}