/* 先給定兩個字串代表加密的字母對應方式
 * 當輸入的字元中不存在對應時則直接輸出明文, 否則輸出加密後的字元。
 * 一維陣列模擬
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=10;
char MapChar[256];  // ASCii ＝[0,255]
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	string s1, s2;
	int caseT; 
	cin>>caseT; 
	getline(cin,s1);
	getline(cin,s1);
	while(caseT--){
		getline(cin,s1);
		getline(cin,s2);
		cout<<s2<<'\n'<<s1<<'\n';
		fill(MapChar,MapChar+256,-1);
		for(int i=0;s1[i]!='\0';i++)
			MapChar[s1[i]]=s2[i];
		while(getline(cin,s1) and s1.length()){
			for(int i=0;s1[i]!='\0';i++)
				(MapChar[s1[i]]>=0)? cout<<MapChar[s1[i]]: cout<<s1[i];
			cout<<'\n';
		}
	}
}