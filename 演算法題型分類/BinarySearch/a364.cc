/* 題目保證Ｎ≦ 500，需要依照題目的規定的進位制作轉換
 * 因為Ｎ≦ 500，所以Ｃ(n,3)和Ｃ(n,2) 可以先求出來後
 * 依照貪婪法搭配二分搜尋法即可。
 */
#include<bits/stdc++.h>
using namespace std;

int CM3(int m){return (m<3)? 0: m*(m-1)*(m-2)/6; }
int main(){
  vector<int> CM2{0,0,1};
  vector<int> CM3{0,0,0};
  for(int i=2; CM2.back()<=500; i++,CM2.push_back(i*(i-1)>>1));
  for(int i=2; CM3.back()<=500; i++,CM3.push_back(i*(i-1)*(i-2)/6));

  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    int a=upper_bound(CM3.begin(),CM3.end(),N)-CM3.begin()-1;
    int b=upper_bound(CM2.begin(),CM2.end(),N-CM3[a])-CM2.begin()-1;
    printf("%d%d%d\n",a,b,N-CM3[a]-CM2[b]);
  }
}