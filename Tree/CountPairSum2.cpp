#include <bits/stdc++.h> 
using namespace std; 

// structure of a node of a binary tree 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

// function to create and return a node 
// of a binary tree 
Node* getNode(int data) 
{ 
	// allocate space for the node 
	Node* new_node = (Node*)malloc(sizeof(Node)); 

	// put in the data 
	new_node->data = data; 
	new_node->left = new_node->right = NULL; 
} 

// A simple recursive function to convert a given 
// Binary tree to Doubly Linked List 
// root	 --> Root of Binary Tree 
// head_ref --> Pointer to head node of created 
// doubly linked list 
void BToDLL(Node* root, Node** head_ref) 
{ 
	// Base cases 
	if (root == NULL) 
		return; 

	// Recursively convert right subtree 
	BToDLL(root->right, head_ref); 

	// insert root into DLL 
	root->right = *head_ref; 

	// Change left pointer of previous head 
	if (*head_ref != NULL) 
		(*head_ref)->left = root; 

	// Change head of Doubly linked list 
	*head_ref = root; 

	// Recursively convert left subtree 
	BToDLL(root->left, head_ref); 
} 

// Split a doubly linked list (DLL) into 2 DLLs of 
// half sizes 
Node* split(Node* head) 
{ 
	Node *fast = head, *slow = head; 
	while (fast->right && fast->right->right) { 
		fast = fast->right->right; 
		slow = slow->right; 
	} 
	Node* temp = slow->right; 
	slow->right = NULL; 
	return temp; 
} 

// Function to merge two sorted doubly linked lists 
Node* merge(Node* first, Node* second) 
{ 
	// If first linked list is empty 
	if (!first) 
		return second; 

	// If second linked list is empty 
	if (!second) 
		return first; 

	// Pick the smaller value 
	if (first->data < second->data) { 
		first->right = merge(first->right, second); 
		first->right->left = first; 
		first->left = NULL; 
		return first; 
	} 
	else { 
		second->right = merge(first, second->right); 
		second->right->left = second; 
		second->left = NULL; 
		return second; 
	} 
} 

// Function to do merge sort 
Node* mergeSort(Node* head) 
{ 
	if (!head || !head->right) 
		return head; 
	Node* second = split(head); 

	// Recur for left and right halves 
	head = mergeSort(head); 
	second = mergeSort(second); 

	// Merge the two sorted halves 
	return merge(head, second); 
} 

// Function to count pairs in a sorted doubly linked list 
// whose sum equal to given value x 
int pairSum(Node* head, int x) 
{ 
	// Set two pointers, first to the beginning of DLL 
	// and second to the end of DLL. 
	Node* first = head; 
	Node* second = head; 
	while (second->right != NULL) 
		second = second->right; 

	int count = 0; 

	// The loop terminates when either of two pointers 
	// become NULL, or they cross each other (second->right 
	// == first), or they become same (first == second) 
	while (first != NULL && second != NULL && first != second && second->right != first) { 
		// pair found 
		if ((first->data + second->data) == x) { 
			count++; 

			// move first in forward direction 
			first = first->right; 

			// move second in backward direction 
			second = second->left; 
		} 
		else { 
			if ((first->data + second->data) < x) 
				first = first->right; 
			else
				second = second->left; 
		} 
	} 

	return count; 
} 

// function to count pairs in a binary tree 
// whose sum is equal to given value x 
int countPairs(Node* root, int x) 
{ 
	Node* head = NULL; 
	int count = 0; 

	// Convert binary tree to 
	// doubly linked list 
	BToDLL(root, &head); 

	// sort DLL 
	head = mergeSort(head); 

	// count pairs 
	return pairSum(head, x); 
} 

// Driver program to test above 
int main() 
{ 
	// formation of binary tree 
	Node* root = getNode(5); /*	 5	 */
	root->left = getNode(3); /*	 / \	 */
	root->right = getNode(7); /* 3 7	 */
	root->left->left = getNode(2); /* / \ / \ */
	root->left->right = getNode(4); /* 2 4 6 8 */
	root->right->left = getNode(6); 
	root->right->right = getNode(8); 

	int x = 10; 

	cout << "Count = "
		<< countPairs(root, x); 

	return 0; 
} 
