/* 給定Ｎ×Ｎ地圖、ＹＢＲ三原色的起始座標，輸出指定顏色在「擴散」過程中某個時間點最多的格子數？
 * 擴散方式：每秒向周圍８個方向往外一格染色，同一格受到不同顏色渲染時顏色會疊加(疊加原理採三元色)。
 * 解題關鍵：BFS＋BitMask(混色＝位元運算)
 * BitMask : Ｙ=1/Ｂ=2/Ｒ=4，染色＝不同的狀態取 OR，判斷是否具有該顏色時則取 XOR 
 * BFS : 模擬墨水擴散的過程(但實際不需要，環狀擴散的座標和時間呈正相關且不存在障礙物)
 */
#include<bits/stdc++.h>
using namespace std;

// constrain
const int MaxN=1e2;
int dict[128]={};
int seen[MaxN][MaxN]={};
int dr[8]={-1,-1,-1, 0, 0, 1, 1, 1};
int dc[8]={-1, 0, 1,-1, 1,-1, 0, 1};

int main(){
	dict['R']=1; dict['Y']=2; dict['B']=4;
	dict['O']=3; dict['P']=5; dict['G']=6;
	dict['D']=7;
	
	int N, r, c;
	int cnt[8]={};
	char tag;
	deque<vector<int>> Q;
	
	scanf("%d\n",&N);
	for(int i=0; i<3;i+=1){
		scanf("%c %d %d\n",&tag,&r,&c);
		seen[r][c]=dict[tag];
		cnt[ dict[tag] ]+=1;
		Q.push_back( {dict[tag],r,c,0} );
	}
	scanf("%c\n",&tag);
	int tag_c=dict[tag];
	int nowT=0;
	int ans=cnt[ tag_c ];
	while(Q.empty()==0){
		vector<int> now=Q.front(); Q.pop_front();
		if(nowT<now[3]){
			ans=max(ans,cnt[tag_c]);
			nowT=now[3];
		}
		for(int t=0;t<8;t+=1){
			r=now[1]+dr[t];
			c=now[2]+dc[t];
			if(r==-1 or r==N or c==-1 or c==N) continue;
			if( seen[r][c]&now[0] ) continue;
			cnt[ seen[r][c] ]-=1;
			seen[r][c]|= now[0];
			cnt[ seen[r][c] ]+=1;
			Q.push_back({now[0],r,c,now[3]+1});
		}
	}
	printf("%d\n",ans);
}
