// 同 c083-UVa00130
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n, k;

  while(cin>>n>>k){
    vector<int> num;
    for(int i=1;i<=n;i++)
      num.push_back(i);
    for(int N=n, now=(k-1)%N, nxt=0; N>1; ){
      // 找到埋葬者的號碼, 此時死者已經不再計算的人數當中
      // 找到埋葬者的號碼在死者後面的位置時記得要+1, 對應回原先的死者還活著時位置
      nxt=(now+k-1)%(N-1);
      if(nxt>=now)  nxt++;
      // 埋葬者的號碼 站到 剛剛死者的位置
      num[now]=num[nxt];
      // 消除埋葬者的位置
      num.erase(num.begin()+nxt);
      N--;
      // 刪除埋葬者時注意 死者的位置是不是在埋葬者的後面, Y代表下一次算k-1個, N代表下一次算k個
      now=(now+k-(now>nxt))%N;
    }
    cout<<(n-num[0]+1)%n+1<<endl;
  }
}