#include <bits/stdc++.h>
using namespace std;
class Node {
	public:
	    int data;
	    Node* left;
	    Node* right;
	    Node(int data) {
	        this->data = data;
	        this->left = nullptr;
	        this->right = nullptr;
    	}
};
vector<vector<int>> LeftView(Node* root) {
	queue<Node *>q;
	vector<vector<int>>ans;
	q.push(root);
	while(!q.empty()) {
		vector<int>v1;
		int n=q.size();
		for(int i=0;i<n;i++) {
			Node* a=q.front();
			if(a->left!=nullptr) q.push(a->left);
			if(a->right!=nullptr) q.push(a->right);
			v1.push_back(a->data);
			q.pop();	
		}
		ans.push_back(v1);
	}
	return ans;
}
void fun(vector<int>& v1, int index, Node* node) {
    if (node == nullptr || index >= v1.size()) return; 
    node->data = v1[index]; 
    if(2*index+1<v1.size()) { 
        node->left=new Node(  v1[2*index + 1]); 
        fun(v1,2*index+1,node->left);
    }
    if(2*index+2<v1.size()) { 
        node->right=new Node(v1[2*index+2]); 
        fun(v1,2*index + 2,node->right);
    }
}
int main() {
     int n;
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v1.push_back(k);
    }
    Node* root = new Node(v1[0]);
    fun(v1,0,root);
    vector<vector<int>>ans=LeftView(root);
    for(int i=0;i<ans.size();i++){
    	for(int j=0;j<ans[i].size();j++)
    	{
    		cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Leftview"<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" ";
	}
}
