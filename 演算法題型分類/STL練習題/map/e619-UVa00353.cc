/* 給定一個字串，問有多少個『相異且迴文』的子字串
 * 字串長度不超過80，所以枚舉端點後判斷該字串是否為迴文
 * 相異的部分則透過<map>紀錄是否判斷過。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=80;

inline bool IsPalindrome(string ss){
	for(int L=ss.length(),i=0;i<(L>>1);i++)
		if(ss[i]!=ss[L-1-i])
			return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string ss, subss;
	while(cin>>ss){
		map<string,bool> memo;
		int cnt=0;
		for(int L=1;L<=ss.length();L++)
			for(int i=0;i+L<=ss.length();i++){
				subss=ss.substr(i,L);
				if(memo.find(subss)==memo.end())
					memo[subss]=IsPalindrome(subss),
					cnt+=memo[subss];
			}
		cout<<"The string '"<<ss<<"' contains "<<cnt<<" palindromes.\n";
	}
}