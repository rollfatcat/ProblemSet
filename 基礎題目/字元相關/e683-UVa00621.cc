/* 根據題目的規則要求輸出對應的字元。
 * 字串相等/字串尾端/字串開頭 的判斷
 */
#include<bits/stdc++.h>
using namespace std;

inline char Judge(string &ss){
	if(ss=="1" or ss=="4" or ss=="78") return '+';
	if(ss.length()>1 and ss[ss.length()-2]=='3' and ss[ss.length()-1]=='5') return '-';
	if(ss[0]=='9' and ss[ss.length()-1]=='4') return '*';
	return '?';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string ss;
	int caseT; cin>>caseT;
	while(caseT--)
		cin>>ss, cout<<Judge(ss)<<'\n';
}