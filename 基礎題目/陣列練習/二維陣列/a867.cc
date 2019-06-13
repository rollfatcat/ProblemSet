// 踩地雷的教學題
#include<iostream>
using namespace std;

int main(){
  int N;
  short cnt[16][32]={};
  char  map[16][32]={};

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int i=1;i<=15;i++)
    for(int j=1;j<=30;j++){
      cin>>map[i][j];
      if(map[i][j]=='*'){
        cnt[i-1][j-1]++;
        cnt[i-1][j]++;
        cnt[i-1][j+1]++;
        cnt[i][j-1]++;
        cnt[i][j+1]++;
        cnt[i+1][j-1]++;
        cnt[i+1][j]++;
        cnt[i+1][j+1]++;
      }
    }
  for(int i=1;i<=15;i++,puts(""))
    for(int j=1;j<=30;j++)
      if(map[i][j]=='*')
        putchar('*');
      else{
        if(cnt[i][j]>0)
          putchar(cnt[i][j]+'0');
        else
          putchar('.');
      }

}