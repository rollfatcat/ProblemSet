/* 給定年份(1000-9999)，輸出所有可能在後面接上月份和日期後能形成的迴文字串？
 * 接上月份和日期的規則：當月份和日期是個位數時，可以當作單位數也可以在前面補０
 *              舉例：１月２日＝ 12/ 012/ 102/ 0102
 * 本題的二月份的天數需要考慮到"閏年"的情況：該年可以被４整除且 (1)不能被100整除 (2)能被100整除和400整除 
 */
#include<bits/stdc++.h>
using namespace std;

int year, month, day;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool CheckLeap(){
	return month==2 and (year&3)==0 and 
	      (year%100>0 or (year%100==0 and year%400==0));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int caseQ;
	string ss;
	cin>>caseQ;
	while(caseQ-->0){
		cin>>ss;
		year=1000*(ss[0]-'0')+100*(ss[1]-'0')+10*(ss[2]-'0')+ss[3]-'0';
		
		vector<string> ans;
		/* 測試長度６必須年份尾端的兩位數相同：YYYYMD */
		if(ss[2]==ss[3] and ss[1]>'0' and ss[0]>'0')
			ans.push_back(ss+ss[1]+ss[0]);
		/* 測試長度７：YYYYMMD */
		month=10*(ss[2]-'0')+ss[1]-'0';
		if( 0<month and month<=12 and ss[0]>'0')
			ans.push_back(ss+ss[2]+ss[1]+ss[0]);
		/* 測試長度７：YYYYMDD */
		month=ss[2]-'0'; 
        day=10*(ss[1]-'0')+ss[0]-'0';
		if(ss[2]>'0' and 0<day and day<=days[ss[2]-'0']+CheckLeap())
			ans.push_back(ss+ss[2]+ss[1]+ss[0]);
		/* 測試長度８：YYYYMMDD */
		month=10*(ss[3]-'0')+ss[2]-'0'; day=10*(ss[1]-'0')+ss[0]-'0';
		if(0<month and month<=12 and day<=days[month]+CheckLeap())
			ans.push_back(ss+ss[3]+ss[2]+ss[1]+ss[0]);
		
		cout<<ans.size();
		for(string s:ans)
			cout<<' '<<s;
		cout<<'\n';
	}
}
