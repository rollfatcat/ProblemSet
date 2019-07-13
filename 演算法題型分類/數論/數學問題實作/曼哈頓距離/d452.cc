#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000;
int num[MAXN];
int main() {
  int caseT, N;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%d",&num[i]);
    sort(num,num+N);
    int mid=num[N>>1];
    long sum=0;
    for(int i=0;i<(N>>1);i++)
      sum+=mid-num[i];
    for(int i=N>>1;i<N;i++)
      sum+=num[i]-mid;
    printf("%ld\n",sum);
  }
}