#pragma once

#include <iostream>

template <class __T, class __Compare = std::less<__T>, class Allocator = std::allocator<__T> >
class AvlBST
{
	private:
		//* Types.
		typedef __T									value_type;	
		typedef	Allocator							allocator_type;
		typedef typename allocator_type::reference	reference;
		typedef typename allocator_type::pointer	pointer;
		// typedef 
	public:
	struct Node
	{
		//? Is the parent node needed?
		Node				*par;			//* The parent node.
		Node				*right;				//* The right child node.
		Node				*left;				//* The left child node.
		value_type			key;				//* The key hold by the node.
		int					height;				//* The height of the node.
	};

	// int height(Node *N)
	// {
	// 	if (N == NULL)
	// 		return 0;
	// 	return N->height;
	// }

	// int max(int a, int b)
	// {
	// 	return (a > b) ? a : b;
	// }

	// Node*	findMin(Node* root)
	// {
	// 	Node* current = root;
	// 	while (current && current->left != NULL)
	// 		current = current->left;
	// 	return current;
	// }

	// int getBalanceFactor(Node *N)
	// {
	// 	if (N == NULL)
	// 		return 0;
	// 	return (height(N->left) - height(N->right));
	// }

	// Node*	rightRotate(Node* y)
	// {
	// 	Node *x = y->left; //* temp nood?
	// 	Node *T2 = x->right;
	// 	x->right = y;
	// 	y->left = T2;
	// 	y->height = max(height(y->left), height(y->right)) + 1;
	// 	x->height = max(height(x->left), height(x->right)) + 1;
	// 	return x;	
	// };

	// Node*	leftRotate(Node* x)
	// {
	// 	Node *y = x->right;
	// 	Node *T2 = y->left;
	// 	y->left = x;
	// 	x->right = T2;
	// 	x->height = max(height(x->left), height(x->right)) + 1;
	// 	y->height = max(height(y->left), height(y->right)) + 1;
	// 	return y;	
	// };
	// Node*	deleteNode(Node* root, value_type key)
	// {
	// 	//* Empty tree
	// 	if (root == NULL)
	// 		return root;
		
	// 	//* Search for the node to be deleted.
	// 	if (key.first < root->key.first)
	// 		root->left = deleteNode(root->left, key);
	// 	else if (key.first > root->key.first)
	// 		root->right = deleteNode(root->right, key);
	// 	else //* Found the node to be deleted.
	// 	{
	// 		//* The case where the node has either one or no child.
	// 		if ((root->left == NULL) || (root->right == NULL))
	// 		{
	// 			Node *temp = root->left ? root->left : root->right;

	// 			if (temp == NULL)
	// 			{
	// 				temp = root;
	// 				root = NULL;
	// 			}
	// 			else
	// 				*root = *temp;
	// 			free(temp);
	// 		}
	// 		else
	// 		{
	// 			Node* temp = findMin(root->right);
	// 			root->key = temp->key;
	// 			root->right = deleteNode(root->right, temp->key);
	// 		}
	// 	}
	// 	if (root == NULL)
	// 		return root;
		

	// 	//* Updating the binary tree to be balanced
	// 	root->height = 1 + max(height(root->left), height(root->right));
	// 	int balanceFactor = getBalanceFactor(root);
	// 	if (balanceFactor > 1)
	// 	{
	// 		if (getBalanceFactor(root->left) >= 0)
	// 			return rightRotate(root);
	// 		else
	// 		{
	// 			root->left = leftRotate(root->left);
	// 			return rightRotate(root);
	// 		}
	// 	}
	// 	if (balanceFactor < -1)
	// 	{
	// 		if (getBalanceFactor(root->right) <= 0)
	// 			return leftRotate(root);
	// 		else
	// 		{
	// 			root->right = rightRotate(root->right);
	// 			return leftRotate(root);
	// 		}
	// 	}
	// 	return root;
	// }

	// Node*	createNode(value_type key, Node* par)
	// {
	// 	Node* newNode = new Node(); //TODO: change the "new" allocation with the allocator allocation.

	// 	//TODO: the key must be allocated and constructed as well
	// 	newNode->key = key;
	// 	newNode->left = newNode->right = NULL;
	// 	newNode->parent = par;
	// 	newNode->height = 1;
	// 	return (newNode);
	// }

	// Node*	insertNode(Node* node, value_type key, Node* parent = NULL)
	// {
	// 	//!====================================================
	// 	//* Generic BST insertion.
	// 	if (node == NULL)
	// 		return(createNode(key, parent));

	// 	if (key.first < node->key.first)
	// 		node->left = insertNode(node->left, key, node);
	// 	else if (key.first > node->key.first)
	// 		node->right = insertNode(node->right, key, node);
	// 	else
	// 		return node;
	// 	//!====================================================



