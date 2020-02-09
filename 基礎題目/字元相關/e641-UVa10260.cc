/* 給定一個長度不超過20的字串，輸出字母對應的數字(若數字不存在對應時則不須輸出)
 * 當對應的數字是『連續且相同』時則只要輸出一個即可。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=20+2;
char ss[MaxL]; 
/* 0: A、E、I、O、U、H、W、Y
 * 1：B、F、P、V
 * 2：C、G、J、K、Q、S、X、Z
 * 3：D、T
 * 4：L
 * 5：M、N
 * 6：R
 */
int memo[26]={0,1,2,3,0,1,2,0,0,2,
              2,4,5,5,0,1,2,6,2,3,
              0,1,0,2,0,2};
int main(){
	while(scanf("%s\n",ss)!=EOF){
		int prev=0, nowv;
		for(int i=0;ss[i]!='\0';i++){
			nowv=memo[ss[i]-'A'];
			if(nowv and prev!=nowv)
				putchar(nowv+'0');
			prev=nowv;
		}
		putchar('\n');
	}
}