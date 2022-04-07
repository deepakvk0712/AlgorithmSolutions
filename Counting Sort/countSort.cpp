#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int size, range;
    cout << "Enter the size of the input array : " << endl;
    cin >> size; 

    cout << "Enter the range of permissible values : " << endl;
    cin >> range;

    int inputArr[size], outputArr[size], countArr[range];

    cout << "Enter " << size << " elements of the input array in any order : " << endl;
    for(int i=0; i<size; i++){
        cin >> inputArr[i];
    }

    cout << "Initialising the count array with value 0 " << endl;
    for(int i=0; i<range; i++){
        countArr[i] = 0;
    }

    // Counting each element in input array and incrementing in the count array
    for(int i = 0; i<size; i++){
        ++countArr[inputArr[i]];
    }

    //Finding the cumulative range of entries in count array
    for(int i=1;i<range; i++){
        countArr[i] += countArr[i-1];
    }

    //For loop to map calculate the output array from
    for(int i=0; i<size; i++){
        outputArr[--countArr[inputArr[i]]] = inputArr[i];
    }

    //Put the output array into the input arrays
    for(int i=0;i <size; i++){
        inputArr[i] = outputArr[i];
    }

    cout << "Printing the sorted array : " << endl;
    for(int x: inputArr){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}