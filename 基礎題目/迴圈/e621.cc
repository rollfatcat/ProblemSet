/* 給定兩個數字作為範圍[Ａ,Ｂ]，輸出範圍內(不包含Ａ,Ｂ)無法被Ｃ整除的數字
 * 若不存在以上敘述的數字時則輸出"No free parking spaces."
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=7;
const int MaxV=500;
int main(){
	int caseT, A, B, C; 
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d %d %d\n",&A,&B,&C);
		bool HasAns=0;
		for(int i=A+1;i<B;i++)
			if(i%C)
				HasAns=1,printf("%d ",i);
		if(HasAns==0) puts("No free parking spaces.");
		putchar('\n');
	}
}
