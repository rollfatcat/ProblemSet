// 算 2^1000次方的位數和
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  unsigned long long int base=1000000000000000000; // 1e18
  vector<unsigned long long int> power2[1001];
  power2[0].push_back(1);
  for(int p=1;p<=1000;p++){
    unsigned long long int carry=0;
    for(int i=0; i<power2[p-1].size(); i++)
      power2[p].push_back((power2[p-1][i]<<1)+carry), carry=power2[p][i]/base, power2[p][i]%=base;
    if(carry) power2[p].push_back(carry);
  }
  int Dsum=0;
  for(int len=power2[1000].size()-1;len>=0;len--)
    for(unsigned long long int x=power2[1000][len]; x; x/=10)
      Dsum+=x%10;
  cout<<Dsum<<endl;
}
