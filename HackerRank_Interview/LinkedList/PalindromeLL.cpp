#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(int val){
		this->data = val;
		this->next = NULL;
	}
};
Node* appendNode(Node* head, int val)
{
	Node* newnode = new Node(val);
	if(!head)
		return newnode;
	Node* cur = head;
	while(cur->next)
	{
		cur= cur->next;
	}
	cur->next = newnode;
	return head;
}
void printList(Node* head)
{
	while(head)
	{
		cout<<head->data<<"->";
		head = head->next;

	}
	cout<<"NULL"<<endl;
}
Node* insertNode(Node* head, int val){
	Node* newnode = new Node(val);
	if (!head) return newnode;
	newnode->next = head;
	return newnode;
}
//This method require extra space
bool checkPalin(Node* head)
{
	vector<int> myvec;
	while(head)
	{
		myvec.push_back(head->data);
		head = head->next;
	}
	int i = 0, j = myvec.size() -1;
	while(i<j)
	{
		if(myvec[i] != myvec[j])
			return false;
		else
		{
			i++;
			j--;
		}
	}
	return true;
}
int main()
{
	Node* head = NULL;
	for(int i = 1; i<= 6; i++)
	{
		head = appendNode(head, i);
	}
	printList(head);
	for(int j =1; j <=5; j++)
	{
		head = insertNode(head, j);

	}
	printList(head);
	bool ret = checkPalin(head);
	if(ret) cout<<"Is palindrome list"<<endl;
	else cout<<"Is not a palindrome list"<<endl;

	return 0;
}
