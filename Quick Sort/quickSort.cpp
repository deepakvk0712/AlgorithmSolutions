#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int start, int end){ //Arrays are always pass by address in c++
    int index = start;
    int pivot = A[end];
    for(int i=start; i<end-1;i++){
        if(A[i] <= pivot){
            swap(A[i], A[index]);
            index++;
        }
    }
    swap(A[index], A[end]);
    return index;
}

void quickSort(int A[], int start, int end){ //Arrays are always pass by address in c++
    if(start < end){
        int p = partition(A, start, end);
        quickSort(A, start, p-1);
        quickSort(A, p+1, end);
    }
}

int main(){
    int size = 0;
    cout << "Enter the size of the input array : "<< endl;
    cin >> size;

    int A[size];
    cout << "Enter the " << size << " elements in any order " << endl;
    for(int i=0; i<size; i++){
        cin >> A[i];
    }

    cout << "\n Array before sorting is " << endl;
    for(int i=0; i<size; i++){
        cout << A[i] << " ";
    }

    cout << "\n Array after sorting is " <<endl;
    quickSort(A, 0, size-1); //Arrays are always pass by address in c++
    for(int x : A){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}