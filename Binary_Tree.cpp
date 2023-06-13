#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode, *BiTree;


BiTree reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    if (pre.size() == 0 || vin.size() == 0)
        return NULL;

    TreeNode *treeNode = new TreeNode(pre[0]);
    int mid = distance(begin(vin), find(vin.begin(), vin.end(), pre[0]));
    vector<int> left_pre(pre.begin() + 1, pre.begin() + mid + 1);
    vector<int> right_pre(pre.begin() + mid + 1, pre.end());
    vector<int> left_in(vin.begin(), vin.begin() + mid);
    vector<int> right_in(vin.begin() + mid + 1, vin.end());

    treeNode->left = reConstructBinaryTree(left_pre, left_in);
    treeNode->right = reConstructBinaryTree(right_pre, right_in);
    return treeNode;
}


BiTree constructBinaryTree(vector<int>& values) {
	if (values.empty()) {
		return NULL;
	}
	// 创建根节点
	TreeNode* root = new TreeNode(values[0]);
	queue<TreeNode*> q;
	q.push(root);
	
	// 从第二个元素开始构建二叉树
	int i = 1;
	while (i < values.size()) {
		TreeNode* current = q.front();
		q.pop();
		// 处理左子节点
		if (values[i] != -1) {  // -1表示空节点
			current->left = new TreeNode(values[i]);
			q.push(current->left);
		}
		
		i++;
		
		if (i >= values.size())
			break;
		
		// 处理右子节点
		if (values[i] != -1) {
			current->right = new TreeNode(values[i]);
			q.push(current->right);
		}
		
		i++;
	}
	
	return root;
}

void printBinaryTree(TreeNode* root) {
	if (root == NULL) return;
	
	queue<TreeNode*> q;
	q.push(root);
	
	while (!q.empty()) {
		TreeNode* current = q.front();
		q.pop();
		
		cout << current->val << " ";
		
		if (current->left) {
			q.push(current->left);
		}
		
		if (current->right) {
			q.push(current->right);
		}
	}
	cout<<endl;
}


BiTree buildTree(vector<int>& preorder, int& preIndex) {
	if (preIndex >= preorder.size() || preorder[preIndex] == -1) {
		preIndex ++;
		return NULL;
	}
	
	int val = preorder[preIndex];  // 当前节点的值
	TreeNode* root = new TreeNode(val);  // 创建当前节点
	preIndex++;
	
	// 递归构建左子树和右子树
	root->left = buildTree(preorder, preIndex);
	root->right = buildTree(preorder, preIndex);
	
	return root;
}

void CreateBiTree(BiTree &root)
{
	int ch;
	static int index = 0;
	int pch[] = {6, 3, 2, -1, -1, 4, 1, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1};
	ch = pch[index++];
	if(ch == -1) root = NULL;
	else {
		root = (BiTree)malloc(sizeof(TreeNode));
		if(!root)	exit(-1);
		root->val = ch; 				// 生成根结点
		CreateBiTree(root->left);	// 构造左子树
		CreateBiTree(root->right);	// 构造右子树
	}
	
}


void PreOrder(BiTree root)
{
	if(root == NULL) return;
	cout<<root->val<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BiTree root)
{
	if(root == NULL) return;
	PreOrder(root->left);
	cout<<root->val<<" ";
	PreOrder(root->right);
}

void PostOrder(BiTree root)
{
	if(root == NULL) return;
	PreOrder(root->left);
	PreOrder(root->right);
	cout<<root->val<<" ";
}

int main() {
	vector<int> values = {6, 3, 2, -1, -1, 4, 1, -1, -1, 5, -1, -1, 8, 7, -1, -1, 9, -1, -1};
//	int index = 0;
//	BiTree root = buildTree(values, index);
	BiTree root;
	CreateBiTree(root);

	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	PostOrder(root);
	cout << endl;
	
	return 0;
}

