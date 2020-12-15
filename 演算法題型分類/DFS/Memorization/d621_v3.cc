/* 給定Ｎ，根據「兔子跳鈴鐺」的計分規則，輸出所有分數總和剛好等於Ｎ的方法(輸出順序加法優於乘法)？
 * 分數計算方式採計兔子跳鈴鐺的遊戲規則：由左而右的運算順序且加法和乘法的權重相同
 * 解題關鍵：DepthFirstSearch＋DP-BottomUp做一次
 * 從 "1" 展開一次，展開的順序加法優於乘法，每次算出新的值就紀錄到對應的 vector 。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=400;
string nss[29]={
  "0","1","2","3","4","5","6","7","8","9","10",
  "11","12","13","14","15","16","17","18","19","20",
  "21","22","23","24","25","26","27","28"};
vector<string> table[MaxN+1];
 
void DFS(int score,int now,string ss){
  if(score+now>MaxN)  return;
  /* 加法優先展開 */
  ss+=" + "+nss[now];
  score+=now;
  table[score].push_back(ss);
  DFS(score,now+1,ss);
  /* 乘法展開順序延後，所以每多一個乘以２就越後面展開 */
  for( score<<=1; score<=MaxN; score<<=1){
    ss+=" * 2";
    table[score].push_back(ss);
    DFS(score,now+1,ss);
  }
}
int main(){
	/* tabulation */
	string ss="1";
	int score=1;
	table[score].push_back(ss);
  DFS(score,2,ss);
  for(score<<=1; score<=MaxN; score<<=1){
    ss+=" * 2";
    table[score].push_back(ss);
    DFS(score,2,ss);
	}
 
	/* main */
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	while(cin>>N and N>0){
		if(table[N].empty()){ 
			cout<<"cheat!\n"; 
		}else
			for(string ss: table[N])
				cout<<ss<<'\n';
	}
}