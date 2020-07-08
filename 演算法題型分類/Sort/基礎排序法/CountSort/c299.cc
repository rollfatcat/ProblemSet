// 只要找最大/最小值時請不要Sort => 說明只要比較O(n)次就可以同時找到最大最小值
// 題目有保證給的數字不會重複 => 檢查最大最小值的差是否等於個數即可
#include<iostream>
using namespace std;

int main(){
  int n, maxN, minN, num;

  cin>>n>>maxN, minN=maxN;
  for(int i=1;i<n;i++)
    cin>>num,
    maxN=(maxN<num)?num:maxN,
    minN=(minN>num)?num:minN;
  cout<<minN<<' '<<maxN<<' '<<((maxN-minN+1==n)?"yes":"no")<<endl;
}