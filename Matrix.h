#ifndef MATLIB_H
#define MATLIB_H

#include <vector>
#include <exception>
#include <iostream>
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
    void print_data();
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

    // Copy constructor
    Matrix<T>(const Matrix &M)
    {
        this->enter_data(M.data);
    }
    // Copy constructor
    Matrix<T>(const vector<vector<T>> newData) 
    {
        this->enter_data(newData);
    }

    void enter_data(const vector<T> rowData, const int rowNum);
    void enter_data(const vector<vector<T>> newData);
    bool check_data(const vector<T> rowData);
    bool check_data(const vector<vector<T>> newData);
    void set_dimensions(const int row, const int col);
    Matrix<T> operator*(const Matrix<T>& anotherMat);
    Matrix<T> transpose();
    void set_data(vector<vector<T>> newData);
    
    template<typename MatType> friend ostream& operator<<(ostream& output, const Matrix<MatType>& M);
    /**
     * @brief Get matrix data
     * 
     * @return int matrix data
     */
    vector<vector<T>> getData(){return (*this).data;}
    /**
     * @brief Get Row variable
     * 
     * @return int number of rows
     */
    int getRow(){return (*this).row;}

    /**
     * @brief Get the Col variable
     * 
     * @return int number of columns
     */
    int getCol(){return (*this).col;}
};


template<typename T>
void Matrix<T>::set_data(vector<vector<T>> newData)
{
    (*this).data = newData;
}
template<typename T>
void Matrix<T>::set_dimensions(const int row, const int col)
{
    this->initialize_data(row, col);
}

/**
 * @brief test to check valid size of row data
 * 
 * @tparam T data type
 * @param rowData vector to check
 * @return true if correct size
 * @return false if incorrect size>
*/
template<typename T>
bool Matrix<T>::check_data(const vector<T> rowData)
{
    bool valid_column = rowData.size() == (*this).getCol();

    if(valid_column)
    {
        return true;
    }

    throw shapeEx;
}

/**
 * @brief test to validate new vector of vectors
 * 
 * @tparam T data type
 * @param toCheck vector of vectors to check
 * @return true if valid size
 * @return false invalid size
 */
template<typename T>
bool Matrix<T>::check_data(const vector<vector<T>> toCheck)
{
    for(int idx=0; idx < toCheck.size();idx++)
    {
        (*this).check_data(toCheck[idx]);
        
    }
    return true;
}
/**
 * @brief enter new matrix data
 * 
 * @tparam T type of data
 * @param newData 
 */

template<typename T>
void Matrix<T>::enter_data(const vector<vector<T>> newData)
{
    if((*this).check_data(newData))
    {
        (*this).getData() = newData;
    }
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
        (*this).data.reserve(row);

        for(int idx=0; idx < row;idx++)
        {
            (*this).data.push_back(colCapacity);
        }
    }
    catch(exception& e)
    {
        cerr << e.what() << '\n';
    }
    
    
}


/**
 * @brief Method to transpose the current matrix, switches rows and columns
 * 
 * @return Matrix returns the object after transformation
 */
template<typename T>
Matrix<T> Matrix<T>::transpose()
{
    vector<vector<T>> updatedData((*this).getRow(), vector<T>((*this).getCol(), 0));
    for(int idx=0; idx < row; idx++)
    {
        for(int jdx=0; jdx < col; jdx++)
        {
            updatedData[jdx][idx] = data[idx][jdx];
        }
    }
    this->data = updatedData;

    cout << *this << endl;
    return *this;
}

/**
 * @brief multiplication property for matrix
 * 
 * @param anotherMat matrix to multiply 
 * @return Matrix resultant matrix after multiplication
 */
template<typename T>
Matrix<T> Matrix<T>::operator* (const Matrix<T> &anotherMat)
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
                    resMat.data[idx][jdx] += this->data[idx][element] * anotherMat->data[element][jdx]; 
                }
            }
        }

        cout << resMat << endl;
        return *resMat;

    }
    catch(exception& e)
    {
        cerr << e.what() << "\n";
    }

}

template<typename T>
void Matrix<T>::print_data()
{
 
   
}

template<typename MatType> 
ostream& operator<<(ostream& output, const Matrix<MatType>& M)
{
    Matrix<MatType>& ref = const_cast <Matrix<MatType>&>(M);
    for(int i=0; i < ref.getRow(); i++)
    {
       output << "[ ";
       for(int j=0; j < ref.getCol(); j++)
       {
           output << ref.getData()[i].at(j) << ' ';

       }
       
       output << "]" << endl;

   }
   return output;
}
#endif