/* 給定Ｎ組(最多100組)轉班關係(ＡtoＢ)輸出存在幾組剛好的逆向關係(ＡtoＢ存在 且 ＢtoＡ存在)？
 * 利用 map＋pair紀錄目前存在的各種關係個數，每輸入一組關係時查詢是否存在逆關係？若存在則配對數+1，若不存在則關係數+1。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
int main(){
	
	for(int N;scanf("%d\n",&N)!=EOF;){
		int a, b, ans=0;
		pair<int,int> ask;
		map<pair<int,int>,int> memo;
		for(int i=0;i<N;i++){
			scanf("%d %d\n",&ask.second,&ask.first);
			ans+= memo[ask]>0;
			(memo[ask]>0)? memo[ask]--:memo[make_pair(ask.second,ask.first)]++;
		}
		printf("%d\n",ans);
	}
}