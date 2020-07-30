/* 給定Ｎ組測資，每組２筆字串輸出是否為錯位字？
 * 錯位字的定義：只統計'a'-'z'的個數且大小寫視為相同，當個數相同時即為錯位字。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=50+2;
int cnt[26];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int Q, idx;
	string ss;
	
	cin>>Q; getline(cin,ss);
	while(Q-->0){
		getline(cin,ss);
		fill(cnt,cnt+26,0);
		for(int i=0;ss[i]!='\0';i++){
			if('a'<=ss[i] and ss[i]<='z')
				cnt[ ss[i]-'a' ]++;
			if('A'<=ss[i] and ss[i]<='Z')
				cnt[ ss[i]-'A' ]++;
		}
		getline(cin,ss);
		for(int i=0;ss[i]!='\0';i++){
			if('a'<=ss[i] and ss[i]<='z')
				cnt[ ss[i]-'a' ]--;
			if('A'<=ss[i] and ss[i]<='Z')
				cnt[ ss[i]-'A' ]--;
		}
		for(idx=0; idx<26 and cnt[idx]==0; idx++);
		cout<<( (idx==26)?1:0 )<<'\n';
	}
}