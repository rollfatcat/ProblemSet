/* 題目保證給的索引值是 1-Ｎ, 所以不需要排序
 * 輸入測資之間會隔一個換行。
 */
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int caseT, x=0;
	string ss;
 
	cin>>caseT;
	while(caseT--){
		getline(cin,ss);
		getline(cin,ss),
		getline(cin,ss);
 
		vector<int> pos;
		for(char ch:ss)
			(ch==' ')? pos.push_back(x-1),x=0: x=10*x+ch-'0';
		pos.push_back(x-1),x=0;
		vector<string> arr(pos.size());
		for(int i=0;i<pos.size();i++)
			cin>>arr[pos[i]];
		for(string ss:arr)
			cout<<ss<<'\n';
	}
}
