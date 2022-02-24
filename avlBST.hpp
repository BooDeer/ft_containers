#pragma once

#include <iostream>


//! The node structer.
struct Node
{
	Node		*parent;			//* The parent node.
	Node		*rchild;			//* The right child node.
	Node		*lchild;			//* The left child node.
	int				data;			//* The data hold by the node.

	// Node (Node *__pr, Node *__rch, Node *__lch, int __data): parent(__pr), rchild(__rch), lchild(__lch), data(__data) {};
};


Node*	createNode(int data)
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->lchild = newNode->rchild = newNode->parent = NULL;
	return (newNode);
}

Node*	insertNode(Node* node, int data)
{
	if (node == NULL)
		return(createNode(data));

	if (data <= node->data)
		node->lchild = insertNode(node->lchild, data);
	else if (data > node->data)
		node->rchild = insertNode(node->rchild, data);
	return node;
}

bool	findNode(Node* __root, int data)
{
	while (__root != NULL)
	{
		if (__root->data == data)
			return true;
		else if (__root->data > data)
			__root = __root->lchild;
		else
			__root = __root->rchild;
	}
	return false;
}




















// template<class T>
// struct Node<T>&	insert(struct Node<T>* node, T key)
// {
// 	//* If the current node is either the root or a leaf. (Meaning reached the end of the recursion)
// 	if (node == NULL)
// 		return Node<T>(node, NULL, NULL, key);
	
// 	if (key < node->key)
// 		node->lchild = insert(node->lchild, key);
// 	else if (key > node->key)
// 		node->rchild = insert(node->rchild, key);

// 	return node;
// };

template <class __T, class __Compare = std::less<__T>, class __Allocator = std::allocator<__T> >
class AvlBST
{
	public:
		//* Types.
		typedef __T									value_type;	

	
	public:
		//* Copy contructor.
		AvlBST( const AvlBST& src )
		{
			*this = src;
		};
		//* Assignement operator.
		AvlBST& operator=( const AvlBST& rhs)
		{
			// __PAR	= rhs.__PAR;
			// __RC	= rhs.__RC;
			// __LC	= rhs.__LC;
			// __root	= NULL;
			__Value	= rhs.__Value;
			return *this;
		};
		//* Destructor
		~AvlBST( void )
		{
			//TODO: to be implemented.
			
		};
	//! Insertion methods.
	public:
		// AvlBST( void ):__root(NULL), __Value(__T()) {};
		// struct Node<value_type>*	insert(struct Node<value_type>* node, value_type key)
		// {
		// 	// Return a new node if the tree is empty
		// 	if (node == NULL) return Node<value_type>(NULL, NULL, NULL, key);

		// 	// Traverse to the right place and insert the node
		// 	if (key < node->key)
		// 		node->left = insert(node->left, key);
		// 	else
		// 		node->right = insert(node->right, key);

		// 	return node;
		// }



	//! ======================================================================================
	private:
		//? Should I keep the default constructor private or not?
		//* Private attributes.

		// AvlBST*								__PAR;					//* The parent node.
		// AvlBST*								__RC;					//* The right child node.
		// AvlBST* 							__LC;					//* The left child node.
		__T									__Value;				//* The hold data.
		// Node<value_type>*					__root;
		__Compare							__cmp;
};