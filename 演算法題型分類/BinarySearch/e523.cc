/* 建表：費波那契數列產生後, 做二分搜尋法確定數列是否包含目標數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNum=1000000;
vector<int> FIB={1,1};
int main(){
	for(int i=2;FIB.back()<=MaxNum;i++)
		FIB.push_back(FIB[i-1]+FIB[i-2]);
	int Qnum;
	scanf("%d",&Qnum);	
	for(int tag, target; Qnum>0; Qnum--){
		scanf("%d",&target),
		tag=lower_bound(FIB.begin(),FIB.end(),target)-FIB.begin();
		printf("%d\n",(FIB[tag]==target)? tag+1: -1);
	}
}
