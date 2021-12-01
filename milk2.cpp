/*
ID: angelin8
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct event {
    long seconds; // # of seconds from the start (5am)
    signed char ss;
}



int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int amount, amount_events, i; // declare the number of sessions, amount of events, and the index
    event events[5000 * 2]; // since the max number of sessions is 5000 and each session contains 2 events, the # of events is 5000 * 2 
    
    fin >> amount;
    amount_events = amount * 2;
    for(int i = 0; i < amount; ++i){ // loop through the amount of sessions to get the time of each event
        int a, b;
        fin >> events[2 * i].seconds; events[2 * i].ss = 1;
        fin >> events[2 * i + 1].seconds; events[2 * i + 1].ss = -1;
    }

    qsort(events, amount_events, sizeof(event), (int(*)(const void*, const void*)) eventcmp);

    return 0;
}
