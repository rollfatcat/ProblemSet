#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxN 500000

struct node{ int x, y; } points[MaxN];
bool compare(node a,node b){ return (a.x==b.x)?(a.y<b.y):(a.x<b.x); }
int main(){
  int N;
  for(int t=1;cin>>N;t++){
    for(int i=0;i<N;i++)
      cin>>points[i].x>>points[i].y;
    sort(points,points+N,compare);
    vector<node>ans;
    int base=-1;
    for(int i=N-1;i>=0;i--)
      if(points[i].y>base)
        ans.push_back(points[i]), base=points[i].y;

    cout<<"Case "<<t<<":\n";
    cout<<"Dominate Point: "<<ans.size()<<endl;
    for(int i=ans.size()-1;i>=0;i--)
      cout<<'('<<ans[i].x<<','<<ans[i].y<<")\n";
  }
}