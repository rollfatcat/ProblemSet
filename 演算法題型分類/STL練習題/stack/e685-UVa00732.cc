/* 給定ＡＢ兩個字串，問如何可以透過 Stack 操作方式把Ａ轉變為Ｂ的『所有方法』
 * 遞迴：每層遞迴由左往右依次固定Ｂ字串，從Ａ字串剩餘的部分或是Stack找到對應的字元
 * 停止：Ｂ字串耗完時檢查Ａ字串耗完且Stack是空的＝存在一個答案
 * 輸出：依字典序輸出操作字串ｉ＞ｏ，但實作時會發現依照字典序執行遞迴會難度激增
 *      若ｏ＞ｉ時則簡單許多...所以需要用 Stack 處理先找到後輸出。
 */
#include<bits/stdc++.h>
using namespace std;

string ss[2];
stack<string> memo; // DFS順序：選擇 o 優於 i 所以答案需要先用 Stack 存起來後輸出
void DFS(int i0,int i1,stack<char> S,string ans){
	if(ss[1][i1]=='\0'){ 
		if(ss[0][i0]=='\0' and S.empty())
			memo.push(ans);
		return;
	}
	if(S.empty()==0 and ss[1][i1]==S.top()){
		char ch=S.top(); S.pop();
		DFS(i0,i1+1,S,ans+"o ");
		S.push(ch);
	}
	for(int i=i0;ss[0][i]!='\0';i++){
		if(ss[0][i]==ss[1][i1])
			DFS(i+1,i1+1,S,ans+"i o ");
		S.push(ss[0][i]); ans+="i ";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	while(cin>>ss[0]>>ss[1]){
		stack<char> S;
		DFS(0,0,S,"");
		for(cout<<"[\n";memo.empty()==0;memo.pop())
			cout<<memo.top()<<'\n';
		cout<<"]\n";
	}
}