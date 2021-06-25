#ifndef MATLIB_H
#define MATLIB_H

#include <vector>
#include <exception>
#include "MyExceptions.h"

using namespace std;

class Matrix
{
private:
    int row, col;
    vector<vector<float>> data;
    void initialize_data(int row, int col);
public:
    Matrix(const int desRow, const int desCol)
        :row(desRow), col(desCol){
            
        };
    
    Matrix operator * (Matrix& anotherMat);
    Matrix transpose();
    Matrix operator = (const Matrix& anotherMat);
    int getRow(){return row;}
    int getCol(){return col;}
};

// reserve vector capacity to increase performance
void Matrix::initialize_data(int row, int col)
{
    // test for correct dimensions
    try
    {
        if(row < 1 | col < 1)
        {
            throw shapeEx;
        }

        // reserve data size ahead of time
        vector<float> colCapacity;
        colCapacity.reserve(col);
        data.reserve(row);

        for(int idx=0; idx < row;idx++)
        {
            data.push_back(colCapacity);
        }
    }
    catch(xception& e)
    {
        cerr << e.what() << '\n';
    }
    
    
}

// Overload copy constructor
Matrix Matrix::operator=(const Matrix& copySource)
{
    data = copySource.data;
    row = copySource.row;
    col = copySource.col;

    return *this;
}

Matrix Matrix::transpose()
{
    vector<vector<float>> updatedData(row, vector<float>(col, 0));
    for(int idx=0; idx < row; idx++)
    {
        for(int jdx=0; jdx < col; jdx++)
        {
            updatedData[jdx][idx] = data[idx][jdx];
        }
    }
    this->data = updatedData;

    return *this;
}

Matrix Matrix::operator *(Matrix& anotherMat)
{
    // test for dimension mismatch
    try{
        if(this->col != anotherMat.row)
        {
            throw dimEx;
        }

        if

        for(int idx=0; idx < row;idx++)
        {
            for(int jdx=0;jdx < col; jdx)
            {

            }
        }

    }
    catch(exception& e)
    {
        cerr << e.what() << "\n";
    }
    
}



#endif