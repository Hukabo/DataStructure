#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix[10][10];
int rows = 10, cols = 10;

void initialize() {
    srand(time(NULL));

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            matrix[i][j] = (rand() % 100) + 1; // 1 ~ 100
        }
    }
}

/*
    c언어 함수에서 2차원 배열을 파라미터로 받을 때 첫 번째 차원은 생략가능하지만,
    두 번째 차원은 명시를 해줘야함(생략 시 컴파일 오류).

    When receving a 2D array as a parameter in C language fucntion,
    the second dimension must be spectified.
*/
void search(int matrix[][10], int key) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == key)
                printf("The element is located at matrix[%d][%d]\n", i, j);
        }
    }
}

void access(int matrix[][10]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++){
            printf("The element %d is located at matrix[%d][%d]\n",matrix[i][j], i, j);
        }
    }
}

int main() {

    initialize();

    printf("The matrix is:\n");

    // Row-wise Traversal of a Matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Column-wise Traversal of a Matrix
    for(int i = 0; i < cols; i++){
        for(int j = 0; j < rows; j++) {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    int key = 3;

    printf("\n");
    search(matrix, key);

    printf("\n");
    access(matrix);

    return 0;
}