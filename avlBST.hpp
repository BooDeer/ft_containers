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
		__Compare			_cmp;
		Node(__T val): key(val) {};
		Node(Node *p, Node *r, Node *l, first_type k1,second_type k2, int h): par(p), right(r), left(l), key(k1, k2), height(h) {};

		Node* next_node(Node* n) const
		{
			if (n->right != NULL)
				return min_node(n->right);

			Node* p = n->par;
			while (p != NULL && n == p->right) {
				n = p;
				p = p->par;
			}
			return p;
		};
		// Node* next_node(Node* re_node) const
		// {
		// 	Node* tmp;
		// 	if(re_node->right != nullptr)
		// 	{
		// 		// if has right go to most left
		// 		re_node = re_node->right;
		// 		re_node = min_node(re_node);
		// 	}
		// 	else
		// 	{
		// 		//if not, return to parent
		// 		tmp = re_node->par;
		// 		while (tmp != NULL && re_node == tmp->right)
		// 		{
		// 			re_node = tmp;
		// 			tmp = tmp->par;
		// 		}
		// 		// if right-most
		// 		re_node = tmp;
		// 	}
		// 	// if(re_node == nullptr)
		// 	// {
		// 		// re_node = last_node;
		// 	// }
		// 	return re_node;
		// };

		Node*	past_node(Node* node) const
		{
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
		
		Node*	max_node(Node *root) const
		{
			Node* temp = root;
			
			while(temp && temp->right)
				temp = temp->right;
			return temp;
		}

		Node*	min_node(Node *root) const
		{
			Node* current = root;
		
			while (current->left != NULL) {
				current = current->left;
			}
			return current;			
		}
	};
	public:
		//* Types.
		typedef __T															value_type;	
		typedef	Allocator													allocator_type;
		typedef typename Allocator::template rebind<Node>::other			__allocTy;
		typedef typename allocator_type::reference							reference;
		typedef typename allocator_type::pointer							pointer;
		typedef typename __T::first_type									first_type;
		typedef typename __T::second_type									second_type;
	public:

	//* Get the node with the smallest value.
	Node* minValue( void ) {
		Node* current = __root;
		if (__root == NULL)
			return __root;
		while (current->left != NULL) {
			current = current->left;
		}
		return current;
	}
	Node* minValue( void ) const {
		Node* current = __root;
		if (__root == NULL)
			return __root;
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
	Node* maxValue(Node* node)
	{
		Node* current = node;
	
		while (current->right != NULL) {
			current = current->right;
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
	Node* searchNode(Node* n, first_type key)
	{
		Node* current = n;

		while (current != NULL)
		{
			if (key == current->key.first)
				return current;
			else if (key < current->key.first)
				current = current->left;
			else if (key > current->key.first)
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
	int cal_hight(Node *r)
	{
		if (r->right && r->left)
		{
			if (r->left->height < r->right->height)
				return r->right->height  + 1;
			else
				return r->left->height + 1;
		}
		else if(r->right && r->left == NULL)
		{
				return r->right->height + 1;
		}
		else if (r->right == NULL && r->left)
			return r->left->height + 1;
		return 1;
	}
	// Function to handle Left Left Case
	
	struct Node* LLR(struct Node* root)
	{
		// LOG("LLR");
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
		// LOG("RRR");
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
		// LOG("LRR");
		root->left = RRR(root->left);
		return LLR(root);
	}
	
	// Function to handle right left case
	struct Node* RLR(struct Node* root)
	{
		// LOG("RLR");
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

	ft::pair<Node*, bool>	insertNode(struct Node* &root,struct Node* parent,	value_type key)
	{
		ft::pair<Node*, bool>	pair_ret;
		if (root == NULL) {
			root = __alloc.allocate(1);
			__alloc.construct(root, Node(NULL, NULL, NULL, key.first, key.second, 0));
			// LOG("Memory allocated for the value: " << key.first << " is " << root);
			root->height = 1;
			root->left = NULL;
			root->right = NULL;
			root->par = parent;
			pair_ret = (ft::make_pair(root, true));
		}
		else if (root->key.first == key.first)
			return(ft::make_pair(root, false));
		else if (root->key.first > key.first) {
			pair_ret = insertNode(root->left,	root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight = root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight- secondheight)== 2) {
	
				if (root->left != NULL && key.first < root->left->key.first) {
					root = LLR(root);
				}
				else {
					root = LRR(root);
				}
			}
		}
	
		else if (root->key < key) {
			pair_ret = insertNode(root->right, root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight
					= root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight - secondheight) == 2) {
				if (root->right != NULL	&& key.first < root->right->key.first) {
					root = RLR(root);
				}
				else {
					root = RRR(root);
				}
			}
		}
		// else {
		// 	pair_ret = (ft::make_pair(root, true));
		// }
		Updateheight(root);
		return pair_ret;
	}

	//! Debugging functions.
	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
		if( node != nullptr )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			// std::cout << node->key.second << "address:" << node;
			std::cout << node->key.first;
			// if (node->par)
				// std::cout << "p:" << node->par->key.second;
			std::cout << std::endl;

			// enter the next tree level - left and right branch
			printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
			printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
		}
	}
	void			swap_wnext(Node* root)
	{
		Node* temp = root->left;
		while(temp->right)
			temp = temp->right;
		ft::pair<const first_type, second_type> temp_pair(temp->key);
		allocPAIR.construct(&temp->key, root->key);
		allocPAIR.construct(&root->key, temp_pair);
	}
    void parent_correction(Node *&n, Node *p)
    {
        if (n == NULL)
            return ;
        parent_correction(n->right, n);
        n->par = p;
        parent_correction(n->left, n);
    }

	int		bf(Node	*&n)
	{
		if (n->right && n->left)
			return n->left->height - n->right->height;
		else if (n->right == NULL && n->left)
			return n->left->height;
		else if (n->right && n->left == NULL)
			return -n->right->height;
		return 1;		
	}

	Node *LLrotation(Node *x)
    {
        Node *y = x->right; // start split nodes
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;
    
        parent_correction(y, x->par); // start set all parrenet

        // update height :)
        if (y->left)
            y->left->height = cal_hight(y->left);
        if (y->right)
            y->right->height = cal_hight(y->right);
        y->height = cal_hight(y);
        return y;
    }
    Node *RRrotation(Node *y)
    {
           Node *x = y->left;
           Node *T2 = x->right;

           x->right = y;
           y->left = T2;
        parent_correction(x, y->par);  // start set all parrenet 

        // update height :)
        if (x->right)
            x->right->height = cal_hight(x->right);
        if (x->left)
            x->left->height = cal_hight(x->left);
        x->height =  cal_hight(x);

        return x;
    }
	struct Node*	eraseNode(Node* root, value_type key)
	{

		// if (root != NULL)
		// {
		// 	if (__cmp(root->key.first, key))
		// 		eraseNode(root->right, key);
		// 	else if (compare(key, root->key.first))
		// 		eraseNode(root->left, key);
		// 	else
		// 	{
		// 		if (root->right == NULL && root->left == NULL) //? Try changing this with corresponding height
		// 		{
		// 			__alloc.destroy(root);
		// 			__alloc.deallocate(root, 1);
		// 			root = NULL;
		// 		}
		// 		else if (root->right == NULL || root->left == NULL)
		// 		{
		// 			Node* temp = root->left ? root->left : root->right;
		// 			Node* tempar = root->par;

		// 			temp->par = root->par;
		// 			__alloc.destroy(root);
		// 			__alloc.deallocate(root, 1);
		// 			root = NULL;

		// 			if (tempar && __cmp(temp->key.first, tempar->key.first))
		// 				tempar->right = temp;
		// 			else if (tempar && __cmp(temp->key.first, tempar->key.first))
		// 				tempar->left = temp;
		// 			else
		// 				root = temp;
		// 		}
		// 		else if (root->left && root->right)
		// 		{
		// 			swap_wnext(root);
		// 			eraseNode(root->left, key);
		// 		}
		// 	}
		// 	if (!root)
		// 	{
		// 		return ;
		// 	}
		// 	Updateheight(root);
		// 	Balance(root);
		// }

		// if (root != NULL) {
		// 	// If the node is found
		// 	if (root->key.first == key.first)
		// 	{
		// 		if (root->right == NULL && root->left != NULL)
		// 		{
		// 			if (root->par != NULL)
		// 			{
		// 				if (root->par->key.first < root->key.first)
		// 					root->par->right = root->left;
		// 				else
		// 					root->par->left = root->left;
		// 				Updateheight(root->par);
		// 			}
		// 			root->left->par = root->par;
		// 			root->left = Balance(root->left);
		// 			return root->left;
		// 		}
		// 		else if (root->left == NULL	&& root->right != NULL)
		// 	{
		// 			if (root->par != NULL)
		// 			{
		// 				if (root->par->key.first < root->key.first)
		// 					root->par->right = root->right;
		// 				else
		// 					root->par->left = root->right;
		// 				Updateheight(root->par);
		// 			}
		// 			root->right->par = root->par;
		// 			root->right = Balance(root->right);
		// 			return root->right;
		// 		}
		// 		else if (root->left == NULL && root->right == NULL)
		// 		{
		// 			if (root-> par == NULL)
		// 			{
		// 				__alloc.destroy(root);
		// 				__alloc.deallocate(root, 1);
		// 				root = NULL;
		// 			}
		// 			else if (root->par->key.first < root->key.first)
		// 			{
		// 				root->par->right = NULL;
		// 			}
		// 			else
		// 			{
		// 				root->par->left = NULL;
		// 			}
	
		// 			if (root && root->par != NULL)
		// 				Updateheight(root->par);
	
		// 			root = NULL;
		// 			return NULL;
		// 		}
		// 		else(root->right != NULL)
		// 		{
		// 			struct Node* tmpnode = root;
		// 			tmpnode = tmpnode->right;
		// 			while (tmpnode->left != NULL)
		// 			{
		// 				tmpnode = tmpnode->left;
		// 			}
	
		// 			// value_type val = tmpnode->key;
		// 			root->right = eraseNode(root->right, tmpnode->key);
	
	
		// 			// root->key = val;
		// 			tmpnode->par = root->par;
		// 			tmpnode->right = root->right;
		// 			tmpnode->left = root->left;
		// 			tmpnode->height = root->height;
		// 			// __alloc.destroy(root);
		// 			// __alloc.deallocate(root, 1);
		// 			root = __alloc.allocate(1);
		// 			__alloc.construct(root,Node(tmpnode->par, tmpnode->right, tmpnode->left, tmpnode->key.first, tmpnode->key.second, tmpnode->height));
		// 			// Node(root->par, root->right, root->left, tmpnode->key.first, tmpnode->key.second, root->height);
		// 			root = Balance(root);
		// 		}
		// 		// else if (root->left != NULL)
		// 		// {
		// 		// 	struct Node* tmpnode = root;
		// 		// 	tmpnode = tmpnode->left;
		// 		// 	while (tmpnode->right != NULL)
		// 		// 	{
		// 		// 		tmpnode = tmpnode->right;
		// 		// 	}
	
		// 		// 	// value_type val = tmpnode->key;
		// 		// 	root->left = eraseNode(root->left, tmpnode->key);
	
	
		// 		// 	// root->key = val;
		// 		// 	tmpnode->par = root->par;
		// 		// 	tmpnode->right = root->right;
		// 		// 	tmpnode->left = root->left;
		// 		// 	tmpnode->height = root->height;
		// 		// 	// __alloc.destroy(root);
		// 		// 	// __alloc.deallocate(root, 1);
		// 		// 	root = __alloc.allocate(1);
		// 		// 	__alloc.construct(root,Node(tmpnode->par, tmpnode->right, tmpnode->left, tmpnode->key.first, tmpnode->key.second, tmpnode->height));
		// 		// 	// Node(root->par, root->right, root->left, tmpnode->key.first, tmpnode->key.second, root->height);
		// 		// 	root = Balance(root);
		// 		// }
		// 	}
		// 	else if (root->key.first < key.first)
		// 	{
		// 		root->right = eraseNode(root->right, key);
	
		// 		root = Balance(root);
		// 	}
		// 	else if (root->key.first > key.first)
		// 	{
		// 		root->left = eraseNode(root->left, key);
	
		// 		root = Balance(root);
		// 	}
		// if (root != NULL)
		// {
		// 	Updateheight(root);
		// }
		// }
		// return root;
		if(root == NULL)
        {
            // is_del = false;
            return NULL;
        }
        Node *tmp;
        if (__cmp(key.first, root->key.first))// key < root->key.first
        {
            // std::cout << "left test" << std::endl;
            root->left = eraseNode(root->left, key);
        }
        else if (__cmp(root->key.first, key.first))//key.first > root->key.first
        {
            // std::cout << "right test" << std::endl;
            root->right = eraseNode(root->right, key);
        }
        else if (key.first == root->key.first)
        {
            if (root->left != NULL)
            {
                tmp = maxValue(root->left);
                Node* tmp_r = root->right;
                Node* tmp_l = root->left;
                Node* tmp_pa = root->par;
                int tmp_h = root->height;
                this->__alloc.destroy(root); // destroy old node
                this->__alloc.deallocate(root, 1);
                root  = this->__alloc.allocate(1);
		// Node(Node *p, Node *r, Node *l, first_type k1,second_type k2, int h): par(p), right(r), left(l), key(k1, k2), height(h) {};

                this->__alloc.construct(root, Node(tmp_pa, tmp_r, tmp_l, tmp->key.first, tmp->key.second, tmp_h)); // copy hieght and parent ........
                root->left =  eraseNode(root->left , tmp->key); // delete next node
            }
            else if (root->right != NULL)
            {
                tmp = minValue(root->right);
                Node* tmp_r = root->right;
                Node* tmp_l = root->left;
                Node* tmp_pa = root->par;
                int tmp_h = root->height;
                this->__alloc.destroy(root); // destroy old node
                this->__alloc.deallocate(root, 1);
                root  = this->__alloc.allocate(1);
				// this->__alloc.construct(r, node<value_type>(tmp->pt.first, tmp->pt.second, tmp_pa, tmp_r, tmp_l, tmp_h));
                this->__alloc.construct(root, Node(tmp_pa, tmp_r, tmp_l, tmp->key.first, tmp->key.second, tmp_h)); // copy hieght and parent ........
                root->right = eraseNode(root->right , tmp->key); // delete next node
            }
            else
            {
                if(key.first == root->key.first)
                {
                    this->__alloc.destroy(root);
                    this->__alloc.deallocate(root, 1);
                }

                return NULL;

            }
		}
		    //balance cases
			if (__root == NULL) // if root == null mean no more node for delet 
				return NULL;
			// update heghit
			root->height =  cal_hight(root);
			if (root->left)
				root->left->height = cal_hight(root->left);
			if (root->right)
				root->right->height = cal_hight(root->right);
			// Updateheight(root);

			// update balance
			if (bf(root) > 1 && bf(root->left) >= 0)
				root = RRrotation(root); // left-left rotation
			else if (bf(root) < -1 && bf(root->right) <= 0)
				root = LLrotation(root);//  right-right rotation
			else if (bf(root) < -1 && bf(root->right) > 0)
			{
				root->right = RRrotation(root->right); // right-left rotation
				root = LLrotation(root);
			}
			else if (bf(root) > 1 && bf(root->left) < 0)
			{
				root->left = LLrotation(root->left); // left-right rotation
				root = RRrotation(root);
			}

		// update parent
			if (root->left)
				root->left->par = root;
			if (root->right)
				root->right->par = root;
		return root;
	}
	//! ===========================================================

	//! ===========================================================
	public:
		void printBT( void )
		{
			printBT("", __root, false);    
		}

		ft::pair<Node*, bool> insertNode(value_type key)
		{
			// if (this->searchNode(__root, key))
			// 	return false;
			return insertNode(__root, NULL, key);
			// return true;
		}

		void deleteNode(value_type key)
		{
			__root = eraseNode(__root, key);
		}
		void deleteNode(first_type key)
		{
			deleteNode(ft::make_pair<first_type, second_type>(key, second_type()));
		}

		Node*	copy_helper(Node* root, Node* par)
		{
			if (root == NULL)
				return root;
			Node*	copy = __alloc.allocate(1);
			// __alloc.construct(root, Node(NULL, NULL, NULL, key.first, key.second, 0));

			__alloc.construct(copy, Node(NULL, NULL, NULL, root->key.first, root->key.second, 0));
			copy->height	= root->height;
			copy->par		= par;
			copy->left		= copy_helper(root->left, copy); 
			copy->right		= copy_helper(root->right, copy); 
			return copy;
		}

		void	noodles_destroyer(Node *noodle)
		{
			// LOG("address of value: " << noodle->key.first << " is " << noodle);
			if (noodle == NULL)
				return;
			
			// LOG(noodle->key.first);
			// LOG("Parent of value: " << noodle->key.first);
			__alloc.destroy(noodle);
			__alloc.deallocate(noodle, 1);
			if (noodle->left)
			{
				noodles_destroyer(noodle->left);
			}
			if (noodle->right)
			{
				noodles_destroyer(noodle->right);
			}
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

		AvlBST(Node *root, Node* copy)
		{
			this->__root	= copy_helper(root, NULL);
			this->mv_ch		= copy_helper(copy, NULL);
		};
		AvlBST(Node *root, Node* copy, Node *end)
		{
			this->__root	= copy_helper(root, NULL);
			if (copy != NULL)
				this->mv_ch		= copy_helper(copy, NULL);
			else
				this->mv_ch		= end;
			// LOG("===========================================================");
			// LOG("-->" << this->mv_ch << " vs -->" << end);
			this->end_node	= end;
		};
		//* Assignement operator. Should be a deep copy not shallow.
		AvlBST& operator=( const AvlBST& rhs)
		{
			//TODO: should copy a whole new tree instead of just one node.
			__alloc	= rhs.__alloc;
			__cmp	= rhs.__cmp;
			__root	= copy_helper(rhs.__root, NULL);
			if (mv_ch != NULL)
				mv_ch	= copy_helper(rhs.mv_ch, NULL);
			else
				mv_ch = rhs.end_node;

			// __root	= rhs.__root;
			// mv_ch	= rhs.mv_ch;
			return *this;
		};
		//* Destructor
		~AvlBST( void )
		{
			// LOG("Reached here");
			//TODO: to be implemented.
			// destroy_noodles();
		};
		Node*	begin()
		{
			return minValue();
		}
		Node*	begin() const
		{
			return const_cast<Node*>(minValue());
		}

		Node*	end()
		{
			return end_node;
		}
		Node*	end() const
		{
			return const_cast<Node*>(end_node);
		}

		second_type&	search(const first_type &k, Node*	root)
		{
			try
			{
				if (root && k == root->key.first)
					return root->key.second;
				if (root && k < root->key.first)
					return search(k, root->left);
				else if (root && k > root->key.first)
					return search(k, root->right);
				throw "Not found";
			}
			catch(const char* e)
			{
				throw e;
			}
		}

		Node*	search_unique(const first_type& k, Node* root)
		{
			try
			{
				if (root && k == root->key.first)
				{
					Node* tmp;

					tmp = root;
					return tmp;
				}
				if (root && k < root->key.first)
				{
					return (search_unique(k, root->left));
				}
				else if (root && k > root->key.first)
				{
					return (search_unique(k, root->right));
				}
				throw "Error";
			}
			catch (const char *s)
			{
				throw s;
			}
		}

	//! Insertion methods.
	public:
		//* Default constructor.
		AvlBST( const allocator_type& alloc = allocator_type() ): __root(NULL), mv_ch(NULL), __alloc(alloc) {
			end_node = __alloc.allocate(1);
		};

	//! Arithmetic operators.
	public:
		Node* operator++()
		{
			mv_ch = inOrderSuccessor(mv_ch);
			if(mv_ch == NULL)
				mv_ch = end_node;
			return mv_ch;
		}
		// AvlBST& operator++(int)
		// {
		// 	AvlBST	tmp(*this);
		// 	++(*this);
		// 	return tmp;
		// }
		AvlBST& operator--()
		{
			if (mv_ch == end_node)
				mv_ch = maxValue(__root);
			else
				mv_ch = inOrderPredecessor(mv_ch);
			return *this;
		}
		AvlBST& operator--(int)
		{
			AvlBST tmp(*this);
			--(*this);
			return tmp;
		}

		value_type&	operator*() const
		{
			return mv_ch->key;
		}
		value_type*	operator->() const
		{
			return &(mv_ch->key);
		}

		friend	bool	operator==(const AvlBST&lhs, const AvlBST& rhs)
		{
			return lhs.mv_ch->key == rhs.mv_ch->key;
		}
		friend	bool	operator!=(const AvlBST&lhs, const AvlBST& rhs)
		{
			return lhs.mv_ch->key != rhs.mv_ch->key;
		}
	//! ======================================================================================
	public:
		//? Should I keep the default constructor private or not?
		//* Private attributes.
		Node								*__root; //* The head of the BST.
		Node								*mv_ch; //* Aka moving child, a sub node that may change. (during the arithmetic operations)
		Node								*end_node;
		__Compare							__cmp;
		Allocator							allocPAIR;
		__allocTy							__alloc;
};



// pass 	the root node of your binary tree