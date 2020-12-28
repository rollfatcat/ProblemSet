/* 給定Ｎ個二維平面上的點座標，從中任選兩點和平面上某點形成最短距離(曼哈頓距離)的點座標？
 * 解題關鍵：Sweep Line - Closest Pair
 * 題目的要求的點必定落在形成最短距離點對的連線上(以下做法是輸出中點)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=10;
const int MaxN=1e4;
struct NODE{
	int x, y;
	NODE(int x=0,int y=0):x(x),y(y){}
	bool operator<(const NODE &rhs)const{ return x<rhs.x; }
} node[MaxN], ans;
inline int dis(int dx,int dy){ return abs(dx)+abs(dy); }
 
int CDQ(int L,int R,int& minD){
	if(L==R) return INT_MAX;
	int M=L+R>>1;
	minD=min(minD,CDQ(  L,M,minD));
	minD=min(minD,CDQ(M+1,R,minD));
	for(int i=M;i>=L and (node[M+1].x-node[i].x)<minD;i-=1)
		for(int j=M+1;j<=R and (node[j].x-node[i].x)<minD;j+=1)
			if(dis(node[j].x-node[i].x,node[j].y-node[i].y)<=minD)
				minD=dis(node[j].x-node[i].x,node[j].y-node[i].y),
				ans=NODE(node[j].x+node[i].x,node[j].y+node[i].y);
	return minD;
}
 
int main(){
	int caseT, N, minD;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&node[i].x,&node[i].y);
		sort(node,node+N);
		minD=INT_MAX;
		CDQ(0,N-1,minD);
		printf("%.3lf %.3lf\n",ans.x/2.0,ans.y/2.0);
		if(caseT) putchar('\n');
	}
}