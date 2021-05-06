/* 透過多個操作後，輸出對應的 JSON 格式內容，並保證輸入的操作合法。
 * 操作分為２類： insert 代表插入 KER:VALUE，並在每一項的 PAIR 以逗號間隔 / end 代表目前的輸入的 VALUE 結束
 * 解題關鍵：遞迴
 * 問題盲點：insert 後跟著 end 時
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=10;
const int MaxInsert=1e3;
char opt[MaxL+2];
char key[MaxL+2];
char val[MaxL+2];
char ss[]="newJSONObject";
 
void Recursion(){
	putchar('{');
	for(bool FirstKey=1; scanf("%s",opt) and opt[0]=='i'; FirstKey=0){
		scanf("%s %s",key,val);
		if(FirstKey==0)
			putchar(',');
		printf("%s:",key);
		if(strcmp(val,"newJSONObject")==0)
			Recursion();
		else
			printf("%s",val);
	}
	putchar('}');
}
 
int main(){
	Recursion();
}