// 這題的加強版就是ZJ-b966(APCS考題)，比對兩題的測資範圍差異說明『演算法』概念
// 下述作法是用填格子的想法把每個線段內的哪個格子塗黑，最後輸出所有塗黑的格子個數
// 顯然這個做法的問題是當線段很長時會有MLE和TLE的情況
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
bool hasTree[MAXN]={};
int main(){
  int maxL, N;
  int nL, nR;

  scanf("%d %d",&maxL,&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&nL,&nR);
    for(int j=nL;j<=nR;j++)
      hasTree[j]=1;
  }
  int cnt=0;
  for(int i=0;i<=maxL;i++)
    if(hasTree[i]==0)
      cnt++;
  printf("%d\n",cnt);
}