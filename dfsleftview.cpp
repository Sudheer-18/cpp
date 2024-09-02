#include<bits/stdc++.h>
using namespace std;
class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val){
			this->val = val;
			this->left = nullptr;
			this->right = nullptr;
	}	
};
int tree_level(TreeNode* root,int lev) {
	if(root == nullptr) {
		return 0;
	}
	return 1+ max(tree_level(root->left,lev+1),tree_level(root->right,lev+1));
}
int find_level(TreeNode* root,int val,int lev) {
if(root == nullptr) return -1;
    if(root->val == val) return lev;
    int left_level = find_level(root->left, val, lev+1);
    if (left_level != -1) return left_level; 
    return find_level(root->right, val, lev+1);
}
void left_view(TreeNode* root,vector<int>& arr) {
	if(root== nullptr) return ;
	int lh  = find_level(root,root->val,0);
	if(find(arr.begin(),arr.end(),lh))  arr.pop_back();
	else  arr.push_back(root->val);
	left_view(root->left,arr);
	left_view(root->right,arr);
	int rh = find_level(root,root->val,0);
}
int main() {
	TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t7 = new TreeNode(7);
    TreeNode* t8 = new TreeNode(8);
    TreeNode* t9 = new TreeNode(9);
    t1->left=t2;
    t1->right=t3;
    t2->left=t4;
    t2->right=t5;
    t3->right=t9;
    t5->left=t6;
    t5->right=t7;
	t7->left=t8;
	TreeNode* root = t1;
	int lev = tree_level(root,0);
	cout<<"Level of the tree "<<lev<<endl;
	vector<int>arr;
	left_view(root,arr);
	for(int i=0;i<arr.size();i++) {
		cout<<arr[i]<<" ";
	}
//	int k = find_level(root,8,0);
//	cout<<k<<endl;;
}