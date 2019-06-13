// 題目要求港口內最多可以停幾艘船：最多括號配對問題 => DP解，做法類似區間合併(很少見的題型)
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1323403160
/* 對數據離散化, 時間點數量： nodeN = 2N,
 * 對於一個位置 DP[st][ed] (st, ed 是某一段起始時間與結束時間)
 * 因此我們求 DP[st][ed] 的最佳值會由4種可能值中取最大的
 * (1) DP[st+1][ ed ]
 * (2) DP[ st ][ed-1]
 * (3) max( DP[ st ][mid]＋DP[mid+1][ ed ]  )
 * (4) max( DP[st+1][mid]＋DP[mid+1][ed-1]+1)  <- 加上有一艘船在(st,ed)
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;
int N, nodeN;
int leav[MAXN];
int back[MAXN];
int node[MAXN<<1];
int DP[MAXN<<1][MAXN<<1];
bool has[MAXN<<1][MAXN<<1];

int main(){

  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d %d",&back[i],&leav[i]),
      node[ i ]=back[i],
      node[i+N]=leav[i];
    // 離散化所有的時間點
    sort(node,node+(N<<1));
    nodeN=unique(node,node+(N<<1))-node;
    //
    memset(DP,0,sizeof(DP));
    memset(has,0,sizeof(has));
    int back_pos, leav_pos;
    for(int i=0;i<N;i++)
      back_pos=lower_bound(node,node+nodeN,back[i])-node,
      leav_pos=lower_bound(node,node+nodeN,leav[i])-node,
      has[ back_pos ][ leav_pos ]=1;

    int ans=0;
    for(int len=1;len<nodeN;len++)
      for(int st=0,ed=st+len;ed<nodeN;st++,ed++){
        DP[st][ed]=max(DP[st+1][ed],DP[st][ed-1]);
        for(int mid=st;mid<ed;mid++)
            DP[st][ed]=max(DP[st][ed],DP[ st ][mid]+DP[mid+1][ ed ]),
            DP[st][ed]=max(DP[st][ed],DP[st+1][mid]+DP[mid+1][ed-1]+has[st][ed]);
        ans=max(ans,DP[st][ed]);
      }
    printf("%d\n",ans);
  }
}
/*
4
1 10
2 5
3 7
6 9
3
10 12
10 15
13 17
2
1 10
10 12
*/