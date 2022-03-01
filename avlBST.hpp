#pragma once

#include <iostream>
#include "utility.hpp"
template <class __T, class __Compare = std::less<__T>, class Allocator = std::allocator<__T> >
class AvlBST
{
	public: 
	struct Node
	{
		typedef typename __T::first_type		first_type;
		typedef typename __T::second_type		second_type;
		//? Is the parent node needed?
		Node				*par;				//* The parent node.
		Node				*right;				//* The right child node.
		Node				*left;				//* The left child node.
		__T					key;				//* The key hold by the node.
		int					height;				//* The height of the node.

		Node(__T val): key(val) {};
		Node(Node *p, Node *r, Node *l, first_type k1,second_type k2, int h): par(p), right(r), left(l), key(k1, k2), height(h) {};
	};
	private:
		//* Types.
		typedef __T															value_type;	
		typedef	Allocator													allocator_type;
		typedef typename Allocator::template rebind<Node>::other			__allocTy;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::pointer							pointer;
		// typedef 
	public:

	//* Get the node with the smallest value.
	Node* minValue( void ) {
		Node* current = __root;

		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	//* Get the node with the smallest value.
	Node* minValue(Node* node)
	{
		Node* current = node;
	
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}

	//* Search for a specific node. 
	Node* searchNode(Node* n, value_type key)
	{
		Node* current = n;

		while (current != NULL)
		{
			if (key.first == current->key.first)
				return current;
			else if (key.first < current->key.first)
				current = current->left;
			else if (key.first > current->key.first)
				current = current->right;
		}

		return NULL;
	}

	//* Find the next node from the current node.
	Node* inOrderSuccessor(Node* n)
	{
		if (n->right != NULL)
			return minValue(n->right);

		Node* p = n->par;
		while (p != NULL && n == p->right) {
			n = p;
			p = p->par;
		}
		return p;
	}

	//* Find the previous node from the current node.
	Node*	inOrderPredecessor(Node* node) {

		if (node == NULL)
			return NULL;
		
		if (node->left != NULL)
		{
			node = node->left;
			while (node->right != NULL)
				node = node->right;
			return node;
		}
		Node* par = node->par;
		while (par != NULL && par->left == node)
		{
			node = par;
			par = par->par;
		}
		return par;
	}

	void Updateheight(struct Node* root)
	{
		if (root != NULL) {
			int val = 1;

			if (root->left != NULL)
				val = root->left->height + 1;
	
			if (root->right != NULL)
				val = std::max(
					val, root->right->height + 1);
			root->height = val;
		}
	}
	
	// Function to handle Left Left Case
	struct Node* LLR(struct Node* root)
	{
		struct Node* tmpnode = root->left;

		root->left = tmpnode->right;
	
		if (tmpnode->right != NULL)
			tmpnode->right->par = root;

		tmpnode->right = root;
		tmpnode->par = root->par;
		root->par = tmpnode;

		if (tmpnode->par != NULL
			&& root->key.first < tmpnode->par->key.first) {
			tmpnode->par->left = tmpnode;
		}
		else {
			if (tmpnode->par != NULL)
				tmpnode->par->right = tmpnode;
		}
		root = tmpnode;
	
		Updateheight(root->left);
		Updateheight(root->right);
		Updateheight(root);
		Updateheight(root->par);
		return root;
	}
	
	// Function to handle Right Right Case
	struct Node* RRR(struct Node* root)
	{
		struct Node* tmpnode = root->right;

		root->right = tmpnode->left;

		if (tmpnode->left != NULL)
			tmpnode->left->par = root;
		tmpnode->left = root;
		tmpnode->par = root->par;
		root->par = tmpnode;
	
		if (tmpnode->par != NULL
			&& root->key < tmpnode->par->key) {
			tmpnode->par->left = tmpnode;
		}
		else {
			if (tmpnode->par != NULL)
				tmpnode->par->right = tmpnode;
		}
		root = tmpnode;
		Updateheight(root->left);
		Updateheight(root->right);
		Updateheight(root);
		Updateheight(root->par);
		return root;
	}
	
	// Function to handle Left Right Case
	struct Node* LRR(struct Node* root)
	{
		root->left = RRR(root->left);
		return LLR(root);
	}
	
	// Function to handle right left case
	struct Node* RLR(struct Node* root)
	{
		root->right = LLR(root->right);
		return RRR(root);
	}


	struct Node* Balance(struct Node* root)
	{
		int firstheight = 0;
		int secondheight = 0;
	
		if (root->left != NULL)
			firstheight = root->left->height;
	
		if (root->right != NULL)
			secondheight = root->right->height;
	
		if (std::abs(firstheight - secondheight) == 2) {
			if (firstheight < secondheight) {
				int rightheight1 = 0;
				int rightheight2 = 0;
				if (root->right->right != NULL)
					rightheight2 = root->right->right->height;
	
				if (root->right->left != NULL)
					rightheight1 = root->right->left->height;
	
				if (rightheight1 > rightheight2) {
					root = RLR(root);
				}
				else {
					root = RRR(root);
				}
			}
			else {
				int leftheight1 = 0;
				int leftheight2 = 0;
				if (root->left->right != NULL)
					leftheight2 = root->left->right->height;
	
				if (root->left->left != NULL)
					leftheight1 = root->left->left->height;
	
				if (leftheight1 > leftheight2) {
					root = LLR(root);
				}
				else {
					root = LRR(root);
				}
			}
		}
		return root;
	}

	struct Node* insertNode(struct Node* root,struct Node* parent,	value_type key)
	{
		if (root == NULL) {
			root = __alloc.allocate(1);
			__alloc.construct(root, Node(NULL, NULL, NULL, key.first, key.second, 0));
			// LOG("Memory allocated for the value: " << key.first << " is " << root);
			root->height = 1;
			root->left = NULL;
			root->right = NULL;
			root->par = parent;
		}
	
		else if (root->key.first > key.first) {
			root->left = insertNode(root->left,	root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight = root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight- secondheight)== 2) {
	
				if (root->left != NULL
					&& key.first < root->left->key.first) {
					root = LLR(root);
				}
				else {
					root = LRR(root);
				}
			}
		}
	
		else if (root->key < key) {
			root->right = insertNode(root->right, root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight
					= root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight - secondheight) == 2) {
				if (root->right != NULL
					&& key.first < root->right->key.first) {
					root = RLR(root);
				}
				else {
					root = RRR(root);
				}
			}
		}
		else {
		}
		Updateheight(root);
		return root;
	}

	//! Debugging functions.
	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
		if( node != nullptr )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			// std::cout << node->key.second << "address: " << node;
			std::cout << node->key.second;
			if (node->par)
				std::cout << "p:" << node->par->key.second;
			std::cout << std::endl;

			// enter the next tree level - left and right branch
			printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
			printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}

	struct Node*	eraseNode(Node* root, value_type key)
	{
		if (root != NULL) {
			// If the node is found
			if (root->key.first == key.first) {
				if (root->right == NULL
					&& root->left != NULL) {
					if (root->par != NULL) {
						if (root->par->key.first
							< root->key.first)
							root->par->right = root->left;
						else
							root->par->left = root->left;
						Updateheight(root->par);
					}
					root->left->par = root->par;
					root->left = Balance(
						root->left);
					return root->left;
				}
				else if (root->left == NULL
						&& root->right != NULL) {
					if (root->par != NULL) {
						if (root->par->key.first
							< root->key.first)
							root->par->right = root->right;
						else
							root->par->left = root->right;
						Updateheight(root->par);
					}
					root->right->par = root->par;
					root->right = Balance(root->right);
					return root->right;
				}
				else if (root->left == NULL
						&& root->right == NULL) {
					if (root->par->key.first < root->key.first) {
						root->par->right = NULL;
					}
					else {
						root->par->left = NULL;
					}
	
					if (root->par != NULL)
						Updateheight(root->par);
	
					root = NULL;
					return NULL;
				}
				else {
					struct Node* tmpnode = root;
					tmpnode = tmpnode->right;
					while (tmpnode->left != NULL) {
						tmpnode = tmpnode->left;
					}
	
					value_type val = tmpnode->key;
	
					root->right
						= eraseNode(root->right, tmpnode->key);
	
					root->key = val;
					root = Balance(root);
				}
			}
			else if (root->key.first < key.first) {
				root->right = eraseNode(root->right, key);
	
				root = Balance(root);
			}
			else if (root->key.first > key.first) {
				root->left = eraseNode(root->left, key);
	
				root = Balance(root);
			}
			if (root != NULL) {
				Updateheight(root);
			}
		}
		return root;
	}

	public:
		void printBT( void )
		{
			printBT("", __root, false);    
		}

		void insertNode(value_type key)
		{
			__root = insertNode(__root, NULL, key);
		}

		void deleteNode(value_type key)
		{
			__root = eraseNode(__root, key);
		}

		Node*	copy_helper(Node* root)
		{
			if (root == NULL)
				return root;
			Node*	copy = __alloc.allocate(1);
			// __alloc.construct(root, Node(NULL, NULL, NULL, key.first, key.second, 0));

			__alloc.construct(copy, Node(NULL, NULL, NULL, root->key.first, root->key.second, 0));
			copy->height	= root->height;
			copy->par		= root->par;
			copy->left		= copy_helper(root->left); 
			copy->right		= copy_helper(root->right); 
			return copy;
		}

		void	noodles_destroyer(Node *noodle)
		{
			// LOG("address of value: " << noodle->key.first << " is " << noodle);
			if (noodle == NULL)
				return;
			
			// LOG(noodle->key.first);
			__alloc.destroy(noodle);
			__alloc.deallocate(noodle, 1);
			if (noodle->left)
				noodles_destroyer(noodle->left);
			if (noodle->right)
				noodles_destroyer(noodle->right);
		}

		void	destroy_noodles( void )
		{
			noodles_destroyer(__root);
			noodles_destroyer(mv_ch);
		}
	//! AvlBSt canonical form
	public:
		//* Copy contructor.
		AvlBST( const AvlBST& src )
		{
			*this = src;
		};
		//* Assignement operator. Should be a deep copy not shallow.
		AvlBST& operator=( const AvlBST& rhs)
		{
			//TODO: should copy a whole new tree instead of just one node.
			__alloc	= rhs.__alloc;
			__cmp	= rhs.__cmp;
			__root	= copy_helper(rhs.__root);
			mv_ch	= copy_helper(rhs.mv_ch);

			// __root	= rhs.__root;
			// mv_ch	= rhs.mv_ch;
			return *this;
		};
		//* Destructor
		~AvlBST( void )
		{
			LOG("Reached here");
			//TODO: to be implemented.
			destroy_noodles();
		};
		AvlBST	begin()
		{
			// value_type	*temp;
			// temp	=	this->minValue();
			AvlBST(__root, minValue());
		}
	//! Insertion methods.
	public:
		//* Default constructor.
		AvlBST( const allocator_type& alloc = allocator_type() ): __root(NULL), mv_ch(NULL), __alloc(alloc) {
		};

	//! Arithmetic operators.
	public:
		AvlBST& operator++()
		{
			mv_ch = inOrderSuccessor(mv_ch);
			LOG(mv_ch->key.second);
			return *this;
		}
	//! ======================================================================================
	public:
		//? Should I keep the default constructor private or not?
		//* Private attributes.
		Node								*__root; //* The head of the BST.
		Node								*mv_ch; //* Aka moving child, a sub node that may change. (during the arithmetic operations)
		__Compare							__cmp;
		Allocator							allocPAIR;
		__allocTy							__alloc;
};



// pass 	the root node of your binary tree