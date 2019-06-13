// 映射版本的 Link list 模擬 Queue 練習
// 不需要考慮非法操作(比如說Queue裡面沒東西時還要DEQUEUE)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1001;
int Gcnt[MAXN];
int IDGroup[1000000];

inline bool scanInt(int &x){
  char c;
  while((c=getchar())==' ' or c=='\n');
  for(x=c-'0';(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c!=EOF;
}
int main(){
  int Ngroup, N, NID;
  for(int caseN=1; scanInt(Ngroup); caseN++){
    memset(Gcnt,0,sizeof(Gcnt));
    memset(IDGroup,0xff,sizeof(IDGroup));
    for(int GID=0;GID<Ngroup;GID++)
      for(scanInt(N); N--;)
        scanInt(NID),
        IDGroup[NID]=GID;
    // ---根據指令模擬 Queue的操作---
    list<int> Q;  //建立list 模擬queue
    list<int>::iterator nowIt,Last_It[MAXN];//Last_It[]紀錄那個群組的最後一個位址
    printf("Line #%d\n",caseN);
    for(char ss[10]; scanf("%s",ss) and ss[0]!='S';){
      if(ss[0]=='E'){
        scanInt(N);
        NID=IDGroup[N];
        if(NID==-1) Q.push_back(N);
        else{
          if(Gcnt[NID]==0)
            Q.push_back(N),          // 那個組沒有加入list中，直接放在最後
            Last_It[NID]=(--Q.end());// 紀錄該組在list當中的記憶體位置
          else
            Last_It[NID]=Q.insert(++Last_It[NID],N); // 根據上次位址插入號碼後更新最後一個位址
          Gcnt[NID]++;
        }
      } else {
        nowIt=Q.begin();
        NID=IDGroup[*nowIt];
        if(NID>=0)  Gcnt[NID]--;
        printf("%d\n",*nowIt),
        Q.erase(nowIt);
      }
    }
  }
}
/*
2
3 1 2 3
4 4 5 6 7
ENQUEUE 1
ENQUEUE 4
ENQUEUE 3
ENQUEUE 2
ENQUEUE 8
ENQUEUE 6
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
3 10000 20000 30000
4 400000 500000 600000 700000
ENQUEUE 10000
ENQUEUE 400000
ENQUEUE 30000
DEQUEUE
DEQUEUE
ENQUEUE 700000
ENQUEUE 600000
ENQUEUE 500000
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
*/