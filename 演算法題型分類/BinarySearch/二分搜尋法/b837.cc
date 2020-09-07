/* 題目給定ＡＢ作為邊界，輸出範圍內的費波那契數列數字和個數，答案間用指定字串隔開
 * 解題關鍵：二分搜尋法的 STL
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxA=1e6;
int main(){
	vector<int> FIB={0,1,1};
	while(FIB.back()<=MaxA)
		FIB.push_back(FIB.back()+FIB[FIB.size()-2]);
	
	int caseT, A, B, st, ed;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d",&A,&B);
		if(A>B) swap(A,B);
		st=lower_bound(FIB.begin(),FIB.end(),A)-FIB.begin();
		ed=upper_bound(FIB.begin(),FIB.end(),B)-FIB.begin();
		for(int i=st;i<ed;i++)
			printf("%d\n",FIB[i]);
		printf("%d\n",ed-st);
		if(caseT) puts("------");
	}
}