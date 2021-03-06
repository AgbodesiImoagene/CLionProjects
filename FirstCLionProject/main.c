#include <stdio.h>
void matrix_calculator(void);
void double_swap(double *a, double *b);
void row_swap(double a[100][100], int row_1, int row_2);
void matrix_addition(double a[100][100], double b[100][100], double c[100][100], int x, int y);
void scalar_multiplication(double a[100][100], int x, int y, double scalar);
void vector_multiplication(double a[100][100], int x, int y, const double b[100], double c[100]);
void matrix_multiplication(double a[100][100], int x, int y, double b[100][100], int w, int z, double c[100][100]);
void transpose(double a[100][100], int x, int y);
void REF(double a[100][100], int x, int y);
void RREF(double a[100][100], int x, int y);
int rank(double a[100][100], int x, int y);
int row_equivalence(double a[100][100], double b[100][100], int x, int y);
int SLE(double a[100][100], int x, int y);
void minors(double a[100][100], int n);
void cofactors(double a[100][100], int n);
void adjoint(double a[100][100], int n);
double determinant(double a[100][100], int n);
void LU_decomposition(double a[100][100], int n, double L[100][100], double U[100][100]);

int main(void) {
    matrix_calculator();
    printf("Thank you for using this program. \n");
    return 0;
}
void matrix_calculator(void) {
    int a, b;
    printf("For matrix addition enter 1. \n");
    printf("For matrix subtraction enter 2. \n");
    printf("For matrix-scalar multiplication enter 3. \n");
    printf("For matrix-vector multiplication enter 4. \n");
    printf("For matrix-matrix multiplication enter 5. \n");
    printf("For the matrix transpose enter 6. \n");
    printf("For the REF of a matrix enter 7. \n");
    printf("For the RREF of a matrix enter 8. \n");
    printf("For the rank of a matrix enter 9. \n");
    printf("To check if two matrices are row-equivalent enter 10. \n");
    printf("To solve an SLE in the form 'Ax = b' enter 11. \n");
    printf("For the matrix of minors of a square matrix enter 12. \n");
    printf("For the matrix of cofactors of a square matrix enter 13. \n");
    printf("For the adjoint of a square matrix enter 14. \n");
    printf("For the determinant of a matrix enter 15. \n");
    printf("For the inverse of a matrix enter 16. \n");
    printf("For the LU-decomposition of a square matrix enter 17. \n");


    scanf("%d", &a);

    if (a == 1) {
        double matrix1[100][100], matrix2[100][100], matrix3[100][100];
        int x, y, i, j;
        printf("Enter the number of rows of the two matrices: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the two matrices: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the first matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix1[i][j]);
                }
            }
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the second matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix2[i][j]);
                }
            }
            matrix_addition(matrix1, matrix2, matrix3, x, y);
            printf("The first matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix1[i][j]);
                }
                printf("] \n");
            }
            printf("The second matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix2[i][j]);
                }
                printf("] \n");
            }
            printf("The sum of both matrices is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix3[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 2) {
        double matrix1[100][100], matrix2[100][100], matrix3[100][100];
        int x, y, i, j;
        printf("Enter the number of rows of the two matrices: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the two matrices: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the first matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix1[i][j]);
                }
            }
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the second matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix2[i][j]);
                }
            }
            printf("The first matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix1[i][j]);
                }
                printf("] \n");
            }
            printf("The second matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix2[i][j]);
                }
                printf("] \n");
            }
            scalar_multiplication(matrix2, x, y, -1.0);
            matrix_addition(matrix1, matrix2, matrix3, x, y);
            printf("The difference of both matrices is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix3[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 3) {
        double matrix[100][100], z;
        int x, y, i, j;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        printf("Enter the scalar value for multiplication: ");
        scanf("%lf", &z);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            printf("The matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            scalar_multiplication(matrix, x, y, z);
            printf("The product of the matrix and the scalar is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 4) {
        double matrix[100][100], vector[100], vector2[100];
        int x, y, z, i, j;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        printf("Enter the size of the vector: ");
        scanf("%d", &z);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else if (z > 100) {
            printf("The vector is too large. \n");
        } else {
            if (y != z) {
                printf("The matrix and vector are not compatible for multiplication. \n");
            } else {
                for (i = 0; i < x; i++) {
                    for (j = 0; j < y; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                for (i = 0; i < z; i++) {
                    printf("Enter the element %d of the vector: ",i + 1);
                    scanf("%lf", &vector[i]);
                }
                printf("The matrix is: \n");
                for (i = 0; i < x; i++) {
                    printf("[ ");
                    for (j = 0; j < y; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                printf("The vector is: \n");
                for (i = 0; i < z; i++) {
                    printf("[ %lf ] \n", vector[i]);
                }
                vector_multiplication(matrix, x, y, vector, vector2);
                printf("The product of the matrix and the vector is: \n");
                for (i = 0; i < x; i++) {
                    printf("[ %lf ] \n", vector2[i]);
                }
            }
        }
    } else if (a == 5) {
        double matrix1[100][100], matrix2[100][100], matrix3[100][100];
        int w, x, y, z, i, j;
        printf("Enter the number of rows of the first matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the first matrix: ");
        scanf("%d", &y);
        printf("Enter the number of rows of the second matrix: ");
        scanf("%d", &w);
        printf("Enter the number of columns of the second matrix: ");
        scanf("%d", &z);
        if ((x > 100) || (y > 100) || (w > 100) || (z > 100)) {
            printf("A matrix is too large. \n");
        } else {
            if (y != w) {
                printf("The two matrices are not compatible for multiplication. \n");
            } else {
                for (i = 0; i < x; i++) {
                    for (j = 0; j < y; j++) {
                        printf("Enter the element %d, %d of the first matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix1[i][j]);
                    }
                }
                for (i = 0; i < w; i++) {
                    for (j = 0; j < z; j++) {
                        printf("Enter the element %d, %d of the second matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix2[i][j]);
                    }
                }
                printf("The first matrix is: \n");
                for (i = 0; i < x; i++) {
                    printf("[ ");
                    for (j = 0; j < y; j++) {
                        printf("%lf ", matrix1[i][j]);
                    }
                    printf("] \n");
                }
                printf("The second matrix is: \n");
                for (i = 0; i < w; i++) {
                    printf("[ ");
                    for (j = 0; j < z; j++) {
                        printf("%lf ", matrix2[i][j]);
                    }
                    printf("] \n");
                }
                matrix_multiplication(matrix1, x,  y, matrix2, w, z, matrix3);
                printf("The product of both matrices is: \n");
                for (i = 0; i < x; i++) {
                    printf("[ ");
                    for (j = 0; j < z; j++) {
                        printf("%lf ", matrix3[i][j]);
                    }
                    printf("] \n");
                }
            }
        }
    } else if (a == 6) {
        double matrix[100][100];
        int x, y, i, j;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            printf("Your matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            transpose(matrix, x, y);
            printf("Your matrix transpose is: \n");
            for (i = 0; i < y; i++) {
                printf("[ ");
                for (j = 0; j < x; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 7) {
        double matrix[100][100];
        int x, y, i, j;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            printf("Your matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            REF(matrix, x, y);
            printf("Your matrix in REF is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 8) {
        double matrix[100][100];
        int x, y, i, j;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            printf("Your matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            RREF(matrix, x, y);
            printf("Your matrix in RREF is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
        }
    } else if (a == 9) {
        double matrix[100][100];
        int x, y, i, j, r;
        printf("Enter the number of rows of the matrix: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the matrix: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            printf("Your matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            r = rank(matrix, x, y);
            printf("The rank of your matrix is: %d. \n", r);
        }
    } else if (a == 10) {
        double matrix1[100][100], matrix2[100][100];
        int x, y, i, j, rowEq;
        printf("Enter the number of rows of the two matrices: ");
        scanf("%d", &x);
        printf("Enter the number of columns of the two matrices: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 100)) {
            printf("The matrix is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the first matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix1[i][j]);
                }
            }
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the second matrix: ", i + 1, j + 1);
                    scanf("%lf", &matrix2[i][j]);
                }
            }
            printf("The first matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix1[i][j]);
                }
                printf("] \n");
            }
            printf("The second matrix is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix2[i][j]);
                }
                printf("] \n");
            }
            rowEq = row_equivalence(matrix1, matrix2, x, y);
            if (rowEq == 1) {
                printf("The matrices are row-equivalent: \n");
            } else {
                printf("The matrices are not row-equivalent: \n");
            }
        }
    } else if (a == 11) {
        double matrix[100][100], matrix2[100][100], vector[100];
        int x, y, z, i, j, k;
        printf("Enter the number of equations in the SLE: ");
        scanf("%d", &x);
        printf("Enter the number of variables in the SLE: ");
        scanf("%d", &y);
        if ((x > 100) || (y > 99)) {
            printf("The SLE is too large. \n");
        } else {
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    printf("Enter the element %d, %d of the matrix of coefficients(A): ", i + 1, j + 1);
                    scanf("%lf", &matrix[i][j]);
                }
            }
            for (i = 0; i < x; i++) {
                printf("Enter the element %d of the vector of constants(b): ",i + 1);
                scanf("%lf", &vector[i]);
            }
            printf("The matrix of coefficients is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y; j++) {
                    printf("%lf ", matrix[i][j]);
                }
                printf("] \n");
            }
            printf("The vector of constants is: \n");
            for (i = 0; i < x; i++) {
                printf("[ %lf ] \n", vector[i]);
            }
            for (i = 0; i < x; i++) {
                for (j = 0; j < y; j++) {
                    matrix2[i][j] = matrix[i][j];
                }
            }
            for (i = 0; i < x; i++) {
                matrix2[i][y] = vector[i];
            }
            printf("The augmented matrix of the SLE is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y + 1; j++) {
                    printf("%lf ", matrix2[i][j]);
                }
                printf("] \n");
            }
            z = SLE(matrix2, x, y + 1);
            printf("The augmented matrix of the SLE in RREF is: \n");
            for (i = 0; i < x; i++) {
                printf("[ ");
                for (j = 0; j < y + 1; j++) {
                    printf("%lf ", matrix2[i][j]);
                }
                printf("] \n");
            }
            if (z == 0) {
                printf("The SLE is inconsistent. \n");
            } else {
                printf("The SLE is consistent. \n");
                printf("The solution is(x): \n");
                for (i = 0; i < x; i++) {
                    for (j = 0; j < y; j++) {
                        if (matrix2[i][j] == 1) {
                            printf("X%d = %lf", j + 1, matrix2[i][y]);
                            for (k = j + 1; k < y; k++) {
                                if (matrix2[i][k] > 0) {
                                    printf(" - (%lf x X%d)", matrix2[i][k], k + 1);
                                } else if (matrix2[i][k] < 0) {
                                    printf(" + (%lf x X%d)", -matrix2[i][k], k + 1);
                                }
                            }
                            break;
                        }
                    }
                    printf(".\n");
                }
                for (i = 0; i < x; i++) {
                    if (z == 1) {
                        for (j = 0; j < y; j++) {
                            if (matrix2[i][j] == 1) {
                                for (k = j + 1; k < y; k++) {
                                    if (matrix2[i][k] != 0) {
                                        z = 0;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
                if (z == 1) {
                    printf("The SLE has a unique solution. \n");
                } else {
                    printf("The SLE has an infinite solution set. \n");
                }
            }
        }
    } else if (a == 12) {
        double matrix[100][100];
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                minors(matrix, n);
                printf("The matrix of minors of your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
            }
        }
    } else if (a == 13) {
        double matrix[100][100];
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                cofactors(matrix, n);
                printf("The matrix of cofactors of your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
            }
        }
    } else if (a == 14) {
        double matrix[100][100];
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                adjoint(matrix, n);
                printf("The adjoint of your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
            }
        }
    } else if (a == 15) {
        double matrix[100][100], det;
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                det = determinant(matrix, n);
                printf("The determinant of your matrix is: %lf. \n", det);
            }
        }
    } else if (a == 16) {
        double matrix1[100][100], matrix2[100][100], det;
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix1[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix1[i][j]);
                    }
                    printf("] \n");
                }
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        matrix2[i][j] = matrix1[i][j];
                    }
                }
                det = determinant(matrix1, n);
                adjoint(matrix2, n);
                if (det != 0) {
                    printf("The inverse of your matrix is: ");
                    for (i = 0; i < n; i++) {
                        printf("\n[ ");
                        for (j = 0; j < n; j++) {
                            printf("%lf ", matrix2[i][j]);
                        }
                        printf("] ");
                    }
                    printf("X %lf\n", (1 / det));
                } else {
                    printf("Your matrix is not invertible. \n");
                }
            }
        }
    } else if (a == 17) {
        double matrix[100][100], lower[100][100], upper[100][100];
        int n, i, j;
        printf("Enter the number of rows and columns of the matrix: ");
        scanf("%d", &n);
        if (n > 100) {
            printf("The matrix is too large. \n");
        } else {
            if (n < 2) {
                printf("The number of rows and columns must be greater than or equal to 2. \n");
            } else {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("Enter the element %d, %d of the matrix: ", i + 1, j + 1);
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("Your matrix is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", matrix[i][j]);
                    }
                    printf("] \n");
                }
                LU_decomposition(matrix, n, lower, upper);
                printf("The lower triangular matrix of the decomposition is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", lower[i][j]);
                    }
                    printf("] \n");
                }
                printf("The upper triangular matrix of the decomposition is: \n");
                for (i = 0; i < n; i++) {
                    printf("[ ");
                    for (j = 0; j < n; j++) {
                        printf("%lf ", upper[i][j]);
                    }
                    printf("] \n");
                }
            }
        }
    }
    printf("\nIf you want to use this program again enter 1, else enter any other number: ");
    scanf("%d", &b);
    printf("\n");
    if (b == 1) {
        matrix_calculator();
    } else {
        return;
    }
    return;
}
void double_swap(double *a, double *b) {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}
void row_swap(double a[100][100], int row_1, int row_2) {
    int i;
    for (i = 0; i < 100; i++) {
        double_swap(&a[row_1][i], &a[row_2][i]);
    }
    return;
}
void matrix_addition(double a[100][100], double b[100][100], double c[100][100], int x, int y) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return;
}
void scalar_multiplication(double a[100][100], int x, int y, double scalar) {
    int i, j;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            a[i][j] *= scalar;
        }
    }
    return;
}
void vector_multiplication(double a[100][100], int x, int y, const double b[100], double c[100]) {
    int i, j;
    double sum;
    for (i = 0; i < x; i++) {
        sum = 0;
        for (j = 0; j < y; j++) {
            sum += a[i][j] * b[j];
        }
        c[i] = sum;
    }
    return;
}
void matrix_multiplication(double a[100][100], int x, int y, double b[100][100], int w, int z, double c[100][100]) {
    int i, j, k;
    double sum;
    for (i = 0; i < x; i++) {
        for (j = 0; j < z; j++) {
            sum = 0;
            for (k = 0; k < y; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
    return;
}
void transpose(double a[100][100], int x, int y) {
    int i, j, swapped[x][y];
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            swapped[i][j] = 0;
        }
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if ((i != j) && (swapped[i][j] == 0)) {
                double_swap(&a[i][j], &a[j][i]);
                swapped[j][i] = 1;
            }
        }
    }
    return;
}
void REF(double a[100][100], int x, int y) {
    double w, z;
    int i, j, k, l;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (a[i][j] == 0) {
                for (l = i + 1; l < x; l++) {
                    if (a[l][j] != 0) {
                        row_swap(a, i, l);
                        break;
                    }
                }
            }
            if (a[i][j] != 0) {
                z = a[i][j];
                for (k = j; k < y; k++) {
                    a[i][k] /= z;
                }
                for (l = i + 1; l < x; l++) {
                    w = a[l][j];
                    for (k = j; k < y; k++) {
                        a[l][k] -= w * a[i][k];
                    }
                }
                break;
            }
        }
    }
    return;
}
void RREF(double a[100][100], int x, int y) {
    double w, z;
    int i, j, k, l;
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            if (a[i][j] == 0) {
                for (l = i + 1; l < x; l++) {
                    if (a[l][j] != 0) {
                        row_swap(a, i, l);
                        break;
                    }
                }
            }
            if (a[i][j] != 0) {
                z = a[i][j];
                for (k = j; k < y; k++) {
                    a[i][k] /= z;
                }
                for (l = 0; l < x; l++) {
                    if (l != i) {
                        w = a[l][j];
                        for (k = j; k < y; k++) {
                            a[l][k] -= w * a[i][k];
                        }
                    }
                }
                break;
            }
        }
    }
    return;
}
int rank(double a[100][100], int x, int y) {
    int i, j, z = 0, rank = 0;
    RREF(a, x, y);
    for (i = 0; i < x; i++) {
        for (j = z; j < y; j++) {
            if (a[i][j] == 1) {
                rank++;
                z = j + 1;
                break;
            }
        }
    }
    return rank;
}
int row_equivalence(double a[100][100], double b[100][100], int x, int y) {
    int i, j, t = 1;
    RREF(a, x, y);
    RREF(b, x, y);
    for (i = 0; i < x; i++) {
        if (t == 1) {
            for (j = 0; j < y; j++) {
                if (a[i][j] != b[i][j]) {
                    t = 0;
                    break;
                }
            }
        } else {
            break;
        }
    }
    return t;
}
int SLE(double a[100][100], int x, int y) {
    int i, j, k, z, consistency = 1;
    RREF(a, x, y);
    for (i = 0; i < x; i++) {
        z = 0;
        for (j = 0; j < y - 1; j++) {
            if (a[i][j] != 0) {
                z = 1;
            }
        }
        if ((z == 0) && (a[i][y - 1] = 1)) {
            consistency = 0;
            break;
        }
    }
    return consistency;
}
void minors(double a[100][100], int n) {
    double b[100][100], c[100][100];
    int i, j, k, l, m, o;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m = 0;
            for (k = 0; k < n; k++) {
                o = 0;
                if (k != i) {
                    for (l = 0; l < n; l++) {
                        if (l != j) {
                            c[m][o] = a[k][l];
                            o++;
                        }
                    }
                    m++;
                }
            }
            b[i][j] = determinant(c, (n - 1));
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }
    return;
}
void cofactors(double a[100][100], int n) {
    int i, j;
    minors(a, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i + j) % 2 == 1) {
                a[i][j] *= -1.0;
            }
        }
    }
    return;
}
void adjoint(double a[100][100], int n) {
    cofactors(a, n);
    transpose(a, n, n);
    return;
}
double determinant(double a[100][100], int n) {
    if (n == 2) {
        return ((a[0][0] * a[1][1]) - (a[0][1] * a[1][0]));
    } else {
        double b[100][100], c[100][100], det = 1;
        int i;
        LU_decomposition(a, n, b, c);
        for (i = 0; i < n; i++) {
            det *= c[i][i];
        }
        return det;
    }
}
void LU_decomposition(double a[100][100], int n, double L[100][100], double U[100][100]) {
    double sum, divisor;
    int i, j, k, x;
    x = 0;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= x; j--) {
            if (i == j) {
                L[i][j] = 1;
            } else {
                L[i][j] = 0;
            }
        }
        x++;
    }
    x = n - 1;
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < x; j++) {
            U[i][j] = 0;
        }
        x--;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j >= i) {
                sum = 0;
                for (k = 0; k < n; k++) {
                    if (k != i) {
                        sum += L[i][k] * U[k][j];
                    }
                }
                U[i][j] = a[i][j] - sum;
            } else {
                sum = 0;
                for (k = 0; k < n; k++) {
                    if (k != j) {
                        sum += L[i][k] * U[k][j];
                    } else {
                        divisor = U[k][j];
                    }
                }
                L[i][j] = (a[i][j] - sum) / divisor;
            }
        }
    }
    return;
}
