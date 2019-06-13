#include<iostream>
using namespace std;

int partner[50000]={};
bool InGroup[50000]={};

void Union(int now){
  if(InGroup[now])
    return;
  InGroup[now]=true;
  Union(partner[now]);
}

int main(void){
  int cnt;
  while(cin>>cnt){
    for(int i=0;i<cnt;i++){
      cin>>partner[i];
      InGroup[i]=false;
    }
    int num_Group=0;
    for(int i=0;i<cnt;i++)
      if(!InGroup[i]){
        Union(i);
        num_Group++;
      }
    cout<<num_Group<<endl;
  }
}