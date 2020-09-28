/* 給定每行字串，經過轉換後輸出注音ㄅㄆㄇ的版本(每個字需要依照 聲母/介音/韻母/聲調 的順序)？
 * 字串的字元代表鍵盤按下的按鍵，題目會給定對應的ㄅㄆㄇ
 * 解題關鍵：HashMap(unordered_map)＋Sort
 */
#include<bits/stdc++.h>
using namespace std;
 
char keyboard[42]={'1','q','a','z','2','w','s','x','e','d','c','r','f','v','5','t','g','b','y','h','n','u','j','m','8','i','k',',','9','o','l','.','0','p',';','/','-',' ','6','3','4','7'};
string Bopomofo[42]={"ㄅ","ㄆ","ㄇ","ㄈ","ㄉ","ㄊ","ㄋ","ㄌ","ㄍ","ㄎ","ㄏ","ㄐ","ㄑ","ㄒ","ㄓ","ㄔ","ㄕ","ㄖ","ㄗ","ㄘ","ㄙ","ㄧ","ㄨ","ㄩ","ㄚ","ㄛ","ㄜ","ㄝ","ㄞ","ㄟ","ㄠ","ㄡ","ㄢ","ㄣ","ㄤ","ㄥ","ㄦ"," ","ˊ","ˇ","ˋ","˙"};
 
unordered_map<char,string> table;
unordered_map<char,int> opt;
bool compare(char a,char b){ return opt[a]<opt[b]; }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	for(int i=0;i<=20;i++)
		table[ keyboard[i] ]=Bopomofo[i], 
		opt[ keyboard[i] ]=0;
	for(int i=21;i<=23;i++)
		table[ keyboard[i] ]=Bopomofo[i], 
		opt[ keyboard[i] ]=1;
	for(int i=24;i<37;i++)
		table[ keyboard[i] ]=Bopomofo[i], 
		opt[ keyboard[i] ]=2;
	for(int i=37;i<42;i++)
		table[ keyboard[i] ]=Bopomofo[i], 
		opt[ keyboard[i] ]=3;
 
	string line;
	while(getline(cin,line)){
		vector<char> buff;
		for(int i=0;line[i]!='\0';i++){
			buff.push_back(line[i]);
			if(line[i]==' ' or line[i]=='6' or line[i]=='3' or line[i]=='4' or line[i]=='7'){
				sort(buff.begin(),buff.end(),compare);
				for(char ch:buff)
					cout<<table[ch];
				buff.clear();
			}
		}
		sort(buff.begin(),buff.end(),compare);
		for(char ch:buff)
			cout<<table[ch];
		cout<<'\n';
	}
}