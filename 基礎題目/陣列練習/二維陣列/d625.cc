// 題目給予一張踩地雷的地圖('*'=地雷 '?'=空地)
// 輸出踩地雷的數字圖(那格如果是地雷就輸出'*'否則就是周圍有幾個地雷的數量)
// 如果那格的地雷數量是0輸出'-'

#include<iostream>
using namespace std;

int main(){
  int N;
  short cnt[102][102]={};
  char map[102][102]={};

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  cin>>N;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
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
  for(int i=1;i<=N;i++,puts(""))
    for(int j=1;j<=N;j++)
      if(map[i][j]=='*')
        putchar('*');
      else{
        if(cnt[i][j]>0)
          putchar(cnt[i][j]+'0');
        else
          putchar('-');
      }

}