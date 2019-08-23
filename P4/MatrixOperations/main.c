#include <stdio.h>

/*
 * Author: Angel Odiel Treviño Villanueva
 * Matricula: A01336559
 * Fecha: 22/08/2019
 *
 * A program that reads two 2x2 matrix and does Addition,
 *      Substraction and Multiplication with them
 * */

//----------------------------------------------------------
void FillinMatrix(
        //Method that receives a Matrix and fills it with
        //      user input

        //Matrix in C are passed as reference and not as a
        //      value, that's why the data can be used
        //      outside of the method
        int intMatrix[2][2]
        ) {
    for(int intCountX = 0; intCountX < 2; intCountX++){
        for(int intCountY = 0; intCountY < 2; intCountY++) {
            scanf("%d", &intMatrix[intCountX][intCountY]);
        }
    }
}

//----------------------------------------------------------
void PrintMatrix(
        //Method that prints a Matrix
        int intMatrix[2][2]
        ) {
    for(int intCountX = 0; intCountX < 2; intCountX++){
        for(int intCountY = 0; intCountY < 2; intCountY++) {
            printf("%d ", intMatrix[intCountX][intCountY]);
        }
        printf("\n");
    }
}

//----------------------------------------------------------
void SumMatrix(
        //Matrix that sums up two matrices and prints the
        //      result

        int intFirstMatrix[2][2],
        int intSecondMatrix[2][2]
        ) {

    int intResultMatrix[2][2];

    for(int intCountX = 0; intCountX < 2; intCountX++) {
        for (int intCountY = 0; intCountY < 2; intCountY++) {
            intResultMatrix[intCountX][intCountY] =
                    intFirstMatrix[intCountX][intCountY] +
                    intSecondMatrix[intCountX][intCountY];
        }
    }

    PrintMatrix(intResultMatrix);
}

//----------------------------------------------------------
void SubtractMatrix(
        //Matrix that subtracts two matrices and prints the
        //      result
        int intFirstMatrix[2][2],
        int intSecondMatrix[2][2]
        ) {

    int intResultMatrix[2][2];

    for(int intCountX = 0; intCountX < 2; intCountX++) {
        for (int intCountY = 0; intCountY < 2; intCountY++) {
            intResultMatrix[intCountX][intCountY] =
                    intFirstMatrix[intCountX][intCountY] -
                    intSecondMatrix[intCountX][intCountY];
        }
    }

    PrintMatrix(intResultMatrix);
}

//----------------------------------------------------------
void MultMatrix(
        //Method that does a multiplication of two matrices
        //      and prints the result
        int intFirstMatrix[2][2],
        int intSecondFirstMatrix[2][2]
        ) {

    int intResultMatrix[2][2];

    for(int intCountX = 0; intCountX < 2; intCountX++) {
        for(int intCountY = 0; intCountY < 2; intCountY++) {
            intResultMatrix[intCountX][intCountY] = 0;
            for (int intCountK = 0; intCountK < 2; intCountK++) {
                intResultMatrix[intCountX][intCountY] +=
                        intFirstMatrix[intCountX][intCountK] *
                        intSecondFirstMatrix[intCountK][intCountY];
            }
        }
    }

    PrintMatrix(intResultMatrix);

}

//----------------------------------------------------------
int main() {


    int intFirstMatrix[2][2];
    int intSecondMatrix[2][2];

    printf("Enter First Matrix\n");
    FillinMatrix(intFirstMatrix);
    printf("Enter Second Matrix\n");
    FillinMatrix(intSecondMatrix);

    printf("Sum of both matrices \n");
    SumMatrix(intFirstMatrix, intSecondMatrix);
    printf("Subtraction of both matrices \n");
    SubtractMatrix(intFirstMatrix, intSecondMatrix);
    printf("Multiplication of both matrices\n");
    MultMatrix(intFirstMatrix, intSecondMatrix);

    return 0;
}