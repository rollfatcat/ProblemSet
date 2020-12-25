/* 多筆測資，統計每一行的字串字母的個數(不分大小寫)和該字母佔所有字母的百分比(四捨五入到小數點第二位)
 * 字串以行為單位(包含空白)且字串存在字母以外的字元
 * 解題關鍵：getline() 讀取 和 "整數"除法 和 如何顯示四捨五入
 */
#include<bits/stdc++.h>
using namespace std;

int cnt[26];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	string ss;
	while(getline(cin,ss)){
		fill(cnt,cnt+26,0);
		int N=0;
		for(int i=0;ss[i]!='\0';i++){
			if('A'<=ss[i] and ss[i]<='Z')
				cnt[ ss[i]-'A' ]+=1, N+=1;
			if('a'<=ss[i] and ss[i]<='z')
				cnt[ ss[i]-'a' ]+=1, N+=1;
		}
		for(int i=0;i<26;i++)
			cout<<cnt[i]<<' ';
		cout<<'\n';
		for(int i=0;i<26;i++)
			cout<<fixed<<setprecision(2)<< 100.0*cnt[i]/N <<' ';
		cout<<'\n';
	}
}