#include<stdio.h>
#include<string>
#include<iostream>
#include<unordered_set>
#include<bitset>
using namespace std;
//44,117,132
//Hints :
// 1. Can you solve it in 0(N lo g N) time? What might a solution like that look like?
// 2. Could a bit vector be useful?
// 3. Try a hash table.

bool isUnique(string s){
    unordered_set<char> st;

    if(s.length() == 0)
        return true;

    for( char c : s ){
        if(st.find(c) == st.end()){
            //char was not found in the set, proceed to add the character
            st.insert(c);
        }
        else{
            return false;
        }
    }

    return true;
}

bool isUniqueBitset(string s){
    bitset<s.length()> b;

    for(int i=0; i<s.length(); i++){
        if(b[s[i]])
    }
}

int main(){
    string s = "";
    cout << "Enter a string : " << endl;
    cin >> s;

    //Make a call to the function here
    bool res = isUnique(s);

    cout << "String " << s << " has unique characters : " << res << endl;
    return 0;
}