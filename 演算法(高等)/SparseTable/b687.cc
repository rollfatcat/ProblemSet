// 題目要求面積必須是剛好而非大於等於要求
/* 先枚舉出各組面積為Area的高寬(H*W)組合，假設在W條相鄰木板中最矮那條木板的高度為Hmin，則有：
 * (1) 若Hmin < H，無法切割成所需的椅板
 * (2) 若Hmin ≧ H，有(Hmin - H + 1)種切割方式
 * 因此此題的考點是『範圍最小值查詢 (Range Minimum Query, RMQ)』=> Sparse Table
 */
#include<bits/stdc++.h>
using namespace std;

int N, H[18][100000];
vector<int> fac, power, pf;
void find_all_fac(int now,long num){
  if(num>1e5 or now>=power.size()) return;
  for(int i=0;i<power[now];i++){
    num*=pf[now];
    if(num>1e5) break;
    fac.push_back(num),
    find_all_fac(now+1,num);
  }
}
long RMQ(int high,int width){
  int h_ST=__lg(width), Hmin;
  long subCnt=0;
  for(int st=0; st+width<=N; st++){
    Hmin=min( H[h_ST][st], H[h_ST][st+width-(1<<h_ST)]);
    if(Hmin>=high)
      subCnt+=(Hmin-high+1);
  }
  return subCnt;
}
int main(){

  // 主程式
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  long Area;
  cin>>N>>Area;
  for(int i=0;i<N;i++)
    cin>>H[0][i];
  // 建表 SparseTable
  for(int h=0;h<__lg(N);h++)
    for(int st=0; st+(1<<h)<N; st++)
      H[h+1][st]=min(H[h][st],H[h][st+(1<<h)]);
  // RMQ
  long cnt=0;
  for(int w=1,bound=(100000<Area)?100000:Area; w<=bound; w++)
    if(Area%w==0 and Area/w<=100000) // 注意寬度和高度都要小於等於1e5
      cnt+=RMQ(w,Area/w);
  cout<<cnt<<'\n';
}
/*
5 4
1 3 2 4 1
8 8
3 4 3 3 5 6 3 1
6 2
3 3 0 3 3 3
5 7
6 6 6 6 6
*/