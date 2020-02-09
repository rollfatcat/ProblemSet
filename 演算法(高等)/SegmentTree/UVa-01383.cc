/* 解題難度極高(★★★★☆)
 * 將取模後最小值查詢轉化為各個區間查詢(區間長度即是模數)
 * 且需要定義 threshold ，避免區間過小時有太多區間需要查詢造成TLE
 * 結果：映射線段樹版本實作(0.32s) 對照 zkw線段樹(0.18s)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5;
const int INF=1<<30;
const int threshold=5e3;
int qL,qR;
int MAP[MAXN+2];
int pos[MAXN+2];
int seg[MAXN<<2];
vector<int> num;

void BuildTree(int nL,int nR,int pt){
  seg[pt]=INF;
  if(nL==nR){ MAP[nL]=pt;  return; }
  int mid=(nL+nR)>>1;
  BuildTree(   nL,mid,  pt<<1);
  BuildTree(mid+1, nR,pt<<1|1);
}
void UpdateNode(int qN){ // ---單點更新---
  num.push_back(qN);
  pos[qN]=num.size();
  int node_pt=MAP[qN];
  if(seg[node_pt]==INF){
    seg[node_pt]=qN;
    for(int i=node_pt; i>1; i>>=1)
      seg[i>>1]=min(seg[i],seg[i^1]);
  }
}
int LinearSearch(int qN){ // ---當查詢間距太小時做線性搜尋---
  int now_num=num.back()%qN,
      now_idx=num.size();
  for(int i=num.size()-2; i>=0;i--){
    int tmp_num=num[i]%qN;
    if(tmp_num<now_num)
      now_num=tmp_num,
      now_idx=i+1;
    if(now_num==0)
      return now_idx;
  }
  return now_idx;
}
int Query_part(int nL,int nR,int pt){
  if(qL<=nL and nR<=qR) return seg[pt];
  int mid=(nL+nR)>>1, Lson=pt<<1;
  if(qR<=mid) return Query_part(nL,mid,Lson);
  if(qL>mid ) return Query_part(mid+1,nR,Lson|1);
  return min( Query_part(nL,mid,Lson), Query_part(mid+1,nR,Lson|1));
}
int main(){
  for(int Q,caseN=0; scanf("%d",&Q) and Q;){
    if(caseN++) puts("");
    printf("Case %d:\n",caseN);
    // ---建樹---
    BuildTree(1,MAXN,1);
    num.clear();
    memset(pos,0,sizeof(pos));
    // ---依照指令操作---
    int qN;
    for(char cmd[5];Q--;){
      scanf("%s %d",cmd,&qN);
      if(cmd[0]=='B')
        UpdateNode(qN);
      else{
        if(num.empty()) puts("-1");
        else if(qN<=threshold) printf("%d\n",LinearSearch(qN));
        else{
          // ---當查詢間距較大時做線段樹搜尋---
          qL=1, qR=qN-1;
          int ans_num=Query_part(1,MAXN,1),
              ans_cmp=ans_num;
          for(int i=qN; i<=MAXN; i+=qN){
            qL=i, qR=min(qL+qN-1,MAXN);
            int tmp_num=Query_part(1,MAXN,1),
                tmp_cmp=tmp_num%qN;
            if(tmp_num==INF) continue;
            if(tmp_cmp<ans_cmp or (tmp_cmp==ans_cmp and pos[ans_num]<pos[tmp_num]))
              ans_num=tmp_num, ans_cmp=tmp_cmp;
          }
          printf("%d\n",pos[ans_num]);
        }
      }
    }
  }
}
/*
5
B 1
A 5
B 10
A 5
A 40
2
B 1
A 2
10
B 500000
B 400000
B 300000
A 499999
B 500000
A 499999
0
*/