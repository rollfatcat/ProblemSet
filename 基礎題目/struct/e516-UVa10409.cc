/* 模擬骰子的在三維空間中轉動的狀態(APCS 202007-PB)
 * 初始狀態：頂面=1,北面=2,西面=3, 給定『轉動方式』後輸出結果
 */
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int N; // MaxN=1024
	char opt[6]; // 指令只會是 east/ south/ west/ north
 
	while(scanf("%d\n",&N) and N){
		int tmp, nowS[3]={1,2,3}; //初始狀態：頂面=1,北面=2,西面=3
		for(int i=1;i<=N;i++){
			scanf("%s\n",opt);
			switch(opt[0]){
				case 'e': // 西面變成頂面, 頂面變成東面
					swap(nowS[0],nowS[2]);
					nowS[2]=7-nowS[2];
					break;
				case 's': // 北面變成頂面, 頂面變成南面
					swap(nowS[0],nowS[1]);
					nowS[1]=7-nowS[1];
					break;
				case 'n': // 北面變成底面, 頂面變成北面
					swap(nowS[0],nowS[1]);
					nowS[0]=7-nowS[0];
					break;
				default: // 東面變成頂面, 頂面變成西面
					swap(nowS[0],nowS[2]);
					nowS[0]=7-nowS[0];    
			}
		}
		printf("%d\n",nowS[0]);
	}
}
