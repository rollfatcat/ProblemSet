#include<iostream>
using namespace std;

int main(){
  int caseNum, winner, numA, numB;
  string ss[2];

  cin>>caseNum;
  while(caseNum--){
    cin>>ss[0]>>ss[1];
    winner=0;
    numA=numB=0;
    int lenA=ss[0].length();
    int lenB=ss[1].length();
    if(lenA>5){
      if(lenA==lenB){
        if(ss[0][lenA-1]=='O' and ss[1][lenA-1]=='X')  winner=1;
        if(ss[0][lenA-1]=='X' and ss[1][lenA-1]=='O')  winner=2;
      }
    }else{
      for(int i=0;i<lenB; i++)
        numA+=(ss[0][i]=='O'),  numB+=(ss[1][i]=='O');
      if(lenA!=lenB)
        numA+=(ss[0][lenB]=='O');
      if( numA>(numB+5-lenB) )  winner=1;
      if( numB>(numA+5-lenA) )  winner=2;
    }
    if(winner==0)
      cout<<"NO"<<endl;
    else
      cout<<char('A'+(winner-1))<<endl;
  }
}