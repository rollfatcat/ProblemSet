#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxT=1e9;
 
int dat[MaxN][3];
int srt[MaxN<<1]; // 出現變化量的時間點
int add[MaxN<<1][2]={};
 
int main(){
	int N;
 
	// input
	cin>>N;
	for(int n=0; n<N; n++){
		cin>>dat[n][0]>>dat[n][1]>>dat[n][2];
		dat[n][0]-=1;
		srt[ n ]=dat[n][1];
		srt[N+n]=dat[n][2];
	}
	//(1) 離散化
	sort(srt,srt+(N<<1));
	int uN=unique(srt,srt+(N<<1))-srt;
	//(2) 計算變化量
	for(int n=0; n<N; n++){
		add[ lower_bound(srt,srt+uN,dat[n][1])-srt ][ dat[n][0] ]+=1;
		add[ lower_bound(srt,srt+uN,dat[n][2])-srt ][ dat[n][0] ]-=1;
	}
	// (3) 知道每個時間點的人數
	int p0=0;
	int p1=0;
	int on_s=0; // 現在狀態是不是在錄影
	int ans_c=0; // 紀錄目前答案存到哪個位置
	for(int n=0; n<uN; n++){
		p0+= add[n][0];
		p1+= add[n][1];
		// 錄影狀態下：什麼時候要卡掉
		if(on_s and (p0==0 or p1>0)){
			dat[ans_c][1]=srt[n];
			ans_c+=1;
			on_s=0;
		}
		// 沒有在錄影：什麼要按下 start
		if(on_s==0 and p0>0 and p1==0){
			dat[ans_c][0]=srt[n];
			on_s=1;
		}
	}
	cout<<ans_c<<'\n';
	for(int o=0; o<ans_c; o++)
		cout<<dat[o][0]<<' '<<dat[o][1]<<'\n';
}