// 題目輸入的字串解析相當複雜，不需要考慮精確度的問題直接計算即可
// map 和 pair 的搭配使用
#include<bits/stdc++.h>
using namespace std;

const double unit=sqrt(1.0/2.0);
map<string,pair<int,int> > table;
int main(){
  // 建表：將字串轉換成向量
  table["N"] =make_pair( 0, 1);
  table["S"] =make_pair( 0,-1);
  table["W"] =make_pair(-1, 0);
  table["E"] =make_pair( 1, 0);
  table["NW"]=make_pair(-1, 1);
  table["SW"]=make_pair(-1,-1);
  table["NE"]=make_pair( 1, 1);
  table["SE"]=make_pair( 1,-1);

  string ss, dir;
  for(int caseN=0;cin>>ss and ss[0]<'E';){
    if(caseN++) cout<<endl;
    cout<<"Map #"<<caseN<<"\n";
    double posx=0.0, posy=0.0;
    int number;
    for(int i=0;i<ss.length();i++){
      for(number=0;ss[i]>='0' and ss[i]<='9';i++)
        number=(number<<3)+(number<<1)+ss[i]-'0';
      for(dir="";ss[i]>='A';i++)
        dir+=ss[i];
      double len=(dir.length()==2)?unit:1.0;
      posx+=table[dir].first*number*len,
      posy+=table[dir].second*number*len;
    }
    printf("The treasure is located at (%.3lf,%.3lf).\n",posx,posy);
    printf("The distance to the treasure is %.3lf.\n",sqrt(posx*posx+posy*posy));
  }
}