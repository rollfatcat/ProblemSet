#include<iostream>
using namespace std;

int main(){
  int caseNum, x, y, n, m;
  cin>>caseNum;
  while(caseNum--)
    cin>>n>>x>>y>>m,  cout<< (n-m*y)/(x-y) <<' '<< (n-m*x)/(y-x) <<endl;
}