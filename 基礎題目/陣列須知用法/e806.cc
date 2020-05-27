/* 給定２個多項式，求相加之後係數不為０的項數和係數值
 * 題目有說明：
 *  0 ≤ｐ≤ 1000    , 直接開一個陣列紀錄對應的係數值
 *  −2^30 ≤ｃ< 2^30, 係數和可以用 int 紀錄 
 * 當 p 沒有限制時需要依據 p 大到小排序後，依序對消，詳情見ZJ-b512
 *  
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxP=1e3;
int coff[MaxP+1]={};

int main(){
	int N;
	for(int t=1;t<=2;t++){
		scanf("%d\n",&N);
		for(int p,c;N--;)
			scanf("%d %d",&p,&c),
			coff[p]+=c;
	}
	bool IsNull=1;
	for(int p=MaxP;p>=0;p--)
		if(coff[p])
			printf("%d:%d\n",p,coff[p]), 
			IsNull=0;
	if(IsNull)
		puts("NULL!");
}