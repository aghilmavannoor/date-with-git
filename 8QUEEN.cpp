#include <stdio.h> 
#include <stdbool.h> 
#define SIZE 8  
bool isSafe(int board[SIZE][SIZE], int row, int col) { 
    int i, j; 
    for (i = 0; i < col; i++) { 
        if (board[row][i]) { 
            return false; 
        } 
    } 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) { 
        if (board[i][j]) { 
            return false; 
        } 
    } 
    for (i = row, j = col; i < SIZE && j >= 0; i++, j--) { 
        if (board[i][j]) { 
            return false; 
        } 
    } 
    return true;   
} 
bool solve8QueensUtil(int board[SIZE][SIZE], int col) { 
    if (col >= SIZE) { 
        return true; 
    } 
    for (int i = 0; i < SIZE; i++) { 
        if (isSafe(board, i, col)) { 
            board[i][col] = 1; 
            if (solve8QueensUtil(board, col + 1)) { 
                return true; 
            }
            board[i][col] = 0; 
        } 
    } 
   return false; 
} 
void solve8Queens() { 
    int board[SIZE][SIZE] = {0};  
	if (solve8QueensUtil(board, 0)) { 
        printf("Solution for the 8-Queens problem:\n"); 
        for (int i = 0; i < SIZE; i++) { 
            for (int j = 0; j < SIZE; j++) { 
                printf("%c ", board[i][j] ? 'Q' : '.'); 
            } 
            printf("\n"); 
        } 
    } else { 
        printf("No solution exists for the 8-Queens problem.\n"); 
    } 
} 
int main() { 
    solve8Queens(); 
    return 0; 
}

















