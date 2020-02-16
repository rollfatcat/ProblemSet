/* 給定一個指定字元Ｄ和原始輸入字串Ｎ，將Ｎ當中的指定字元去除後的字串以『數字』的形式輸出(不可為空字串或是前導為０)
 * 重點：讀取Ｄ/Ｎ時需要使用字元的形式而非數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=100;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for(string D,N; cin>>D>>N;){
		if(D=="0" and N=="0") break;
		string M="";
		for(char ch:N)
			if(ch!=D[0])
				M+=ch;
		/* 處理前導＝0 和 去除指定字元後形成空字串或者是都是"0"*/
		int idx=0;
		for(;idx<M.length() and M[idx]=='0';idx++);
		if(idx==M.length()) cout<<"0";
		for(;idx<M.length();cout<<M[idx],idx++);
		cout<<'\n';
	}
}



