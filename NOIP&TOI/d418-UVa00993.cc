 // 原先的要求應該是輸入的數字必須只能由2/3/5/7構成
 // 簡單剪枝, 如果無法被2/3/5/7整除那一定輸出-1, 除非輸入是1
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int T, x;

  cin>>T;
  while(T--){
    cin>>x;
    if(x==1) //把 1 當specialcase處理
      cout<<1<<endl;
    else if( x%2 and x%3 and x%5 and x%7 ) //簡單剪枝
      cout<<-1<<endl;
    else{
      vector<int> num;
      for(int i=9;i>=2 and x>1;i--)
        for( ;x%i==0 and x>1;x/=i)
          num.push_back(i);
      if(x==1) // 可以用2/3/5/7構成原先的數字
        for(int i=num.size()-1;i>=0;i--)
          cout<<num[i];
      else
        cout<<-1;
      cout<<endl;
    }
  }
}