// 簡單的條件判斷＋getline()讀取測資(讀完測資數量後記得把後面的空白吃掉)
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  cin>>caseT>>ws;
  while(caseT--){
    string line, word;
    getline(cin,line);
    stringstream ss(line);

    bool moreTU=false;
    int eat=0, out=0;
    while(ss>>word){
      (word[0]=='c')? eat++: out++;
      moreTU|=(out>eat);
    }
    bool moreEat=(eat>out);

    if(moreTU){
      if(moreEat) cout<<"chi pu tao bu tu pu tao pi, bu chi pu tao dao tu pu tao pi\n";
      else cout<<"bu chi pu tao dao tu pu tao pi\n";
    }
    else{
      if(moreEat) cout<<"chi pu tao bu tu pu tao pi\n";
      else cout<<"chi pu tao tu pu tao pi\n";
    }

  }
}