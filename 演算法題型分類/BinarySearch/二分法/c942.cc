// 二分搜尋法的應用題型：搜尋可能的最佳化分配問題：等同基地台覆蓋
// 題解說明：http://squall.cs.ntou.edu.tw/cprog/content/10b1%20Binary%20search%20and%20applications_bw.pdf
#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1);
const double ESP=1e-4;

int N, M;
double Round[50];
inline bool test(double interval,int cnt=0){
  for(int i=0;i<N;i++)
    cnt+=(int)(Round[i]/interval);
  return cnt>=M;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N>>M and N){
    double minR=1<<30;
    double maxR=0;
    for(int i=0;i<N;i++)
      cin>>Round[i],
      Round[i]*=2.0*PI,
      minR=min(minR,Round[i]),
      maxR=max(maxR,Round[i]);

    double nL=(double)minR/(M-N+1);
    double nR=maxR, nM;
    while(nR-nL>=ESP)
      nM=(nL+nR)/2.0,
      (test(nM))? nL=nM: nR=nM-ESP;

    for(int i=0;i<N;i++)
      cout<<(int)(Round[i]/nL)<<' ';
    cout<<'\n';

  }
}