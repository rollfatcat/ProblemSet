/* 給定需要加密的字串，尋找字典中可以對應的加密字串(只需找到一組解即可)
 * 若字典中不存在可以成功對應的字串時則輸出 "impossible"
 * 規定建表中的每個字元都是一對一對應且不可以對應回原本的字元
 *     兩字串需要長度相同，
 *     若第一次出現在需要建立『雙向』的對應表
 *     若重複的出現在查表確認該字元是否符合對應表的內容
 */
#include<bits/stdc++.h>
using namespace std;

string s1, s2;
inline bool Illegal(void){
	if(s1.length()!=s2.length())
		return false;
		
	vector<char> to(256,'?');
	vector<char> fr(256,'?');
	for(int i=0;i<s1.length();i++){
		if(s1[i]==s2[i])
			return false;
		if(to[s1[i]]=='?' and fr[s2[i]]=='?')
			to[s1[i]]=s2[i], 
			fr[s2[i]]=s1[i];
		else if(to[s1[i]]!=s2[i] or fr[s2[i]]!=s1[i])
			return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	bool HasAns=0;
	for(cin>>s1;cin>>s2 and (HasAns=Illegal())==0;);
	cout<<((HasAns)? s2: "impossible")<<'\n';
}
