#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define MaxN 101
#define MaxW 10001

int v[MaxN], w[MaxN];
int val_map[MaxN][MaxW];

int knapsack(int len,int total_w){
  memset(val_map,sizeof(val_map),0);
  for(int i=0; i<len; i++){    // 窮舉每種物品
    for(int j=total_w; j>=w[i]; j--) { // 窮舉每種重量
      if( j<w[i] ) // 耐重能力不足，故只能不放。
        val_map[i+1][j]=val_map[i][j];
      else // 耐重能力足夠，可以放或不放。
        val_map[i+1][j]=max( val_map[i][j], val_map[i][j-w[i]]+v[i] );
    }
  }
  return val_map[len][total_w];
}
int main(){
  int rem, len;
  for(int caseNum=1000; caseNum; caseNum--){
    cin>>len;
    for(int i=0;i<len;i++)
      cin>>w[i]>>v[i];
    cin>>rem;
    cout<<knapsack(len,rem)<<endl;
    for(int i=1;i<=len;i++,cout<<endl)
      for(int j=0;j<=rem;j++)
        printf("%2d ",val_map[i][j]);
  }
}