#pragma once

#include <iostream>
#include "../Utils/utility.hpp"

template <class __T, class __Compare, class Allocator = std::allocator<__T> >
class AvlBST
{
	public: 
	struct Node
	{
		typedef typename __T::first_type		first_type;
		typedef typename __T::second_type		second_type;
		//? Is the parent node needed?
		Node				*par;
		Node				*right;
		Node				*left;
		__T					key;
		int					height;
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
			else if (__cmp(key.first, current->key.first))
				current = current->left;
			else if (__cmp(current->key.first, key.first))
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
			else if (__cmp(key, current->key.first))
				current = current->left;
			else if (__cmp(current->key.first, key))
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
			&& __cmp(root->key.first, tmpnode->par->key.first)) {
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
			&& __cmp(root->key.first, tmpnode->par->key.first)) {
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

	ft::pair<Node*, bool>	insertNode(struct Node* &root,struct Node* parent,	value_type key)
	{
		ft::pair<Node*, bool>	pair_ret;
		if (root == NULL) {
			root = __alloc.allocate(1);
			__alloc.construct(root, Node(NULL, NULL, NULL, key.first, key.second, 0));
			root->height = 1;
			root->left = NULL;
			root->right = NULL;
			root->par = parent;
			pair_ret = (ft::make_pair(root, true));
		}
		else if (root->key.first == key.first)
			return(ft::make_pair(root, false));
		else if (__cmp(key.first, root->key.first)) {
			pair_ret = insertNode(root->left,	root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight = root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight- secondheight)== 2) {
	
				if (root->left != NULL && __cmp(key.first, root->left->key.first)) {
					root = LLR(root);
				}
				else {
					root = LRR(root);
				}
			}
		}
	
		else if (__cmp(root->key.first, key.first)) {
			pair_ret = insertNode(root->right, root, key);
			int firstheight = 0;
			int secondheight = 0;
	
			if (root->left != NULL)
				firstheight
					= root->left->height;
	
			if (root->right != NULL)
				secondheight = root->right->height;
			if (abs(firstheight - secondheight) == 2) {
				if (root->right != NULL	&& __cmp(key.first, root->right->key.first)) {
					root = RLR(root);
				}
				else {
					root = RRR(root);
				}
			}
		}
		Updateheight(root);
		return pair_ret;
	}

	//! Debugging functions.
	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
		if( node != nullptr )
		{
			std::cout << prefix;

			std::cout << (isLeft ? "?????????" : "?????????" );

			std::cout << node->key.first;
			std::cout << std::endl;

			printBT( prefix + (isLeft ? "???   " : "    "), node->left, true);
			printBT( prefix + (isLeft ? "???   " : "    "), node->right, false);
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

	public:
		void printBT( void )
		{
			printBT("", __root, false);    
		}

		ft::pair<Node*, bool> insertNode(value_type key)
		{
			return insertNode(__root, NULL, key);
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

			__alloc.construct(copy, Node(NULL, NULL, NULL, root->key.first, root->key.second, 0));
			copy->height	= root->height;
			copy->par		= par;
			copy->left		= copy_helper(root->left, copy); 
			copy->right		= copy_helper(root->right, copy); 
			return copy;
		}

		void	noodles_destroyer(Node *noodle)
		{
			if (noodle == NULL)
				return;
			
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
	public:

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
			this->end_node	= end;
		};

		AvlBST& operator=( const AvlBST& rhs)
		{
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
		~AvlBST( void ) {};

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
				if (root && __cmp(k, root->key.first))
					return search(k, root->left);
				else if (root && __cmp(root->key.first, k))
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
				if (root && __cmp(k, root->key.first))
				{
					return (search_unique(k, root->left));
				}
				else if (root && __cmp(root->key.first, k))
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

		Node*	search_unique(const first_type& k, Node* root) const
		{
			try
			{
				if (root && k == root->key.first)
				{
					Node* tmp;

					tmp = root;
					return tmp;
				}
				if (root && __cmp(k, root->key.first))
				{
					return (search_unique(k, root->left));
				}
				else if (root && __cmp(root->key.first, k))
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

	public:
		//* Default constructor.
		AvlBST( const allocator_type& alloc = allocator_type() ): __root(NULL), mv_ch(NULL), __alloc(alloc) {
			end_node = __alloc.allocate(1);
		};

	public:
		Node* operator++()
		{
			mv_ch = inOrderSuccessor(mv_ch);
			if(mv_ch == NULL)
				mv_ch = end_node;
			return mv_ch;
		}

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
		Node								*__root;
		Node								*mv_ch;
		Node								*end_node;
		__Compare							__cmp;
		Allocator							allocPAIR;
		__allocTy							__alloc;
};
