// LinkList 實作，查詢某個數字存在的成本是O(N) => 照搬到 a175 70%(最後三筆測資會TLE)
// 練習指標和自定義struct的搭配用法，插入數字時需要考慮各種情況
#include<bits/stdc++.h>
using namespace std;

struct NODE{
  int tag;
  struct NODE *nxt;
}*HASH[200], *cur, *pre, *tmp;
int N, Q;

inline void Hash_Insert(int num,int Nmod){
  if(HASH[Nmod]==NULL){
    cur=(struct NODE *)malloc(sizeof(struct NODE)),
    cur->tag=num, cur->nxt=NULL;
    HASH[Nmod]=cur;
    return;
  }
  pre=NULL,
  cur=HASH[Nmod];
  while(cur->tag<=num){ // 前方存在節點，若數字已經存在則不插入
    if(cur->tag==num)  return;
    if(cur->nxt!=NULL) pre=cur,cur=cur->nxt; // 還存在節點且數值比現在的數還小
    else { // 找完整個序列後最大的數字仍比要插入的數字小，放在尾端
      tmp=(struct NODE *)malloc(sizeof(struct NODE));
      tmp->tag=num, tmp->nxt=NULL;
      cur->nxt=tmp;
      return;
    }
  }
  if(pre!=NULL){ // 前後兩個方向都存在節點
    tmp=(struct NODE *)malloc(sizeof(struct NODE));
    tmp->tag=num;
    pre->nxt=tmp,
    tmp->nxt=cur;
  }
  else{ // 後方存在節點：要插在第一個位置
    tmp=(struct NODE *)malloc(sizeof(struct NODE));
    tmp->tag=num;
    HASH[Nmod]=tmp,
    tmp->nxt=cur;
  }
  return;
}
inline void Hash_Delete(int num,int Nmod){
  pre=NULL,
  cur=HASH[Nmod];
  while(cur!=NULL){
    if(cur->tag<num)
      pre=cur,
      cur=cur->nxt;
    else if(cur->tag==num){
      (pre==NULL)? HASH[Nmod]=cur->nxt: pre->nxt=cur->nxt;
      free(cur);
      return;
    }
    else
      return;
  }
}
inline void Hash_Print(){
  puts("===== s =====");
  for(int i=0; i<N; i++){
    printf("[%03d]:",i);
    for(cur=HASH[i]; cur!=NULL; cur=cur->nxt)
      printf("%d -> ",cur->tag);
    puts("NULL");
  }
  puts("===== e =====");
}

int main(){
  while(scanf("%d%d",&Q,&N)!=EOF){
    // 初始化 HashTable
    for(int i=0; i<N; i++){
      for(pre=NULL,cur=HASH[i]; cur!=NULL; )
        pre=cur,
        cur=cur->nxt,
        free(pre);
      HASH[i]=NULL;
    }
    int opt, num;
    while(Q--){
      scanf("%d",&opt);
      if(opt==3)
        Hash_Print();
      else{
        scanf("%d",&num),
        (opt==1)? Hash_Insert(num,num%N) : Hash_Delete(num,num%N);
      }
    }
  }
}
/*
13 5
1 17
1 8
3
3
1 18
1 24
3
1 37
1 64
1 84
3
2 18
3
*/