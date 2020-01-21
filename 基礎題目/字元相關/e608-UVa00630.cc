/* 所有單詞均為小寫(最後一個單詞"END"表示測資結尾，不需用處理)。
 * 所有單詞長度不超過20個字元。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000;
vector<string> dict(MaxN);
vector<int> one(26);
vector<vector<int>> cnt(MaxN,one);

inline bool CntEqual(vector<int> &a,vector<int> &b){
	for(int i=0;i<26;i++)
		if(a[i]!=b[i])
			return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseT, N;
	string ss;
	
	cin>>caseT; 
	while(caseT--){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>dict[i];
			fill(cnt[i].begin(),cnt[i].end(),0);
			for(int j=0;dict[i][j]!='\0';j++)
				cnt[i][dict[i][j]-'a']++;
		}
		while(cin>>ss and ss!="END"){
			fill(one.begin(),one.end(),0);
			for(int i=0;ss[i]!='\0';i++)
				one[ss[i]-'a']++;
			cout<<"Anagrams for: "<<ss<<'\n';
			int ans=0;
			for(int i=0;i<N;i++)
				if(CntEqual(one,cnt[i]))
					ans++, cout<<ans<<") "<<dict[i]<<'\n';
			if(ans==0) cout<<"No anagrams for: "<<ss<<'\n';
		}
	}
}