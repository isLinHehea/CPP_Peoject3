#ifndef __MATRIX_H__
#include "matrix.h"
#endif

int sizeMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix is NULL. (sizeMatrix)\n");
        return ERROR;
    }
    else
        return matrix->row * matrix->col;
}

int printMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be printed is NULL. (printMatrix)\n");
        return ERROR;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be printed is NULL. (printMatrix)\n");
        return ERROR;
    }
    else
    {
        printf("Matrix\n");
        if (matrix->row == 1 && matrix->col == 1)
        {
            printf("【 ");
            printf("%-12f  ", matrix->matrixData[0]);
            printf("】");
        }
        else if (matrix->row == 1)
        {
            printf("【 ");
            for (int i = 0; i < sizeMatrix(matrix); i++)
                printf("%-12f  ", matrix->matrixData[i]);
            printf("】");
        }
        else
        {
            for (int i = 0; i < sizeMatrix(matrix); i++)
            {
                if (i == 0)
                    printf("┏ ");
                else if (i == sizeMatrix(matrix) - matrix->col)
                    printf("┗ ");
                else if (i % matrix->col == 0)
                    printf("┃ ");

                printf("%-12f  ", matrix->matrixData[i]);
                if (i == matrix->col - 1)
                    printf(" ┓");
                else if (i == sizeMatrix(matrix) - 1)
                    printf(" ┛");
                else if ((i + 1) % matrix->col == 0)
                    printf(" ┃");
                if ((i + 1) % matrix->col == 0)
                    printf("\n");
            }
        }
        return SUCCEED;
    }
}

Matrix *createMatrix(int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        printf("Error: The row and col of the initialized matrix should be positive. (createMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
        matrix->row = row;
        matrix->col = col;
        matrix->matrixData = (float *)malloc(sizeof(float) * row * col);
        // 初始化为0
        memset(matrix->matrixData, 0, sizeof(float) * row * col);
        return matrix;
    }
}

int valueMatrix(Matrix *matrix, float *valuedMtrixData)
{
    if (matrix == NULL)
    {

        printf("Error: The matrix to be valued is NULL. (valueMatrix)\n");
        return ERROR;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be valued is NULL. (valueMatrix)\n");
        return ERROR;
    }
    else if (valuedMtrixData == NULL)
    {
        printf("Error: The data to be assigned is NULL. (valueMatrix)\n");
        return ERROR;
    }
    else
        memcpy(matrix->matrixData, valuedMtrixData, sizeof(float) * matrix->row * matrix->col);
    return SUCCEED;
}

int deleteMatrix(Matrix **matrix)
{
    if (matrix == NULL)
    {
        printf("Error:The pointer of Matrix pointer matrix is NULL.(deleteMatrix)\n");
        return ERROR;
    }
    else if ((*matrix) == NULL)
    {
        printf("Error: The Matrix is already NULL.(deleteMatrix)\n");
        return ERROR;
    }
    else
    {
        free((*matrix)->matrixData);
        (*matrix)->matrixData = NULL;
        free(*matrix);
        *matrix = NULL;
        printf("Matrix memory released successfully!\n");
        return SUCCEED;
    }
}

int copyMatrix(Matrix *matrixBefore, Matrix *matrixLater)
{
    if (matrixBefore == NULL)
    {
        printf("Error: The matrix for assignment is NUll(copyMatrix)\n");
        return ERROR;
    }
    else if (matrixLater == NULL)
    {
        printf("Error: The matrix to be assigned is NUll(copyMatrix)\n");
        return ERROR;
    }
    else if (matrixBefore->matrixData == NULL)
    {
        printf("Error: The data of matrix for assignment is NUll(copyMatrix)\n");
        return ERROR;
    }
    else if (matrixLater->matrixData == NULL)
    {
        printf("Error: The data of matrix to be assigned is NUll(copyMatrix)\n");
        return ERROR;
    }
    else
    {
        matrixLater->row = matrixBefore->row;
        matrixLater->col = matrixBefore->col;
        memcpy(matrixLater->matrixData, matrixBefore->matrixData, sizeMatrix(matrixBefore) * sizeof(float));
        return SUCCEED;
    }
}

float findMinValue(Matrix *matrix)
{
    if (matrix == NULL)
    {

        printf("Error: The matrix is NULL. (findMinValue)\n");
        return ERROR;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix is NULL. (findMinValue)\n");
        return ERROR;
    }
    else
    {
        float minimum = FLT_MAX;
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                float tempFlt = matrix->matrixData[i * matrix->col + j];
                minimum = (tempFlt < minimum ? tempFlt : minimum);
            }
        }
        return minimum;
    }
}

