// 狀態壓縮的DP解法=>最終優化(以bit為單位思考)  時間：3.28s=>0.47s
#include<iostream>
using namespace std;

int N, cnt, y_row[20];
void DFS(int y, int x, int Nslash, int Pslash){
  if(y==N){ cnt++;  return; }
  int Nmask = Nslash>>y;
  int Pmask = Pslash>>(N-y-1);
  int canPutQueen = y_row[y] & x & Nmask & Pmask;
  while(canPutQueen){
    int xPut = canPutQueen & (-canPutQueen);
    DFS(y+1, x^xPut, Nslash^(xPut<<y), Pslash^(xPut<<(N-y-1)) );
    canPutQueen^=xPut;
  }
}
int main(){
  string ss;

  for(int caseNum=1;cin>>N and N;caseNum++){
    for(int i=0;i<N;i++){
      cin>>ss;
      y_row[i]=0;
      for(int j=0;j<ss.length();j++)
        if(ss[j]=='.')
          y_row[i]+=(1<<j);
    }
    cnt=0;
    DFS(0, (1<<N)-1, (1<<(2*N-1))-1, (1<<(2*N-1))-1);
    cout<<"Case "<<caseNum<<": "<<cnt<<endl;
  }
}