/* 給定目標字串(由大寫字元和空白組成)和剪報出現的大寫字母，輸出能拼湊出的目標字串？
 * 無視空白個數。
 * 解題關鍵：統計每個大寫字母個數 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=100;
int cnt[128];
string target, paper;
int main(){
   	ios::sync_with_stdio(0);
   	cin.tie(0); cout.tie(0);
   
   	while(getline(cin,target)){
   		getline(cin,paper);
   		fill(cnt,cnt+128,0);
   		for(int i=0;paper[i]!='\0';i++)
   			if('A'<=paper[i] and paper[i]<='Z')
   				cnt[paper[i]]++;
   		for(int i=0;target[i]!='\0';i++){
   			if('A'<=target[i] and target[i]<='Z')
   				if(cnt[target[i]]==0)
   					break;
   				else
   					cnt[target[i]]--;
   			cout<<target[i];
   		}
   		cout<<'\n';
   }
}