	// 	//* Update balance factor of each node.
	// 	node->height = 1 + max(height(node->left), height(node->right));
	// 	int	balanceFactor = getBalanceFactor(node);
	// 	if (balanceFactor > 1)
	// 	{
	// 		if (key.first < node->left->key.first)
	// 			return rightRotate(node);
	// 		else if (key.first > node->left->key.first)
	// 		{
	// 			node->left = leftRotate(node->left);
	// 			return rightRotate(node);
	// 		}
	// 	}
		
	// 	if (balanceFactor < - 1)
	// 	{
	// 		if (key.first > node->right->key.first)
	// 			return leftRotate(node);
	// 		else if (key.first < node->right->key.first)
	// 		{
	// 			node->right = rightRotate(node->right);
	// 			return leftRotate(node);
	// 		}
	// 	}
	// 	return node;

	// }





Node* minValue(Node* node)
{
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

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

Node* inOrderSuccessor(
    Node* root,
    Node* n)
{
    // step 1 of the above algorithm
    if (n->right != NULL)
        return minValue(n->right);
 
    // step 2 of the above algorithm
    Node* p = n->par;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->par;
    }
    return p;
}

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

void Updateheight(
    struct Node* root)
{
    if (root != NULL) {
  
        // Store the height of the
        // current node
        int val = 1;
  
        // Store the height of the left
        // and right substree
        if (root->left != NULL)
            val = root->left->height + 1;
  
        if (root->right != NULL)
            val = std::max(
                val, root->right->height + 1);
  
        // Update the height of the
        // current node
        root->height = val;
    }
}
  
// Function to handle Left Left Case
struct Node* LLR(
    struct Node* root)
{
    // Create a reference to the
    // left child
    struct Node* tmpnode = root->left;
  
    // Update the left child of the
    // root to the right child of the
    // current left child of the root
    root->left = tmpnode->right;
  
    // Update parent pointer of the
    // left child of the root node
    if (tmpnode->right != NULL)
        tmpnode->right->par = root;
  
    // Update the right child of
    // tmpnode to root
    tmpnode->right = root;
  
    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;
  
    // Update the parent pointer
    // of the root
    root->par = tmpnode;
  
    // Update tmpnode as the left or the
    // right child of its parent pointer
    // according to its key value
    if (tmpnode->par != NULL
        && root->key.first < tmpnode->par->key.first) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
  
    // Make tmpnode as the new root
    root = tmpnode;
  
    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
  
    // Return the root node
    return root;
}
  
// Function to handle Right Right Case
struct Node* RRR(
    struct Node* root)
{
    // Create a reference to the
    // right child
    struct Node* tmpnode = root->right;
  
    // Update the right child of the
    // root as the left child of the
    // current right child of the root
    root->right = tmpnode->left;
  
    // Update parent pointer of the
    // right child of the root node
    if (tmpnode->left != NULL)
        tmpnode->left->par = root;
  
    // Update the left child of the
    // tmpnode to root
    tmpnode->left = root;
  
    // Update parent pointer of
    // the tmpnode
    tmpnode->par = root->par;
  
    // Update the parent pointer
    // of the root
    root->par = tmpnode;
  
    // Update tmpnode as the left or
    // the right child of its parent
    // pointer according to its key value
    if (tmpnode->par != NULL
        && root->key < tmpnode->par->key) {
        tmpnode->par->left = tmpnode;
    }
    else {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }
  
    // Make tmpnode as the new root
    root = tmpnode;
  
    // Update the heights
    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
  
    // Return the root node
    return root;
}
  
// Function to handle Left Right Case
struct Node* LRR(
    struct Node* root)
{
    root->left = RRR(root->left);
    return LLR(root);
}
  
// Function to handle right left case
struct Node* RLR(
    struct Node* root)
{
    root->right = LLR(root->right);
    return RRR(root);
}


struct Node* Balance(
    struct Node* root)
{
    // Store the current height of
    // the left and right subtree
    int firstheight = 0;
    int secondheight = 0;
  
    if (root->left != NULL)
        firstheight = root->left->height;
  
    if (root->right != NULL)
        secondheight = root->right->height;
  
    // If current node is not balanced
    if (std::abs(firstheight - secondheight) == 2) {
        if (firstheight < secondheight) {
  
            // Store the height of the
            // left and right subtree
            // of the current node's
            // right subtree
            int rightheight1 = 0;
            int rightheight2 = 0;
            if (root->right->right != NULL)
                rightheight2 = root->right->right->height;
  
            if (root->right->left != NULL)
                rightheight1 = root->right->left->height;
  
            if (rightheight1 > rightheight2) {
  
                // Right Left Case
                root = RLR(root);
            }
            else {
  
                // Right Right Case
                root = RRR(root);
            }
        }
        else {
  
            // Store the height of the
            // left and right subtree
            // of the current node's
            // left subtree
            int leftheight1 = 0;
            int leftheight2 = 0;
            if (root->left->right != NULL)
                leftheight2 = root->left->right->height;
  
            if (root->left->left != NULL)
                leftheight1 = root->left->left->height;
  
            if (leftheight1 > leftheight2) {
  
                // Left Left Case
                root = LLR(root);
            }
            else {
  
                // Left Right Case
                root = LRR(root);
            }
        }
    }
  
