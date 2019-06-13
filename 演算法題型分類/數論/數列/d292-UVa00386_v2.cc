// 4層for迴圈找組合找到直接輸出：32ms
#include<iostream>
#include<cmath>
using namespace std;

int power[201];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  for(int i=2;i<=200;i++)
    power[i]=pow(i,3);
  for(int a=6;a<=200;a++)
    for(int b=2;b<=200;b++)
      for(int c=b;c<=200;c++)
        for(int d=c;true;d++){
          int num=power[b]+power[c]+power[d];
          if(power[a]==num)
            cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
          else if(power[a]<num)
            break;
        }
}