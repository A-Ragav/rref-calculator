#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int numCols, numRows;
    cout << "Enter no. of rows: ";
    cin >> numRows;
    cout << "Enter no. of columns: ";
    cin >> numCols;
    cout<<"Enter Matrix\n";

    vector<vector<double>> matrix(numRows, vector<double>(numCols));

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cin >> matrix[row][col];
        }
    }

    int pivotRow = 0;

    for (int pivotCol = 0;
         pivotCol < numCols && pivotRow < numRows;
         pivotCol++) {

        if (matrix[pivotRow][pivotCol] == 0) {
            int row = pivotRow + 1;

            while (row < numRows && matrix[row][pivotCol] == 0) {
                row++;
            }

            if (row == numRows)
                continue;

            swap(matrix[pivotRow], matrix[row]);
        }

        double pivot = matrix[pivotRow][pivotCol];

        for (int col = 0; col < numCols; col++) {
            matrix[pivotRow][col] /= pivot;
        }

        for (int row = 0; row < numRows; row++) {
            if (row == pivotRow)
                continue;

            double eliminationFactor = matrix[row][pivotCol];

            for (int col = 0; col < numCols; col++) {
                matrix[row][col] -=
                    eliminationFactor * matrix[pivotRow][col];
            }

            matrix[row][pivotCol] = 0;
        }

        pivotRow++;
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if(fabs(matrix[row][col])<1e-9){
                cout << 0 << " ";
            }
            else{
                cout << matrix[row][col] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
