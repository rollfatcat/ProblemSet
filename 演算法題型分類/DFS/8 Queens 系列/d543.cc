// 參考： http://maplewing.blogspot.com/2011/03/uva11195another-n-queen-problem.html
// 狀態壓縮的DP解法=> 最終優化(以bit為單位思考)
#include<iostream>
using namespace std;

int N, cnt[16], y_row;
void DFS(int y, int x, int Nslash, int Pslash){
  if(y==N){ cnt[N]++;  return; }
  //壓在一維來看,正斜率是由右到左,負斜率是由左到右
  int Nmask = Nslash>>y;        // x+y=[     0, 2N]
  int Pmask = Pslash>>(N-y-1);  // x-y=[-(N-1),N-1]
  int canPutQueen = x & Nmask & Pmask;
  //主要是這個寫法可以保證每次都讀取到能放Queen的位置
  for(int xPut; canPutQueen; canPutQueen^=xPut)
    xPut=canPutQueen & (-canPutQueen), //從尾端數來的第一個1(可以放Queen位置)
    DFS(y+1, x^xPut, Nslash^(xPut<<y), Pslash^(xPut<<(N-1-y)) );
}
int main(){
  for(N=1;N<16;N++)
    cnt[N]=0,
    DFS(0, (1<<N)-1, (1<<(2*N-1))-1, (1<<(2*N-1))-1);
  while(cin>>N and N)
    cout<<cnt[N]<<endl;
}