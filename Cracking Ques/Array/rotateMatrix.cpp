#include<stdio.h>
#include<iostream>
#include<array>
#include<vector>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int> > M){
    int row = M.size();
    int col = M[0].size();

    for(int i = 0; i<row; i++){
        for(int j = i; j<col; j++){
            int temp = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = temp;
        }
    }

    for(int i = 0; i < row;i++){
        for(int j = 0; j<(col/2); j++){
            int temp = M[i][j];
            M[i][j] = M[i][col-j-1];
            M[i][col-j-1] = temp;
        }
    }

    return M;
}

int main(){
    vector<vector<int>> mat {
        {62,35,31,12},
        {12,27,48,36},
        {11,64,32,67},
        {13,52,79,40},
    };

    //Printing the initial matrix
    for(int i=0; i<mat.size(); i++){
        for(int j = 0; j<mat[0].size(); j++){
            cout << mat[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "\n \n";

    //Call the rotate matrix function Here
    mat = rotateMatrix(mat);

    //Printing the rotated matrix
    for(int i=0; i<mat.size(); i++){
        for(int j = 0; j<mat[0].size(); j++){
            cout << mat[i][j] << " | ";
        }
        cout << endl;
    }
    return 0;
}