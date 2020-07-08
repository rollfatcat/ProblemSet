/* 題目要兩兩一組,且希望組和組之間的差距越平均越好
 * 在上述前提下要輸出最大的組和
 */
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  for(int n,num[10000]; cin>>n; ){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n);
    int maxP=num[0]+num[n-1], ed=n-1;
    for(int i=1, tmpP;i<n/2;i++){
      tmpP=num[i]+num[ed-i];
      if(tmpP>maxP)
        maxP=tmpP;
    }
    cout<<maxP<<endl;
  }
}