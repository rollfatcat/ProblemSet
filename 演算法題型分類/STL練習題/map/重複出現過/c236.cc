/* 給定Ｔ本字典和每本字典Ｎ個單字，將所有單字收錄為一本字典後依序輸出。
 * 收錄：兩個單字全部轉換成大寫後為同樣的字視為相同單字，相同的字只收錄年代最早出現的型態。
 * 排序：越早年分出現的字排越前面，如果年分一樣，就按照字母排序(a/A~z/Z)(不分大小寫)。
 * 核心關鍵：怎麼處理 Hash-Map 問題？
 * 辨別是否出現過相同的單字 和 查詢年份時都需要 KeyString(統一為小寫)，因此利用兩個 map 達成。
 * memo 紀錄形式 / mapv 紀錄最早出現的年份，而且需要 book 這個 vector 最後時排序用。
 * 將 KeyString 排序時則需要查詢 mapv 再者依據  KeyString 的字串順序 排列即可。
 */

#include<bits/stdc++.h>
using namespace std;

const int MaxT=1e2;
const int MaxN=1e2;
const int MaxS=1e1; // 錯誤資訊，測資字串最長會超過
const int MaxY=5e2;
const int sft='a'-'A';

vector<string> book;
map<string,string> memo;
map<string,int   > mapv;

inline bool compare(string &a,string &b){
	return (mapv[a]==mapv[b])? a<b : mapv[a]<mapv[b];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int Q, N, v;
	string org_ss, key_ss;
	
	cin>>T;
	while(T-->0){
		cin>>N;
		for(int i=0;i<N;i++){
			cin>>org_ss>>v;
			// 將輸入的字串轉換為 KeyString 
            key_ss=org_ss;
			for(int j=0;key_ss[j]!='\0';j++)
				if(key_ss[j]<'a')
					key_ss[j]+= 'a'-'A';
			/* (1) KeyString 未出現過，將 KeyString 加入 book / mapv / memo
             * (2) KeyString 已經出現，根據紀錄中的年份決定是否"更新" 年份 和 形式
             */
			if(mapv.find(key_ss)==mapv.end())
				book.emplace_back(key_ss),
				mapv[key_ss]=v, 
				memo[key_ss]=org_ss;
			else if(mapv[key_ss]>v)
				mapv[key_ss]=v, 
				memo[key_ss]=org_ss;
			
		}
	}
	sort(book.begin(),book.end(),compare);
	for(string ss: book)
		cout<<memo[ss]<<'\n';
}
