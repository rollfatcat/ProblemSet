// 等同：HDU-3303 / POJ-3145，題解：http://morris821028.github.io/2014/10/23/oj/uva/uva-1383/
/* 題意
 * B X：加入一個數字 X 於陣列尾端
 * A Y：找到序列中 mod Y 的最小值的數字 X 位置，如果有相同的，取最後加入的數字位置。
 * 測資範圍：1≤ X,Y ≤5e5 , Q1 ≤ 4e4
 * 想法(難點：如何意識到取模=區間查詢，且當區間極小時不如線性搜尋)
 * 每一次查詢區間 [1,Y-1]、[Y,2Y-1]、[2Y,3Y-1] … 的最小值
 * SegmentTree版本是 0.32s，但 zkw是 0.18s
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5;
const int threshold=5e3; // <- Morris測試後的結果
const int INF=0x7f7f7f7f;
const int M=1<<(__lg(MAXN)+1);
int zkw[MAXN<<2];
int pos[MAXN+2];
vector<int> BX;

inline bool scanInt(int &x){char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int LinearSearch(int qN){
  int now_num=BX.back()%qN,
      now_idx=BX.size();
  for(int i=BX.size()-2; i>=0;i--){
    int tmp_num=BX[i]%qN;
    if(tmp_num<now_num)
      now_num=tmp_num,
      now_idx=i+1;
    if(now_num==0)
      return now_idx;
  }
  return now_idx;
}
int Query_RangeMin(int qL,int qR,int ans=INF){
  for(qL+=M-1,qR+=M+1; qL^qR^1; qL>>=1,qR>>=1){
    if(~qL&1) ans=min(ans, zkw[qL^1]);
    if( qR&1) ans=min(ans, zkw[qR^1]);
  }
  return ans;
}
int main(){
  for(int caseN=0,Q; scanInt(Q) and Q; ){
    if(caseN++) puts("");
    printf("Case %d:\n",caseN);
    // ---初始化---
    BX.clear();
    memset(pos,0xff,sizeof(pos));
    memset(zkw,0x7f,sizeof(zkw));

    // ---依照指令操作---
    for(int qN;Q--;){
      char cmd=getchar();
      getchar(), scanInt(qN);
      // ---查詢取模後的最小值---
      if(cmd=='A'){
        if(BX.empty())  puts("-1");
        // ---根據 threshold 決定搜尋方式---
        else if(qN<=threshold)  // ---當查詢間距太小時做線性搜尋---
          printf("%d\n",LinearSearch(qN));
        else{ // ---當查詢間距較大時做線段樹搜尋---
          int ans_num=Query_RangeMin(1,qN-1),
              ans_cmp=ans_num;
          for(int i=qN; i<=MAXN; i+=qN){
            int tmp_num=Query_RangeMin(i,min(i+qN-1,MAXN)),
                tmp_cmp=tmp_num%qN;
            if(tmp_num==INF) continue;
            if(tmp_cmp<ans_cmp or (tmp_cmp==ans_cmp and pos[ans_num]<pos[tmp_num]))
              ans_num=tmp_num, ans_cmp=tmp_cmp;
          }
          printf("%d\n",pos[ans_num]);
        }
      }//加到陣列尾端，維護樹組
      else{
        BX.push_back(qN);
        pos[qN]=BX.size();
        // ---更新數組:只有當數字『剛加入』時才需要維護數組---
        int leaf=M+qN, now;
        if(zkw[leaf]==INF)
          for(zkw[leaf]=qN,now=leaf; now>1; now>>=1)
            zkw[now>>1]=min(zkw[now],zkw[now^1]);
      }
    }
  }
}
/*
10
B 500000
B 400000
B 300000
A 499999
B 500000
A 499999
*/