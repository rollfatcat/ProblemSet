// 用這題來講解FloydWall
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;


int main(){
  for(int N; cin>>N; ){

    int map[26][26];
    memset(map,0x3f,sizeof(map));
    char a, b;
    for(int v;N--;)  // 這個寫法會出現問題：dual Edge時會出現Error 必須保證兩點之間的值是最低COST
      cin>>a>>b>>v,  map[a-'A'][b-'A']=map[b-'A'][a-'A']=v;
    // Floyed-Warshall Main Function
    for(int k=0;k<26;k++)
      for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
          map[i][j]=min(map[i][j],map[i][k]+map[k][j]);

    cin>>a>>b;
    if(map[a-'A'][b-'A']==0x3f3f3f3f) cout<<"NoRoute"<<endl;
    else cout<<map[a-'A'][b-'A']<<endl;
  }
}