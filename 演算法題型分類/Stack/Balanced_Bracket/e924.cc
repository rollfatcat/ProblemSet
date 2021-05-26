/* 給定一個字串由４種類型的括號構成，判斷是否為合法的形式。
 * 括號的類型："{}" . "()" . "[]" . "<>"
 * 括號合法配對問題＝標準Stack應用
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e3;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseT, idx;
	for(cin>>caseT;caseT--;){
		string ss; cin>>ss;
		stack<char> S;
		for(idx=0;ss[idx]!='\0';idx++){
			if(ss[idx]=='{' or ss[idx]=='(' or ss[idx]=='<' or ss[idx]=='[') S.push(ss[idx]);
			if(ss[idx]=='}'){ 
				if(S.empty() or S.top()!='{') break; else S.pop(); }
			if(ss[idx]==')'){ 
				if(S.empty() or S.top()!='(') break; else S.pop(); }
			if(ss[idx]=='>'){ 
				if(S.empty() or S.top()!='<') break; else S.pop(); }
			if(ss[idx]==']'){ 
				if(S.empty() or S.top()!='[') break; else S.pop(); }
		}
		cout<<((ss[idx]=='\0' and S.empty())?"Y\n":"N\n");
	}
}
