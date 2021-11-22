/*
ID: angelin8
PROG: ride
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int encode(string word){
    int result = int(word[0]) - 64;
    for(int i = 1; i < word.length(); i++){
        result *= int(word[i]) - 64;
    }
    return result % 47;
}

int main(){
    string comet, group;
    cin >> comet >> group;
    if(encode(comet) == encode(group)){
        cout << "GO";
    }else{
        cout << "STAY";
    }
    return 0;
}
