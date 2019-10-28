#include<iostream>
#include<map>
#include<vector>

using namespace std;
class Tree{
public:
	int data;
	Tree* left, *right;
	Tree(int val)
	{
		this->data = val;
		this->left = this->right = NULL;
	}
};
void levelOrderTraversal(Tree* head, int hd, map<int,vector<int> > &mymap){
	if(!head) return ;
	cout<<head->data<<endl;
	mymap[hd].push_back(head->data);
	levelOrderTraversal(head->left, hd-1, mymap);
	levelOrderTraversal(head->right, hd+1, mymap);
}
int main(){
	Tree* head = new Tree(20);
	head->right = new Tree(22);
	head->left = new Tree(8);
	head->left->left = new Tree(4);
	head->left->right = new Tree(12);
	head->left->right->left = new Tree(10);
	head->left->right->right = new Tree(14);
	int hd=0;
	map<int, vector<int> > mymap;
	levelOrderTraversal(head, hd, mymap);
	map< int,vector<int> > ::iterator it;
	for( it=mymap.begin(); it!=mymap.end(); it++)
	{
		for(int i =0; i < it->second.size(); i++)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}


	return 0;
}