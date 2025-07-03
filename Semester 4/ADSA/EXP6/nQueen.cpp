#include<iostream>
using namespace std;

int nQueen(int n, int** Solutions, int m);
int PlaceQueen(int** board, int n, int Row, int** Solutions, int& m); // Pass m by reference
int IsSafe(int** Board, int n, int Row, int Col);
void PrintSolutions(int** Solutions, int n, int m);

int nQueen(int n, int** Solutions, int m) {
    int** Board = new int*[n];
    for (int i = 0; i < n; i++) {
        Board[i] = new int[n];
        for (int j = 0; j < n; j++) {
            Board[i][j] = 0;
        }
    }
    int Row = 0;
    int result = PlaceQueen(Board, n, Row, Solutions, m);
    PrintSolutions(Solutions, n, m); // Print all solutions found
    return result;
}

int PlaceQueen(int** board, int n, int Row, int** Solutions, int& m) { // Pass m by reference
    if (Row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 1) {
                    Solutions[m][i] = j + 1; // Store the solution in a separate row
                    break;
                }
            }
        }
        m++; // Increment m to move to the next row for the next solution
        return 1;
    }
    int Res = 0;
    for (int Col = 0; Col < n; Col++) {
        if (IsSafe(board, n, Row, Col)) {
            board[Row][Col] = 1;
            Res = PlaceQueen(board, n, Row + 1, Solutions, m);
            board[Row][Col] = 0;
        }
    }
    return Res;
}

int IsSafe(int** Board, int n, int Row, int Col) {
    for (int i = 0; i < Row; i++) {
        if (Board[i][Col] == 1)
            return 0;
    }
    int i = Row;
    int j = Col;
    while ((i >= 0) && (j >= 0)) {
        if (Board[i][j] == 1)
            return 0;
        i--;
        j--;
    }
    i = Row;
    j = Col;
    while ((i >= 0) && (j < n)) {
        if (Board[i][j] == 1)
            return 0;
        i--;
        j++;
    }
    return 1;
}

void PrintSolutions(int** Solutions, int n, int m) {
    for (int i = 0; i < m; i++) {
        cout << "Solution " << (i + 1) << ": ";
        for (int j = 0; j < n; j++) {
            cout << Solutions[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int** Solutions = new int*[n * n]; // Allocate enough space for all possible solutions
    for (int i = 0; i < n * n; i++) {
        Solutions[i] = new int[n];
    }
    int result = nQueen(n, Solutions, 0);
    // if (result == 1) {
    //     cout << "Solutions found!" << endl;
    // } else {
    //     cout << "No solutions found." << endl;
    // }

    // Free memory
    for (int i = 0; i < n * n; i++) {
        delete[] Solutions[i];
    }
    delete[] Solutions;

    return 0;
}