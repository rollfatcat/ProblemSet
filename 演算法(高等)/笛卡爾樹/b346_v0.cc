/* 題目問題點說明：https://www.pttdata.com/ResponesPage.php?u=/bbs/C_and_CPP/M.1424010938.A.A4B.html
 * 二元搜尋樹的 worst case 的是單枝樹的關係，單個節點插入時是O(n)，整體就是O(n^2)
 * 所以題目的問題在O(n㏒n)的要求下建立單枝樹
 * 以下是一般建立二元搜尋樹的做法作法會TLE(60% AC)
 * v1(SegmentTree版本) v2(SparseTree版本)
 */
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
void pre_order(Node* ptr){
	printf("%d ",ptr->data);
	if(ptr->left)   pre_order(ptr->left);
	if(ptr->right)  pre_order(ptr->right);
}
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}

int main(){
	int N;
	Node* nodes=NULL;
	while(scanInt(N)){
		nodes=new Node[N];
		Node* head=&nodes[0];
		Node* ptr=head;
		scanInt(head->data);
		head->left=NULL;
		head->right=NULL;

		for(int i=1;i<N;++i,ptr=head){
			scanInt(nodes[i].data);
			while(true){
				if(nodes[i].data < ptr->data){
					if(ptr->left)
						ptr=ptr->left;
					else{
						ptr->left=&nodes[i];
						ptr->left->left=NULL;
						ptr->left->right=NULL;
						break;
					}
				}
				else{
					if(ptr->right)
						ptr=ptr->right;
					else{
						ptr->right=&nodes[i];
						ptr->right->left=NULL;
						ptr->right->right=NULL;
						break;
					}
				}
			}
		}
		pre_order(head);
		puts("");
		delete[] nodes;
		nodes=NULL;
	}
}