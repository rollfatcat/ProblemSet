/* 給定Ｌ個長度的字串(由大寫字母組成)和Ｍ個位置，依該位置輸出字母。
 * 每個位置需要輸出的字母代表為原始字串依 ASCii 順序小到大排列後的字母位置。
 * 解題關鍵： CountingSort＋PrefixSum＋BinaySearch
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e7;
int cnt[26];
int main(){
	int L, M, P;
	while(scanf("%d %d\n",&L,&M)!=EOF){
		fill(cnt,cnt+26,0);
		while(L-->0)
			cnt[getchar_unlocked()-'A']++;
		for(int i=1;i<26;i++)
			cnt[i]+=cnt[i-1];
		while(M-->0){
			scanf("%d",&P);
			putchar(lower_bound(cnt,cnt+26,P)-cnt+'A');
		}
		putchar('\n');
	}
}