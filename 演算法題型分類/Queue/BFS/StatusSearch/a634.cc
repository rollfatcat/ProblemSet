#include<bits/stdc++.h>
using namespace std;

int dis[8][8];
const int INF=1<<30;
struct NODE{
	int x, y, d;
	string ss;
	NODE(int x=0,int y=0,int d=0,string ss=""):x(x),y(y),d(d),ss(ss){}
} ;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string ss;
	string s1="87654321", s2="abcdefgh";
	while(cin>>ss){
		NODE st=NODE('8'-ss[1],ss[0]-'a',0,ss);
		cin>>ss;
		NODE ed=NODE('8'-ss[1],ss[0]-'a');
		/* BFS 的特性：第一次走到該格子代表從起點到這一格即是最短距離
     	* 設定每一格為『走不到』的狀態：距離＝INF
     	* 障礙物：距離＝0代表無法更新
     	*/
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				dis[i][j]=INF;
		while(cin>>ss and ss[0]!='x')
			dis['8'-ss[1]][ss[0]-'a']=0;
    /* BFS：求起點到終點的『所有』『最短』『路徑』
     * 抵達同一格時可能存在不同路徑，所以不能因為走過而捨棄掉這格往周圍展開
     * 判斷方式需要改為：當現在距離>目前這格紀錄的最短路徑時則 pass，代表一定有繞遠路
     * 對於終點則是『更新第一次』時需要印出『最少步數』
     *           『現在的步數＝最少步數』時則印出路徑後 pass(不需要再展開)
     */
		queue<NODE> Q;
		for(Q.push(st);Q.empty()==0;Q.pop()){
			NODE now=Q.front();
			if(now.d>dis[ed.x][ed.y]) break;
			if(now.x==ed.x and now.y==ed.y){
				if(dis[ed.x][ed.y]>now.d)
					dis[ed.x][ed.y]=now.d,
					cout<<"The shortest solution is "<<now.d<<" move(s)."<<'\n';
				if(dis[ed.x][ed.y]==now.d)
					cout<<"Solution: "<<now.ss<<'\n';
        		continue;
			}
			if(now.d>dis[now.x][now.y]) continue;
			dis[now.x][now.y]=now.d;
			if(now.y>1){
				if(now.x<7 and dis[now.x+1][now.y-2]>now.d)
					Q.push(NODE(now.x+1,now.y-2,now.d+1,now.ss+' '+s2[now.y-2]+s1[now.x+1]));
				if(now.x>0 and dis[now.x-1][now.y-2]>now.d)
					Q.push(NODE(now.x-1,now.y-2,now.d+1,now.ss+' '+s2[now.y-2]+s1[now.x-1]));
			}
			if(now.y>0){
				if(now.x<6 and dis[now.x+2][now.y-1]>now.d)
					Q.push(NODE(now.x+2,now.y-1,now.d+1,now.ss+' '+s2[now.y-1]+s1[now.x+2]));
				if(now.x>1 and dis[now.x-2][now.y-1]>now.d)
					Q.push(NODE(now.x-2,now.y-1,now.d+1,now.ss+' '+s2[now.y-1]+s1[now.x-2]));
			}
			if(now.y<7){
				if(now.x<6 and dis[now.x+2][now.y+1]>now.d)
					Q.push(NODE(now.x+2,now.y+1,now.d+1,now.ss+' '+s2[now.y+1]+s1[now.x+2]));
				if(now.x>1 and dis[now.x-2][now.y+1]>now.d)
					Q.push(NODE(now.x-2,now.y+1,now.d+1,now.ss+' '+s2[now.y+1]+s1[now.x-2]));
			}
			if(now.y<6){
				if(now.x<7 and dis[now.x+1][now.y+2]>now.d)
					Q.push(NODE(now.x+1,now.y+2,now.d+1,now.ss+' '+s2[now.y+2]+s1[now.x+1]));
				if(now.x>0 and dis[now.x-1][now.y+2]>now.d)
					Q.push(NODE(now.x-1,now.y+2,now.d+1,now.ss+' '+s2[now.y+2]+s1[now.x-1]));
			}
		}
		
	}
}