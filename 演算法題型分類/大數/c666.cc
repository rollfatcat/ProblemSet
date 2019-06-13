// 找前n個質數的乘積, n<=5000, 建表做大數乘法
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int preLen=1, prime[5000]={2}; //5000th質數=48611
  long long int base=10000000000000; // 1e13
  vector<long long int>mul[5000];
  mul[0].push_back(2);
  for(int num=3, cnt=1, idx; cnt<5000; num+=2){
    for(idx=0;idx<cnt and num%prime[idx];idx++);
    if(idx==cnt){ // n=質數
      long long int carry=0;
      for(int i=0; i<preLen; i++)
        mul[cnt].push_back(mul[cnt-1][i]*num+carry),
        carry=mul[cnt][i]/base, mul[cnt][i]%=base;
      if(carry) mul[cnt].push_back(carry),  preLen++;
      prime[cnt++]=num;
    }
  }
  //
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int n;cin>>n;){
    n--;
    printf("%llu",mul[n].back());
    for(int len=mul[n].size()-2;;len>=0;len--)
      printf("%013llu",mul[n][len]);
    printf("\n");
  }
}