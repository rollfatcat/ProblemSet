/* 給定Ｎ個數字(數值只會有１/２/３)，輸出小到大排序完的結果
 */
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100001

int main(){
  int n, x;
  int cnt[4];
  
  while(cin>>n){
    memset(cnt,0,sizeof(cnt));
    while(n--)
        cin>>x, cnt[x]++;
    for(int i=0;i<cnt[1];i++)
        cout<<"1 ";
    for(int i=0;i<cnt[2];i++)
        cout<<"2 ";
    for(int i=0;i<cnt[3];i++)
        cout<<"3 ";
    cout<<'\n';
  }
}