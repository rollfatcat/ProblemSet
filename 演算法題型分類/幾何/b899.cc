// 給3個點算正方形的第4個點，正方形不一定平行座標軸
// 由3點中找到那組對角線的點對(算三邊中的等長兩邊的同一點即是遠端的點)
#include<iostream>
using namespace std;

struct nn{ int x,y; }node[4], tmp;
int main(){
  while(cin>>node[0].x>>node[0].y){
    cin>>node[1].x>>node[1].y>>node[2].x>>node[2].y;
    int D01=(node[0].x-node[1].x)*(node[0].x-node[1].x)+(node[0].y-node[1].y)*(node[0].y-node[1].y);
    int D02=(node[0].x-node[2].x)*(node[0].x-node[2].x)+(node[0].y-node[2].y)*(node[0].y-node[2].y);
    int D12=(node[1].x-node[2].x)*(node[1].x-node[2].x)+(node[1].y-node[2].y)*(node[1].y-node[2].y);
    if(D02==D12)  tmp=node[2], node[2]=node[0], node[0]=tmp;
    else if(D01==D12) tmp=node[1], node[1]=node[0], node[0]=tmp;
    node[3].x=node[1].x+node[2].x-node[0].x;
    node[3].y=node[1].y+node[2].y-node[0].y;
    cout<<node[3].x<<' '<<node[3].y<<endl;
  }
}