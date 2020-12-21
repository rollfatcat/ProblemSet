// 難題, DP的更新思維但是窮舉時的位置很大 n≤100000, m≤1000000000, a[i]≤10000, 1≤b[i]≤m
// 一個保險的作法是將所有的點都看過一遍,這樣會 TLE 。
// 可以用另一變數存 i-18 以前的最大值，隨著 i 的推進更新，
// 這樣只要再看 i-17 到 i-1
// 注意規定從 0 開始會有些座標走不到要記得先處理。

// 測資讀入時間有點多,加入加速代碼：48ms=>16ms
#include<iostream>
#include<algorithm>
using namespace std;
#define MaxN 100001

struct Node{
  int pos, num;
  bool operator<(const Node &other)const{ return pos<other.pos; }
}data[MaxN];

bool mask[18]={ 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int m, n, maxFood, untilIdx;
  int rec[MaxN]={0};

  cin>>n>>m;
  data[0]={0,0};
  for(int i=1;i<=n;i++)
    cin>>data[i].num>>data[i].pos, rec[i]=-1;
  sort(data+1,data+n+1);

  maxFood=0, untilIdx=0;
  for(int now=1;now<=n;now++){
    for(int idx=now-1;idx>=0;idx--){
      int dis=data[now].pos-data[idx].pos;
      if(18>dis){
        if(mask[dis] and rec[idx]>-1)
          rec[now]=max(rec[now],rec[idx]+data[now].num);
      }else{
        // 從上次更新到的地方往下再更新到距離>18時最近的一個點
        for(int i=untilIdx+1;i<=idx;i++)
          if(rec[i]>maxFood)
            maxFood=rec[i];
        untilIdx=idx;
        rec[now]=max(rec[now],maxFood+data[now].num);
        break;
      }
    }
  }
  // 從上次更新到的地方往下再更新到全部的紀錄
  for(int i=untilIdx+1;i<=n;i++)
    maxFood=max(maxFood,rec[i]);
  cout<<maxFood<<endl;
}
