#ifndef __MATRIX_H__
#include "matrix.h"
#endif

int main()
{
    Matrix *matrix1 = createMatrix(3, 2);
    // Matrix *matrix1;
    float valuedMtrixData1[] = {2, 2, 2, 2, 2, 2};
    valueMatrix(matrix1, valuedMtrixData1);
    printMatrix(matrix1);
    // deleteMatrix(&matrix1);
    // printMatrix(matrix1);
    // Matrix *matrix2 = createMatrix(2, 3);
    // Matrix *matrix2;
    // float valuedMtrixData2[] = {2, 2, 2, 2, 2, 2};
    // valueMatrix(matrix2, valuedMtrixData2);
    // printMatrix(matrix2);
    // Matrix *matrix3 = addMatrix(matrix1, matrix2);
    // printMatrix(matrix3);
    // Matrix *matrix4 = subtractMatrix(matrix1, matrix2);
    // printMatrix(matrix4);
    // Matrix *matrix5 = multiplyMatrix(matrix1, matrix2);
    // printMatrix(matrix5);
    // Matrix *matrix6 = powerMatrix(matrix1, 2);
    // printMatrix(matrix6);
    // Matrix *matrix1 = createMatrix(3, 3);
    // float valuedMtrixData1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // Matrix *matrix2 = addScalarToMatrix(matrix1, 2);
    // printMatrix(matrix2);
    // Matrix *matrix3 = subtractScalarFromMatrix(matrix1, 2);
    // printMatrix(matrix3);
    // Matrix *matrix4 = multiplyMatrixWithScalar(matrix1, 4);
    // printMatrix(matrix4);
    // Matrix *matrix1 = createMatrix(3, 3);
    // float valuedMtrixData1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // Matrix *matrix2 = transMatrix(matrix1);
    // printMatrix(matrix2);
    // Matrix *matrix1 = createMatrix(3, 3);
    // float valuedMtrixData1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // printf("%f\n", findMaxValue(matrix1));
    // printf("%f\n", findMinValue(matrix1));
    // Matrix *matrix1 = createMatrix(3, 4);
    // float valuedMtrixData1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // printMatrix(reshapeMatrix(matrix1, 4, 3));
    // printMatrix(flattenMatrix(matrix1));
    // Matrix *matrix1 = createMatrix(3, 4);
    // float valuedMtrixData1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // printMatrix(subMatrix(matrix1, 1, 2, 2, 2));
    // Matrix *matrix1 = createMatrix(3, 2);
    // float valuedMtrixData1[] = {1, 2, -3, 0, 1, 2, 0, 0, 1};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
    // printf("%f\n", detMatrix(matrix1));
    // printMatrix(invMatrix(matrix1));
    // Matrix *matrix1 = createMatrix(3, 2);
    // float valuedMtrixData1[] = {1, 2, -3, 0, 1, 2, 0, 0, 1};
    // valueMatrix(matrix1, valuedMtrixData1);
    // printMatrix(matrix1);
}
