/* 給定一個字串，在『拆成數個相同的子字串』的要求下最多是幾個？
 * 解題關鍵：子字串長度必定是字串長度的因數
 * 暴力法由小到大嘗試子字串長度。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e6+2;
char ss[MaxL];
int main(){
	while(scanf("%s\n",ss) and ss[0]!='.'){
		int subL, cnt;
		int ssL=strlen(ss);
		for(subL=1;subL<ssL;subL++)
			/* 子字串長度必定是字串長度的因數 
			 * 只有『所有』"相同餘數位置"的字元都相同＝測試成功
			 * j＜cnt 代表存在一組"相同餘數位置"的字元不同＝fail
			 * i==subL代表每組的餘數都測試成功
			 */
			if(ssL%subL==0){
				cnt=ssL/subL;
				int i, j;
				for(i=0;i<subL;i++){
					for(j=1;j<cnt and ss[i]==ss[i+j*subL];j++);
					if(j<cnt) break;
				}
				if(i==subL) break;
			}
		printf("%d\n",(subL==ssL)? 1:cnt);
	}
}