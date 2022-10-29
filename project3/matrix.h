#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#ifndef __MATRIX_H__
#define __MATRIX_H__

#define ERROR -1
#define SUCCEED 0

// 定义矩阵结构
typedef struct
{
    int row, col;      //矩阵的行和列
    float *matrixData; //矩阵的值
} Matrix;

// 矩阵大小
int sizeMatrix(Matrix *matrix);

// print矩阵
int printMatrix(Matrix *matrix);

// 创建一个矩阵，初始化为0
Matrix *createMatrix(int row, int col);

// 矩阵赋值
int valueMatrix(Matrix *matrix, float *valuedMtrixData);

// 删除矩阵
int deleteMatrix(Matrix **matrix);

// 复制矩阵
int copyMatrix(Matrix *matrixBefore, Matrix *matrixLater);

// 矩阵相加
Matrix *addMatrix(Matrix *matrixA, Matrix *matrixB);

// 矩阵相减
Matrix *subtractMatrix(Matrix *matrixA, Matrix *matrixB);

// 矩阵相乘
Matrix *multiplyMatrix(Matrix *matrixA, Matrix *matrixB);

// 矩阵乘方
Matrix *powerMatrix(Matrix *matrix, int power);

// 矩阵和标量相加
Matrix *addScalarToMatrix(Matrix *matrix, float scalar);

// 矩阵和标量相减
Matrix *subtractScalarFromMatrix(Matrix *matrix, float scalar);

// 矩阵和标量相乘
Matrix *multiplyMatrixWithScalar(Matrix *matrix, float scalar);

// 找到矩阵中的最小值
float findMinValue(Matrix *matrix);

// 找到矩阵中的最大值
float findMaxValue(Matrix *matrix);

// 矩阵转置
Matrix *transMatrix(Matrix *matrix);

Matrix *zerosMatrix(int row, int col);

Matrix *onesMatrix(int row, int col);

Matrix *zerosLikeMatrix(Matrix *matrix);

Matrix *onesLikeMatrix(Matrix *matrix);

Matrix *identityMatrix(int dim);

Matrix *identityLikeMatrix(Matrix *matrix);

Matrix *reshapeMatrix(Matrix *matrix, int row, int col);

Matrix *flattenMatrix(Matrix *matrix);

Matrix *subMatrix(Matrix *matrix, int rowStart, int colStar, int rowLength, int colLength);

float detMatrix(Matrix *matrix);

Matrix *matrixForDet(Matrix *matrix, int row, int col);

Matrix *invMatrix(Matrix *matrix);
#endif
