// 原題目是多組解只要輸出其中一組即可(但測資只提供一組)

#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, hN;
  int org[105];
  int min_cnt[9];
  int sumn[2]={};
  vector<short> pos[2][9];

  cin>>N; hN=N>>1;
  for(int i=0;i<hN;i++){
    cin>>org[i];
    (org[i]<0)? pos[0][-org[i]].push_back(i): sumn[0]+=org[i];
  }
  for(int i=hN;i<N;i++){
    cin>>org[i];
    (org[i]<0)? pos[1][-org[i]].push_back(i): sumn[1]+=org[i];
  }
  // 兩倆對消(把該位置的值設為１)
  for(int i=1;i<=8;i++){
    min_cnt[i]=min(pos[0][i].size(),pos[1][i].size());
    for(int j=0;j<min_cnt[i];j++)
      org[ pos[0][j] ]=1,
      org[ pos[1][j] ]=1,
      sumn[0]+=1, sumn[1]+=1;
  }
  //
  bool possible=true;
  int a, b;
  if(sumn[0]>sumn[1]) a=0, b=1;
  else a=1, b=0;

  if(sumn[a]!=sumn[b]){
    int var_num=0;
    for(int i=1;i<=8;i++){
      sumn[a]+=pos[a][i].size()-min_cnt[i],
      var_num+=pos[b][i].size()-min_cnt[i];
      for(int j=min_cnt[i];j<pos[a].size();j++)
        org[ pos[a][j] ]=1;
    }
    if((var_num*10)<(sumn[a]-sumn[b])){
      possible=false; break;
    }

  }

}