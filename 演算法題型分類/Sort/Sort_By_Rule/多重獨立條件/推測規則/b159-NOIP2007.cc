/*
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e4;
int num[MaxN];
int main(){
  int w, n;
  
  while(cin>>w>>n){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    int cnt=0;
    for(int front=0, back=n-1;front<=back;cnt++,back--)
      if(num[front]+num[back]<=w)
        front++;
    cout<<cnt<<'\n';
  }
}