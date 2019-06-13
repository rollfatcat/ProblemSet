// 除非『其他人』已經解完6題且佔據排名第一，否則都有可能

#include<iostream>
using namespace std;

int main(){
  bool poss=true;
  int P, R;
  for(int i=0;i<6;i++){
    cin>>P>>R;
    if(i and P[i]==6 and R[i]==1)
      poss=false;
  }
  puts((poss)?"Yes":"No");
}