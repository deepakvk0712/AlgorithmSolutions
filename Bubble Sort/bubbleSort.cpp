#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

void bubbleSort(vector<int>& A){
    for(int i=0;i < A.size(); i++){
        for(int j=A.size()-1; j>=i+1; j--){
            if(A[j] < A[j-1]){
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main(){
    vector<int> Inp {7,1,3,2,6,3,8};
    bubbleSort(Inp);

    for (int x : Inp){
        cout << x << " ";
    }
    
    return 0;
}