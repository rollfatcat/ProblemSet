/* 給定可以提升等級的魔塵( 除以1000就是能夠提升的等級 ) 和 Ｎ隻寵物的CP和IV
 * 輸出 CP值最高的寵物和他的ID( 保證唯一 )
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=50;
const int MaxS=1e5;
const int MaxCP=1e6;
const int MaxIV=45;
inline int LevelUp(int IV){return (IV<=29)? 10: (IV<=39)? 50: 100;}
int main(){
	int N, S, CP, IV, maxCP, maxID;
	while(scanf("%d %d\n",&N,&S)!=EOF){
		S/=1000; // Ｓ最多可以提升的等級
		maxID=maxCP=0;
		for(int ID=1;ID<=N;ID++){
			scanf("%d %d\n",&CP,&IV);
			CP+=LevelUp(IV)*S;
			if(maxCP<CP)
				maxID=ID, maxCP=CP;
		}
		printf("%d %d\n",maxID,maxCP);
	}
}
