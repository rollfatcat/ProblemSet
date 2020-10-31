/* 給定Ｍ代表要覆蓋的範圍[0,M]，之後給定左右端點代表線段(當左右端點＝０時輸入結束)，輸出最少需要用到的線段？
 * 解題關鍵：排序＋掃描線
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=5e3;
const int MaxN=1e5;
struct LINE{
	int st, ed;
	LINE(int s=0,int e=0):st(s),ed(e){}
} line[MaxN];
int memo[MaxN];

bool compare(LINE a,LINE b){ return a.st<b.st; }
int main(){
	int caseT, M, S, E, uN;
	
	scanf("%d\n",&caseT);
	while(caseT-->0){
		/* 只紀錄和「覆蓋範圍重疊」的線段，並依據起點排序。
		 * 重疊的定義：終點大於０且起點小於等於Ｍ
		 */
		scanf("%d\n",&M);
		int N=0;
		while(scanf("%d %d\n",&S,&E) and (S or E))
			if(0<E and S<=M)
				line[N++]=LINE(S,E);
		sort(line,line+N,compare);
		
		/* E=目前的界線  ，初始化是０代表找到的線段必定經過該界線＝覆蓋到０這個點。
		 * S=下一段的界線，萬一不存在最小起點能覆蓋到０的線段。
		 * Greedy：
		 * 		從「起點落在目前界線左側(包含重疊)」的線段中能夠找到最遠的右端點，代表可以覆蓋的最遠範圍。
		 * 		若目前線段的起點「超過目前界線」代表上述的搜尋狀態結束需要更新目前的界線(將目前界線移動到下一段界線)。
		 * 		注意因為界線更新所以這個線段需要重新判斷：
		 * 			若目前線段起點落在新界線右側＝覆蓋失敗，提早結束過程。
		 * 			若目前線段起點落在新界線左側＝需要紀錄的線段編號假設為-1並重新考量該線段。
		 */
		uN=S=E=0;
		memo[0]=-1;
		for(int i=0; i<N and E<M; i++){
			if(line[i].st<=E){
				if(S<line[i].ed){
					S=line[i].ed;
					memo[uN]=i;
				}
			}else{
				E=S;
				if(E<line[i].st)
					break;
				memo[++uN]=-1;
				i--;
			}
			//printf("%d %d %d %d\n",line[i].st,line[i].ed,E,S);
		}
		/* 需要確認最後一次的最遠邊界有沒有更新，編號!=-1時代表最遠邊界被更新，答案的線段數+1 */
		uN+= memo[uN]>=0 ;
		/* 若提早跳開：記錄到的最後一個線段右端點會無法覆蓋到Ｍ */
		if( line[memo[uN-1]].ed<M )
			puts("0");
		else{
			printf("%d\n",uN);
			for(int i=0;i<uN;i++)
				printf("%d %d\n",line[memo[i]].st,line[memo[i]].ed);
		}
		/* 測資間輸出一個換行 */
		if(caseT) putchar('\n');
	}
}

