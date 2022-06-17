/* 給定範圍Ｒ和Ｎ個點的二維座標，輸出有多少組合是可以彼此連結到的感應器？
 * 感應器的偵測範圍為「正方形」
 * 解題關鍵：掃描線(排序)＋離散化＋RMQ(單點更新＋區間查詢＝BIT實作)
 * 掃描線，依照Ｘ座標由小到大排序(更新順序)
 * RMQ(BIT實作)：維護(離散化)Ｙ座標的點數。
 *          依序枚舉每個點(Ｘ,Ｙ)，移除目前BIT紀錄的點數中屬於(Ｘ＋Ｒ<Ｙ)的點，
 *          查詢[ (離散化的)Ｙ-Ｒ,(離散化的)Ｙ+Ｒ ]範圍內的點數(區間和)，並加入這個點(離散化的)Ｙ。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5+1;
struct NODE{
	int x, y;
	NODE(int d1=0,int d2=0):x(d1),y(d2){}
} node[MaxN];

int pool[MaxN];
int ord[MaxN];
int BIT[MaxN];

inline bool compare(NODE a,NODE b){ return a.x<b.x; }
inline int  lowbit(int x){ return x&-x; }
int main(){
	int N, uN;
	long R;
	while( scanf("%ld %d\n",&R,&N)!=EOF ){
		for(int i=1;i<=N;i++){
			scanf("%d %d\n",&node[i].x,&node[i].y);
			pool[i]=node[i].y;
		}
		/* 從低的開始更新 */
		sort(node+1,node+N+1,compare);
		/* 離散化 */
		sort(pool+1,pool+N+1);
		uN=unique(pool+1,pool+N+1)-pool;
		fill(BIT,BIT+uN,0);
		
		int ans_cnt=0;
		int tag, front=1;
		
		for(int back=1; back<=N; back++){
			tag=lower_bound(pool+1,pool+uN,node[back].y)-pool;
			for(ord[back]=tag; node[front].x+R<node[back].x; front++)
				for(int p=ord[front]; p<uN; BIT[p]-=1, p+=lowbit(p));
			int ths_v=0;
			for(int qL=lower_bound(pool,pool+uN,node[back].y-R)-pool-1; qL>0;qL-=lowbit(qL))
				ths_v-=BIT[qL];
			for(int qR=upper_bound(pool,pool+uN,node[back].y+R)-pool-1; qR>0;qR-=lowbit(qR))
				ths_v+=BIT[qR];
			ans_cnt+=ths_v;
			for(int p=tag; p<uN; BIT[p]+=1, p+=lowbit(p));
		}
		
		printf("%d\n",ans_cnt);
	}
}

