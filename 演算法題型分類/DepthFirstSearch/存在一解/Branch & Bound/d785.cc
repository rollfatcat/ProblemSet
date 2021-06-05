// ZJ-d375/UVa-10364 的變形題
// 但這題不能枚舉每個筷子在現階段要不要選入會TLE
// 正確的做法是根據目前的筷子決定要選入哪個區段，搭配剪枝：回朔時區段不可為０
#include<bits/stdc++.h>
using namespace std;

const int MAXE=31;
int Nedge, Ngon, avgL;
int len[MAXE];
int bucket[MAXE];

bool compare(int a,int b){ return a>b; }
bool DFS(int remN,int remE,int nowP){
  if(remN==1) return true;
  if(remN>remE) return false;
  for(int i=0;i<Ngon;i++){
    if(bucket[i]+len[nowP]>avgL) continue;
    bucket[i]+=len[nowP];
    if( DFS(remN-(bucket[i]==avgL),remE-1,nowP+1) )
      return true;
    bucket[i]-=len[nowP];
    if(bucket[i]==0) break; // <- 填區段的時候不能導致區段空置
  }
  return false;
}
int main(){
  int caseT;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d",&Ngon);
    scanf("%d",&Nedge);
    int maxL=0, sumL=0;
    for(int i=0;i<Nedge;i++)
      scanf("%d",&len[i]),
      sumL+=len[i], maxL=max(maxL,len[i]);
    if(sumL%Ngon){ puts("0");continue; }
    avgL=sumL/Ngon;
    if(maxL>avgL){ puts("0");continue; }
    memset(bucket,0,sizeof(bucket));
    sort(len,len+Nedge,compare);
    printf("%d\n",DFS(Ngon,Nedge,0));
  }
}
/*
3
4 5 1 3 3 4 5
4 8 2 5 6 7 1 4 4 3
4 8 1 7 2 6 4 4 3 9
*/