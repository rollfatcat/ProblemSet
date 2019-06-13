// 貪婪法：各自排序後配對算加權總和

#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1000002

short w[MAXN], d[MAXN];
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int Nw, Nd;
  cin>>Nw>>Nd;
  for(int i=0;i<Nw;i++)
    cin>>w[i];
  for(int i=0;i<Nd;i++)
    cin>>d[i];
  sort(w,w+Nw);
  sort(d,d+Nd);
  long long sum=0;
  for(int i=0;i<Nw;i++)
    sum+=(long long)w[Nw-1-i]*d[i];
  cout<<sum<<endl;
}

/* 514x1+10x2+4x2+2x3+1x9=557
5 6
10 2 1 514 4
1 2 100 2 3 9
*/