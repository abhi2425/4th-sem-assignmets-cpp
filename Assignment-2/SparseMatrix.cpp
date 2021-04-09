#include <iostream>
#include <process.h>
using namespace std;

const int maxRowSize = 15, maxColumnSize = 15;
int matrix[maxRowSize][maxColumnSize], rowSize = 0, columnSize = 0;

void traverseMatrix(int arg[][maxColumnSize])
{
    cout << "Entered Matrix-:" << endl;
    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < columnSize; j++)
            cout << arg[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void inputMatrix(int arg[][maxColumnSize])
{
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < columnSize; j++)
            cin >> matrix[i][j];
    cout << endl;
}

bool checkForSparseness(int arg[][maxColumnSize])
{
    int zeros = 0;
    bool sparse = false;
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < columnSize; j++)
            if (arg[i][j] == 0)
                zeros++;

    sparse = zeros > (rowSize * columnSize) / 2 ? true : false;
    traverseMatrix(matrix);
    return sparse;
}

int countNonZeroValues(int arg[][maxColumnSize])
{
    int count = 0;
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < columnSize; j++)
            count = arg[i][j] > 0 ? count + 1 : count;
    return count;
}

void evaluateSparseMatrix(int arg[][maxColumnSize])
{
    int count = countNonZeroValues(matrix);
    int newMatrix[count][3], newRowSize = 0;

    cout << "Total Non-zero values in Entered Matrix-:" << count << endl;
    cout << endl;
    cout << "Evaluated Matrix-:" << endl;
    for (int i = 0; i < rowSize; i++)
        for (int j = 0; j < columnSize; j++)
            if (arg[i][j] > 0)
            {
                newMatrix[newRowSize][0] = i;
                newMatrix[newRowSize][1] = j;
                newMatrix[newRowSize][2] = arg[i][j];
                newRowSize++;
            }

    cout << "Dimensions of Evaluated Matrix-:" << newRowSize << " X " << 3 << endl;
    cout << endl;
    cout << "Row Column Value" << endl;
    for (int i = 0; i < newRowSize; i++)
    {
        cout << newMatrix[i][0] << "      "
             << newMatrix[i][1] << "      "
             << newMatrix[i][2] << "\n";
    }
}

int main()
{
    cout << endl;
    cout << "**************SPARSE MATRIX**************" << endl;
    cout << endl;
    cout << "Enter the Row Size of the matrix-:";
    cin >> rowSize;
    cout << "Enter the Column Size-:";
    cin >> columnSize;
    cout << "Enter " << rowSize * columnSize << " Elemets Of The Matrix-:" << endl;
    inputMatrix(matrix);

    bool sparse = checkForSparseness(matrix);
    while (!sparse)
    {
        cout << "Entered Matrix Is Not A Sparse Matrix" << endl;
        cout << "Please Enter The Elemets Again-:" << endl;
        inputMatrix(matrix);
        sparse = checkForSparseness(matrix);
    }
    if (sparse)
    {
        cout << "Entered Matrix Is A Sparse Matrix" << endl;
        evaluateSparseMatrix(matrix);
    }

    return 0;
}