// 有趣的遞迴題目：二進位制的輾轉相除法
#include<iostream>
#include<cstring>
using namespace std;

bool compare(string A, string B){
  if(A.length()==B.length())
    for(int i=0;i<A.length();i++)
      if(A[i]!=B[i])
        return A[i]>B[i];
  return A.length()>=B.length();
}
string GCD(string A, string B){
  if(A==B or B=="0") return A;
  int Alen=A.length(), Blen=B.length();
  if(A[Alen-1]!=B[Blen-1]){
    if(!A[Alen-1]){ A=A.substr(0,Alen-1); return (compare(A,B))?GCD(A,B):GCD(B,A); }
    else{ return GCD(A,B.substr(0,Blen-1)); }
  }else{
    if(!A[Alen-1]){  return GCD(A.substr(0,Alen-1),B.substr(0,Blen-1))+'0';  }
    else{ // 模擬輾轉相除法 => 等同大數除法
      for(int st=0,ed=Blen-1; ed<Alen; ed++){
        if(compare(A.substr(st,ed-st+1),B)){
          for(int i=0;i<Blen;i++){
            A[ed-i]-=(B[Blen-1-i]-'0');
            if(A[ed-i]<'0')
              A[ed-i]+=2, A[ed-i-1]--;
          }
          while(st<=ed and A[st]=='0') st++;
        }
      }
      int iA=0;
      while(iA<Alen-1 and A[iA]=='0') iA++;
      A=A.substr(iA);
      return GCD(B,A);
    }
  }
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string A, B;
  cin>>A>>B,
  cout<<( (compare(A,B))?GCD(A,B):GCD(B,A) )<<endl;
}