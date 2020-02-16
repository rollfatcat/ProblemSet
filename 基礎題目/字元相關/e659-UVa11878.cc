/* 給定一個算式(格式只有 Ａ+Ｂ=Ｃ 或 Ａ-Ｂ=Ｃ)
 * 變數(Ａ/Ｂ/Ｃ)可能會用 '？' 代替，則此時這題視為不正確
 * 若符合運算結果則答對題數＋1，最後輸出全部答對的題數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;// T＜100
int main(){
	ios::sync_with_stdio(0),
	cin.tie(0), cout.tie(0);
	
	int AC=0, num[3], idx, cnt, IsAdd;
	string ss;
	while(cin>>ss){
		num[0]=num[1]=num[2]=0;
		for(idx=cnt=0; ss[idx]!='\0';idx++){
			if(ss[idx]=='?')  break;
			if('0'<=ss[idx] and ss[idx]<='9') // 將字串轉換為數字
				num[cnt]=10*num[cnt]+ss[idx]-'0';
			else{ // 運算符號(+/-/=)
				cnt++;
				if(ss[idx]!='=')
					IsAdd=ss[idx]=='+';
			}
		}
		if(ss[idx]=='?')  continue;
		if(ss[idx]=='\0') cnt++;
		AC+=( (IsAdd    and num[0]+num[1]==num[2]) or 
				(IsAdd==0 and num[0]-num[1]==num[2]) );
	}
	cout<<AC<<'\n';
}