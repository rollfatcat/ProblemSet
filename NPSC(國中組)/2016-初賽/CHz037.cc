// 注意開啟的門最多是N-2扇
/* 直覺作法：扣除門後面是汽車以及選中的門即可
 * 若兩者是同一扇門時上述做法會輸出N-1扇門(60%)
 */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  string ss;
  int N, P, i;

  cin>>N>>ss>>P;
  vector<bool> open(N+1,1);
  open[P]=0;
  for(i=0;ss[i]=='M';i++);
  open[++i]=0;

  bool after=0;
  for(int i=1,j=2;j<N;i++)
    if(open[i]){
      if(after) cout<<' ';
      after=1, cout<<i, j++;
    }
}