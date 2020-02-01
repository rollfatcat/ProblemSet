/* 給定一個數字Ｓ, 問哪個數字(最大化)的因數和剛好＝Ｓ
 * 建表：數值和對應的因數和, 排序時順序依據：因數和＞數值
 * 做二分法找到某個數值的因數和大於Ｓ, 該數值的前一個有２種情況：
 *   (1)因數和＝Ｓ的最大數值 (2)因數和＜Ｓ, 則不存在因數和＝Ｓ輸出-1
 */
#include<bits/stdc++.h>
using namespace std;

int MaxS=1000;
struct DATA{
	int sum, val;
	bool operator<(const DATA &rhs)const{ 
		return (sum==rhs.sum)? val<rhs.val : sum<rhs.sum; }
} data[1001];
int main(){
	for(int i=1;i<=MaxS;i++){
		data[i].val=i;
		for(int j=1;i*j<=MaxS;j++)
			data[i*j].sum+=i;
	}
	sort(data,data+1001);
	for(int S,caseI=1;scanf("%d",&S) and S>0;caseI++){
		int L=0, R=1000;
		for(int M;L<R; (data[M].sum>S)? R=M: L=M+1)
			M=L+R>>1;
		L--;
		printf("Case %d: %d\n",caseI,(data[L].sum==S)?data[L].val:-1);
	}
}