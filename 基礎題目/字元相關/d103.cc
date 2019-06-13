#include<iostream>
using namespace std;

int main(){
  string ss, check="0123456789X";

  while(cin>>ss){
    int n=(ss[0]-'0')+(ss[2]-'0')*2+(ss[3]-'0')*3+(ss[4]-'0')*4+(ss[6]-'0')*5+(ss[7]-'0')*6+(ss[8]-'0')*7+(ss[9]-'0')*8+(ss[10]-'0')*9;
    if(check[n%11]==ss[12]) cout<<"Right"<<endl;
    else ss[12]=check[n%11], cout<<ss<<endl;
  }
}