/* 本題需要加速讀取，讀取格式約略不同
 * 核心作法只需要簡單排序(由大到小)即可
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e4;
int money[MAXN];
inline bool scanInt(int &x){
  char c=getchar();
  bool sign=c=='-';
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
bool compare(int a,int b){ return a>b; }
int main(){
  for(int N,num; scanInt(N); ){
    for(num=0;scanInt(money[num]) and money[num]>=0;num++);
    sort(money,money+num,compare);
    int sumM=0;
    for(int i=0;i<min(num,N);i++)
      sumM+=money[i];
    printf("%d\n",sumM);
  }
}