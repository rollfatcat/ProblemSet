/* 給定Ｎ位同學的名字清單和一個數字ｖ，輸出倒數第ｖ位同學的名字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=50;
string name[MaxN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N, v=0;
	for(N=0;cin>>ss and ss[0]>'9';N++)
		name[N]=ss;
	for(int i=0;ss[i]!='\0';i++)
		v=10*v+(ss[i]-'0');
	cout<<name[N-v]<<'\n';
}