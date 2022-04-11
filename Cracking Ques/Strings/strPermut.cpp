// Check Permutation: Given two strings, write a method to decide if one is a permutation of the
// other. 

//Hint : 
// 1. There is one solution that isO(N lo g N) time. Another solution uses some space, but isO(N) time.
// 2. Could a hash table be useful?
// 3. Two strings that are permutations should have the same characters, but in different orders. Can you make the orders the same?

#include<stdio.h>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

//The method below uses an unordered map to store the characters that appear in first string and we check if those same characters appear in the second string
bool isPerm(string a, string b){
    unordered_map<char, int> m;

    if(a.length()!=b.length())
        return false;
    
    for(char c : a){
        if(m.find(c)==m.end()){
            m.insert({c,1});
        }
        else{
            m.insert({c, m.at(c)++});
        }
    }

    for(char c : b){
        if(m.find(c)!=m.end() && m.at(c) >= 1){
            m.insert({c, m.at(c)--});
        }
        else if(m.find(c) == m.end() || m.at(c) < 1){
            return false;
        }
    }

    return true;
}

//In the below method, we sort the two strings in alphabatical order and check if they are same.
bool stringSortMethod(string a, string b){
    int maxChar = 52;
    if(a.length()!=b.length())
        return false;
    int charArr[maxChar] = {0};
    int charArr2[maxChar] = {0};

    for(int i=0; i<a.length(); i++){
        charArr[a[i]-'A']++;
    }

    for(int i=0; i<b.length(); i++){
        charArr2[b[i]-'A']++;
    }

    a = "";

    for(int i=0; i<maxChar; i++){
        for(int j=0; j<charArr[i]; j++){
            a = a + (char)('A'+i);
        }
    }

    b = "";

    for(int i=0; i<maxChar; i++){
        for(int j=0; j<charArr[i]; j++){
            b = b + (char)('A'+i);
        }
    }
    
    if(a == b){
        return true;
    }

    return false;
}

int main(){
    string s = "";
    string t = "";
    cout << "Enter string 'a' : " << endl;
    cin >> s;
    cout << "Enter string 'b' : " << endl;
    cin >> t;

    //Make a call to the function here
    // bool res = isPerm(s,t);
    bool res = stringSortMethod(s,t);

    cout << "String " << t << " is permutation of string " << s << " : " << res << endl;
    return 0;
}