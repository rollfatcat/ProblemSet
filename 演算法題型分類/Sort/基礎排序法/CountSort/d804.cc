/* 給定Ｎ個食物的飽足感和Ｍ單位的飽足需求，最少需要多少個食物？
 * Ｎ ≦ 1e5，但每個食物的飽足感不超過 1e3。
 * 從最大飽足感的食物開始選。
 */
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