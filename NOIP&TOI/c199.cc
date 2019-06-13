#include<iostream>
using namespace std;

int main(){
  int n, x, cnt;
  int len, h[100000];


  while(cin>>n>>h[0]){
    len=1;
    for(int i=1;i<n;i++){ //消除『高原』
      cin>>h[len];
      if(h[len]!=h[len-1])
        len++;
    }
    cnt=0;
    for(int i=1;i<len-1;i++)
      if(h[i-1]<h[i] and h[i]>h[i+1]) // 找到高峰即可
        cnt++;
    cout<<cnt<<endl;
  }
}