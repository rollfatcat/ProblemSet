// 計算同時符合三個數列性質的數
/* 每次都挑選最小的值找該數列的下一項，直到三個數列的最後一項都相同
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
  vector<long> Tn, Pn, Hn;
  long Ti=286, Pi=166, Hi=144;
  Tn.push_back( Ti*(Ti+1)/2 ),
  Pn.push_back( Pi*(3*Pi-1)/2 ),
  Hn.push_back( Hi*(2*Hi-1) );
  while(true){
    if(Tn.back()==Pn.back() and Pn.back()==Hn.back()) break;
    int minN=min(min(Tn.back(),Pn.back()),Hn.back());
    if(Tn.back()==minN) Ti++, Tn.push_back( Ti*(Ti+1)/2 );
    if(Pn.back()==minN) Pi++, Pn.push_back( Pi*(3*Pi-1)/2 );
    if(Hn.back()==minN) Hi++, Hn.push_back( Hi*(2*Hi-1) );
  }
  cout<<Tn.back()<<'\n';
}