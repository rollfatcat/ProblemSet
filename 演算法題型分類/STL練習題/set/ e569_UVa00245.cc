/* 字串處理(根據非數字和字母部分做字串切割)＋Set紀錄是否存在
 * 根據題目的壓縮規則, 讀取數字時根據數值取出在紀錄的字串, 並將該字串從陣列中移出並加入到最前面。實作時則是利用vector加到『尾端』,若讀取到字串時則需判斷該字串是否已經儲存並加入set中確保之後查詢『有沒有出現過』時可以判斷。
 */
#include<bits/stdc++.h>
using namespace std;
vector<string> vecMemo;
set<string> setMemo;

inline bool check(char ch){ return ('0'<=ch and ch<='9')or('a'<=ch and ch<='z')or('A'<=ch and ch<='Z'); }
inline void wordcompress(string &word,char ch){
	if('0'<=word[0] and word[0]<='9'){
		int v=0;
		for(char c:word)
			v=10*v+c-'0';
		word=vecMemo[vecMemo.size()-v];
		vecMemo.erase(vecMemo.end()-v);
		vecMemo.push_back(word);
	}else{
		if(setMemo.find(word)==setMemo.end())
			setMemo.insert(word),
			vecMemo.push_back(word);
	}
	cout<<word<<ch;
	word="";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for(string line;getline(cin,line) and line!="0";){
		string word;
		/* 該字元屬於數字或字母, 則併入目前的word
		 * 若不屬於上述情況, 則檢查word後直接輸出該字元
		 */
		for(char ch:line){
			if(check(ch))
				word+=ch;
			else
				wordcompress(word,ch);
		}
		wordcompress(word,'\n');
	}
}
