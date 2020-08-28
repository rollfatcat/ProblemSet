/* 輸出第Ｎ個UglyNumber？
 * UglyNumber的定義：該數字的質因數只包含２、３、５
 * 解題關鍵：狀態展開
 * 從１開始展開，分支展開＝該數字乘以２、３、５形成，每次取分支當中數字最小的展開。
 * (1) 利用 PriorityQueue 將目前狀態(數值)最小值加入數列(UglyNumber)並展開。
 * (2) 因為數列是共通的，利用３個變數各自代表某次狀態展開後２、３、５的值從中取最小值作為下次加入數列的值
 *     因為２、３、５的間距和乘法的關係只需要判斷一次(不需要利用迴圈逼近)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int main(){
	/* preprocess */
	vector<long> num={1};
	int p2=0, p3=0, p5=0;
	while(num.size()<MaxN){
		p2+= 2*num[p2]<=num.back();
		p3+= 3*num[p3]<=num.back();
		p5+= 5*num[p5]<=num.back();
		num.push_back( min(min(2*num[p2],3*num[p3]),5*num[p5]) );
	}
	/* main */
	int caseT, N;
	scanf("%d\n",&caseT);
	while(caseT-->0)
		scanf("%d\n",&N),
		printf("%ld\n",num[N-1]);
}