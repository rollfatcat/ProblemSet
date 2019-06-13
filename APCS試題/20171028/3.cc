#include<iostream>
using namespace std;

int cnt, root;
int parent[100001]={};
int height[100001]={};
void FindRoot(int no, int h){
  int p=parent[no];
  if(p==0){
    root=no;
    return;
  }
  if(height[p]<h)
    height[p]=h;
  FindRoot(parent[no],h+1);
}
int main(){

  while(cin>>cnt){
  //
  root=0;
  for(int i=1;i<=cnt;i++){
    height[i]=0;
    parent[i]=0;
  }
  int num=0;
  int leaf[100000]={};
  //
  for(int i=1;i<=cnt;i++){
    int num_child;
    cin>>num_child;
    if(num_child==0)
      leaf[num++]=i;
    else
      for(int j=1;j<=num_child;j++){
        int no;
        cin>>no;
        parent[no]=i;
      }
  }
  //

  //
  for(int i=0;i<num;i++)
    FindRoot(leaf[i],1);
  long int sum=0;
  for(int i=1;i<=cnt;i++)
    sum+=height[i];
  cout<<root<<endl<<sum<<endl;
  }
}
