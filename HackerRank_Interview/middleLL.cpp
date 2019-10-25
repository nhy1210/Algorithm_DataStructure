#include<iostream>
#include<vector>

using namespace std;
class Node{
public: 
	Node(int data){
		val = data;
		next = NULL;
	}
	int val;
	Node* next;
	
};
Node* insertNode(Node* head, int data)
	{
		Node* newnode = new Node(data);
		if(!head)
		{
			cout<<newnode->val<<endl;
			return newnode;
		}
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
		cout<<head->val<<"->";
		head = head->next;


	}
	cout<<"NULL"<<endl;
}
int findMiddleOfList(Node* head)
{
	Node* fastptr = head, *slowptr = head;
	while(fastptr->next->next!=NULL)
	{
		fastptr= fastptr->next->next;
		slowptr= slowptr->next;
	}
	return slowptr->val;

}

int main(){
	
	Node* head = NULL;
	head =insertNode(head, 3);
	head =insertNode(head, 6);
	head =insertNode(head, 7);
	head =insertNode(head, 5);
	head =insertNode(head, 4);
	head =insertNode(head, 9);
	printList(head);
	cout<<"Middle of the list is : ";
	cout<<findMiddleOfList(head)<<endl;
	return 0;
}
