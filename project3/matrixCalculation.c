#ifndef __MATRIX_H__
#include "matrix.h"
#endif

Matrix *addMatrix(Matrix *matrixA, Matrix *matrixB)
{
    if (matrixA == NULL || matrixB == NULL)
    {
        printf("Error: The matrix to be added is NULL. (addMatrix)\n");
        return NULL;
    }
    else
    {
        if (matrixA->matrixData == NULL || matrixB->matrixData == NULL)
        {
            printf("Error: The data of matrix to be added is NULL. (addMatrix)\n");
            return NULL;
        }
        else
        {
            if (matrixA->row != matrixB->row || matrixB->col != matrixB->col)
            {
                printf("Error: The two matrices to be added have different sizes. (addMatrix)\n");
                return NULL;
            }
            else
            {
                Matrix *matrixC = createMatrix(matrixA->row, matrixA->col);
                for (int i = 0; i < sizeMatrix(matrixA); i++)
                {
                    matrixC->matrixData[i] =
                        matrixA->matrixData[i] + matrixB->matrixData[i];
                }
                return matrixC;
            }
        }
    }
}

Matrix *subtractMatrix(Matrix *matrixA, Matrix *matrixB)
{
    if (matrixA == NULL || matrixB == NULL)
    {
        printf("Error: The matrix to be subtracted is NULL. (subtractMatrix)\n");
        return NULL;
    }
    else
    {
        if (matrixA->matrixData == NULL || matrixB->matrixData == NULL)
        {
            printf("Error: The data of matrix to be subtracted is NULL. (subtractMatrix)\n");
            return NULL;
        }
        else
        {
            if (matrixA->row != matrixB->row || matrixB->col != matrixB->col)
            {
                printf("Error: The two matrices to be subtracted have different sizes. (subtractMatrix)\n");
                return NULL;
            }
            else
            {
                Matrix *matrixC = createMatrix(matrixA->row, matrixA->col);
                for (int i = 0; i < sizeMatrix(matrixA); i++)
                {
                    matrixC->matrixData[i] =
                        matrixA->matrixData[i] - matrixB->matrixData[i];
                }
                return matrixC;
            }
        }
    }
}

Matrix *multiplyMatrix(Matrix *matrixA, Matrix *matrixB)
{
    if (matrixA == NULL || matrixB == NULL)
    {
        printf("Error: The matrix to be multiplied is NULL. (multiplyMatrix)\n");
        return NULL;
    }
    else
    {
        if (matrixA->matrixData == NULL || matrixB->matrixData == NULL)
        {
            printf("Error: The data of matrix to be multiplied is NULL. (multiplyMatrix)\n");
            return NULL;
        }
        else
        {
            if (matrixA->col != matrixB->row)
            {
                printf("Error: The sizes of two matrices to be multiplied do not match. (multiplyMatrix)\n");
                return NULL;
            }
            else
            {
                Matrix *matrixC = createMatrix(matrixA->row, matrixB->col);
                for (int i = 0; i < matrixA->row; i++)
                {
                    for (int j = 0; j < matrixB->col; j++)
                    {
                        for (int k = 0; k < matrixA->col; k++)
                        {
                            matrixC->matrixData[i * matrixC->col + j] +=
                                matrixA->matrixData[i * matrixA->col + k] * matrixB->matrixData[k * matrixB->col + j];
                        }
                    }
                }
                return matrixC;
            }
        }
    }
}

Matrix *powerMatrix(Matrix *matrix, int power)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be powered is NULL. (powerMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be powered is NULL. (powerMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *ans = onesMatrix(matrix->row, matrix->col);
        if (matrix->row == matrix->col)
        {
            for (int i = 0; i < power - 1; i++)
            {
                ans = multiplyMatrix(ans, matrix);
            }
        }
        return ans;
    }
}

Matrix *addScalarToMatrix(Matrix *matrix, float scalar)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be added is NULL. (addScalarToMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be added is NULL. (addScalarToMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *ans = createMatrix(matrix->row, matrix->col);
        copyMatrix(matrix, ans);
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                ans->matrixData[i * matrix->col + j] += scalar;
            }
        }
        return ans;
    }
}

Matrix *subtractScalarFromMatrix(Matrix *matrix, float scalar)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be subtracted is NULL. (subtractScalarFromMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be subtracted is NULL. (subtractScalarFromMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *ans = createMatrix(matrix->row, matrix->col);
        copyMatrix(matrix, ans);
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                ans->matrixData[i * matrix->col + j] -= scalar;
            }
        }
        return ans;
    }
}

Matrix *multiplyMatrixWithScalar(Matrix *matrix, float scalar)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be multiplied is NULL. (multiplyMatrixWithScalar)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be multiplied is NULL. (multiplyMatrixWithScalar)\n");
        return NULL;
    }
    else
    {
        Matrix *ans = createMatrix(matrix->row, matrix->col);
        copyMatrix(matrix, ans);
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                ans->matrixData[i * matrix->col + j] *= scalar;
            }
        }
        return ans;
    }
}