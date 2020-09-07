// BinarySearch( 0.2s/15.8MB )
/* 第一眼看以為是暴力法，但會發現即使深度只有4層但是分支太多(N=1000)
 * 雙向BFS的概念，產生兩個數列(各由兩層的數值加總產生)，做BinarySearch
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, P, cnt=0;
  scanf("%d %d",&N,&P);

  int w[1000];
  vector<int> A, B;
  for(int i=0,x;i<N;i++)
    scanf("%d",&w[i]);
  for(int i=0,x;i<N;i++){
    scanf("%d",&x);
    for(int j=0;j<N;j++)
      A.push_back(w[j]+x);
  }
  for(int i=0,x;i<N;i++)
    scanf("%d",&w[i]);
  for(int i=0,x;i<N;i++){
    scanf("%d",&x);
    for(int j=0;j<N;j++)
      B.push_back(w[j]+x);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  for(int i=0;i<A.size();i++){
    int v=P-A[i];
    int x1=lower_bound(B.begin(),B.end(),v)-B.begin();
    int x2=upper_bound(B.begin(),B.end(),v)-B.begin();
    cnt+=x2-x1;
  }
  printf("%d\n",cnt);
}