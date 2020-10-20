/* 給定Ｎ條雙向聯通的路線(但並未告知站數)和起點、終點，輸出兩站間最低的花費？
 * 路線：兩個字串各自代表站Ａ和站Ｂ，而字串開頭第一個字元為大寫代表不同的捷運路線，字串後續的數字為號碼。
 * 站Ａ到站Ｂ的花費計算方式：(1)基本票價１０元 (2)每經過３站多加５元 (3)每次轉換不同路線時需要多加５元。
 * 解題關鍵： HashTable＋Dijkstra(PriorityQueue)，優先展開花費最低的點
 * 狀態紀錄：目前所在哪一站、距離起點的站數、轉換路線的次數、從起點抵達此站時的花費(前兩者是計算花費必須的)
 * 建圖表路線的端點站、起點、終點代表字串需要轉換為「數字」才能做 Dijkstra。
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxPathCnt=500;
struct STATUS{
	int node, step, color, cost;
	STATUS(int n=0,int s=0,int c=0,int v=0):node(n),step(s),color(c),cost(v){}
	bool operator<(const STATUS &rhs)const{ return cost>rhs.cost; }
};
 
vector<string> Node;
vector<int> min_cost;
map<string,int> HashTable;
vector<int> to[1000];
/* 輸入：字串代表的站名
 * 輸出：車站的編號
 * 若是該字串第一次加入表格中，同時初始化相關需要的資訊( Dijkstra需要的點、紀錄抵達的其他站、目前這個編號的站名 )。
 */
int GetNodeID(string &ss){
	if(HashTable.find(ss)==HashTable.end()){
		min_cost.push_back(INT_MAX);
		to[Node.size()].clear();
		HashTable[ss]=Node.size();
		Node.push_back(ss);
	}
	return HashTable[ss];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int PathCnt, u, v;
	string ss_u, ss_v;
	while(cin>>PathCnt){
		Node.clear();
		min_cost.clear();
		HashTable.clear();
		/* 建表 */
		while(PathCnt-->0){
			cin>>ss_u>>ss_v;
			u=GetNodeID(ss_u);
			v=GetNodeID(ss_v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		cin>>ss_u>>ss_v;
		int st=GetNodeID(ss_u);
		int ed=GetNodeID(ss_v);
		/* Dijkstra */
		priority_queue<STATUS,vector<STATUS>> PQ;
		PQ.push(STATUS(st,1,0,10));
		while(PQ.empty()==0){
			STATUS now=PQ.top(); PQ.pop();
			if(min_cost[now.node]<INT_MAX) 
				continue;
			min_cost[now.node]=now.cost;
			if(now.node==ed) 
				break;
			for(int nxt:to[now.node])
				if(min_cost[nxt]==INT_MAX){
					int color_cnt=now.color+(Node[now.node][0]!=Node[nxt][0]);
					PQ.push( STATUS(nxt,now.step+1,color_cnt,10+5*(color_cnt+now.step/3)) );
				}
		}
		cout<<min_cost[ed]<<'\n';
	}
}