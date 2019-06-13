// 教學文件出處：https://www.csie.ntu.edu.tw/~sprout/algo2016/homework/week11.pdf
// https://tw.saowen.com/a/71b4379ab093bb0d7aa9ecded9f4e60897cfa4e951b047bf5d3932499d9b1b64
// BIT可以做到區間更新嗎？
#include<iostream>
using namespace std;

int N, num[10], BIT1[10]={}, BIT2[10]={};
inline int lowbit(int x){ return x&-x; }
int query(int x){ //前綴和：計算1~x的總和 O(㏒N)
  int sum=0;
  for(int i=x;i>0;i-=lowbit(i))
    sum+=BIT2[i];
  return sum;
}
void update(int pos,int d){ //單點更新：從自己的位置開始往上層更新 O(㏒N)
  for(int i=pos;i<=N;i+=lowbit(i))
    BIT2[i]+=d;
}
int main(){
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>num[i];
  // init 1
  for(int i=1;i<=N;i++){
    BIT1[i]=num[i];
    int low_bound=i-lowbit(i);
    for(int j=i-1;j>low_bound;j-=lowbit(j)) // O(N)
      BIT1[i]+=BIT1[j];
    cout<<BIT1[i]<<' ';
  }
  cout<<endl;
  // init 2(需要更正，不要動到初始資料的陣列)
  for(int i=1;i<=N;i++){
    BIT2[i]+=num[i];
    int up_layer=i+lowbit(i);
    if(up_layer<=N) // 拿更新過的BIT2往上一層更新，在範圍內就疊加:O(N)
      BIT2[up_layer]+=BIT2[i];
    cout<<BIT2[i]<<' ';
  }
  cout<<endl;
}