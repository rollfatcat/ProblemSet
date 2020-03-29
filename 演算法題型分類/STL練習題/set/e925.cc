/* 給定10個學號字串，輸出是否合法和最後WA的比例
 * 規則如下：
 * ss[0]='B'，
 * '0'<=ss[x]<='9'，x={2,3,7,8}
 * ss[3:6]必須需是存在給定的字典中
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=76;
inline bool Judge(string ss,set<string> &memo){
	if(ss[0]!='B') return true;
	if(ss[1]<'0' or ss[1]>'9') return true;
	if(ss[2]<'0' or ss[2]>'9') return true;
	if(ss[7]<'0' or ss[7]>'9') return true;
	if(ss[8]<'0' or ss[8]>'9') return true;
	return memo.find(ss.substr(3,4))==memo.end();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string ss;
	for(int N;cin>>N;){
		set<string> memo;
		for(int i=0;i<N;i++)
			cin>>ss, memo.insert(ss);
		string wa_cnt="0";
		for(int i=0;i<10;i++){
			cin>>ss;
			if(Judge(ss,memo))
				cout<<"N\n", wa_cnt[0]++;
			else
				cout<<"Y\n";
		}
		if(wa_cnt[0]>'0') wa_cnt="0."+wa_cnt;
		cout<<wa_cnt<<'\n';
	}
}