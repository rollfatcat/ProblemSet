#include<iostream>
#include<vector>
using namespace std;

int cnt=0;
int pos_y[12];
bool Pslash[23]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool Nslash[23]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool col[12]={1,1,1,1,1,1,1,1,1,1,1,1};
bool *ps=&Pslash[0];  // /  範圍變化：x+y =   0 ~ 22
bool *ns=&Nslash[12];  // \  範圍變化：x-y = -11 ~ 11
int n;
void DFS(int x){
  if(x==n){
    for(int i=0;i<n;i++)
      cout<<pos_y[i]<<' ';
    cout<<endl;
    return;
  }
  for(int i=0;i<n;i++)
    if(col[i] and ps[x+i] and ns[x-i]){
      pos_y[x]=i+1;
      col[i]=ps[x+i]=ns[x-i]=0;
      DFS(x+1);
      col[i]=ps[x+i]=ns[x-i]=1;
    }
}
int main(){
  while(cin>>n)
    DFS(0);
}