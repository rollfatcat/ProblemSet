/* 給定Ｎ種類型的Key和該類型Key的數量應該有Ｍ個，輸入ＮＭ-1個Key，輸出少一個的Key名稱
 * Key長度不超過1000個字元，但Ｎ最多有1e7個。
 * 直覺：map<string,int> 紀錄但Key的數量會高達1e7個導致SE...。
 * 類推：Ｍ=2時, d708
 *      Ｍ=3時, e319
 *      Ｍ不確定時, c489
 * 概念：Key的長度不超過1e3，對於每個字元位置出現的字元個數必定是Ｍ的倍數，除了缺失一個的以外。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7;
const int MaxM=25;
const int MaxL=1e3;
const int MaxASCii=256;

int key[MaxL][MaxASCii];
string Kss;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N, M;
	while(cin>>N>>M and N){
		memset(key,0,sizeof(key));
		getline(cin,Kss);
		for(int i=1;i<N*M;i++){
			getline(cin,Kss);
			for(int j=0;Kss[j]!='\0';j++)
				key[j][Kss[j]]++;
		}
		for(int ch,i=0;i<MaxL;i++){
			for(ch=0;ch<MaxASCii and (key[i][ch]%M)==0;ch++);
			cout<<( (ch==MaxASCii)? '\n': (char)ch );
			if(ch==MaxASCii) break;
		}
	}
}