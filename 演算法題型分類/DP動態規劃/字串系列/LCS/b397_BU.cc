/* 給兩個字串ＡＢ，按照字典順序列出所有ＡＢ的最長共同子序列。
 * 題目保證字串長度不超過３２並且只會由小寫字母和數字組成。
 * 核心作法：BottomUp＋滾動陣列
 * 考慮到狀態轉移時當上/左的字串長度一樣時要合併需要剔除相同字串並維護字典序
 *    (1)set    , 問題點插入新字串時的時間是 ㏒Ｎ, 實作後時間為0.9s
 *    (2)vecotr , 給定兩個依照字典序的集合做合併並剔除相同的字串
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxL=35;
string ss[2];
string empty_s;
vector<string> dp[2][MaxL];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int L, caseT, pre, now;
	cin>>caseT;
	
	dp[1][0]={""};
	for(int caseI=1;caseI<=caseT;caseI++){
		cin>>ss[0]>>ss[1];

		pre=0, now=1;
		for(int j=0;j<=ss[1].length();j++) 
			dp[0][j]={""};
		for(int i=0;ss[0][i]!='\0';i++){
			for(int j=0;ss[1][j]!='\0';j++){
				dp[now][j+1].clear();
				if(ss[0][i]==ss[1][j]){
					for(string s:dp[pre][j])
						dp[now][j+1].emplace_back(s+ss[0][i]);
				}else{
					if( dp[now][j][0].length()>dp[pre][j+1][0].length() )
						dp[now][j+1]=dp[now][j];
					else if( dp[now][j][0].length()<dp[pre][j+1][0].length() )
						dp[now][j+1]=dp[pre][j+1];
					else{ // 給定兩個依照字典序的集合做合併並剔除相同的字串
						int a=0, b=0;
						while(a<dp[now][j].size() and b<dp[pre][j+1].size()){
							if(dp[now][j][a]<dp[pre][j+1][b])
								dp[now][j+1].emplace_back(dp[now][j][a++]);
							else if(dp[now][j][a]>dp[pre][j+1][b])
								dp[now][j+1].emplace_back(dp[pre][j+1][b++]);
							else
								dp[now][j+1].emplace_back(dp[pre][j+1][b++]),a++;
						}
						while(a<dp[now][j].size())
							dp[now][j+1].emplace_back(dp[now][j][a++]);
						while(b<dp[pre][j+1].size())
							dp[now][j+1].emplace_back(dp[pre][j+1][b++]);
					}
				}
			}
			swap(pre,now);
		}
		
		cout<<"Case #"<<caseI<<": "<<dp[pre][ss[1].length()].size()<<'\n';
		for(string s:dp[pre][ss[1].length()])
			cout<<s<<'\n';
	}
}