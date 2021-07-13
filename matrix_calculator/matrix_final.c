#include<stdio.h>

void add_two_matrix();
void sub_two_matrix();
void mul_two_matrix();
void mul_matrix_constant();
void determinant_of_matrix();

void display_menu();
void get_matrix();
int i, j, k;
int row, column;
float ratio;

int main(){
    display_menu();
    int choose;
    scanf("%d", &choose);

    if (choose == 1){
        int matrix1[20][20]; get_matrix(matrix1);
        int matrix2[20][20]; get_matrix(matrix2);
        int matrixSum[20][20]; add_two_matrix(matrixSum, matrix1, matrix2, row, column);
        printf("two matrices are added together: \n");
        for (i=0; i<row; ++i)
            for (j=0; j<column; ++j){
                printf("%d  ", matrixSum[i][j]);
                if(j == column - 1){
                    printf("\n\n");
                }
            }
    }

    else if (choose == 2){
        int matrix1[20][20]; get_matrix(matrix1);
        int matrix2[20][20]; get_matrix(matrix2);
        int matrixSub[20][20]; sub_two_matrix(matrixSub, matrix1, matrix2, row, column);
        printf("two matrices are added together: \n");
        for (i=0; i<row; ++i)
            for (j=0; j<column; ++j){
                printf("%d  ", matrixSub[i][j]);
                if(j == column - 1){
                    printf("\n\n");
                }
            }
    }
    else if (choose == 3){
        int matrix1[20][20]; get_matrix(matrix1);
        int matrix2[20][20]; get_matrix(matrix2);
        int matrixMul[20][20]; mul_two_matrix(matrixMul, matrix1, matrix2, row, column);
        printf("two matrices are multiplied: \n");
        for (i=0; i<row; ++i)
            for (j=0; j<column; ++j){
                printf("%d  ", matrixMul[i][j]);
                if(j == column - 1){
                    printf("\n\n");
                }
            }
    }

    else if (choose == 4){
        int matrix1[20][20]; get_matrix(matrix1);
        int constant; printf("enter the constant: "); scanf("%d", &constant);

        mul_matrix_constant(matrix1, constant, row, column);
        printf("matrix is multiplied by %d: \n", constant);
        for (i=0; i<row; ++i)
            for (j=0; j<column; ++j){
                printf("%d  ", matrix1[i][j]);
                if(j == column - 1){
                    printf("\n\n");
                }
            }
    }

    else if (choose == 5){
        float matrix1[20][20];
        int n;

        // matrix must be square
        printf("enter order of matrix: ");
        scanf("%d", &n);

        // user enters matrix' elements
        for (i=0; i<n; ++i)
            for(j=0; j<n; j++){
                printf("matrix1[%d][%d]= ", i, j);
                scanf("%f", &matrix1[i][j]);
            }

        // applying gauss elimination
        for(i=0; i<n; i++){
            if(matrix1[i][i] == 0){
                printf("Error! Diagonal element cant be zero!\n");
                exit(0);
            }
            for(j=i+1; j<n; j++){
                ratio = matrix1[j][i] / matrix1[i][i];

                for(k=0; k<n; k++)
                    matrix1[j][k] = matrix1[j][k] - ratio*matrix1[i][k];
            }
        }

        determinant_of_matrix(matrix1, n);
    }

    system("pause");
    return 0;
}

void display_menu(){
    printf("1: Add two matrix\n");
    printf("2: Substract two matrix\n");
    printf("3: Multiply two matrix\n");
    printf("4: Multiply matrix with a constant\n");
    printf("5: Find determinant of a matrix\n");
}

void get_matrix(int matrix[20][20]){

    printf("enter number of rows: ");
    scanf("%d", &row);

    printf("enter number of columns: ");
    scanf("%d", &column);

    for (i=0; i<row; ++i)
        for (j=0; j<column; ++j){
        printf("enter a[%d][%d]: ", i+1, j+1 );
        scanf("%d", &matrix[i][j]);
    }

}

void add_two_matrix(int sum[20][20], int a[20][20], int b[20][20], int row, int column){
    for (i=0; i<row; ++i)
        for (j=0; j<column; ++j){
            sum[i][j] = a[i][j] + b[i][j];
        }
}

void sub_two_matrix(int sub[20][20], int a[20][20], int b[20][20], int row, int column){
    for (i=0; i<row; ++i)
        for (j=0; j<column; ++j){
            sub[i][j] = a[i][j] - b[i][j];
    }
}

void mul_two_matrix(int mul[20][20], int a[20][20], int b[20][20], int row, int column){
    for (i=0; i<row; ++i)
        for (j=0; j<column; ++j){
            mul[i][j] = 0;
            for (k = 0; k < column; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
}

void mul_matrix_constant(int a[20][20], int constant, int row, int column){
    for (i=0; i<row; ++i)
        for (j=0; j<column; ++j)
                a[i][j] = a[i][j] * constant;
}

void determinant_of_matrix(float matrix[20][20], int n){

    float det = 1;

    // second, applying gauss elimination
    for(i=0; i<n; i++){
        if(matrix[i][i] == 0){
            printf("Error! Diagonal element cant be zero!\n");
            exit(0);
        }
        for(j=i+1; j<n; j++){
            ratio = matrix[j][i] / matrix[i][i];

            for(k=0; k<n; k++)
                matrix[j][k] = matrix[j][k] - ratio*matrix[i][k];
        }
    }

    // determinant can be found by
    for(i=0; i<n; i++){
        det = det*matrix[i][i];
    }
    printf("Determinant of this matrix is: %f\n", det);
}
