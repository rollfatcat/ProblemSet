/* 給定一個字串(包含二進位和位元運算符號)，輸出時將位元運算符號的字串改為符號並且輸出計算後的答案
 * 解題關鍵：字串解析＋位元運算
 * 格式是固定的(每個字串間間隔一個空白 且 二進位的字串長度一定是５)
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string ss;
	while(getline(cin,ss)){
		bool num[5]={0,0,0,0,0}, opt=1;
		int idx=0;
		while(ss[idx]!='\0'){
			if(ss[idx]=='0' or ss[idx]=='1'){
				if(opt){
					cout<<ss[idx]; num[0]|= ss[idx++]=='1';
					cout<<ss[idx]; num[1]|= ss[idx++]=='1';
					cout<<ss[idx]; num[2]|= ss[idx++]=='1';
					cout<<ss[idx]; num[3]|= ss[idx++]=='1';
					cout<<ss[idx]; num[4]|= ss[idx++]=='1';
				}else{
					cout<<ss[idx]; num[0]&= ss[idx++]=='1';
					cout<<ss[idx]; num[1]&= ss[idx++]=='1';
					cout<<ss[idx]; num[2]&= ss[idx++]=='1';
					cout<<ss[idx]; num[3]&= ss[idx++]=='1';
					cout<<ss[idx]; num[4]&= ss[idx++]=='1';
				}
				idx++;
			}
			else{ // ss[idx]=='a' or ss[idx]=='o')
				if(ss[idx]=='a'){ opt=0; cout<<"&&"; idx+=4; }
				if(ss[idx]=='o'){ opt=1; cout<<"||"; idx+=3; }
			}
		}
		cout<<" = "<<num[0]<<num[1]<<num[2]<<num[3]<<num[4]<<'\n';
	}
}