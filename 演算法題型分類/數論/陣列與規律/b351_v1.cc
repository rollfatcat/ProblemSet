/* 題目給定邊長Ｎ的矩陣和Ｒ、Ｃ的位置，輸出依據"規則填寫的陣列位置"數字是多少？
 * 規則：
 * 		數字１從第１個 Row 的中間位置開始填寫。
 * 		每次向"左上方"填入下個數字(若超過邊界時則從一側繼續)直到遇到格子填寫過。
 * 		若下個位置是填寫過的狀態則改由目前位置的下一格重複剛剛的流程。
 * 解題關鍵：根據填寫規則 和 邊長必定是奇數 推測規律。
 */
#include<bits/stdc++.h>
using namespace std;

int MaxCaseT=9;
int MaxN=4999;
int main(){
	int caseT, N, R, C;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d %d\n",&N,&R,&C);
		
		int hN=N>>1;
		int slash=R-C;
		if(slash> hN) slash-=N;
		if(slash<-hN) slash+=N;
		
		int cycle=slash+hN;
		int start_c=hN+1+cycle;
		if(start_c>N) start_c-=N;
		
		int step=(start_c<C)? start_c+N-C: start_c-C;
		printf("%d\n",1+cycle*N+step);
	}
}