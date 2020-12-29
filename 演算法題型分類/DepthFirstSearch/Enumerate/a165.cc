/* 請找出一個９位數的 Magic number，其各位數均不相等且由1~9組成，輸出這個魔術數字？
 * 這個九位數滿足：前１位被1整除，前２位被2整除，前３位被3整除.... 前９位被9整除
 * 解題關鍵：BackTrace
 */
#include<bits/stdc++.h>
using namespace std;

int N;
bool use[10]={1};
void Enumerate(int num,int depth){
  if(depth==10){ N=num; return; }
  for(int i=1;i<=9;i++)
    if(use[i]==0 and (10*num+i)%depth==0){
      use[i]=1;
      Enumerate(10*num+i,depth+1);
      use[i]=0;
    }
}
int main(){
  Enumerate(0,1);
  printf("%d\n",N);
}