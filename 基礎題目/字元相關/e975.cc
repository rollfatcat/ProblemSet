/* 凱薩加密規則：大(小)寫字母往左Ｋ格偏移。
 * 還原＝密文將個別字母往右偏移
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=1e3;

char MapCH[26][27]={"abcdefghijklmnopqrstuvwxyz"};
char mask[4]={"ove"};
int minK;
string ss;
inline int Decode(int now,int shift=INF){
	// 這個字元對應到 'L'或是'l' 推算出位移的數量。
	if('A'<=ss[now] and ss[now]<='Z') shift=('L'-ss[now]+26)%26;
	if('a'<=ss[now] and ss[now]<='z') shift=('l'-ss[now]+26)%26;
	// 這個字元不是"字母"，直接跳到下個字元開始
	if(shift==INF) return now+1; 
	/* 檢查後面的３個字元是否依序對應到"ove"
	 * 對應的是小寫字母，若不符合還原的字元則從這個字元開始
	 * 對應的是大寫字母，則從這個字元開始
	 * 對應的是其他字母，則從下個字元開始
	 */
	for(int i=0;mask[i]!='\0';i++){
		now++;
		if('a'<=ss[now] and ss[now]<='z'){
			if(MapCH[shift][ss[now]-'a']!=mask[i])
				return now; 
		}else if('A'<=ss[now] and ss[now]<='Z')
			return now;
		else
			return now+1;
	}
	// 存在Ｋ，使得這個字元開頭能找到對應。
	minK=min(minK,shift);
	return now+1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	// 解密表：反凱薩加密，將字母往左位移Ｋ格(枚舉Ｋ種可能)
	for(int i=0;i<26;i++)
		for(int j=1;j<26;j++)
			MapCH[j][(i-j+26)%26]=MapCH[0][i];
	while(getline(cin,ss)){
		minK=INF;
		for(int i=0;i<ss.length()-3;i=Decode(i));
		cout<<minK<<'\n';
	}
}