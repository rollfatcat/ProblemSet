/* 植物會依照「規則」的成長， 輸出在第Ｎ天時最高層由左邊數來第Ｋ個分枝的顏色？
 * 種子落地後的第一天會先長出一根長一公分的綠色分枝。
 * 綠色的分枝每經過一天的時間，會向上成長一公分，並且變成黃色。
 * 黃色的分枝每經過一天的時間，會向上成長一公分，並且分成左右兩個分枝，其中左分枝為綠色，右分枝為黃色。
 * 所有的分枝都不會互相交錯，同時恰好成長在同一個平面上。
 * 若我們由左而右俯視觀察此海藻最高層每天的生長情形：
 *    第一天『綠』，第二天『黃』，第三天『綠黃』，第四天『黃綠黃』， 第五天『綠黃黃綠黃』，依此類推。
 * 解題關鍵：Divide & Conquer( Recursion )
 * 問題盲點：樹枝的樹枝的生長情形為「費波那契式」，不可能產生前 100 天的所有情況 ... 遞迴推導
 *         Ｋ最大不超過 2e9 ，所以 Ｍ 超過 47 時只需考慮奇偶數(even → 46 odd → 47)，因為這會影響到"起點的字元"。
 * 需要對前 47 項的費波那契字串長度建表，方便判斷遞迴時要用到的「切點」。
 * 「費波那契式」規律：F(Ｎ)=Ｆ(N-2)+Ｆ(N-1), F(1)=0, F(2)=1
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=100;
const int MaxM=100;
const int MaxK=2e9;
vector<long> FIB={0,1};
int DCQ(int qv,int ID){
	return (ID<=2)? ID-1: (qv<FIB[ID-2])? DCQ(qv,ID-2):DCQ(qv-FIB[ID-2],ID-1);
}
int main(){
	for(int i=2;FIB.back()<=MaxK;i++)
		FIB.push_back( FIB[i-1]+FIB[i-2] );
		
	int caseT, N, qv;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&qv);
		printf("%d\n",(qv<=FIB[N])? DCQ(qv-1,min(N,47+(N&1))): -1);
	}
}