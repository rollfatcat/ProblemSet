#include<bits/stdc++.h>
using namespace std;

// 所有數字介於 0 ~ 1e150 之間且 m ≤ n ≤ 2e5
const int MAXN=2e5;
const int MAXM=2e5;


int main(){
    
    ios::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);

    int N, M;
    cin>>M>>N;

    map<string,int> memo;
    int ans_cnt=0;
    int now_cnt=0;
    string color_now, color_ss[MAXM];
    for(int i=0;i<M;i++){
        cin>>color_now;
        if(memo.find(color_now)==memo.end())
            now_cnt++;
        memo[color_now]++,
        color_ss[i]=color_now;
    }
    if(now_cnt==M)
        ans_cnt++;
    for(int i=M;i<N;i++){
        color_now=color_ss[i%M];
        memo[color_now]--;
        if(memo[color_now]==0)
            now_cnt--;
        cin>>color_now;
        if(memo.find(color_now)==memo.end() or memo[color_now]==0)
            now_cnt++;
        memo[color_now]++;
        color_ss[i%M]=color_now;
        if(now_cnt==M)
            ans_cnt++;
    }
    cout<<ans_cnt<<'\n';
}