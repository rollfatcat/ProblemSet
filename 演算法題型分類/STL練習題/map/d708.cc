// 題目要求輸出『無法成對』的數字(map解)，可用XOR的特性解題
// 說明 map 存的方式是n㏒n查詢是否有該元素,且需要記憶體=> 0.4s/31MB
#include<iostream>
#include<map>
using namespace std;

int main(){
  cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);

  map<long,int> Book;
  map<long,int>::iterator it;
  int N;
  cin>>N, N--;
  for(long x;N--;){
		cin>>x;
		if(Book.find(x)==Book.end())  Book[x]=1;
		else  Book[x]++;
  }
	for(it=Book.begin();it!=Book.end();it++)
	  if(it->second%2){
      cout<<it->first<<endl; break;
	  }
}