#include <stdlib.h>
#include <stdio.h>

float **MultiplyMatrix(int lenght, float **matrix1, float **matrix2)
{

    //Allocates space for the answer to the matrix multiplications
    float **answer = (float **)calloc(lenght, sizeof(float *));
    for (int count = 0; count <= lenght - 1; count++)
    {
        answer[count] = new float[lenght];
    }

    //loops through each entrance and does the calculations
    for (int P = 0; P <= lenght - 1; P++)
    {
        for (int i = 0; i <= lenght - 1; i++)
        {
            for (int L = 0; L <= lenght - 1; L++)
            {
                answer[P][i] += matrix1[P][i] * matrix2[P][L];
            }
        }
    }
    return answer;
}

void printMatrix(float **matrix, int lenght)
{
    for (int i = 0; i <= lenght - 1; i++)
    {
        printf("\n");
        for (int L = 0; L <= lenght - 1; L++)
        {
            printf(" %f ,", matrix[i][L]);
        }
    }
}

int main()
{
    float **test = (float **)calloc(4, sizeof(float *));
    for (int count = 0; count <= 3; ++count)
    {
        test[count] = new float[4]; // these are our columns
    }

    float **test2 = (float **)calloc(4, sizeof(float *));
    for (int count = 0; count <= 3; ++count)
    {
        test2[count] = new float[4]; // these are our columns
    }

    for (int i = 0; i <= 3; i++)
    {
        for (int L = 0; L <= 3; L++)
        {
            test[i][L] = (float) L;
        }
    }
    for (int i = 0; i <= 3; i++)
    {
        for (int L = 0; L <= 3; L++)
        {
            test2[i][L] = (float) L;
        }
    }
    printMatrix(test,4);
    printMatrix(MultiplyMatrix(4, test, test2), 4);
}