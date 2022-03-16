#pragma once

#include <iostream>
#include "utility.hpp"
#include "mapIterator.hpp"
#include "avlBST.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <unistd.h>
#include "iterator_traits.hpp"
namespace ft
{


	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			//* Types.
			typedef	Key																				key_type;
			typedef	T																				mapped_type;
			typedef ft::pair<const key_type, mapped_type>											value_type;
			typedef Compare																			key_compare;
			typedef	Alloc																			allocator_type;
			typedef typename allocator_type::reference&												reference;
			typedef typename allocator_type::const_reference&										const_reference;
			typedef typename Alloc::template rebind<AvlBST<value_type, key_compare, Alloc> >::other __AllocAVL;


			typedef typename allocator_type::pointer												pointer;
			typedef typename allocator_type::const_pointer											const_pointer;
			
			//* Iterators.
			typedef	mapIterator<AvlBST<value_type, key_compare, Alloc> >							iterator;
			typedef mapIterator<const AvlBST<value_type, key_compare, Alloc> >						const_iterator;
			typedef ft::reverse_iterator<iterator>													reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>											const_reverse_iterator;
			typedef std::ptrdiff_t																	difference_type;
			typedef std::size_t																		size_type;

		class value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};




		public:
		//! The canonical form =====================================================================
		//* Default constructor.
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __Size(0), __Alloc(alloc), __cmp(comp) {
			__TreeRoot =  __allocAVL.allocate(1);
			__allocAVL.construct(__TreeRoot,AvlBST<value_type, key_compare, Alloc>());
		};
		//* Copy constructor.
		map (const map& src): __Size(src.__Size), __cmp(src.__cmp)
		{
			//TODO: implement copy constructor.
			__TreeRoot =  __allocAVL.allocate(1);
			__allocAVL.construct(__TreeRoot,AvlBST<value_type, key_compare, Alloc>());
			*this = src;
		}
		//* Range constructor.
		template <class InputIterator>
  		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __Size(0), __Alloc(alloc), __cmp(comp)
		{
			__TreeRoot =  __allocAVL.allocate(1);
			__allocAVL.construct(__TreeRoot,AvlBST<value_type, key_compare, Alloc>());
			insert(first, last);
		};
		map& operator= (const map& x)
		{
			this->__Alloc = x.__Alloc;
			__TreeRoot->__root = __TreeRoot->copy_helper(x.__TreeRoot->__root, NULL);
			__Size		= x.__Size;
			return *this;
		};

		~map ( void )
		{
			this->clear();
			__allocAVL.destroy(__TreeRoot);
			__allocAVL.deallocate(__TreeRoot, 1);
		}
		//! The canonical form =====================================================================



		//! Capacity Member functions.
		public:
			size_type	size() const
			{
				return __Size;
			};

			bool		empty() const
			{
				return (__TreeRoot->__root) ? false : true;
			}

			size_type	max_size() const
			{
				return __Alloc.max_size();
			}

			ft::pair<iterator, bool>	insert(const value_type& val)
			{
				ft::pair<typename AvlBST<value_type, key_compare, Alloc>::Node*, bool> ret;
				ret = __TreeRoot->insertNode(val);
				if (ret.second)
					__Size++;
				return ft::make_pair<iterator, bool>(this->find(val.first), ret.second);
			};

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				return	insert(val).first;
			};

			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(ft::pair<key_type, mapped_type>((*first).first, (*first).second));
					first++;
				}
			};

		//! Iterator member functions.
		public:
			iterator	begin()
			{
				typename AvlBST<value_type, key_compare, Alloc>::Node*	temp;
				if (!__Size)
					temp = __TreeRoot->end();
				else
					temp = __TreeRoot->begin();
				return iterator(__TreeRoot, temp);
			}
			const_iterator	begin() const
			{
				typename AvlBST<value_type, key_compare, Alloc>::Node*	temp;
				if (!__Size)
					temp = __TreeRoot->end();
				else
					temp = __TreeRoot->begin();
				return const_iterator(__TreeRoot, temp);
			}
			reverse_iterator	rbegin()
			{
				return reverse_iterator(this->end());
			}
			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(this->end());
			}

			iterator	end()
			{
				typename AvlBST<value_type, key_compare, Alloc>::Node*	temp = __TreeRoot->end();
				return iterator(__TreeRoot, temp);
			}
			const_iterator	end() const
			{
				typename AvlBST<value_type, key_compare, Alloc>::Node*	temp = __TreeRoot->end();
				return const_iterator(__TreeRoot, temp);
			}

			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend() const
			{
				return const_reverse_iterator(begin());
			}
		//! Operators.
		void			clear()
		{
			while (__Size > 0)
				this->erase(__TreeRoot->__root->key.first);
		}

		mapped_type&	operator[] (const key_type& k)
		{
			try
			{
				return (__TreeRoot->search(k, __TreeRoot->__root));
			}
			catch(...)
			{
				insert(ft::make_pair(k, mapped_type()));
				return (__TreeRoot->search(k, __TreeRoot->__root));
			}
		}
		key_compare	key_comp() const
		{
			return key_compare(__cmp);
		}
		//? What the heck is this function doing. V
		value_compare	value_comp() const
		{
			return value_compare(key_comp());
		}

		void erase (iterator first, iterator last)
		{
			std::vector<key_type> temp;
			while (first != last)
			{
				temp.push_back(first->first);
				first++;
			}
			for(size_t i = 0; i < temp.size(); i++)
			{
				__TreeRoot->deleteNode((temp[i]));
				__Size--;	
			}
		};

		void		erase(iterator position)
		{
			if (__TreeRoot->searchNode(__TreeRoot->__root, (*position).first))
			{
				__Size--;
				__TreeRoot->deleteNode((*position).first);
			}
		}

		size_type	erase (const key_type& k)
		{
			int ret = 0;
			if (__TreeRoot->searchNode(__TreeRoot->__root, k))
				ret = 1;
			__TreeRoot->deleteNode(k);
			if (ret && __Size > 0)
				__Size--;
			return ret;
		}

		void	swap(map& x)
		{
			AvlBST<value_type, key_compare, Alloc>			*tempTree	= this->__TreeRoot;
			size_t											tempSize	= this->__Size;
			this->__TreeRoot	= x.__TreeRoot;
			this->__Size		= x.__Size;
			x.__TreeRoot		= tempTree;
			x.__Size			= tempSize;
		}

		iterator	find(const key_type& k)
		{
			if (__TreeRoot->__root != NULL)
			{
				try
				{
					return(iterator(__TreeRoot, __TreeRoot->search_unique(k, __TreeRoot->__root)));
				}
				catch(const char *e)
				{
					return end();
				}
				
			}
			else
				return end();
		}
		const_iterator	find(const key_type& k) const
		{
			if (__TreeRoot->__root != NULL)
			{
				try
				{
					return(const_iterator(__TreeRoot, __TreeRoot->search_unique(k, __TreeRoot->__root)));
				}
				catch(const char *e)
				{
					return end();
				}
				
			}
			else
				return end();
		}

		size_type	count(const key_type& k) const
		{
			if (find(k) == end())
				return 0;
			else
				return 1;
		}

		iterator	lower_bound (const key_type& k)
		{
			typename AvlBST<value_type, key_compare, Alloc>::Node*	lowest = __TreeRoot->__root;
			iterator												result;
			while (lowest)
			{
				if (!__cmp(lowest->key.first, k))
				{
					result = iterator(__TreeRoot, lowest);
					lowest = lowest->left;
				}
				else
					lowest = lowest->right;
			}
			return iterator(result);
		}
		const_iterator	lower_bound (const key_type& k) const
		{
			typename AvlBST<value_type, key_compare, Alloc>::Node*	lowest = __TreeRoot->__root;
			const_iterator												result;
			while (lowest)
			{
				if (!__cmp(lowest->key.first, k))
				{
					result = const_iterator(__TreeRoot, lowest);
					lowest = lowest->left;
				}
				else
					lowest = lowest->right;
			}
			return const_iterator(result);
		}

		iterator	upper_bound(const key_type& k)
		{
			typename AvlBST<value_type, key_compare, Alloc>::Node*	upper = __TreeRoot->__root;
			iterator												result;

			while (upper)
			{
				if (__cmp(k, upper->key.first))
				{
					result = iterator(__TreeRoot, upper);
					upper = upper->left; 
				}
				else
					upper = upper->right;
			}
			return iterator(result);
		}
		const_iterator	upper_bound(const key_type& k) const
		{
			typename AvlBST<value_type, key_compare, Alloc>::Node*	upper = __TreeRoot->__root;
			const_iterator												result;

			while (upper)
			{
				if (__cmp(k, upper->key.first))
				{
					result = const_iterator(__TreeRoot, upper);
					upper = upper->left; 
				}
				else
					upper = upper->right;
			}
			return const_iterator(result);
		}
		ft::pair<iterator, iterator>	equal_range(const key_type& k)
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
		{
			return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
		}

		allocator_type get_allocator() const
		{
			return allocator_type();
		};

		private:
			__AllocAVL										__allocAVL;
			size_t											__Size;
			AvlBST<value_type, key_compare, Alloc>			*__TreeRoot;
			allocator_type									__Alloc;
			key_compare										__cmp;

	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator< (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return	ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator> (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return	rhs < lhs;
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator<= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return	!(rhs < lhs);
	};
	template< class Key, class T, class Compare, class Alloc >
	bool operator>= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return	!(lhs < rhs);
	};
	template <class Key, class T, class Compare, class Alloc>
  	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	};
};