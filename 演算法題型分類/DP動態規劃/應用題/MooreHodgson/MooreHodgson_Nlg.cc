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
	int index, process, due;
	Job(int i=0,int p=0,int d=0):index(i),process(p),due(d){}
	bool operator<(const Job &rhs)const{ return due<rhs.due; }
}now;
struct Record{
	int index, process;
	Record(int i=0,int p=0):index(i),process(p){}
	bool operator<(const Record &rhs)const{ return process<rhs.process; }
};
// 將演算法封裝使用
struct Moore_Hodgson{
	vector<Job> jobs;
	vector<bool> overdue;
	int last_valid_idx;// 最後一個可以在期限內完成的工作的 Index

	// 初始化，根據期限排序
  void initial(void){
		last_valid_idx=jobs.size()-1;
		sort(jobs.begin(),jobs.end());
		overdue.resize(jobs.size()+1);
  }
  void operate(void){
		priority_queue<Record> PQ;
		// 初始化 Jobs
		initial();
		int sum_time=0;
		for(auto &job:jobs){
			// 加入 priority queue
			PQ.push({job.index,job.process} );
			// 加上此工作的耗時
			sum_time+=job.process;

			// 檢查是否會超時
			if(sum_time>job.due){
				// 刪掉最大耗時並記錄
				sum_time-=PQ.top().process;
				overdue[PQ.top().index]=true;
				PQ.pop();
			}
		}
		last_valid_idx=PQ.size();
  }
  // 輸出結果
  int ShowResult(void){
    // 先輸出沒有超時的部分
		for(auto i=0;i<jobs.size();i++)
			if(overdue[jobs[i].index]==0)
				cout<<jobs[i].index<<" ";
		// 任意順序輸出超時的部分
		for(auto i=1; i<overdue.size();i++)
			if(overdue[i])
				cout<<i<<" ";
		cout<<endl;
		return last_valid_idx;
  }
};

int main(){
	for(int N,caseN=1;cin>>N;caseN++){
	  Moore_Hodgson MH;
	  for(int i=1;i<=N;i++)
	    now.index=i,
	    cin>>now.process>>now.due,
	    MH.jobs.emplace_back( now );
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