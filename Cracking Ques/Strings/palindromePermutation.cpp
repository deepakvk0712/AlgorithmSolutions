#include<stdio.h>
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool permutPalindrome(string s){
    bool oneOdd = false;
    unordered_map<char, int> m;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for(char c : s){
        if(c == ' ')
            continue;
        if(m.find(c) == m.end()){
            m.insert({c,1});
        }
        else{
            m.insert({c, m.at(c)++});
        }
    }

    for(auto i : m){
        if(i.second % 2 == 0){
            continue;
        }
        else{
            if(oneOdd == false){
                oneOdd = true;
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    string s = "abcd    ";

    //Call the function here to
    bool res = permutPalindrome(s);

    cout << "The entered permutation " << s << " is a palindrome : " << res << endl;
    return 0;
}