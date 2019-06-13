// 產生只有 2/3/5 可以整除的數列，概念同 d214
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int numS[1501]={0,1};
  int p2=1, p3=1, p5=1;
  for(int i=2; i<=1500; i++){
    while(2*numS[p2]<=numS[i-1]) p2++;
    while(3*numS[p3]<=numS[i-1]) p3++;
    while(5*numS[p5]<=numS[i-1]) p5++;
    numS[i]=min(min(2*numS[p2],3*numS[p3]),5*numS[p5]);
  }
  cout<<"The 1500'th ugly number is "<<numS[1500]<<"."<<endl;
}
//859963392