// 原題目來自於：BZOJ-3262 陌上花开
// 第一维排序，第二维分治，第三维树状数组
/* 那麼這道题在排序 a需要考虑 b,c，並且合併相同點，同时保證在分治時先修改再詢問，
 * 這樣就能轉化為嚴格不等。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000;
int maxz=0;
int BITz[MAXN+1]={};
struct NODE{
  int x,y,z,n,v;
  void Print(){ printf("%d %d %d",x,y,z); }
  bool equal(const NODE &rhs){ return x==rhs.x and y==rhs.y and z==rhs.z; }
  bool operator<(const NODE &rhs)const{
    if(rhs.x==x) return (y==rhs.y)?(z<rhs.z):(y<rhs.y);
    return x<rhs.x;
  }
}org[MAXN], cpy[MAXN];

inline int lowbit(int x){ return x&-x; }
inline int Update(int pos,int v){
  for(int i=pos;i<=maxz;i+=lowbit(i))
    BITz[i]+=v;
}
inline int Query(int pos,int out=0){
  for(int i=pos;i;i-=lowbit(i))
    out+=BITz[i];
  return out;
}
void CDQ(int nL,int nR){
  if(nL==nR) return;
  int nM=(nL+nR)>>1;
  CDQ(  nL,nM),
  CDQ(nM+1,nR);
  int i=nL, j=nM+1, k=nL, Qi;
  while(i<=nM and j<=nR)
    if(org[i].y<=org[j].y)
      Update(org[i].z,org[i].n),
      cpy[k++]=org[i++];
    else
      org[j].v+=Query(org[j].z),
      cpy[k++]=org[j++];
  for(Qi=i;i<=nM;) // 保留目前 i 的位置，還原BIT時會用到
    cpy[k++]=org[i++];
  while(j<=nR)
    org[j].v+=Query(org[j].z),
    cpy[k++]=org[j++];

  for(i=nL;i<Qi;i++)
    Update(org[i].z,-org[i].n);
  for(i=nL;i<=nR;i++)
    org[i]=cpy[i];
}
int main(){
  int N, tot;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    org[i].n=1,
    scanf("%d",&org[i].x),
    scanf("%d",&org[i].y),
    scanf("%d",&org[i].z),
    maxz=max(maxz,org[i].z);
  sort(org,org+N);
  // 合併重複的點
  tot=0;
  for(int i=1;i<N;i++)
    if(org[tot].equal(org[i])) org[tot].n++;
    else  org[++tot]=org[i];
  CDQ(0,tot);
  for(int i=0;i<=tot;i++)
    org[i].Print(), printf(" %d\n",org[i].v);
}
/*
10
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1
======
3 3 3 (9) 3
2 3 3 (6) 1
2 3 1 (2) 3
3 1 1 (0) 0
3 1 2 (2) 1
1 3 1 (1) 0
1 1 2 (0) 1
1 2 2 (2) 0
1 3 2 (4) 0
1 2 1 (0) 1
*/