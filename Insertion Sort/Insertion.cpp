#include<vector>
#include<stdio.h>
#include<iostream>

using namespace std;

vector<int> insertionIncreasing(vector<int> A){
    //Here A is the input array of length n
    //Sorting this array in ascending order using insertion sort algorithm

    for(int i=1; i<A.size(); i++){
        int key = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

    return A;
}

vector<int> insertionDecreasing(vector<int> A){
    //Here A is the input array of length n
    //Sorting this array in ascending order using insertion sort algorithm

    for(int i=1; i<A.size(); i++){
        int key = A[i];
        int j = i - 1;
        while(j>=0 && A[j]<key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }

    return A;
}

int main(){
    vector<int> Inp {7,1,3,2,6,3,8};

    vector<int> OpInc = insertionIncreasing(Inp);

    for (int x : OpInc){
        cout << x << " ";
    }

    cout << "\n";

    vector<int> OpDec = insertionDecreasing(Inp);

    for (int x : OpDec){
        cout << x << " ";
    }
    return 0;
}