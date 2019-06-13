// 算含有 2/3/5/7 所有的倍數(值<=2000000000 )
// 注意輸出時第N個開頭的字串

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxN 5842

vector<int>np[4], num;
int base[4]={2,3,5,7};
void DFS(int now,long long int x){
  if(now==4){
    if(x<=2000000000) num.push_back(x);
    return;
  }
  for(int i=0;i<np[now].size() and (x*np[now][i])<=2000000000;i++)
    DFS(now+1,x*np[now][i]);
}
string IdxToStr(int x){
  if(x%10==1 and x%100!=11) return "st";
  if(x%10==2 and x%100!=12) return "nd";
  if(x%10==3 and x%100!=13) return "rd";
  return "th";
}
int main(){
  for(int i=0;i<4;i++)
    for(long long int n=1; n<=2000000000; n*=base[i])
      np[i].push_back(n);
  DFS(0,1);
  sort(num.begin(),num.end());

  for(int idx; cin>>idx and idx; )
    cout<<"The "<<idx<<IdxToStr(idx)<<" humble number is "<<num[idx-1]<<".\n";
}