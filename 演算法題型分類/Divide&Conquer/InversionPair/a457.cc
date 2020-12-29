/* 給定兩列Ｍ個數字的數列，輸出有幾組符合條件的數對？
 * 條件：任選兩個位置(ＡＢ且Ａ<Ｂ)上列關係為小於且下列關係為大於 或者 上列關係為大於且下列關係為小於
 * 解題關鍵：上述的兩項條件可以透過『排序』後視為相同的關係
 * 排序規則：(1)若目前關係為 上列關係為小於且下列關係為大於 時交換ＡＢ位置則關係為 上列關係為大於且下列關係為小於
 *            維護上側數列為遞增時，找出下側數列的逆數對
 *         (2)數值可能重複，若上側數列的數對關係為相等時應該不列入計算，
 *            所以當上側數列數值相等時需同時將下側數列由小到大(消去逆數對)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int K, M;
struct PAIR{
  int x,y;
  bool operator<(const PAIR &rhs)const{ return(x==rhs.x)?(y>rhs.y):(x>rhs.x); }
}org[MaxN], cpy[MaxN];

long CDQ(int nL,int nR,long res=0){
  if(nL>=nR) return 0;
  // Divide 確保兩個子序列都維持單調棧
  int nM=(nL+nR)>>1;
  res+=CDQ(  nL,nM);
  res+=CDQ(nM+1,nR);
  // 合併兩個子序列，累計逆數對
  for(int i=nL,j=nM+1,k=nL;i<=nM or j<=nR; )
    if(j>nR or i<=nM and org[i].y>=org[j].y )
      cpy[k++]=org[i++];
    else
      cpy[k++]=org[j++],
      res+=nM-i+1;
  for(int i=nL;i<=nR;i++)
    org[i]=cpy[i];
  return res;
}

int main(){
  // 讀取輸入
  scanf("%d %d",&K,&M);
  for(int i=0;i<K;i++)
    scanf("%d",&org[i].x);
  for(int i=0;i<K;i++)
    scanf("%d",&org[i].y);
  // 排序，保證第一維度是由大到小(若第一維度相同時第二維度由大到小)
  sort(org,org+K);
  printf("%ld\n",CDQ(0,K-1));
}

int main(){
	for(int N, M;scanf("%d %d\n",&N,&M)!=EOF;){
		for(int i=0;i<N;i++)
			scanf("%d",&data[i][0]);
		for(int i=0;i<N;i++)
			scanf("%d",&data[i][1]),
			ord[i]=i;
		sort(ord,ord+N,compare);
		for(int i=0;i<N;i++)
			ord[i]=data[ord[i]][1];
		ans=0;
		MergeSort(0,N-1);
		printf("%ld\n",ans);
	}
}