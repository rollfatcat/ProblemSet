// 題目沒說要選到剛好 => 貪婪法
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int w[100000];
  for(int n,m; cin>>n>>m;){
    for(int i=0;i<n;i++)
      cin>>w[i];
    sort(w,w+n);
    int idx, nowW=0;
    for(idx=n-1;idx>=0 and nowW<m;idx--)
      nowW+=w[idx];
    if(nowW<m)  cout<<"OAQ"<<endl;
    else cout<<n-1-idx<<endl;
  }
}