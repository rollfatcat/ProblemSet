/* 給定Ｎ座城市的二維座標，問"中樞城市"需要設定在哪座城市才能確保抵達其他城市的距離最短？
 * 中樞城市可能存在多座，則依據Ｘ座標由小到大，再依據Ｙ座標小到大輸出並輸出最短的距離和。
 * 距離的定義(x1,y1)到(x2,y2)＝|x1-x2|+|y1-y2|(曼哈頓距離)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxV=5e5;
struct NODE{ int x,y; }node[MaxN];
inline bool compare(int a,int b){ 
	return (node[a].x==node[b].x)? node[a].y<node[b].y: node[a].x<node[b].x; }

int main(){
	
	for(int N,caseI=0;scanf("%d\n",&N)!=EOF;caseI++){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&node[i].x,&node[i].y);
		int minD=1<<30;
		vector<int> ord;
		for(int i=0;i<N;i++){
			int sumD=0;
			for(int j=0;j<N;j++)
				sumD+=abs(node[j].x-node[i].x)+abs(node[j].y-node[i].y);
			if(minD>sumD){  minD=sumD;ord.clear(); }
			if(minD==sumD){	ord.push_back(i);}
		}
		sort(ord.begin(),ord.end(),compare);
		for(int t:ord)
			printf("%d %d\n",node[t].x,node[t].y);
		printf("%d\n\n",minD);
	}
}