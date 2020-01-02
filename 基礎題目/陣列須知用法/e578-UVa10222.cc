#include<bits/stdc++.h>
using namespace std;

string number="8?`1234567";
string letter="?czaqsdfyghjbvui?w?etx??r?";
map<char,char> Memo;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// 補足缺失的部分
	Memo['-']='9';	Memo['=']='0'; Memo['\\']='[';
	Memo['[']='o';	Memo[']']='p';
	Memo[';']='k';	Memo['\'']='l';
	Memo[',']='n';	Memo['.']='m'; Memo['/']=',';
	//
	for(string line; getline(cin,line); cout<<'\n')
		for(char ch:line)
			if(ch!=' '){
				if(Memo.find(ch)==Memo.end()){
					if('0'<=ch and ch<='9')
						cout<<number[ch-'0'];
					else cout<<letter[ch-'a'];
				}else cout<<Memo[ch];
			}else cout<<' ';
		
}
