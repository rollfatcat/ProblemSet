#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main(){
  int T;
  char c;

  cin>>T;
  c=getchar();
  while(T--){
    int pair=0;
    c=getchar();
    for(int pNum=0;c!='\n';c=getchar())
      if(c=='p')
        pNum++;
      else if(c=='q')
        if(pNum>0)
          pNum--, pair++;
    cout<<pair<<endl;
  }
}