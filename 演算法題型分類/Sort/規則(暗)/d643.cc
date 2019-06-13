// 標準做法是 KMP 但這題的測資很寬鬆所以就直覺做即可
// 沒有任何需要加速的技巧和限制判斷
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MaxL 100002

bool cmp(string s1, string s2){
  int i=0, len=s1.length();
  while(i<len and s1[i]==s2[i])
    i++;
  return (i==len)?0:(s1[i]<s2[i]);
}
int main(){
    string ss;

    cin>>ss;
    int sslen=ss.length();

    vector<string> ans;
    ans.push_back(ss);
    for(int len=1;len<sslen;len++)
        if(sslen%len==0){
            int num=sslen/len;
            string subss[num];
            for(int i=0;i<num;i++)
              subss[i]=ss.substr(i*len,len);
            sort(subss,subss+num,cmp);
            string sortss="";
            for(int i=0;i<num;i++)
              sortss+=subss[i];
            int idx=0;
            while(idx<ans.size() and sortss!=ans[idx])
              idx++;
            if(idx==ans.size())
              ans.push_back(sortss),  cout<<sortss<<endl;
        }
    if(ans.size()==1)
      cout<<"bomb!"<<endl;

}