// 參考網址：https://polarzcoding.blogspot.com/2017/09/tioj1420-mine.html
/* Disjoint Set的變形(一般是有向圖的形式描述)
 * Map+Pair的STL應用，Map是有紅黑數實作達成O(㏒Ｎ)查詢元素是否存在。
 * 如果以 Struct 搭配時需要告知比對的方法：定義 operator<
 * (1) 判斷疊合的方式(X)點A的9個位置對應點B的9個位置=>(O)點A是否落在點B的24個位置內
 * (2) 注意有種情況是這個點一加入剛好可以 Merge 好幾個群體，所以 Merge要重複判斷
 * 二維範圍過大(無法直接開這麼大的空間處理)用Map輔助或是將二維座標轉為一維座標
 */
#include<bits/stdc++.h>
using namespace std;
#define MaxN 50001

int dx[24]={ 0, 0, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 0, 0,-1,-1,-2,-2,-1,-2,-1,-2,-2,-1};
int dy[24]={ 1, 2, 1, 2, 2, 1, 0, 0,-1,-1,-2,-2,-1,-2,-1,-2,-2,-1, 0, 0, 1, 1, 2, 2};
int parent[MaxN];
struct POINT{
  short x, y;
  POINT(short a=0,short b=0):x(a),y(b){}
  bool operator<(const POINT &rhs)const{ return(x==rhs.x)?(y<rhs.y):(x<rhs.x); }
};
map<POINT,int> REC;

int GetP(int x){ return (x==parent[x])?x:parent[x]=GetP(parent[x]); }
void unite(int a,int b){ parent[GetP(a)]=GetP(b); }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int R,C,N;
  cin>>R>>C>>N;

  int Nowx, Nowy;
  for(int i=1;i<=N;i++){
    parent[i]=i;
    cin>>Nowx>>Nowy,
    REC[ POINT(Nowx,Nowy) ]=i;
    for(int j=0;j<24;j++){
      int x=Nowx+dx[j], y=Nowy+dy[j];
      if(1<=x and x<=R and 1<=y and y<=C and REC.count( POINT(x,y) ))
        unite(i,REC[ POINT(x,y) ]);
    }
  }
  vector<bool> isIn(N+1,0);
  int cnt=0, rt;
  for(int i=1;i<=N;i++){
    rt=GetP(i);
    if(isIn[rt]==0)
      cnt++,
      isIn[rt]=1;
  }
  cout<<cnt<<endl;
}