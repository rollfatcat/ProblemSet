#include<iostream>
#include<math.h>
using namespace std;
int CharToInt(char c){ return c-'0'; }
int main(void){
  string ss;
  while(cin>>ss){
    int num[2]={0,0};
    for(int i=0;i<ss.length();i++)
      num[i%2]+=CharToInt(ss[i]);
    cout<<abs(num[0]-num[1])<<endl;
  }
}