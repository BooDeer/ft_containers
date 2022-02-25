#pragma once

#include <iostream>


// //! The node structer.




// void	inorderTraversal(Node* root)
// {
// 	if (root != NULL)
// 	{
// 		inorderTraversal(root->left);
// 		std::cout << root->key << " --> ";
// 		inorderTraversal(root->right);
// 	}
// }
















// 


















template <class __T, class __Compare = std::less<__T>, class __Allocator = std::allocator<__T> >
class AvlBST
{
	public:
		//* Types.
		typedef __T									value_type;	

	
	struct Node
	{
		//? Is the parent node needed?
		Node				*parent;			//* The parent node.
		Node				*right;			//* The right child node.
		Node				*left;			//* The left child node.
		value_type			key;				//* The key hold by the node.
		int					height;				//* The height of the node.
		// Node (Node *__pr, Node *__rch, Node *__lch, int __data): parent(__pr), right(__rch), left(__lch), key(__data) {};
	};

	int height(Node *N)
	{
		if (N == NULL)
			return 0;
		return N->height;
	}

	int max(int a, int b)
	{
		return (a > b) ? a : b;
	}

	Node*	findMin(Node* root)
	{
		Node* current = root;
		while (current && current->left != NULL)
			current = current->left;
		return current;
	}

	int getBalanceFactor(Node *N)
	{
		if (N == NULL)
			return 0;
		return (height(N->left) - height(N->right));
	}

	Node*	rightRotate(Node* y)
	{
		Node *x = y->left;
		Node *T2 = x->right;
		x->right = y;
		y->left = T2;
		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;
		return x;	
	};

	Node*	leftRotate(Node* x)
	{
		Node *y = x->right;
		Node *T2 = y->left;
		y->left = x;
		x->right = T2;
		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;
		return y;	
	};
	Node*	deleteNode(Node* root, value_type key)
	{
		//* Empty tree
		if (root == NULL)
			return root;
		
		//* Search for the node to be deleted.
		if (key.first < root->key.first)
			root->left = deleteNode(root->left, key);
		else if (key.first > root->key.first)
			root->right = deleteNode(root->right, key);
		else //* Found the node to be deleted.
		{
			//* The case where the node has either one or no child.
			if ((root->left == NULL) || (root->right == NULL))
			{
				Node *temp = root->left ? root->left : root->right;

				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else
					*root = *temp;
				free(temp);
			}
			else
			{
				Node* temp = findMin(root->right);
				root->key = temp->key;
				root->right = deleteNode(root->right, temp->key);
			}
		}
		if (root == NULL)
			return root;
		

		//* Updating the binary tree to be balanced
		root->height = 1 + max(height(root->left), height(root->right));
		int balanceFactor = getBalanceFactor(root);
		if (balanceFactor > 1)
		{
			if (getBalanceFactor(root->left) >= 0)
				return rightRotate(root);
			else
			{
				root->left = leftRotate(root->left);
				return rightRotate(root);
			}
		}
		if (balanceFactor < -1)
		{
			if (getBalanceFactor(root->right) <= 0)
				return leftRotate(root);
			else
			{
				root->right = rightRotate(root->right);
				return leftRotate(root);
			}
		}
		return root;
	}

	Node*	createNode(value_type key)
	{
		Node* newNode = new Node();

		//TODO: the key must be allocated and constructed as well
		newNode->key = key;
		newNode->left = newNode->right = newNode->parent = NULL;
		newNode->height = 1;
		return (newNode);
	}

	Node*	insertNode(Node* node, value_type key)
	{
		//!====================================================
		//* Generic BST insertion.
		if (node == NULL)
			return(createNode(key));

		if (key.first <= node->key.first)
			node->left = insertNode(node->left, key);
		else if (key.first > node->key.first)
			node->right = insertNode(node->right, key);
		else
			return node;
		//!====================================================



		//* Update balance factor of each node.
		node->height = 1 + max(height(node->left), height(node->right));
		int	balanceFactor = getBalanceFactor(node);
		if (balanceFactor > 1)
		{
			if (key.first < node->left->key.first)
				return rightRotate(node);
			else if (key.first > node->left->key.first)
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
		}
		
		if (balanceFactor < - 1)
		{
			if (key.first > node->right->key.first)
				return leftRotate(node);
			else if (key.first < node->right->key.first)
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		}
		return node;

	}

	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
		if( node != nullptr )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << node->key.second << std::endl;

			// enter the next tree level - left and right branch
			printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
			printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}

	void printBT(const Node* node)
	{
		printBT("", node, false);    
	}


























	public:
		//* Copy contructor.
		AvlBST( const AvlBST& src )
		{
			*this = src;
		};
		//* Assignement operator.
		AvlBST& operator=( const AvlBST& rhs)
		{
			return *this;
		};
		//* Destructor
		~AvlBST( void )
		{
			//TODO: to be implemented.
			
		};
	//! Insertion methods.
	public:
		AvlBST( void ):__root(NULL) {
			std::cout << "[AvlBST] Default constructor.\n";
		};
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
	public:
		//? Should I keep the default constructor private or not?
		//* Private attributes.

		// AvlBST*								__PAR;					//* The parent node.
		// AvlBST*								__RC;					//* The right child node.
		// AvlBST* 							__LC;					//* The left child node.
		// __T									__Value;				//* The hold key.
		Node								*__root;
		__Compare							__cmp;
};



// pass the root node of your binary tree