    // Return the root node
    return root;
}

// Function to insertNode a node in
// the AVL tree
struct Node* insertNode(
    struct Node* root,
    struct Node* parent,
    value_type key)
{
  
    if (root == NULL) {
  
        // Create and assign values
        // to a new node
        root = new struct Node;
		root->height = 1;
		root->left = NULL;
		root->right = NULL;
		root->par = parent;
		root->key = key;
    }
  
    else if (root->key.first > key.first) {
  
        // Recur to the left subtree
        // to insertNode the node
        root->left = insertNode(root->left,
                            root, key);
  
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
  
        if (root->left != NULL)
            firstheight = root->left->height;
  
        if (root->right != NULL)
            secondheight = root->right->height;
  
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight
                - secondheight)
            == 2) {
  
            if (root->left != NULL
                && key.first < root->left->key.first) {
  
                // Left Left Case
                root = LLR(root);
            }
            else {
  
                // Left Right Case
                root = LRR(root);
            }
        }
    }
  
    else if (root->key < key) {
  
        // Recur to the right subtree
        // to insertNode the node
        root->right = insertNode(root->right,
                             root, key);
  
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
  
        if (root->left != NULL)
            firstheight
                = root->left->height;
  
        if (root->right != NULL)
            secondheight = root->right->height;
  
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight - secondheight) == 2) {
            if (root->right != NULL
                && key.first < root->right->key.first) {
  
                // Right Left Case
                root = RLR(root);
            }
            else {
  
                // Right Right Case
                root = RRR(root);
            }
        }
    }
  
    // Case when given key is already
    // in the tree
    else {
    }
  
    // Update the height of the
    // root node
    Updateheight(root);
  
    // Return the root node
    return root;
}







void printBT(const std::string& prefix, const Node* node, bool isLeft)
{
	if( node != nullptr )
	{
		std::cout << prefix;

		std::cout << (isLeft ? "├──" : "└──" );

		// print the value of the node
		std::cout << node->key.second;
		if (node->par)
			std::cout << "p:" << node->par->key.second << std::endl;

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
  
            // Replace root with its
            // left child
            if (root->right == NULL
                && root->left != NULL) {
                if (root->par != NULL) {
                    if (root->par->key.first
                        < root->key.first)
                        root->par->right = root->left;
                    else
                        root->par->left = root->left;
  
                    // Update the height
                    // of root's parent
                    Updateheight(root->par);
                }
  
                root->left->par = root->par;
  
                // Balance the node
                // after deletion
                root->left = Balance(
                    root->left);
  
                return root->left;
            }
  
            // Replace root with its
            // right child
            else if (root->left == NULL
                     && root->right != NULL) {
                if (root->par != NULL) {
                    if (root->par->key.first
                        < root->key.first)
                        root->par->right = root->right;
                    else
                        root->par->left = root->right;
  
                    // Update the height
                    // of the root's parent
                    Updateheight(root->par);
                }
  
                root->right->par = root->par;
  
                // Balance the node after
                // deletion
                root->right = Balance(root->right);
                return root->right;
            }
  
            // Remove the references of
            // the current node
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
  
            // Otherwise, replace the
            // current node with its
            // successor and then
            // recursively call eraseNode()
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
  
                // Balance the node
                // after deletion
                root = Balance(root);
            }
        }
  
        // Recur to the right subtree to
        // eraseNode the current node
        else if (root->key.first < key.first) {
            root->right = eraseNode(root->right, key);
  
            root = Balance(root);
        }
  
        // Recur into the right subtree
        // to eraseNode the current node
        else if (root->key.first > key.first) {
            root->left = eraseNode(root->left, key);
  
            root = Balance(root);
        }
  
        // Update height of the root
        if (root != NULL) {
            Updateheight(root);
        }
	}
  
    // Return the root node
    return root;
}











	public:
		void printBT(const Node* node)
		{
			printBT("", node, false);    
		}

		Node*	insertNode(const Node* __root, value_type key)
		{
			return insertNode(__root, key);
		}

		Node*	deleteNode(Node* __root, value_type key)
		{
			return eraseNode(__root, key);
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
		//* Default constructor.
		AvlBST( void ){
			std::cout << "[AvlBST] Default constructor.\n";
		};
		// struct Node<value_type>*	insertNode(struct Node<value_type>* node, value_type key)
		// {
		// 	// Return a new node if the tree is empty
		// 	if (node == NULL) return Node<value_type>(NULL, NULL, NULL, key);

		// 	// Traverse to the right place and insertNode the node
		// 	if (key < node->key)
		// 		node->left = insertNode(node->left, key);
		// 	else
		// 		node->right = insertNode(node->right, key);

		// 	return node;
		// }



	//! ======================================================================================
	public:
		//? Should I keep the default constructor private or not?
		//* Private attributes.
		// Node								*__root;
		__Compare							__cmp;
};



// pass 	the root node of your binary tree