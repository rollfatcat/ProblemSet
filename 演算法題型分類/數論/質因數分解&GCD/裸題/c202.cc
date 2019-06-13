// GCD的水題
#include<iostream>
#include<vector>
using namespace std;

long GCD(long a,long b){ return(a%b)?GCD(b,a%b):b; }
vector<int> prime, p2;
int main(){
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for(int n; cin>>n; ){
    long a, b, gcd;
    cin>>a>>b;
    gcd=GCD(a,b);
    for(int i=2;i<n;i++)
      cin>>a, gcd=GCD(gcd,a);
    cout<<gcd<<endl;
  }
}