/* 輸出出第Ｎ項的費波那契字串的第Ｌ個字元到第Ｒ個字元(包含Ｌ、Ｒ)？
 * 字串組成：F(Ｎ)＝F(Ｎ-2)+F(Ｎ-1), F(０)＝"０",F(１)＝"１"
 * 解題關鍵：Divide & Conquer( Recursion )＋tabulation
 * 題目盲點：第Ｎ項可能極大，但是(Ｌ、Ｒ)的範圍仍舊不超過 INT_MAX( 只需要考慮Ｎ=47以內的部分 )
 *         當Ｎ超過 46 時只需考慮奇偶數(even → 46 odd → 47)，因為這會影響到"起點的字元"。
 * 需要對前 47 項的費波那契字串長度建表，方便判斷遞迴時要用到的「切點」。
 * 建表時的長度區間表示方式為左閉右開(不包含右邊界)而查詢區間的右邊界需要印出來，所以右邊界要加一
 * 遞迴實作：處理 F(Ｎ) 時考慮查詢區間和 F(Ｎ-2) 的長度 
 *         (1) 區間全部落在 F(N-2)，遞迴處理時可以將問題範圍限縮為 N-2 
 *         (2) 區間全部落在 F(N-1)，遞迴處理時可以將查詢區間可以「平移」到問題範圍的 N-1 
 *         (3) 橫跨 F(N-2) 和 F(N-1)，將查詢區間拆為兩個部分 且 上述兩個都執行
 * 停止條件：當區間的長度＝1時根據當下問題的Ｎ決定輸出字元
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=100;
const int MaxN=INT_MAX;
const int MaxqR=INT_MAX;
const int MaxL=1e4;
vector<long> FIB={1,1};
void DCQ(long qL,long qR,int ID){
	if(ID<=1){ putchar( (ID)?'1':'0' );  return; }
	long qM=FIB[ID-2];
	if(qL<qM) DCQ(qL,min(qR,qM),ID-2);
	if(qM<qR) DCQ(max((long)0,qL-qM),qR-qM,ID-1);
}
int main(){
	for(int i=2;FIB.back()<=INT_MAX;i++)
		FIB.push_back( FIB[i-1]+FIB[i-2] );
		
	int caseT, N;
	long qL, qR;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %ld %ld\n",&N,&qL,&qR); qR+=1;
		DCQ(qL,qR,min(N,46+(N&1)));
		putchar('\n');
	}
}