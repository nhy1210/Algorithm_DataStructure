#include<iostream>
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
Node* appendNode(Node* head, int val)
{
	Node* newnode = new Node(val);
	if(!head) return newnode;
	Node* cur = head;
	while(cur->next){
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
	cout<<"NUL"<<endl;
}
//This method is for dummy node
/*Node* mergesortLinkedList(Node* head1, Node* head2)
{
	Node* ret;
	if(head1->data > head2->data)
	{
		ret = head2;
		head2 = head2->next;
	}
	else
	{
		ret = head1;
		head1 = head1->next;
	}
	Node* retRef = ret;
	while(head1 && head2)
	{
		cout<<head1->data<<" : "<<head2->data<<endl;
		if(head1->data < head2->data)
		{
			ret->next = head1;
			ret = ret->next;
			head1 = head1->next;
		}
		else 
		{
			ret->next = head2;
			ret = ret->next;
			head2 = head2->next;
		}
	}
	if(head1)
	{
		ret->next = head1;
		ret = ret->next;
		head1 = head1->next;
	}
	if(head2)
	{
		ret->next = head2;
		ret = ret->next;
		head2 = head2->next;
	}
	return retRef;
}*/
//Using recursion
Node* mergesortLinkedList(Node* head1, Node* head2)
{
	if(!head1 ) return head2;
	if (!head2) return head1;
	if (!head1 && !head2) return NULL;
	Node* ret;
	if(head1->data < head2->data)
	{
		ret = head1;
		ret->next = mergesortLinkedList(head1->next, head2);

	}
	else 
	{
		ret = head2;
		ret->next = mergesortLinkedList(head1, head2->next);
	}
	return ret;

}

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	for(int i =1; i< 10; i++ )
	{
		head1 = appendNode(head1, i);
		i++;
	}
	for(int j = 2; j <=10; j++)
	{
		head2 = appendNode(head2, j);
		j++;
	}
	printList(head1);
	printList(head2);
	Node* ret = mergesortLinkedList(head1, head2);
	printList(ret);

	return 0;
}