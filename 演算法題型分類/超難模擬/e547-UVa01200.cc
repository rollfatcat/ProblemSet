/* 線性方程，該方程只有一個變量x，沒有括號！
 * 每個表達式由一個或多個"+"或"-"運算符號組合而成。
 * 每個項可以是單個整數也可以是整數後跟小寫字元x，或者單個字元x。
 * 你將寫一個程式來找到滿足方程式的x值。
 * 請注意，方程可能無解或無限多組解。你的程式也必須檢測這些情況。
 * 所有數字都是[0~1000]範圍內的整數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=10;
const int MaxLen=255;
char ss[MaxLen+2];

bool IsNeg;
bool Equal;
int coff, x[2];
inline void ClearBuff(int power){
	if(IsNeg) 
		coff*=-1; 
	x[power]+=coff;
	coff=0;
} 
int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%s",ss);
		coff=IsNeg=Equal=x[0]=x[1]=0;
		for(int i=0;ss[i]!='\0';i++){
			if('0'<=ss[i] and ss[i]<='9'){
				coff=10*coff+ss[i]-'0';
			}else if(ss[i]=='x'){
				// 若第０個字元就是'x' 或前一個字元不是數字代表 1x
				coff+= (i==0 or (i>0 and (ss[i-1]<'0' or ss[i-1]>'9')));
				ClearBuff(1);
			}else{
				if(coff) // 若係數不為0 代表 該係數為常數
					ClearBuff(0);
				Equal|= ss[i]=='='; // 偵測到等號後, 運算符號的正負顛倒 
				IsNeg= Equal^(ss[i]=='-'); // 需考慮到是在等號的左右哪邊
			}
		}
		if(coff) ClearBuff(0);
		
		if(x[1]==0 and x[0]!=0) puts("IMPOSSIBLE");
		else if(x[1]==0 and x[0]==0) puts("IDENTITY");
		else printf("%d\n",(int)floor(-(double)x[0]/x[1]));
	}
}