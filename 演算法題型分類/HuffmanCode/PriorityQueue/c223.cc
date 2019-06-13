#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000001;
char buf[1<<23]; // 輸入最多1e6個數字且每個數字不超過1e6
int num[MAXN]={};
int num_idx, N;
queue<long> Q;

inline long LeastNumber(){
  if(Q.empty() or num_idx<N and num[num_idx]<Q.front())
    return num[num_idx++];
  long rem=Q.front(); Q.pop();
  return rem;
}
int main(){
  int x;
  while(scanf("%d\n",&N)!=EOF and N){
    // init
    while(Q.empty()==0) Q.pop();
    // 利用 fgets() 只做一次IO 把整行的數字讀入以字元形式存到暫存區後
    num_idx=x=0;
    for(char *p=fgets(buf,sizeof(buf),stdin); *p!='\0'; p++){
      if(*p=='\n')
        num[num_idx++]=x,
        x=0;
      else
        x=(x<<3)+(x<<1)+*p-'0';
    }
    num[num_idx++]=x;

    // CountSort
    sort(num,num+N);
    num_idx=0;
    long sum=0, min_one, min_two;
    for(int t=1; t<N; t++){
      min_one=LeastNumber(),
      min_two=LeastNumber(),
      sum+=min_one+min_two;
      Q.push(min_one+min_two);
    }
    printf("%ld\n",sum);
  }
}