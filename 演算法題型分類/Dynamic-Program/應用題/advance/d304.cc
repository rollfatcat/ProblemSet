// 44ms/33MB vs 3.8s(DFS)
// 動態規劃預處理一次全部的方法數
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int CV[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<string> way[10001];
vector<int> base, power;
map<int,int> fac;
int N;

void DFS(int r, int mul){
  if(r==base.size())  return;
  DFS(r+1,mul);
  for(int i=1; i<=power[r]; i++)
    mul*=base[r], fac[mul]=1, DFS(r+1,mul);
}
bool compare(string a, string b){ return a<b; }
int main(){
  // 產生質數表, 找出小於10000的質數
  // 質數的方法數只會有1種而且最小次數就是質數本身
  // 這一題4是比較特別就額外預處理
  bool isCV[10001];
  fill(isCV,isCV+10001,0);
  int pre=1;
  string ss="C";
  for(int i=2;i<100;i++)
    if(isCV[i]==0){
      for(int j=0;j<(i-pre);j++)  ss+=" + V";
      way[i].push_back(ss), pre=i;
      for(int j=2;i*j<=10000;j++)
        isCV[i*j]=1;
    }
  for(int i=100;i<10000;i++)
    if(isCV[i]==0){
      for(int j=0;j<(i-pre);j++)  ss+=" + V";
      way[i].push_back(ss), pre=i;
    }
  way[4].push_back("C + V + C + V");
  way[4].push_back("C + V + V + V");
  while(cin>>N){
    if(way[N].size()==0){ // 沒計算過的
      // 做質因數分解
      base.clear(); power.clear();
      int num=N, p;
      for(int i=0;i<25 and num>1;i++)
        if(num%CV[i]==0){
          base.push_back(CV[i]);
          for(p=0;num%CV[i]==0;num/=CV[i])  p++;
          power.push_back(p);
        }
      //只要檢查sqrt(10000)以內的全部質數, 不能整除的部分一定也是質數
      if(num>1) base.push_back(num),  power.push_back(1);
      // 找出這個數字的所有因數
      fac.clear();
      DFS(0,1);
      // 利用iterator抓出每一個因數, 用Bottom-Up方式建出全部的方法數
      for(map<int,int>::iterator it=fac.begin(); it!=fac.end(); it++){
        int num=it->first;
        if(way[num].size()==0){
          for(int j=0;j<base.size();j++)
            if(num%base[j]==0)
              for(int l=0;l<way[base[j]].size();l++)
                for(int k=0;k<way[ num/base[j] ].size();k++)
                  way[num].push_back(way[base[j]][l]+" + "+way[ num/base[j] ][k]);
          if(num%4==0) // 4的部分額外判斷
            for(int k=0;k<way[num/4].size();k++)
              way[num].push_back(way[4][1]+" + "+way[num/4][k]);
          sort(way[num].begin(),way[num].end(),compare);
        }
      }
    }
    cout<<"min : "<<(way[N][0].length()-1)/4+1<<endl<<"way : "<<way[N].size()<<endl;
    for(int i=0;i<way[N].size();i++)
        cout<<"Ctrl "<<way[N][i]<<endl;
  }
}