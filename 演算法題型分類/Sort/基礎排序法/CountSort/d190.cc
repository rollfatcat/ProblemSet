// CountSort
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 101

int main(){
  int age[MaxN], x, n;
  while(cin>>n and n){
    memset(age,0,sizeof(age));
    for(int i=0;i<n;i++)
      cin>>x, age[x]++;
    for(int i=0;i<MaxN;i++)
      for(int j=0;j<age[i];j++)
        cout<<i<<' ';
    cout<<endl;
  }
}