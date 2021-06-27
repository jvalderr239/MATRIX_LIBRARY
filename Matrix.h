#ifndef MATLIB_H
#define MATLIB_H

#include <vector>
#include <exception>
#include "MyExceptions.h"

using namespace std;

/**
 * @brief Matrix object that has the multiplication property and transpose property
 * 
 */
template<typename T = float> 
class Matrix
{
private:
    int row, col;
    vector<vector<T>> data;
    void initialize_data(const int row, const int col);
public:
    Matrix<T>(const int desRow, const int desCol)
        :row(desRow), col(desCol){
            this->initialize_data(this->row, this->col);
        };
    Matrix<T>()
    {
        // start with a matrix capacity of 10
        this->initialize_data(10,10);
    };
    bool enter_data(const vector<T> rowData, const int rowNum);
    bool enter_data(const vector<vector<T>> newData);
    void setDim(const int row, const int col);
    Matrix<T> operator * (const Matrix& anotherMat);
    Matrix<T> transpose();
    Matrix<T> operator = (const Matrix& anotherMat);
    int getRow(){return row;}
    int getCol(){return col;}
};

template<typename T>
void Matrix<T>::setDim(const int row, const int col)
{
    this->row = row;
    this->col = col;
}
/**
 * @brief enter new matrix data by row number
 * 
 * @tparam T type of data
 * @param rowData vector of type T
 * @param rowNum row index to enter data
 * @return bool checks if data saved or not
 */
template<typename T>
bool Matrix<T>::enter_data(const vector<T> rowData, const int rowNum)
{
    
    bool valid_data = rowData.size() == this.col;
    
    // check if the column size of entered row matches the initialized 
    if(!valid_data)
    {
        cout << "Data entered is invalid size. Try again.";

        return valid_data;
    }
    this->data[rowNum] = rowData;
    
    return valid_data;
}

/**
 * @brief enter new matrix data
 * 
 * @tparam T type of data
 * @param newData 
 */
template<typename T>
bool Matrix<T>::enter_data(const vector<vector<T>> newData)
{
    bool col_data = newData.size() == this->col;
    bool row_data = newData.size() == this->row;
 
    // check if the column size of entered row matches the initialized 
    if(!row_data or !col_data)
    {
        cout << "Data entered is invalid size. Try again.";

        return valid_data;
    }
    this->data = newData;
    
    return valid_data;
}

/**
 * @brief reserve vector capacity to increase performance
 * this will also limit the size of the matrix 
 * throws exception for invalid dimension types
 * 
 * @param row number of rows in the matrix
 * @param col number of columns in the matrix
 */
template<typename T>
void Matrix<T>::initialize_data(const int row, const int col)
{
    // test for correct dimensions
    try
    {
        bool tooSmall = row < 1 or col < 1;
        bool tooBig = row > 15 or col | 15;

        if(tooSmall or tooBig)
        {
            throw shapeEx;
        }

        // reserve data size ahead of time
        vector<T> colCapacity;
        colCapacity.reserve(col);
        data.reserve(row);

        for(int idx=0; idx < row;idx++)
        {
            data.push_back(colCapacity);
        }
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    
}

/**
 * @brief method to overload copy operator
 * 
 * @param copySource Matrix to be copied
 * @return Matrix returns the copied object
 */
template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& copySource)
{
    this->data = copySource.data;
    this->row = copySource.row;
    this->col = copySource.col;

    return *this;
}

/**
 * @brief Method to transpose the current matrix, switches rows and columns
 * 
 * @return Matrix returns the object after transformation
 */
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    vector<vector<T>> updatedData(this.row, vector<T>(this.col, 0));
    for(int idx=0; idx < row; idx++)
    {
        for(int jdx=0; jdx < col; jdx++)
        {
            updatedData[jdx][idx] = this->data[idx][jdx];
        }
    }
    this->data = updatedData;

    return *this;
}

/**
 * @brief multiplication property for matrix
 * 
 * @param anotherMat matrix to multiply 
 * @return Matrix resultant matrix after multiplication
 */
template<typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T>& anotherMat)
{
    // test for dimension mismatch
    try{
        if(this->col != anotherMat.row)
        {
            throw dimEx;
        }
        // create resultant matrix
        Matrix<T> resMat(this->row, anotherMat.col);

        for(int idx=0; idx < row;idx++)
        {
            for(int jdx=0;jdx < col; jdx)
            {
                for(int element = 0; element < col; element++)
                {
                    resMat->data[idx][jdx] += this->data[idx][element] * anotherMat->data[element][jdx]; 
                }
            }
        }

    }
    catch(exception& e)
    {
        cerr << e.what() << "\n";
    }
    
}

#endif