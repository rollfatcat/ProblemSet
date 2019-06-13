#include<bits/stdc++.h>
using namespace std;

struct Time{
  int H, M;
  bool operator<(const Time &other)const{
    return(H==other.H)?(M<other.M):(H<other.H);
  }
};
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(Time t1,t2; cin>>t1.H>>t1.M>>t2.H>>t2.M; ){
    if(t2<t1){
      t2.M+=(60-t1.M),  t2.H+=(23-t1.H);
      if(t2.M>=60)  t2.M-=60, t2.H++;
    }else{
      t2.M-=t1.M;
      if(t2.M<0) t2.M+=60, t2.H--;
      t2.H-=t1.H;
    }
    cout<<t2.H<<' '<<t2.M<<'\n';
  }
}