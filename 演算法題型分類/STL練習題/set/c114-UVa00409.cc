/* 給定Ｋ個關鍵字和Ｅ個藉口，依照字典序輸出包含最多關鍵字的藉口？
 * 題目給定的關鍵字只涵蓋小寫。
 * 包含關鍵字：無視大小寫，空白和非字母的字元都會切割成不同的單字。
 * 解題關鍵：HashTable 查表確認單字是否為關鍵字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=20;
const int MaxE=20;

string excu[MaxE];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int K, E;
	string line, word;
	for(int caseI=1; cin>>K>>E; caseI++){
		set<string> dict;
		for(int i=0;i<K;i++)
			cin>>word, dict.insert(word);
		cin>>ws;
		
		word="";
		int max_cnt=0, ansN=0;
		while(E-->0){
			getline(cin,line);
			
			int now_cnt=0; 
			for(int j=0;line[j]!='\0';j++)
				if('a'<=line[j] and line[j]<='z')
					word+=line[j];
				else if('A'<=line[j] and line[j]<='Z')
					word+=(line[j]-'A'+'a');
				else{
					now_cnt+= dict.find(word)!=dict.end();
					word="";
				}
			
			if(now_cnt>max_cnt) 
				max_cnt=now_cnt, ansN=0;
			if(now_cnt==max_cnt)
				excu[ansN++]=line;
		}
		
		sort(excu,excu+ansN);
		cout<<"Excuse Set #"<<caseI<<'\n';
		for(int i=0;i<ansN;i++)
			cout<<excu[i]<<'\n';
	}
}