/* 給定Ｓ個行程(開始時間、結束時間、行程名稱，依時間序給定)，輸出最久的休息時間(多組解，以起始時間早的優先)
 * 解題關鍵：計算２個字串型態的時間差
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxS=1e2;
int Calculate(string s1,string s2){ return 600*(s2[0]-s1[0])+60*(s2[1]-s1[1])+10*(s2[3]-s1[3])+(s2[4]-s1[4]); }
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int S;
	string start, end, appointment;
	for(int caseI=1; cin>>S; caseI++){
		string pvt="10:00";
		string ans;
		int maxT=0, nowT;
		while(S-->0){
			cin>>start>>end;
			getline(cin,appointment);
			nowT=Calculate(pvt,start);
			if(nowT>maxT)
				maxT=nowT, ans=pvt;
			pvt=end;
		}
		nowT=Calculate(pvt,"18:00");
		if(nowT>maxT)
			maxT=nowT, ans=pvt;
        /* 輸出格式：需要把大於等於６０的分鐘數轉為 hh:mm */
		cout<<"Day #"<<caseI<<": the longest nap starts at "<<ans<<" and will last for ";
		if(maxT>=60)
			cout<< maxT/60 <<" hours and "<< maxT%60 <<" minutes.\n";
		else
			cout<< maxT <<" minutes.\n";
	}
}