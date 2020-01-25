/* 給定一個字串，求最少需要從尾端新增字串才能讓整個字串成為迴文
 * GreedyForce，由左往右枚舉從現在這個字元到字尾間能否形成迴文，一旦找到就從現在這個位置(不包含)由右往左輸出字元即可。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxL=1e5;
char ss[MaxL+2];
inline bool IsPalindrome(int L,int R){
	for(;L<R;L++,R--)
		if(ss[L]!=ss[R])
			return false;
	return true;
}
int main(){
	while(scanf("%s",ss)!=EOF){
		int i,L=strlen(ss);
		vector<int> pos;
		for(i=0;i<L and IsPalindrome(i,L-1)==0;i++);
		for(printf("%s",ss);--i>=0;)
			putchar(ss[i]);
		putchar('\n');
	}
}