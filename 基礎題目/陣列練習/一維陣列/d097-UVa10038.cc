// 滿足『連續』差值
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MaxN 3000

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  bool cnt[MaxN];
  for(int i,n,pre,now; cin>>n>>pre; ){
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<n;i++)
      cin>>now, cnt[abs(now-pre)]=true, pre=now;
    for(i=1;i<n and cnt[i];i++);
    if(i==n)  cout<<"Jolly"<<endl;
    else  cout<<"Not jolly"<<endl;
  }
}
