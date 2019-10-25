#include<iostream>

using namespace std;
class Tree{
public: 
	int data;
	Tree* left, * right;
	Tree(int dat)
	{
		this->data = dat;
		this->left = this->right = NULL;
	}
};
int lcs(Tree* head, int p, int q)
{
	if(!head) return NULL;
	if (head->data > p && head->data > q)
		return lcs (head->left, p,q);
	else if (head->data < p && head->data < q)
		return lcs (head->right,p,q);
	return head->data;
}
int main()
{
	Tree* head = new Tree(20);
	head->right = new Tree(22);
	head->left = new Tree(8);
	head->left->left = new Tree(4);
	head->left->right = new Tree(12);
	head->left->right->left = new Tree(10);
	head->left->right->right = new Tree(14);
	int ret = lcs(head, 14,22);
	cout<<ret<<endl;

}