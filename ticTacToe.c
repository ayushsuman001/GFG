#include <stdio.h>

//print statement
void print(char matrix[3][3]) {
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", matrix[i][0], matrix[i][1], matrix[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

//To check for win status
int checkWin(char matrix[3][3], char playerName) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == playerName && matrix[i][1] == playerName && matrix[i][2] == playerName) ||
            (matrix[0][i] == playerName && matrix[1][i] == playerName && matrix[2][i] == playerName)) {
            return 1; // Player has won
        }
    }
    if ((matrix[0][0] == playerName && matrix[1][1] == playerName && matrix[2][2] == playerName) ||
        (matrix[0][2] == playerName && matrix[1][1] == playerName && matrix[2][0] == playerName)) {
        return 1; // Player has won
    }
    return 0; // No winner yet
}


//_main_

int main() {
    char matrix[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int drawCheck = 1;
    printf("\n--------------------------------\n");
    printf("\nTic-Tac-Toe Game\n");
    printf("\n--------------------------------\n");
    while (1) {
        print(matrix);
        printf("\nPlayer %c's turn,\n\nEnter row and column (example : 1 2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3 || matrix[row - 1][col - 1] != ' ') {
            printf("\nInvalid move , try again\n");
            continue;
        }
        matrix[row - 1][col - 1] = currentPlayer;
        if (checkWin(matrix, currentPlayer)) {
            print(matrix);
            printf("Player %c won!\n", currentPlayer);
            break;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == ' ') {
                    drawCheck = 0;
                    break;
                }
            }
        }
        if (drawCheck) {
            print(matrix);
            printf("The match is a DRAW!\n");
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
