/* 給定Ｎ代表某個階乘的質因數的個數前綴和，若該階乘存在則輸出數字否則輸出"Not possible."
 * 解題關鍵：sieve＋質因數分解＋前綴和＋二分搜尋法
 * 問題點：題目給的Ｎ並非代表質因數前綴和的涵蓋的範圍，需確保能判斷 1e7+1 範圍內的質數(假設每個數都質數時)。
 * 基於上述要求建表的質數範圍為 sqrt(1e7+1)，建表後從２開始枚舉做質因數分解。
 * 因為階乘的特性質因數個數就是前綴和：fac(N!)=fac(N)+fac( (N-1)! )
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7+1;
const int SqrN=sqrt(MaxN);

bool NotP[SqrN+1]={};
vector<int> prime={2};
 
int main(){
  /* Sieve：建表的質數範圍為 sqrt(1e7+1) */
  for(int i=4;i<=SqrN;i+=2)
  	NotP[i]=1;
  for(int i=3;i<=sqrt(SqrN);i+=2)
  	if(NotP[i]==0)
  		for(int j=3;i*j<=SqrN;j+=2)
  			NotP[i*j]=1;
  for(int i=3;i<=SqrN;i+=2)
  	if(NotP[i]==0)
  		prime.push_back(i);
  /* 枚舉每個數字做質因數分解，累加質因數的個數做前綴和直到個數總和超過題目要求 */
  vector<int> num={0,0};
  for(int number=2; num.back()<=MaxN; number++){
  	int v=number;
  	int cnt=0;
  	for(int i=0;i<prime.size() and prime[i]*prime[i]<=v;i++)
  		while(v%prime[i]==0)
  			v/=prime[i], cnt++;
  	cnt+= v>1;
  	num.push_back(num.back()+cnt);
  }
  /* main */ 
  int N, tag;
  for(int caseI=1; scanf("%d",&N) and N>=0;caseI++){
  	tag=lower_bound(num.begin(),num.end(),N)-num.begin();
  	printf("Case %d: ",caseI);
  	(num[tag]!=N)? puts("Not possible."): printf("%d!\n",tag);
  }
}