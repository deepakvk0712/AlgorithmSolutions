#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int max_size = 1000;

string urlify(string url){
    int spaceCount = 0;

    for(char c : url){
        if(c == ' ')
            spaceCount++;
    }

    //Below code is for removing the trailing spaces, we should not replace them as per the problem
    int end = url.length();
    while(url[end-1] == ' '){
        end--;
        spaceCount--;
    }

    int newLength = end + spaceCount*2 + 1; // I think the plus one is for the null character at the end

    if(newLength > max_size)
        return "Cannot be URLified!";

    int index = newLength - 1;
    string temp = url; // Temp string variable
    url.resize(newLength);
    url[index--] = '\0';
    for(int i = end-1; i>=0; i--){
        if(temp[i] == ' '){
            url[index] = '0';
            url[index-1] = '2';
            url[index-2] = '%';
            index = index-3;
        }
        else{
            url[index] = temp[i];
            index--;
        }
    }

    return url;
}


int main(){
    //Taking input directly into the string s when it is declared.
    string s = "abcd abcd      ";

    // cout << "Enter a string which needs to be urlified : " << endl;
    // cin >> s;
    // while(s == ""){
    //     cout << "Enter a valid string to urlify!" << endl;
    //     cin >> s;
    // }

    //Make a call to the Urlify function here.
    string res = urlify(s);

    cout << "The initial string was : " << s << endl;
    cout << "After urlifying the string is : " << res << endl;
    cout << "The new length of the string is : " << res.length() << endl;

    return 0;
}