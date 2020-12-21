// 不只輸出最少的貨幣數,還要記錄形成組合的方式(只保留字典序最小的)
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 10001

int main(){
  int money[4], sum;
  int cnt[MaxN][5];

  while(cin>>money[0] and money[0]){
    cin>>money[1]>>money[2]>>money[3]>>sum;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=sum;i++)
      cnt[i][4]=MaxN;
    for(int k=3;k>=0;k--){
      for(int j=money[k];j<=sum;j++)
        if(cnt[j][4]>cnt[j-money[k]][4]+1){
          cnt[j][4]=cnt[j-money[k]][4]+1;
          for(int i=0;i<4;i++)
            cnt[j][i]=cnt[j-money[k]][i];
          cnt[j][k]=cnt[j-money[k]][k]+1;
        }
    }
    if(cnt[sum][4]==MaxN)
      cout<<"0\n";
    else
      cout<<cnt[sum][4]<<' '<<cnt[sum][0]<<' '<<cnt[sum][1]<<' '<<cnt[sum][2]<<' '<<cnt[sum][3]<<endl;
  }
}