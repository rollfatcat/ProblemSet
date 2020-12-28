// DFS 暴力法選數字，挑進來後判斷會不會跟前面的數字互質
// 根據Co-Prime的定義是最大公因數=1, 換句話說1可以重複出現但其他數字只會出現一次
#include<iostream>
using namespace std;

int S, T, last, bag[30];
bool isCoPrime[101][101];
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
bool AllCoPrime(int now, int num){
  int idx=0;
  for(;idx<now and isCoPrime[bag[idx]][num];idx++);
  return idx==now;
}
void DFS(int now,int st){
  if(now==last){
    if(st<=S and AllCoPrime(last,S)){
      for(int i=0;i<last;i++)
        printf("%d ",bag[i]);
      printf("%d\n",S);
    }
    return;
  }
  for(int i=st;i<=S;i++)
    if(AllCoPrime(now,i)){
      bag[now]=i;
      S-=i;
      DFS(now+1,i+1);
      S+=i;
    }
}

int main(){
  for(int i=1;i<=100;i++)
    for(int j=1;j<=i;j++)
      isCoPrime[i][j]=isCoPrime[j][i]=(GCD(i,j)==1);
  int caseT;
  while(scanf("%d",&caseT)!=EOF){
    for(int caseNum=1; caseNum<=caseT;caseNum++){
      scanf("%d %d",&S,&T);
      printf("Case %d:\n",caseNum);
      last=T-1;
      //因為1可以重複選仍符合Co-Prime定義所以額外處理, 之後從2開始選
      // SpecialCase : S==T, 都是1的情況
      if(S==T){
        for(int i=0;i<last;i++)
          printf("1 ");
        printf("1\n");
      }else
        for(int i=last;i>=0;i--){
          for(int j=0;j<i;j++)
            bag[j]=1;
          S-=i;
          DFS(i,2);
          S+=i;
        }
    }
  }
}