/* 給定長度Ｎ，將１-Ｎ的每個號碼都出現一次的排列依照字典序大到小輸出？
 * 解題關鍵：枚舉法，數字大的優先處理
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=8;
int N;
int bag[MaxN];
bool use[MaxN+1]={};
void Enumerate(int depth){
  if(depth==N){
  	for(int i=0;i<depth;i++)
  		printf("%d",bag[i]);
  	putchar('\n');
  	return; 
  }
  for(int i=N;i>0;i--)
    if(use[i]==0){
      use[i]=1;
      bag[depth]=i;
      Enumerate(depth+1);
      use[i]=0;
    }
}
int main(){
	while(scanf("%d\n",&N)!=EOF)
		Enumerate(0);
}