float findMaxValue(Matrix *matrix)
{

    if (matrix == NULL)
    {

        printf("Error: The matrix is NULL. (findMaxValue)\n");
        return ERROR;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix is NULL. (findMaxValue)\n");
        return ERROR;
    }
    else
    {
        float maximum = FLT_MIN;
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                float tempFlt = matrix->matrixData[i * matrix->col + j];
                maximum = (tempFlt > maximum ? tempFlt : maximum);
            }
        }
        return maximum;
    }
}

Matrix *transMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be transposed is NULL. (transMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be transposed is NULL. (transMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *matrixTrans = createMatrix(matrix->col, matrix->row);
        for (int i = 0; i < matrix->row; i++)
        {
            for (int j = 0; j < matrix->col; j++)
            {
                matrixTrans->matrixData[j * matrixTrans->col + i] = matrix->matrixData[i * matrix->col + j];
            }
        }
        return matrixTrans;
    }
}

Matrix *zerosMatrix(int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        printf("Error: The row and col of the initialized matrix should be positive. (zerosMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
        matrix->row = row;
        matrix->col = col;
        matrix->matrixData = (float *)malloc(sizeof(float) * row * col);
        // 初始化为0
        memset(matrix->matrixData, 0, sizeof(float) * row * col);
        return matrix;
    }
}

Matrix *onesMatrix(int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        printf("Error: The row and col of the initialized matrix should be positive. (onesMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
        matrix->row = row;
        matrix->col = col;
        matrix->matrixData = (float *)malloc(sizeof(float) * row * col);
        // 初始化为1
        for (int i = 0; i < sizeMatrix(matrix); i++)
            matrix->matrixData[i] = 1.;
        return matrix;
    }
}

Matrix *zerosLikeMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be created the same size is NULL. (zerosLikeMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be created the same size is NULL. (zerosLikeMatrix)\n");
        return NULL;
    }
    else
        return zerosMatrix(matrix->row, matrix->col);
}

Matrix *onesLikeMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be created the same size is NULL. (onesLikeMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be created the same size is NULL. (onesLikeMatrix)\n");
        return NULL;
    }
    else
        return onesMatrix(matrix->row, matrix->col);
}

Matrix *identityMatrix(int dim)
{
    if (dim <= 0)
    {
        printf("Error: The dimension of matrix to be created should be positive. (identityMatrix)\n");
        return NULL;
    }
    else
    {
        Matrix *matrix = zerosMatrix(dim, dim);
        for (int i = 0; i < dim; i++)
        {
            matrix->matrixData[i * dim + i] = 1.;
        }
        return matrix;
    }
}

Matrix *identityLikeMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be created the same size is NULL. (identityLikeMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be created the same size is NULL. (identityLikeMatrix)\n");
        return NULL;
    }
    else
    {
        if (matrix->row != matrix->col)
        {
            printf("Error: The matrix to be created of the same size should be square matrix. (identityLikeMatrix)\n");
            return NULL;
        }
        else
        {
            return identityMatrix(matrix->col);
        }
    }
}

Matrix *reshapeMatrix(Matrix *matrix, int row, int col)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be reshaped is NULL. (reshapeMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be reshaped is NULL. (reshapeMatrix)\n");
        return NULL;
    }
    else
    {
        if (col <= 0 || row <= 0)
        {
            printf("Error: The row and col of the reshaped matrix should be positive. (reshapeMatrix)\n");
            return NULL;
        }
        else if (sizeMatrix(matrix) != row * col)
        {
            printf("Error: The shape and the size of matrice to be reshaped do not match. (reshapeMatrix)\n");
            return NULL;
        }
        else
        {
            Matrix *ans = createMatrix(row, col);
            ans->matrixData = matrix->matrixData;
            return ans;
        }
    }
}

Matrix *flattenMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be flattened is NULL. (flattenMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be flattened is NULL. (flattenMatrix)\n");
        return NULL;
    }
    else
    {
        return reshapeMatrix(matrix, sizeMatrix(matrix), 1);
    }
}

Matrix *subMatrix(Matrix *matrix, int rowStart, int colStart, int rowLength, int colLength)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be gotten submatrix is NULL. (subMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be gotten submatrix is NULL. (subMatrix)\n");
        return NULL;
    }
    else
    {
        if (colStart < 0 || rowStart < 0)
        {
            printf("Error: Submatrix start row and column should not be negative. (subMatrix)\n");
            return NULL;
        }
        else if (colLength <= 0 || rowLength <= 0)
        {
            printf("Error: The rowLength and colLength of submatrix should not be negative. (subMatrix)\n");
            return NULL;
        }
        else if (matrix->col < colStart + colLength || matrix->row < rowStart + colLength)
        {
            printf("Error: Submatrix start row and column out of range. (subMatrix)\n");
            return NULL;
        }
        else
        {
            Matrix *ans = createMatrix(rowLength, colLength);
            int dropLength = rowStart * matrix->col;
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    ans->matrixData[i * colLength + j] = matrix->matrixData[dropLength + i * matrix->col + j + colStart];
                }
            }
            return ans;
        }
    }
}

float detMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be calculated determinant is NULL. (detMatrix)\n");
        return ERROR;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be calculated determinant is NULL. (detMatrix)\n");
        return ERROR;
    }
    else
    {
        if (matrix->row != matrix->col)
        {
            printf("Error: The matrix to be calculated determinant should be square matrix. (detMatrix)\n");
            return ERROR;
        }
        else
        {
            double result = 0;
            if (matrix->col == 1)
                result = matrix->matrixData[0];
            else if (matrix->col == 2)
                result = matrix->matrixData[0] * matrix->matrixData[3] - matrix->matrixData[1] * matrix->matrixData[2];
            else
            {
                for (int i = 0; i < matrix->col; i++)
                {
                    if (matrix->matrixData[i] == 0)
                        result += 0;
                    else
                    {
                        if ((i + 2) % 2 == 0)
                            result += matrix->matrixData[i] * detMatrix(matrixForDet(matrix, 0, i));
                        else
                            result += matrix->matrixData[i] * (-1) * detMatrix(matrixForDet(matrix, 0, i));
                    }
                }
            }
            return result;
        }
    }
}

Matrix *matrixForDet(Matrix *matrix, int row, int col)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be calculated determinant is NULL. (matrixForDet)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be calculated determinant is NULL. (matrixForDet)\n");
        return NULL;
    }
    else
    {
        if (matrix->col < col || matrix->row < row)
        {
            printf("Error: The col or row is out of range. (matrixForDet)\n");
            return NULL;
        }
        else
        {
            Matrix *ans = createMatrix(matrix->row - 1, matrix->col - 1);
            int indexAns = 0;
            for (int i = 0; i < matrix->row; i++)
            {
                if (i == row)
                    continue;
                for (int j = 0; j < matrix->col; j++)
                {
                    if (j == col)
                        continue;
                    else
                        ans->matrixData[indexAns++] = matrix->matrixData[i * matrix->col + j];
                }
            }
            return ans;
            // for (int i = 1; i < matrix->row; i++)
            // {
            //     for (int j = 0; j < matrix->col; j++)
            //     {
            //         if (j < col)
            //             ans->matrixData[(i - 1) * ans->col + j] = matrix->matrixData[i * matrix->col + j];
            //         else if (j > col)
            //             ans->matrixData[(i - 1) * ans->col + j - 1] = matrix->matrixData[i * matrix->col + j];
            //         else
            //             continue;
            //     }
            // }
            // return ans;
        }
    }
}

Matrix *invMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        printf("Error: The matrix to be calculated inverse matrix is NULL. (invMatrix)\n");
        return NULL;
    }
    else if (matrix->matrixData == NULL)
    {
        printf("Error: The data of matrix to be calculated inverse matrix is NULL. (invMatrix)\n");
        return NULL;
    }
    else
    {
        if (matrix->row != matrix->col)
        {
            printf("Error: The matrix to be calculated inverse matrix should be square matrix. (invMatrix)\n");
            return NULL;
        }
        else
        {
            if (detMatrix(matrix) == 0)
            {
                printf("Error: The data of matrix to be calculated inverse matrix is noninvertible matrix. (invMatrix)\n");
                return NULL;
            }
            else
            {
                double result = 0;
                if (matrix->col == 1)
                {
                    float f = matrix->matrixData[0];
                    Matrix *ans = multiplyMatrixWithScalar(matrix, 1. / f);
                    return ans;
                }
                else
                {
                    Matrix *ans = zerosLikeMatrix(matrix);
                    for (int i = 0; i < ans->row; i++)
                    {
                        for (int j = 0; j < ans->col; j++)
                        {
                            if ((i + j + 2) % 2 == 0)
                                ans->matrixData[i * ans->col + j] = detMatrix(matrixForDet(matrix, i, j));
                            else
                            {
                                float f = detMatrix(matrixForDet(matrix, i, j));
                                if (f != 0.)
                                    ans->matrixData[i * ans->col + j] = -f;
                                else
                                    ans->matrixData[i * ans->col + j] = f;
                            }
                        }
                    }
                    return multiplyMatrixWithScalar(transMatrix(ans), 1. / detMatrix(matrix));
                }
            }
        }
    }
}