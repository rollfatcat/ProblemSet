// 題意不清 PK賽只有前5球 之後都是一球一球看
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
// 以下是5球5球的看
/*
for(int i=0;i<ss[1].length() and winner==0; i++){
  numA+=(ss[0][i]=='O');
  numB+=(ss[1][i]=='O');
  if(i%5==4){
    if(numA>numB) winner=1;
    if(numA<numB) winner=2;
    numA=numB=0;
  }
}
if(winner==0){
  if(ss[0].length()!=ss[1].length())
    numA+=(ss[0][ss[1].length()]=='O');
  int other=ss[1].length()%5;
  other=(other==0)0:5-other;
  if( numA>numB+other )  winner=1;
  other=ss[0].length()%5;
  other=(other==0)0:5-other;
  if( numB>numA+other )  winner=2;
}
*/