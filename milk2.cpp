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
    signed char ss; // determine whether starting or ending (start = 1, end = -1)
}

int eventcmp(const event *a, const event *b){
    if(a->seconds != b->seconds){
        return (a->seconds - b->seconds); // since seconds is # secs from start, we subtract to determine which event came before (ie, 300 - 500 = -200 since its negative a came before)
    }
    return b->ss - a->ss; // since ss determines whether the event is the starting or ending point of each session, if event takes place at same time we can use ss to determine which came before
}

int main(){
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int amount, amount_events, i; // declare the number of sessions, amount of events, and the index
    event events[5000 * 2]; // since the max number of sessions is 5000 and each session contains 2 events, the # of events is 5000 * 2 
    
    fin >> amount;
    amount_events = amount * 2;
    for(int i = 0; i < amount; ++i){ // loop through the amount of sessions to get the time of each event
        fin >> events[2 * i].seconds; events[2 * i].ss = 1; // fill in events with first event inside session  
        fin >> events[2 * i + 1].seconds; events[2 * i + 1].ss = -1; // the next event in the events array 
    }
    
    // once all the events are in, sorts the events in acsending order using eventcmp
    qsort(events, amount_events, sizeof(event), (int(*)(const void*, const void*)) eventcmp);

    int num_milkers = 0, no_milkers = 1;
    int longest_milk = 0, longest_wo_milk = 0;
    int interval_start, interval_ending;

    for(int i = 0; i < amount_events; ++i){
       num_milkers += events[i].ss;
        
       if(!no_milkers && !num_milkers){ // if there are no milkers
            interval_length = events[i].seconds - interval_start; //find the interval length from the start, interval_start is last time person milked a cow
            if(interval_length > longest_milk){
                longest_milk = interval_length; 
            }
            interval_start = events[i].seconds;
       }else if(num_milkers && was_none){ // if there are milkers
           if(i != 0){  // if not the starting event (DO this to prevent edge case of checking before the starting event and couting that as not milking)
               interval_length = events[i].seconds - interval_start;
               if(interval_length > longest_no_milk){
                   longest_no_milk = interval_length;
               }
               interval_start = events[i].seconds;
           }
           no_milkers = (num_milkers == 0);
       }
    }

    fout << longest_milk << " " << longest_wo_milk << endl;

    return 0;
}
