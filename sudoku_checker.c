#include <stdio.h>

#define NUM_ROWS    9

int check_line(int line[NUM_ROWS]){
    int check_arr[NUM_ROWS] = {1,1,1,1,1,1,1,1,1};
    for (int i=0; i<NUM_ROWS; i++){
        check_arr[line[i]-1] = !check_arr[line[i]-1];
        /*printf("\ncurrent value %d\n", line[i]);*/
    }
    int sum = 0;
    for (int i=0; i<NUM_ROWS; i++){
        if(check_arr[i] != 0){
            /*printf("\nfailed value %d\n", i);*/
            return 1;
        }
        sum = sum + check_arr[i];
    }
    /*printf("\nsum: %d (should be 0)\n", sum);*/
    return sum;
}

int sudoku_checker(int sudoku[NUM_ROWS][NUM_ROWS]){
    for (int i=0; i<NUM_ROWS; i++){
        int temp_arr[NUM_ROWS];

        /* check row */
        if(check_line(sudoku[i])){
            printf("failed row %d", i);
            return 1;
        }
        for (int j=0; j<NUM_ROWS; j++){
            temp_arr[j] = sudoku[i][j];
        }
        /* check column */
        if(check_line(temp_arr)){
            printf("failed col %d", i);
            return 1;
        }
    }
    return 0;
}

int main (int argc, char *argv[]){
    int sudoku[NUM_ROWS][NUM_ROWS] = {
        {7,8,4,1,5,9,3,2,6},
        {5,3,9,6,7,2,8,4,1},
        {6,1,2,4,3,8,7,5,9},
        {9,2,8,7,1,5,4,6,3},
        {3,5,7,8,4,6,1,9,2},
        {4,6,1,9,2,3,5,8,7},
        {8,7,6,3,9,4,2,1,5},
        {2,4,3,5,6,1,9,7,8},
        {1,9,5,2,8,7,6,3,4}
    };
    if(sudoku_checker(sudoku)){
        printf("\nFailed\n");
        return 1;
    }
    printf("\nPassed\n");
    return 0;
}
