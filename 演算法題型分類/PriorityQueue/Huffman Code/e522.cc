/* 給定Ｑ行輸入(字串間可能包含空白)，若該行字串為"二進制"組成(字元只包含０和１)輸出壓縮編碼和壓縮比，否則輸出−１。
 * 壓縮的規定：輸出的壓縮碼固定長度為４，第１碼表示位元(０或１)，第２-４碼表示個數(最多只能紀錄７個)
 *           若存在１４個１則拆分為兩組７個１
 * 壓縮比：輸出四捨五入後的百分比
 */
#include<bits/stdc++.h>
using namespace std;

string IntStr[16]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int Q, L, cnt, tag;
	string ss;
	cin>>Q; getline(cin,ss);
	while(Q-->0){
		getline(cin,ss);
		if(ss[0]!='0' and ss[0]!='1'){
			cout<<-1<<'\n'; continue;
		}
		vector<int> memo;
		tag=ss[0]; cnt=1;
		for(L=1;ss[L]!='\0';L++)
			if(ss[L]!='0' and ss[L]!='1'){
				cout<<-1<<'\n'; break;
			}else{
				if(ss[L]==tag){
					if(cnt==7)
						memo.push_back( ((tag-'0')<<3)|7 ),
						cnt=0;
					cnt++;
				}else{
					memo.push_back( ((tag-'0')<<3)|cnt );
					tag=ss[L], cnt=1;
				}
			}
		if(L==ss.length()){
			memo.push_back( ((tag-'0')<<3)|cnt );
			for(int x: memo)
				cout<<IntStr[x]<<' ';
			int ans=1000*(memo.size()<<2)/L;
			cout<< (ans/10+(ans%10>=5)) <<"%\n";
		}
	}
}