#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

void print_board();
void update_board(char pos, char player);
bool check_winner();

vector<vector<char>> board = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
bool valid = false;

int main(void){
    char position;
    char player, first;
    print_board();
    cout << "Who starts first(x/o)? ";
    cin >> first;
    if (first == 'X' || first == 'x') {
        player = 'X';
    }
    else if (first == 'O' || first == 'o') {
        player = 'O';
    }
    while (true) {
        while (valid == false) {
            printf("%c turn - Enter position:", player);
            cin >> position;
            update_board(position, player);
        }
        valid = false;

        if (check_winner()) {
            cout << player << " Wins!";
            break;
        }

        if (player == 'X') {
            player = 'O';
        }
        else if (player == 'O') {
            player = 'X';
        }

    }
    return 0;
}

void print_board() {
    printf("%c|%c|%c\n_____\n%c|%c|%c\n_____\n%c|%c|%c\n", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2], board[2][0], board[2][1], board[2][2]);
    return;
}

void update_board(char pos, char player) {
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            if (pos == board[i][j] && (board[i][j] != 'X' && board[i][j] != 'O')) {
                board[i][j] = player;
                valid = true;
                break;
            }
        }
    }
    if (valid == false) {
        cout << "Invalid or already chosen position!" << endl;
    }
    else {
        print_board();
    }
    return;
}

bool check_winner() {
    // Check horizontaly
    for (size_t i = 0, n = board.size(); i < n; i++) {
        int count = 0;
        for (size_t j = 0, m = board[i].size()-1; j < m; j++) {
            if (board[i][j] == board[i][j+1]) {
                count++;
            }
        }
        if (count == 2) {
            return true;
        }
    }

    // Check verticaly
    for (size_t i = 0, n = board.size(); i < n; i++) {
        int count = 0;
        for (size_t j = 0, m = board[i].size()-1; j < m; j++) {
            if (board[j][i] == board[j + 1][i]) {
                count++;
            }
        }
        if (count == 2) {
            return true;
        }
    }

    // Check diagonal
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }
    return false;
}
