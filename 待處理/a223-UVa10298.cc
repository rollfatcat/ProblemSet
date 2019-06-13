/* 由KMP演算法
 * 觀察以上的兩個情況，可以使用【從右往左】數過來【第一個0的位置】來判斷，
 * 1.【當0的位置】超過【字串長度一半】時，代表這個字串連一半都不能切割，所以答案必為1。
 * 2.【當0的位置】不能整除【全部字串長度】時，代表不能剛好分割，所以答案為1。
 * 3.【當0的位置】都符合時，答案就會是【全部字串長度】/【0的位置】。
 * 4.【全部字串長度】如果一開始為１的話，不用檢查，答案為１。
 */
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(string ss; cin>>ss and ss!=".";){
    int len=ss.length(), subL;
    for(subL=1; subL<=len; subL++)
      if(len%subL==0){
        int t=len/subL, i, j;
        for(i=0; i<subL; i++){
          for(j=1; j<t and ss[j*subL+i]==ss[i]; j++);
          if(j!=t) break;
        }
        if(i==subL) break; //succuss
      }
    cout<<(len/subL)<<endl;
  }
}