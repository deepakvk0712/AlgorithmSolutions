#include<vector>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;

void mergeHalves(vector<int>& A, vector<int> temp, int leftStart, int rightEnd){
    int leftEnd = (leftStart + rightEnd)/2;
    int rightStart = leftEnd+1;
    int size = rightEnd-leftStart;

    int left = leftStart;
    int right = rightStart;
    // int index = leftStart; //Starts at the left index

    while(left <= leftEnd && right <= rightEnd){
        if(A[left] <= A[right]){
            temp.push_back(A[left]);
            left++;
        }
        else{
            temp.push_back(A[right]);
            right++;
        }
    }

    //Copy the remaining elements
    while(left <= leftEnd){
        temp.push_back(A[left]);
        left++;
    }
    while(right <= rightEnd){
        temp.push_back(A[right]);
        right++;
    }

    for (int i = leftStart; i <= rightEnd; ++i){
	    A[i] = temp[i - leftStart];
    }

}

void mergeSort(vector<int>& A, vector<int> temp, int leftStart, int rightEnd){
    if(leftStart >= rightEnd){
        return;
    }
    int middle = (leftStart + rightEnd)/2;
    mergeSort(A, temp, leftStart, middle);
    mergeSort(A, temp, middle+1, rightEnd);
    mergeHalves(A, temp, leftStart, rightEnd);
}

vector<int> mergeSortHelper(vector<int> A){
    vector<int> temp1;
    mergeSort(A, temp1, 0, A.size()-1);
    return A;
}

int main(){
    vector<int> Inp {7,1,3,2,6,3,8};
    vector<int> opInc = mergeSortHelper(Inp);

    for (int x : opInc){
        cout << x << " ";
    }
    
    return 0;
}