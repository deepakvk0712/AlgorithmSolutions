#include<stdio.h>
#include<iostream>
#include<array>
#include<vector>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> M){
    int row = M.size();
    int col = M[0].size();
    vector<int> colZero;
    vector<int> rowZero;

    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            if(M[i][j] == 0){
                colZero.push_back(j);
                rowZero.push_back(i);
            }
        }
    }

    for(int i = 0; i<colZero.size(); i++){
        int c = colZero[i];
        for(int j = 0; j<row; j++){
            M[j][c] = 0;
        }
    }
    cout << "Zero doll" << endl;
    for(int i = 0; i<rowZero.size(); i++){
        int r = rowZero[i];
        for(int j = 0; j<col; j++){
            M[r][j] = 0;
        }
    }

    return M;
}

int main(){
    vector<vector<int>> mat {
        {21,34,57,68},
        {57,45,72,10},
        {51,33,0,86},
        {24,39,55,20}
    };

    for(int i = 0; i < mat.size();i++){
        for(int j = 0; j < mat[0].size(); j++){
            cout << mat[i][j] << "  |  ";
        }
        cout << endl;
    }
    cout << "\n \n";
    
    //Call the function here
    mat = zeroMatrix(mat);

    cout << "--------------------------------" << endl;
    cout << "\n \n";

    for(int i = 0; i < mat.size();i++){
        for(int j = 0; j < mat[0].size(); j++){
            cout << mat[i][j] << "  |  ";
        }
        cout << endl;
    }
    return 0;
}