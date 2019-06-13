// 調整矩形內的數值(統一增加或減少)使得整體的"20"個數最大化
// 矩形範圍不大：1 ≤ R ≤ 25，1 ≤ C ≤ 25，推測可以暴力解
#include<bits/stdc++.h>
using namespace std;
#define MAXN 25

int num[MAXN][MAXN];
int main(){
  int R, C;
  cin>>R>>C;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      cin>>num[i][j],
      cnt[num[i][j]]++;
}