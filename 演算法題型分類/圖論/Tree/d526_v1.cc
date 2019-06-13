// 二分樹的建樹概念：左子樹所有的數比現在節點都小，右子樹所有的數比現在節點都大
// PreOrder = 中左右
// 以下寫法是指標版本，由於指標會儲存記憶體位址，所以空間上消耗大的許多
#include<bits/stdc++.h>
using namespace std;

struct node{ int num; node *l,*r; } root;
void PreOrder(node *now){
  printf("%d ",now->num);
  if(now->l!=NULL)  PreOrder(now->l);
  if(now->r!=NULL)  PreOrder(now->r);
}
int main(){

  for(int N; scanf("%d",&N)!=EOF; ){
    // new Root，左右節點的號碼預設是-1
    scanf("%d",&root.num),
    root.l=root.r=NULL;

    for(int i=1;i<N;i++){
      node *newNode=new node;
      scanf("%d",&newNode->num),
      newNode->l=newNode->r=NULL;
      node *now, *nxt;
      for(nxt=&root; nxt!=NULL; )
        now=nxt,  nxt=(now->num < newNode->num)?nxt->r:nxt->l;
      (now->num < newNode->num)?(now->r=newNode):(now->l=newNode);
    }
    PreOrder(&root),
    puts("");
  }
}