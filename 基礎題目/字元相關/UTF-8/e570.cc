/* 給定中文字串將「賓語」後面的語句提前到句首輸出。
 * 賓語：之, 是。
 * 解題關鍵：UTF-8，複製和判斷時都是以３個字元為單位。
 */
#include<bits/stdc++.h>
using namespace std;
 
const char CUT[2][5]={"之","是"};
char  ss[10000];
char ans[10000];
inline bool IsCut(int pos){ 
	return (ss[pos]==CUT[0][0] and ss[pos+1]==CUT[0][1] and ss[pos+2]==CUT[0][2]) or 
           (ss[pos]==CUT[1][0] and ss[pos+1]==CUT[1][1] and ss[pos+2]==CUT[1][2]);
}
int main(){
 
	int idx, stop, p0;
	while(scanf("%s\n",ss)!=EOF){
		for(stop=0; IsCut(stop)==0; stop+=3);
		for(p0=0, idx=stop+3; ss[idx]!='\0'; )
			ans[p0++]=ss[idx++];
		for(idx=0; idx<stop; )
			ans[p0++]=ss[idx++];
		ans[p0]='\0';
		printf("%d %s\n",idx,ans);
	}
}