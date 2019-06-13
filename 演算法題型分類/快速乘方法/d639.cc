// 矩陣乘法練習
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int base[3][3]={{1,1,1},{1,0,0},{0,1,0}};
  int nxt[3][3], ans[3]={1,1,1}, tmp[3];
  int power;

  scanf("%d",&power);
  for(power--;power>0; power/=2){
    if(power%2){
      memset(tmp,0,sizeof(tmp));
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          tmp[i]+=base[i][j]*ans[j];
      for(int i=0;i<3;i++)
        ans[i]=tmp[i]%10007;
    }
    memset(nxt,0,sizeof(nxt));
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
          nxt[i][j]+=base[i][k]*base[k][j];
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        base[i][j]=nxt[i][j]%10007;
  }
  printf("%d\n",ans[2]);
}