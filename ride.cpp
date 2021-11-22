/*
ID: angelin8
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int encode(string word){
    int result = int(word[0]) - 64;
    for(int i = 1; i < word.length(); i++){
        result *= int(word[i]) - 64;
    }
    return result % 47;
}

int main(){
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet, group;
    fin >> comet >> group;
    if(encode(comet) == encode(group)){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    return 0;
}
