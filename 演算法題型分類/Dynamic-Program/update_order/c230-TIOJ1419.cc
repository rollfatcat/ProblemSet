/* 動態規劃的概念解題
 * 使用距離原點的距離由近到遠排序，使用 nL 紀錄由近到遠的最大高度，
 * nR 紀錄由遠到近的最小高度，比較nL[i]與nR[i]相減的最大值就是結果。
 */
#include<bits/stdc++.h>
using namespace std;
#define SQU(x) (x*x)
#define MAXN 100001

struct NODE{
  int x, y, h, r;
  bool operator<(const NODE &rhs)const{ return r<rhs.r; }
} tree[MAXN];
int nL[100001];
int nR[100001];

int main (){
  int N, x, y, h;
  while(scanf("%d",&N)!=EOF){
  	for(int i=0;i<N;i++)
  	  scanf("%d",&tree[i].x),
  	  scanf("%d",&tree[i].y),
  	  scanf("%d",&tree[i].h),
	    tree[i].r=SQU(tree[i].x)+SQU(tree[i].y); //題目保證 1 ≤ x,y ≤ 10000 => 1 ≤ r ≤ 10000,0000
    sort(tree,tree+N);
    // nL[i]：從起點到達第i棵樹的最大高度
    nL[0]=tree[0].h;
    for(int i=1;i<N;i++)
      nL[i]=( nL[i-1]>tree[i-1].h )? nL[i-1]: tree[i-1].h;
    // nR[i]：從終點到達第i棵樹的最小高度
    nR[N-1]=tree[N-1].h;
    for(int i=N-2;i>=0;i--)
      nR[i]=( nR[i+1]<tree[i].h )? nR[i+1]: tree[i].h;
    int maxH=0;
    for(int i=0;i<N-1;i++)
      maxH=max(maxH,nL[i]-nR[i]);
    printf("%d\n",maxH);
  }
}