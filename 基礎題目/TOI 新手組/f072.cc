/* 給定Ｎ個(Ｎ≤25)１維地圖，格子為０＝空地,１＝柵欄,９＝害蟲
 * 植物只能種植在柵欄框圍起來的空地但相鄰的兩格都不能存在害蟲，輸出可以種植的空地數量？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=25;
int  type[MaxN+2]; // 避免處理邊界，所以左右各多１格
bool safe[MaxN+2];
int main(){
	int N, st, ed;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=1;i<=N;i++)
			scanf("%d ",&type[i]);
		fill(safe+1,safe+N+1,1);
		for(int i=1;i<=N;i++){
			if(type[i]) safe[i]=0;
			if(type[i]==9) safe[i-1]=safe[i+1]=0;
		}
		// 找到第０個和最後一個柵欄，並計算這當中所有狀態是１的格子
		for(st=1;st<=N and type[st]!=1;st++);
		for(ed=N;ed>=1 and type[ed]!=1;ed--);
		int ans=0;
		for(int i=st+1;i<ed;i++)
			ans+=safe[i];
		printf("%d\n",ans);
	}
}
