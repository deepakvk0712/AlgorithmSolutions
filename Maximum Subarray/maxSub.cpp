#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int maxSubarray(vector<int> A){
    int current_max = A[0];
    int sum = 0;
    vector<int> temp;

    temp.push_back(A[0]);

    for(int i=1; i<A.size(); i++){
        if(current_max+A[i] > 0){
            current_max = current_max+A[i];
        }
        else
            current_max = 0;

        sum = max(sum, current_max);
    }

    return sum;
}

int main(){
    vector<int> Inp {-2,1,-3,4,-1,2,1,-5,4};
    int opInc = maxSubarray(Inp);

    cout << opInc << endl;
    
    return 0;
}