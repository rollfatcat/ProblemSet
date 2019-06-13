// 題目會給一個數字Ｎ，和Ｎ-1個數字，詢問哪一個數字不在
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 2001

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  bool page[MaxN];
  for(int n, x, i; cin>>n;){
    memset(page,0,sizeof(page));
    for(i=1;i<=n;i++)
      cin>>x, page[x]=true;
    for(i=1; page[i];i++);
    cout<<i<<endl;
  }
}