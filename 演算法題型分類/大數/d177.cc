// 題目沒說, 不過輸入的測資都是『整數』
// 模擬整除的方式,除數是字串讀入
#include<iostream>
using namespace std;

int main(){
  int caseNum, x, i, l;

  for(cin>>caseNum; caseNum--; ){
    string ss;
    cin>>ss;
    l=(3<ss.length())?3:ss.length();
    for(x=i=0; i<l; i++)
      x=x*10+ss[i]-'0';
    for(i=l;i<ss.length();i++)
      x=10*(x%360)+ss[i]-'0';
    cout<<x%360<<endl;
  }
}