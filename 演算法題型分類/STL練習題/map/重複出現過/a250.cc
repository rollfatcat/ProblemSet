/* 題目要求輸出字典序最小的區間，該連續區間和必須可以被Ｋ整除
 * 某段連續區間和可以被Ｋ整除＝目前這段連續區間的模Ｋ的餘數『曾經出現過』
 * 利用 map<區間和的餘數,位置> 紀錄上述對應關係，仿效陣列實現查詢某個數字是否出現過
 * map的內部實作是紅黑數，查詢成本是㏒Ｎ，MAXN=1e5
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
const int INF=1<<30;
int num[MAXN];
char buff[1<<22];
int main(){
  int N, K, now_x;
  while(scanf("%d\n",&N) and N){
    // 利用 fgets() 實現加速讀取
    // Ｋ暫時拿來存放數字到正確的位置，初始化 now_x=sign=0
    K=now_x=0;
    bool sign=0;
    for(char *p=fgets(buff,sizeof(buff),stdin); *p!=0; ++p){
      if(*p==' ') num[K++]=(sign)? -now_x: now_x, sign=now_x=0;
      else if(*p=='-') sign=1;
      else if('0'<=*p and *p<='9') now_x=(now_x<<3)+(now_x<<1)+*p-'0';
    }
    num[K]=(sign)? -now_x: now_x;
    //
    scanf("%d",&K);

    map<int,int> memo;
    memo[0]=-1; // 預設memo存在0，意思是從取第一個數的連續區間和，對應的位置是-1
    pair<int,int> ans=make_pair(INF,INF); // 預設的答案是(INF,INF)
    long sum_x=0; // 避免計算過程出現溢位問題，宣告成long
    for(int i=0;i<N;i++){
      sum_x=(sum_x+num[i])%K;
      if(sum_x<0)  sum_x+=K;
      if(memo.find(sum_x)==memo.end())
        memo[sum_x]=i;
      else
        ans=min(ans,make_pair(memo[sum_x]+2,i+1));
    }
    (ans.first==INF)? puts("no solutions."): printf("%d %d\n",ans.first,ans.second);
  }
}