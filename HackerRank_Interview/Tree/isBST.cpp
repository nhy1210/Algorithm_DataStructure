#include<iostream>
#include<vector>

using namespace std;
//Check if the tree is BST or not
//Pre order : Root ->left ->right
//Post order: left->right->>root
//In order: left-root-right
//If tree is BST , inorder will result in sorted array
class Node{
public:
	int data;
	Node * left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right= NULL;
	}

};
bool isBST(Node* head)
{
	//Method 1: save in array and check array is sorted or not
	vector<int> myvec;
	//In order traversal using stack
	stack<Node*> myst;
	myst.insert(head);
	if(root)
	{
		if(!isBST(root->left)) return false;
	} 
	for(int i =0; i< myvec.size()-1; i++)
	{
		if(myvec[i] > myvec[i+1])
			return false;

	}
	return true;

}
int main(){
	Node* head = new Node(6);
	head->right = new Node(7);
	head->left = new Node(3);
	head->left->left = new Node(2);
	head->left->right = new Node(4);
	head->right->left = new Node(5);
	head->right->right = new Node(8);
	bool ret = isBST(head);
	if (ret) cout<<"is BST"<<endl;
	else cout<<"Not BST"<<endl;

	return 0;
}
