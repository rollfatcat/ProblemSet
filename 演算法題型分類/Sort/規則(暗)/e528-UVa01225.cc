/* 離線處理的練習
 * 根據數字由小到大排序後模擬Digit計算過程
 * 將過程依照『輸入順序』存入後再一次輸出。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
int Qry[MaxCaseT]; // 1 < Qi < 1e4
int Ord[MaxCaseT];

bool compare(int a,int b){
	return Qry[a]<Qry[b];
}
int main(){
	int caseT;
	scanf("%d",&caseT);
	for(int i=0;i<caseT;i++)
		scanf("%d",&Qry[i]), Ord[i]=i;
	sort(Ord,Ord+caseT,compare);
	
	vector<int> cnt(10);
	vector<vector<int>> ans(caseT,cnt);
	int idx=0;
	for(int now=1;now<=Qry[caseT-1];now++){
		for(int num=now;num>0;num/=10)
			cnt[num%10]++;
		if(now==Qry[idx])
			ans[Ord[idx]]=cnt, idx++;
	}
	for(int i=0;i<caseT;i++,putchar('\n'))
		for(int j:ans[i])
			printf("%d ",j);
}