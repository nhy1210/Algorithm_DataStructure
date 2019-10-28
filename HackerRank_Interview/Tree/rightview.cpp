#include<iostream>
#include<vector>
#include<map>

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
void printleftviewUtil(Tree* head,int level, map<int,int>& mymap)
{
	if(!head) return ;
	mymap[level] = head->data;

	printleftviewUtil(head->left,level+1,  mymap);
	printleftviewUtil(head->right,level+1,  mymap);
}

void printleftview(Tree* head)
{
	int max_level=0;
	map<int, int> mymap;
	printleftviewUtil(head, 1,  mymap);
	/*for(auto i : mymap)
	{
		cout<<i<<" ";
	}*/
	for(auto it= mymap.begin(); it!= mymap.end(); it++)
	{
		cout<<it->second<<" ";
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