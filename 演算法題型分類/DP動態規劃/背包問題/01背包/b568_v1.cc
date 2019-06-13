// 利用bool陣列紀錄是否重複，運算後找到最大的值
// set可以排序＋濾除重複的數字(但插入的成本高)，所以才採用上面的搭配
#include<iostream>
#include<vector>
using namespace std;
#define UpBound 700000

bool is[UpBound+1];
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int w, cnt, i;
  cin>>cnt;
  vector<int>num;
  for(i=0; i<cnt; i++){
    cin>>w;
    for(int j=num.size()-1; j>=0; j--){ // 從反向讀取避免新的數字到num時會出現錯誤
      int v=(num[j]+w-1)%UpBound+1;
      if(!is[v]) num.push_back(v), is[v]=1;
    }
    if(!is[w]) num.push_back(w), is[w]=1;
  }
  int maxN=0;
  for(int i=0;i<num.size();i++)
    if(maxN<num[i])
      maxN=num[i];
  cout<<maxN<<endl;
}