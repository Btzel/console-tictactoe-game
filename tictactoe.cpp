#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

bool isCheck(string arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int size = 3;
    int counter = 0;
    string ttt[3][3];
    
    // Initialize board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ttt[i][j] = "-";
        }
    }

    // Print initial board
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << " " << ttt[i][j] << " ";
            if (j != size - 1) {
                cout << "|";
            }
        }
        cout << endl;
    }

    while (true) {
        int row, column;
        string sign;
        int player_num;
        
        if (counter % 2 == 0) {
            player_num = 1;
            cout << "Turn for player 1" << endl;
            cout << "Please enter empty places to fill with X by their index" << endl;
            cout << "Index (row column): ";
            sign = "X";
        } else {
            player_num = 2;
            cout << "Turn for player 2" << endl;
            cout << "Please enter empty places to fill with O by their index" << endl;
            cout << "Index (row column): ";
            sign = "O";
        }
        
        cin >> row >> column;

        // Check for out-of-bounds and already filled positions
        if (row < 0 || row >= size || column < 0 || column >= size || ttt[row][column] != "-") {
            cout << "Invalid move, please try again." << endl;
            continue;
        }

        // Place the sign
        ttt[row][column] = sign;
        
        // Print updated board
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << " " << ttt[i][j] << " ";
                if (j != size - 1) {
                    cout << "|";
                }
            }
            cout << endl;
        }

        // Check horizontal, vertical, and diagonal win conditions
        string horizontal[3], vertical[3], diagonal1[3], diagonal2[3];
        for (int i = 0; i < size; i++) {
            horizontal[i] = ttt[row][i];
            vertical[i] = ttt[i][column];
        }

        bool diagonal1Check = false, diagonal2Check = false;

        if (row == column) {  // Main diagonal (top-left to bottom-right)
            for (int i = 0; i < size; i++) {
                diagonal1[i] = ttt[i][i];
            }
            diagonal1Check = true;
        }

        if (row + column == 2) {  // Anti-diagonal (bottom-left to top-right)
            for (int i = 0; i < size; i++) {
                diagonal2[i] = ttt[i][2 - i];
            }
            diagonal2Check = true;
        }

        // Check if any winning condition is met
        if (isCheck(horizontal, 3) || isCheck(vertical, 3) || (diagonal1Check && isCheck(diagonal1, 3)) || (diagonal2Check && isCheck(diagonal2, 3))) {
            cout << "The game is finished! Player " << player_num << " has won!" << endl;
            break;
        }

        // Check for draw
        if (counter == 8) {
            cout << "The game is a draw!" << endl;
            break;
        }

        counter++;
    }

    return 0;
}
