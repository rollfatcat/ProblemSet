/* 多筆測資輸入，每次給定２行(第１行的數字代表Ｘ值，第２行代表降冪的係數)，輸出一次微分後的值？
 * 解題關鍵：題目的降冪係數並沒有先給個數，所以只能整行讀取後依照空白拆成各個數字
 * 題目盲點：第２行輸入的數字之間以空白隔開 且 最後一個字元為空白(非換行)
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long x;
	string ss;
	while(cin>>x>>ws){
		getline(cin,ss);
		
		vector<int> coff;
		for(int i=0;i<ss.length();i++){
			long v=0;
			bool nega=(ss[i]=='-');
			for(i+=nega; '0'<=ss[i] and ss[i]<='9'; i++)
				v=(v<<3)+(v<<1)+ss[i]-'0';
			coff.push_back( (nega)? -v: v);
		}
		coff.pop_back();
		
		long ans=(coff.size())? coff.back(): 0; 
		long v=1, c=1;
		for(int i=coff.size()-2; i>=0; i--)
			c+=1, v*=x, ans+=c*coff[i]*v;
		cout<<ans<<'\n';
	}
}