#include<iostream>

using namespace std;
class Node{
public: 
	int data;
	Node* next;
	Node(int dat)
	{
		this->data = dat;
		this->next = NULL;
	}
};
Node* appendNode(Node* head, int data){
	Node* newnode = new Node(data);
	if(!head) return newnode;
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
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
Node* deleteNode(Node* head, int data)
{
	Node* cur = head;
	if(!head) return NULL;
	if(head->data == data) 
	{
		Node* newnode = head->next;
		return newnode;
	}
	while (cur->next)
	{
		if(cur->next->data == data)
		{
			Node* next = cur->next->next;
			delete cur->next;
			cur->next = next;

		}
		cur = cur->next;
	}
	return head;
}
int main(){

	Node* head = NULL;
	head = appendNode(head, 2);
	
	head = appendNode(head, 20);
	head = appendNode(head, 3);
	head = appendNode(head, 30);
	head = appendNode(head, 5);
	printList(head);
	head = deleteNode(head, 2);
	printList(head);
	return 0;
}