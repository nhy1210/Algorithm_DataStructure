#include<iostream>
#include<vector>

using namespace std;

class Node{
public: 
	int data;
	Node* next;
	Node(int val)
	{
		this->data = val;
		this->next = NULL;
	}
};
Node* insertNode(Node* head, int val)
{
	Node* newnode = new Node(val);
	if(!head)
		return newnode;
	Node* cur = head;
	while(cur->next)
	{
		cur = cur->next;
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
Node* reverseList(Node* head)
{
	Node* cur = head;
	Node* prev = NULL, *next = NULL;
	while(cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}
int main()
{
	Node* head = NULL;
	for(int i =0; i < 10; i++)
	{
		head = insertNode(head, i);
	}
	printList(head);
	head = reverseList(head);
	cout<<"After reverse List : "<<endl;
	printList(head);



}
