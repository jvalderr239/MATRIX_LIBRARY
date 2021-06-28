#include "Matrix.h"
#include <vector>

int main()
{
    Matrix<int> m1;
    m1.set_dimensions(2,2);
    vector<int> firstRow = {2, 3};
    vector<int> secondRow = {3, 2};
    vector<int> thirdRow = {1,2};
    vector<int> fourthRow = {2,1};
    vector<vector<int>> data = {firstRow, secondRow};
    vector<vector<int>> otherData = {thirdRow, fourthRow};
    m1 = data;
    Matrix<int> m2 = otherData;

    m1.transpose();
    
    return 0;
}