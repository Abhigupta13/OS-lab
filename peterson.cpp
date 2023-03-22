// Write a program to implement Peterson Solution for 2 process, 
// test whether the solution satisfies critical section conditions or not?
// Give appropriate message by testing the algorithm.
#include <bits/stdc++.h>
using namespace std;
int i=0,j=0;
int turn;
bool flag_i,flag_j;
void mutualExclusive(){
    
}
void p1(){
      // process i
    flag_i=true;
    turn=j;
    while(flag_j && turn==j){
         // Critical Section
         cout<<"p1 in cs"<<"\n";
         }
    flag_i=false;
}
void p2(){
     // process j
    flag_j=true;
     turn=i;
    while(flag_i && turn==i){
        // Critical Section
          cout<<"p2 in cs"<<"\n";
    }
    flag_j=false;
}
int main() {
  p1();
  p2();
}
