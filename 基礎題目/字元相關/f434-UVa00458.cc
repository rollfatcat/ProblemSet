/* 凱薩加密：給定密文還原為明文
 * 解題關鍵：ascii code 的概念
 * 觀察輸入和輸出的字串可以發現(1)密文和明文的字元代碼相差７ (2)密文可能包含' '需要getline()讀取
 */
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	string ss;
	while( getline(cin,ss) ){
		for(int i=0;i<ss.length();i++)
			cout<< (char)(ss[i]-7);
		cout<<'\n';
	}
}