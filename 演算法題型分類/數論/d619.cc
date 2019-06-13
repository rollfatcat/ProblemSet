// 計算 1~N之間二進位時1的個數
// 觀察規律，題解：https://home.gamer.com.tw/creationDetail.php?sn=4077023
#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000000

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
struct nn{int bound, cnt;};
int main(){
  vector<nn> num;
  num.push_back({0,0}),
  num.push_back({1,1});
  for(int len=2; num.back().bound<=100000000; len<<=1)
    num.push_back({ num.back().bound+len, len+(num.back().cnt<<1) });

  for(int N; scanInt(N); ){
    if(N==num[__lg(N)+1].bound){ cout<<num[__lg(N)+1].cnt<<endl; continue; }
    int sum_cnt=0;
    for(int L; N>0; N-=(1<<L))
      L=__lg(N),  sum_cnt+=num[L].cnt+(N-num[L].bound);
    printf("%d\n",sum_cnt%MOD);
  }
}