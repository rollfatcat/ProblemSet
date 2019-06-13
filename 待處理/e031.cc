// KMP 標準解
#include<bits/stdc++.h>
using namespace std;


vector<int> nxt;
inline void getNext(string ss){
  nxt.resize(ss.length());

  int j=0;
	int k=-1;
	nxt[j]=k;
	while(j<ss.length()){
		if(k==-1 or ss[j]==ss[k]){
      // 若滿足Ｐk=Ｐj的情況，則繼續比較下一個字元，並得next[j+1]=next[j]+1
			nxt[++j]=++k;
		}
		else // 若出現字元不匹配時，則依據next[k]繼續尋找下一個比較的位置
			k=nxt[k];
	}
  for(int i=0;i<ss.length();i++)
    cout<<nxt[i]<<' ';
  cout<<endl;
}
int main(){
  string ss;
  while(cin>>ss)
    getNext(ss);
}