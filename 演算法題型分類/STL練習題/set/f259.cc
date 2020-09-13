/* 題目每次會給定字串，輸出該字串是否在之前出現過？
 * 解題關鍵：set (紅黑樹)維護(㏒Ｎ)查詢
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string ss;
	set<string> memo;
	while(cin>>ss){
		bool out= memo.find(ss)!=memo.end();
		if(!out) memo.insert(ss);
		cout<<out<<'\n';
	}
}
