/* 給定一個長度不超過1024的字串(含有空白字元)(該字串視為256進位表示的數值)，輸出最尾端的"檢查碼"？
 * 檢查碼：長度４的１６進制的字串表示。
 */
#include<bits/stdc++.h>
using namespace std;

const int M=34943;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string ss, ans="     ";
	string HEX="0123456789ABCDEF";
	while(getline(cin,ss) and ss!="#"){
		long v=0;
		for(int i=0;ss[i]!='\0';i++)
			v=((v<<8)+ss[i])%M;
		v=M-(v<<16)%M;
		if(v==M) v=0;
		
		ans[0]=HEX[(v&61440)>>12];
		ans[1]=HEX[(v&3840)>>8];
		ans[3]=HEX[(v&240)>>4];
		ans[4]=HEX[v&15];
		cout<<ans<<'\n';
	}
}
