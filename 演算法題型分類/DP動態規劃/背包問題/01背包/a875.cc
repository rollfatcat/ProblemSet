// 0/1背包的微變形版本, 沒有精確度問題(別怕)
#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string, double>Book;
int main(){
  Book["Cu"]=1.730, Book["Zn"]=1.130, Book["H2O"]=3.720,
  Book["Fe"]=0.410, Book["Si"]=0.320, Book["Mg"]=3.460,
  Book["C"] =2.750, Book["Ag"]=190.629,
  Book["Pt"]=25000.000, Book["Au"]=12260.000;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for(int bag, fuel, back; cin>>fuel>>back>>bag;){
    fuel-=back;
    vector<double> DP(bag+1,0.0);
    string ss;
    bool keep=true;
    for(int f, w; cin>>f>>ss>>w and ss!="X"; ){
      if(fuel<f)  keep=false;
      if(keep){
        fuel-=f;
        double v=w*Book[ss];
        for(int i=bag;i>=w;i--)
          DP[i]=max(DP[i],DP[i-w]+v);
      }
    }
    while(DP[bag]==DP[bag-1]) bag--;
    printf("kg=%d value=%.1lf\n",bag,DP[bag]);
  }
}