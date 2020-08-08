/* 給定Ｎ個人的身高，在"保持隊形"的前提下移除最少的人數？
 * 隊形：Ｔ1 < Ｔ2 < … < Ｔi and Ｔi > Ｔi+1 > … > ＴK (１≦ｉ≦Ｋ)
 * 枚舉每個人為隊形的中央時可形成的最多人數：LIS＋LDS
 * LIS 紀錄"由左往右"包含這個點 的"嚴格遞增數列"長度 
 * LDS 紀錄"由右往左"包含這個點 的"嚴格遞減數列"長度
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
int num[MaxN];
int LIS[MaxN]={};
int LDS[MaxN]={};

int main(){
  int N;
  scanf("%d\n",&N);
  for(int i=0;i<N;i++)
  	scanf("%d",&num[i]);
  /* 由左往右找LIS */
  for(int i=0;i<N;i++){
  	for(int j=0;j<i;j++)
  		if(num[j]<num[i])
  			LIS[i]=max(LIS[i],LIS[j]);
  	LIS[i]++;
  }
  /* 由左往右找LDS＝由右往左找LIS */
  for(int i=N-1;i>=0;i--){
  	for(int j=N-1;j>i;j--)
  		if(num[j]<num[i])
  			LDS[i]=max(LDS[i],LDS[j]);
  	LDS[i]++;
  }
  /* 枚舉每個人為中心時可以形成的長度 */
  int ans=LIS[0]+LDS[0]-1;
  for(int i=1;i<N;i++)
  	ans=max(ans,LIS[i]+LDS[i]-1);
  printf("%d\n",N-ans);
}