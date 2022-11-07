#include<iostream>
using namespace std;

int main(){
  int step[3][21];
  step[0][0]=1, step[0][1]=1, step[0][2]=1;
  step[1][0]=1, step[1][1]=1, step[1][2]=2;
  step[2][0]=1, step[2][1]=1, step[2][2]=2;
  for(int i=3;i<=20;i++)
    step[0][i]=step[0][i-1],
    step[1][i]=step[1][i-1]+step[1][i-2],
    step[2][i]=step[2][i-1]+step[2][i-2]+step[2][i-3];

  int t, k;
  while(cin>>t>>k)
    cout<<step[t-1][-k]<<endl;
}