// 類似 NPSC 2005國中組決賽題目：CHg011: E.誰先晚餐
// 裝訂時間可以cover印刷時間, 所以先照裝訂時間去排序
#include<iostream>
#include<algorithm>
using namespace std;

struct Node{
  int x, y;
  bool operator<(const Node &other)const{
    return (y==other.y)?(x>other.x):(y>other.y); }
}data[1000];
int main(){
  int n;

  while(cin>>n){
    for(int i=0;i<n;i++)
      cin>>data[i].x>>data[i].y;
    sort(data,data+n);
    int sumT=0, maxT=0;
    for(int i=0;i<n;i++){
      sumT+=data[i].x;
      int tmpT=sumT+data[i].y;
      if(tmpT>maxT)
        maxT=tmpT;
    }
    cout<<maxT<<endl;
  }
}