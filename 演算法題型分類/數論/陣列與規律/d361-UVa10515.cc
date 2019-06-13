
#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<short> cycle[10];
  for(short idx=0; idx<=9;idx++){
    cycle[idx].push_back(idx);
    for(short num=idx*idx%10; num!=cycle[idx][0]; num=num*idx%10)
      cycle[idx].push_back(num);
  }
  ios::sync_with_stdio(0), cin.tie(0);
  for(string Nss,Mss; cin>>Mss>>Nss; ){
    if(Nss=="0"){
      if(Mss=="0")  break;
      puts("1"); continue;
    }
    short base=Mss[Mss.length()-1]-'0';
    short power=Nss[Nss.length()-1]-'0';
    if(Nss.length()>=2) power+=10*Nss[Nss.length()-2]-'0';
    power=(power-1)%cycle[base].size();
    putchar(cycle[base][power]+'0');
    putchar('\n');
  }
}