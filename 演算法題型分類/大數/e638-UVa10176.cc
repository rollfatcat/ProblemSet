/* 題目存在『惡意測資』：一個(二進位)數字會分行給，每一筆測資的結束是以'#'劃分。
 * 題目保證二進位的大數不會超過100位數且數字最多1e4個
 */
#include<bits/stdc++.h>
using namespace std;

const int mod=131071;
int main(){
	char ss[200];
	__int128 v=0; // 二進位的大數不會超過100位數，可用__int128紀錄
	while(scanf("%s",ss)!=EOF){
		for(int i=0;ss[i]!='\0';i++)
			if(ss[i]=='#')
				puts((v%mod)?"NO":"YES"), v=0;
			else
				v=(v<<1)+(ss[i]=='1');
	}
}