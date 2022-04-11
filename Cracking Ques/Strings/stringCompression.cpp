#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

string stringCompression(string s){
    int count = 1;
    string res;
    char currChar;
    if(s == ""){
        return s;
    }

    for(int i = 0; i<s.length(); i++){
        currChar = s[i];

        while(s[i+1] == currChar){
            count++;
            i++;
        }

        if(count == 1){
            res = res + s[i];
        }
        else{
            res = res + s[i] + to_string(count);
            count  = 1;
        }
    }
    return res;
}

int main(){
    string s = "";

    //Call the string compression function Here
    string res = stringCompression(s);
    cout << "The original string is " << s << endl;
    cout << "The compressed string is " << res << endl;
    return 0;
}