/* 動態規劃建表＋BackTrace 計算第Ｎ個 LunlunNumber
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
vector<int> sumL(1);
vector<vector<int>> allS(1);
int main(){
	// init
	vector<int> Start(10,1);
	allS.push_back(Start); 
	sumL.push_back(9);
	for(int preL=1;sumL.back()<=MaxN;preL++){
		sumL.push_back(sumL.back());
		vector<int> oneS(10);
		oneS[0]=allS[preL][0]+allS[preL][1];
		for(int D=1;D<9;D++)
			oneS[D]=allS[preL][D-1]+allS[preL][D]+allS[preL][D+1],
			sumL.back()+=oneS[D];
		oneS[9]=allS[preL][8]+allS[preL][9],
		sumL.back()+=oneS[9];
		allS.push_back(oneS);
	}
	/* BackTrace
	 * 先算出第Ｎ個 LunlunNmber 的長度：二分搜尋 sumL
	 * 計算第一個位數後下一個位數的範圍＝現在找到的數字-1開始找
	 * 因為 LunlunNmber 的定義是每個位數差值不超過1，但注意當現在位數的數字是０時則不-1
	 */
	for(int N;scanf("%d\n",&N)!=EOF;){
		int L=lower_bound(sumL.begin(),sumL.end(),N)-sumL.begin();
		char ans[L+1];
		N-=sumL[L-1];
		for(int D=2,now=L;now>0;now--){
			for(D-=(D>0);N>allS[now][D];D++)
				N-=allS[now][D];
			ans[L-now]=D+'0';
		}
        ans[L]='\0';
		puts(ans);
	}
}