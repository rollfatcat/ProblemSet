#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int n, w, v, map[101];

  while(cin>>n){
    memset(map,0,sizeof(map));
    for(int i=0;i<n;i++){
      cin>>w>>v;
      for(int j=100;j>=w;j--)
        map[j]=max(map[j],map[j-w]+v);
    }
    cout<<map[100]<<endl;
  }
}