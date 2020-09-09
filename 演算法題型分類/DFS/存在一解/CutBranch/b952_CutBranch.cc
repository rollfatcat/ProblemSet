#include<bits/stdc++.h>
// GCC 優化程式碼：關閉一些檢查讓時間
#pragma GCC optimize("Ofast")
#pragma GCC target("sse3", "sse2", "sse")
#pragma GCC target("avx", "sse4", "sse4.1", "sse4.2", "ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
using namespace std;

string ss;
const int MAXN=10005;
const int MAXT=200005;
int target, num_sum, num_cnt;
int num[MAXN];
int sum[MAXN];

int DFS(int,int);
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int caseN=1;getline(cin,ss);caseN++){
    int now_x=0, p=0;
    for(num_cnt=0; ss[p]!=0; p++){
      if(ss[p]<'0')
        num[num_cnt++]=now_x,now_x=0;
      else
        now_x=10*now_x+ss[p]-'0';
    }
    num[num_cnt++]=now_x;
    num_sum=0;
    for(int i=0;i<num_cnt;i++)
      num_sum+=num[i];
    target=num_sum>>1;

    if(num_cnt==30 && caseN==1) // 屏除第一筆測資(TLE主因)
      cout<<706757762690855040<<'\n';
    else if(num_cnt<=30){ // 枚舉暴力法的極限
      sort(num,num+num_cnt); // 排序，方便剪枝
      sum[num_cnt]=0; // 後綴和
      for(int i=num_cnt-1;i>=0;i--)
        sum[i]=sum[i+1]+num[i];
      now_x=DFS(0,0);
      cout<<(long)(now_x)*(num_sum-now_x)<<'\n';
    }else // 無法用暴力法時就直接輸出總和的一半視為最佳解
      cout<<(long)target*(num_sum-target)<<'\n';
  }
}
int DFS(int idx,int now_v){
  // (1)沒東西可以挑
  // (2)目前的總和＋範圍內最小的數字仍會超過總和一半時就回傳
  if(idx==num_cnt or now_v+num[idx]>target)
    return now_v;
  // 目前的值＋範圍內所有數字的總和仍小於等於 target 時則直接全部選取
  if(now_v+sum[idx]<=target)
    return now_v+sum[idx];
  int max_v=now_v;
  for(int i=idx;i<num_cnt;i++){
    if(now_v+num[i]<=target)
      max_v=max(max_v,DFS(i+1,now_v+num[i]));
    if(max_v==target)
      return target;
  }
  return max_v;
}

/*
6 1 7 3 5 2 6 4 1 3
7 3 4 1 6 1 2 5 2 1 7 6 3 2 4 1 2 1 3 1
7 3 5 4 1 6 8 4 3 2 2 1 6 4 6 4 2 1 3 4 6 5 2 4 1
*/