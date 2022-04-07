//This program just shows how to use the priority queue provided by the STL library.
#include<queue> //This contains the priority queue DS
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    //Compare has default value, higher number will have higher priority
    // priority_queue<int> Q;
    // vector<int> v {8,1,6,4,0,7,2,9};
    // for(int x : v){
    //     Q.push(x);
    // }
    // while(!Q.empty()){
    //     cout << Q.top() << " ";
    //     Q.pop();
    // }
    // cout << endl;

    //Changed the default comparator to give higher priority to lower value
    // priority_queue<int, vector<int>, std::greater<int>> Q;
    // vector<int> v {8,1,6,4,0,7,2,9};
    // for(int x : v){
    //     Q.push(x);
    // }
    // while(!Q.empty()){
    //     cout << Q.top() << " ";
    //     Q.pop();
    // }
    // cout << endl;

    //Now we are writing custom compare function
    auto cmp = [](int a, int b){
        return a>b;
    };

    priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);
    vector<int> v {8,1,6,4,0,7,2,9};
    for(int x : v){
        Q.push(x);
    }
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;
}