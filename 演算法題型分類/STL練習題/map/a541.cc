// 練習用map STL查詢某個key是否存在
#include<iostream>
#include<map>
using namespace std;

int main(){
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for(int n; cin>>n;){
    map<string,bool> Book;
    map<string,bool>::iterator iter;
    string ss;
    for(int i=0;i<n;i++)
      cin>>ss,  Book[ss]=1;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>ss, iter=Book.find(ss);
      if(iter==Book.end())
        cout<<"no"<<endl, Book[ss]=1;
      else
        cout<<"yes"<<endl;
    }
  }
}