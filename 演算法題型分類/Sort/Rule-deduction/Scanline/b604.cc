/* 給定Ｎ個二維座標的點(座標皆為整數)，輸出是否存在一個中心點，使得每個點都能和另外一個點湊成對？
 * 解題關鍵：掃描線概念＋排序
 * 由左而右掃描時，左下需要對應到右上，所以也得根據Ｙ座標小到大排序。
 * 中心點的位置(若存在)必定是最左下＋最右上的座標除以二，這邊處理時會有奇數的問題
 * 所以檢查時只算兩個點的總和，避免上述除以二的問題。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxV=1e7;
struct NODE{ 
	int x, y;
	NODE(int x=0,int y=0):x(x),y(y){}
}node[MaxN];
bool compare(NODE &a,NODE &b){ return (a.x==b.x)? a.y<b.y: a.x<b.x; }
 
int main(){
	int N, mx, my;
 
	while(scanf("%d",&N)!=EOF and N>0){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&node[i].x,&node[i].y);
		/* 依照掃描線排序 */
		sort(node,node+N,compare);
		/* 中心位置 */
		mx=node[0].x+node[N-1].x;
		my=node[0].y+node[N-1].y;
		bool check=true;
		for(int i=1;check and i<(N>>1);i++)
			check= (mx==node[i].x+node[N-1-i].x) and (my==node[i].y+node[N-1-i].y);
		puts(check?"yes":"no");
	}
}