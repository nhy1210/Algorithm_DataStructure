#include<iostream>
#include<vector>

using namespace std;
class Tree
{
public:
	int data;
	Tree* left, *right;
	Tree(int dat)
	{
		this->data = dat;
		this->left = this->right = NULL;

	}
	
	
};
void printleftviewUtil(Tree* head,int level, int* max_level, vector<int> & myvec)
{
	if(!head) return ;
	if(*max_level < level)
	{
		myvec.push_back(head->data);
		*max_level = level;
	}
	printleftviewUtil(head->left,level+1, max_level, myvec);
	printleftviewUtil(head->right,level+1, max_level, myvec);
}

void printleftview(Tree* head)
{
	int max_level=0;
	vector<int> myvec;
	printleftviewUtil(head, 1, &max_level, myvec);
	for(auto i : myvec)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	/* code */
	Tree* head = new Tree(20);
	head->right = new Tree(22);
	head->left = new Tree(8);
	head->left->left = new Tree(4);
	head->left->right = new Tree(12);
	head->left->right->left = new Tree(10);
	head->left->right->right = new Tree(14);
	printleftview(head);
	return 0;
}