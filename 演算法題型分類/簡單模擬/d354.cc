// 簡單模擬，但是要注意把號碼從名單剔除的時機
// 要理解題目的規則說明需要花一段時間，需要計算的就是各個位數取n次方加總
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

int main(){

  for(int turn, x; cin>>turn;){
    vector<short> num;
    cin>>x, num.push_back(x);
    while(getchar()==' ')
      cin>>x, num.push_back(x);
    sort(num.begin(),num.end());
    vector<bool> out(256,0);
    for(int i=1;i<=turn;i++){
      // 用一個陣列把這一輪要踢除的號碼存起來
      // (不能一邊踢除一邊算要踢除的號碼，會有人『提早』被踢除)
      vector<short> menu;
      for(int j=0;j<num.size();j++)
        if(!out[ num[j] ]){
          int number=0;
          for(int x=num[j]; x>0 and number<=255;x/=10)
            number+=pow(x%10,i+1);
          if(number<=255) menu.push_back(number);
        }
      for(int j=0;j<menu.size();j++)
        out[ menu[j] ]=1;
    }
    for(int i=0;i<num.size();i++)
      if(!out[num[i]])
        cout<<num[i]<<' ';
    cout<<endl;
  }
}