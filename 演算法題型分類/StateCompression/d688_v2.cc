// 做法的核心思考不變，內部判斷找到一條邊，其中一個不存在集合中的點且另一個點存在集合中
// v1 是O(N^2)判斷，但加速版本利用狀態壓縮處理只需要O(N) => 86ms

#include<bits/stdc++.h>
using namespace std;

const int MAXN=20;
int Edge[MAXN]; // 代表有和這個點連結的其他點用壓縮狀態表示
bool status[1<<MAXN];

int main(){
  int Vnum, Enum;
  while(scanf("%d %d",&Vnum,&Enum) and Vnum){
    int maxs=(1<<Vnum)-1;
    for(int nows=0;nows<=maxs;nows++)// 避開用memset()，陣列空間過大
      status[nows]=0;
    for(int i=0;i<Vnum;i++)
      Edge[i]=0,       // 狀態還原
      status[1<<i]=1;  // 單點狀態設定為 1
    for(int a,b;Enum--;)
      scanf("%d %d",&a,&b), a--, b--,
      Edge[a]|=(1<<b),
      Edge[b]|=(1<<a);

    for(int nows=1;nows<=maxs;nows++) // 枚舉全部的狀態
      if( status[nows] )
        for(int NotIn,coms=nows^maxs; coms; coms^=(1<<NotIn)){// 現在狀態的互補數代表未存在集合中的所有點
          NotIn=__builtin_ctz(coms); // 回傳從後面數來0的個數
          if( nows&Edge[NotIn] ) // 枚舉每個未存在集合中的點，存在一條邊可以連到現在的集合中的點時，就能狀態轉移過去
            status[nows|(1<<NotIn)]=true;
        }
    int cnt=0;
    for(int i=0;i<=maxs;i++)
      cnt+=status[i];
    printf("%d\n",cnt);
  }
}