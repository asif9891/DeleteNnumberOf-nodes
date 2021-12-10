/*
* delete a n number of number after m element.
* ex 1,2,3,4,5,6,7,8,-1
* -1 is terminating point of Node<int>.
* output should be look like
* 1,2,5,6
* 
*/
#include"Node.h"

Node<int>* takeinput()
{
	int data;
	cin >> data;
	Node<int>* head = NULL;
	Node<int>* tail = NULL;
	while (data != -1)
	{
		Node<int>* Data = new Node<int>(data);
		if (head == NULL)
		{
			head = Data;
			tail = Data;
		}
		else
		{
			tail->next = Data;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
}

void print(Node<int>* root)
{
	while (root != NULL)
	{
		cout << root->data << " ";
		root = root->next;
	}
}

Node<int>* skipMdeleteN(Node<int>* head, int M, int N) {

	if (M == 0) return NULL; // edge case  not a base case

	//base case
	if (head == NULL || head->next == NULL)
	{
		return head;
	}

	Node<int>* temp = head;
	int count1 = 0;
	int count2 = 0;
	while (temp->next != NULL && count1 < M - 1) //travel M Node<int>s
	{
		count1++;
		temp = temp->next;

	}
	Node<int>* t1 = temp;
	// t1=temp;
	temp = temp->next;
	if (temp == NULL)
		return head;

	while (temp->next != NULL && count2 < N - 1)
	{
		count2++;
		temp = temp->next;

	}

	Node<int>* t2 = NULL;
	t2 = temp->next;


	Node<int>* m = skipMdeleteN(t2, M, N);
	t1->next = m;
	return head;
}
int main()
{
	Node<int>* root = takeinput();
	root = skipMdeleteN(root, 2, 2);
	print(root);
	return 0;
}