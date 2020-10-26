// 原文出處：https://nicknick0630.github.io/2019/03/07/Moore-Hodgson-s-Algorithm-Minimizing-the-number-of-late-jobs/#more
// 演算法目的：此演算法將一個 O( N2 ) 的 Scheduling 問題縮減到了 O( NlogN )
/* 題目敘述：有 N 個 Jobs，每個 Job 耗時 p 且期限 (due) 為 d，
 *           求最少逾期工作數量(Minimum number of late jobs)的排程方式
 *           要找出一個排程方式是能夠讓在期限之前完成的工作數量最大化
 * 作法：
 * (1)設 J = ∅ ( J 是一個 subschedule 且為空集合 )
 * (2)將 Jobs 按照期限遞增排序( d1 < d2 < …… < dn )，也就是依照 Earliest Due Date( EDD )的方式，並放入 J 中
 * (3)令 k = subschedule J 中的第一個逾期工作的 index，如果沒有找到，代表已完成排程。
 * (4)找出 pm = max{ pi, for i = 1 ~ k } ( 找出 index <= k 中最耗時的工作)
 * (5)將 Job m 移出 subschedule J，放入集合 S 中
 * (6)重複步驟 3
 * (7)最後，將集合 S 以任意順序加到 J 的後面，此 Schedule J 即為最少逾期工作數量的排程
 */

// 定義每個工作有的排序方式/初始化/屬性：到達Queue順序、工作時間、期限、完成時間

#include<bits/stdc++.h>
using namespace std;

struct Job{
	int index, process, due, end_time;
	Job(int i=0,int p=0,int d=0,int e=0):index{i},process{p},due{d},end_time{e}{}
	bool operator<(const Job &rhs)const{ return due<rhs.due; }
}now;

// 將演算法封裝使用
struct Moore_Hodgson{
	vector<Job> jobs;
	int last_valid_idx;// 最後一個可以在期限內完成的工作的 Index

  void operate(void){
		int tem=0;
		// 若此次迴圈中沒有改變到 last_valid_idx 的值，代表已完成演算法
		while(tem!=last_valid_idx){
			tem=last_valid_idx;
			for(int idx=0;idx<=last_valid_idx;idx++){
				// 找到逾期的工作
				if(jobs[idx].end_time>jobs[idx].due){
					// 找出最大工作量的工作 J_max
					auto itr=find_max_processing_time(jobs,0,idx);
					// 先記錄起來
					auto rec=*itr;

					// 移除最大工作量的工作 J_max
					auto new_itr=jobs.erase(itr);
					// 將 last_valid_idx 往前移一位
					last_valid_idx--;
					// 把在被刪掉的 J_max 工作之後的工作的結束時間更新 ( 不包括已經確定逾期的工作 )
					// 且只需要將之後的每個工作都減掉 J_max 的工作量就可以
					update_end_time(jobs,rec.process);

					// 將逾期的工作加到最後面放著
					jobs.push_back(rec);

					// 跳出 for 迴圈
					break;
				}
			}
		}
  }
  // 初始化，根據期限排序
  void initial(void){
		last_valid_idx=jobs.size()-1;
		sort(jobs.begin(),jobs.end());
		jobs[0].end_time=jobs[0].process;
		for (auto idx=1; idx<jobs.size(); idx++)
			jobs[idx].end_time=jobs[idx-1].end_time+jobs[idx].process;
  }
  // 輸出結果
  int ShowResult(void){
    for(auto x:jobs)
      cout<<x.index<<' ';
    cout<<endl;
    return last_valid_idx+1;
  }
  // 回傳最耗時的process指標
  vector<Job>::iterator find_max_processing_time(vector<Job> &jobs,int start,int end)const{
		int maxv=-1, idx=-1;
		for(int i=start;i<=end;i++)
			if(jobs[i].process>maxv)
				maxv=jobs[i].process,
				idx=i;
	  return jobs.begin()+idx;
  }
  // 範圍內的工作完成時間扣除某個值
  void update_end_time(vector<Job> &jobs,int proc){
	  for(int idx=0;idx<=last_valid_idx;idx++)
		  jobs[idx].end_time-=proc;
  }
};

int main(){
	for(int N,caseN=1;cin>>N;caseN++){
	  Moore_Hodgson MH;
	  for(int i=1;i<=N;i++)
	    now.index=i,
	    cin>>now.process>>now.due,
	    MH.jobs.emplace_back( now );
    MH.initial();
    MH.operate();
	  cout<<"Schedule "<<caseN<<" : "<<MH.ShowResult()<<endl;
	}
}
/*
 6
10 15
 3  6
 4  9
 8 23
10 20
 6 30

 5
 4 6
 3 7
 2 8
 5 9
 6 1
*/