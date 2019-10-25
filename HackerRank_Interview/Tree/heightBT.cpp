#include<iostream>
#include<vector>

using namespace std;
class Tree{
public:
	int data;
	Tree* left, *right;
	Tree(int dat)
	{
		this->data = dat;
		this->left = this->right = NULL;
	}
};
int heightOfTree (Tree* head)
{
	if(!head) return 0;
	int left = heightOfTree(head->left);
	int right = heightOfTree(head->right);
	if(left>right) return left+1;
	else return right+1;
}
int main(){


	Tree* head = new Tree(3);
	head->left = new Tree(5);
	head->right  = new Tree(8);

	head->right->left  = new Tree(18);
	int height = heightOfTree(head);
	cout<<height<<endl;

	return 0;

}