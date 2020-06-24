/* 解法是 C++的 multiset
 * BinarySearch+vector會TLE
 */
#include<iostream>
#include<set>
using namespace std;

multiset<int> S;
multiset<int>::iterator it;

int main(){
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for(int n;cin>>n and n;){
    if(n==-1){
      if(S.size()==0) continue;
      it=S.begin();
      cout<< *it <<' ', S.erase(it);
    } else if(n==-2){
      if(S.size()==0) continue;
      it=S.end(), it--;
      cout<< *it <<' ', S.erase(it);
    } else
      S.insert(n);
  }
}