#pragma once

#include <iostream>
#include "utility.hpp"
#include "mapIterator.hpp"
#include "avlBST.hpp"
#include "reverse_iterator.hpp"
namespace ft
{

	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> >
	> class map
	{
		public:
			//* Types.
			typedef	Key														key_type;
			typedef	T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			typedef	Alloc													allocator_type;
			typedef typename allocator_type::reference&						reference;
			typedef typename allocator_type::const_reference&				const_reference;


			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			
			//* Iterators.
			typedef	mapIterator<AvlBST<value_type, key_compare> >							iterator;
			typedef mapIterator<AvlBST<value_type, key_compare> >						const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef std::size_t										size_type;






		public:
		//! The canonical form =====================================================================
		//* Default constructor.
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __Size(0), __Alloc(alloc), __cmp(comp) {
			// LOG("[map] Default constructor.");
		};
		//* Copy constructor.
		map (const map& src): __Size(src.__Size), __cmp(src.__cmp), __TreeRoot(src.__TreeRoot)
		{
			//TODO: implement copy constructor.

		}
		//* Range constructor.
		template <class InputIterator>
  		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): __Size(0), __cmp(comp), __Alloc(alloc)
		{
			insert(first, last);
		};
		map& operator= (const map& x)
		{
			__TreeRoot	= x.__TreeRoot;
			__Size		= x.__Size;
			return *this;
		};
		//! The canonical form =====================================================================



		//! Capacity Member functions.
		public:
			size_type	size() const
			{
				return __Size;
			};

			bool		empty() const
			{
				return __Size;
			}

			size_type	max_size() const	//! Incorrect.
			{
				return __Alloc.max_size();
			}
			ft::pair<iterator, bool>	insert(const value_type& val)
			// void	insert(const value_type& val)
			{
				// typename AvlBST<value_type, key_compare, Alloc>::Node*	temp;
				// bool													ret;
















				ft::pair<typename AvlBST<value_type, key_compare, Alloc>::Node*, bool> ret;
				ret = __TreeRoot.insertNode(val);
				// LOG("---> " << ret.first->key.first << ": " << ret.second);
				if (ret.second)
					__Size++;
				return ft::make_pair<iterator, bool>(this->find(val.first), ret.second);










				// if ((temp = __TreeRoot.searchNode(__TreeRoot.__root, val)))
				// 	return ft::make_pair<iterator, bool>(iterator(AvlBST<value_type, key_compare>(__TreeRoot.__root, temp)), false);
				// LOG("--->" << __TreeRoot.insertNode(val).second);
				// temp = __TreeRoot.searchNode(__TreeRoot.__root, val);
				// __Size++;
				// return ft::make_pair<iterator, bool>(iterator(AvlBST<value_type, key_compare>(__TreeRoot.__root, ret.first)), ret.second);
			};
			//! Am I retarded or that's how it should be done?
			//* Yes I am indeed retarded, the hint is to help you reach faster the required node, if not found, then insert from the root.
			// iterator insert (iterator position, const value_type& val)
			// {
			// 	reinterpret_cast<void>(position);
			// 	return	insert(val).first;
			// };
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
				return iterator(__TreeRoot.begin());
			}
			const_iterator	begin() const
			{
				return const_iterator(__TreeRoot.begin());
			}

			//? Is this working? I don't feel like it should be working but I guess it does work?!

			iterator	end()
			{
				return iterator(__TreeRoot.end());
			}
			const_iterator	end() const
			{
				return const_iterator(__TreeRoot.end());
			}
		//! Operators.
		void			clear()
		{
			while (__Size > 0)
				this->erase(__TreeRoot.__root->key.first);
		}
		mapped_type&	operator[] (const key_type& k)
		{
			typename AvlBST<value_type, key_compare, Alloc>::Node*	temp;
			if ( (temp = __TreeRoot.searchNode(__TreeRoot.__root, ft::make_pair<key_type, mapped_type>(k, mapped_type()))))
				return temp->key.second;
			temp = __TreeRoot.insertNode(__TreeRoot.__root,NULL, ft::make_pair<key_type, mapped_type>(k, mapped_type())).first;
			return temp->key.second;
		}
		key_compare	key_comp() const
		{
			return key_compare(__cmp);
		}
		//? What the heck is this function doing. V
		// value_compare	value_comp() const
		// {
			
		// }
		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				first++;
			}
		};
		void		erase(iterator position)
		{
			//TODO: (ΦзΦ). . . fuck this.
			if (__TreeRoot.searchNode(__TreeRoot.__root, (*position).first))
			{
				__TreeRoot.deleteNode((*position).first);
				__Size--;
			}
		}
		size_type	erase (const key_type& k)
		{
			int ret = 0;
			if (__TreeRoot.searchNode(__TreeRoot.__root, k))
				ret = 1;
			__TreeRoot.deleteNode(k);
			if (ret && __Size > 0)
				__Size--;
			return ret;
		}

		void	swap(map& x)
		{
			map	temp;

			temp	= x;
			x 		= *this;
			x		= temp;
		}

		iterator	find(const key_type& k)
		{
			if (__TreeRoot.__root != NULL)
			{
				try
				{
					return(iterator(__TreeRoot.search_unique(k, __TreeRoot.__root)));
				}
				catch(const char *e)
				{
					return end();
				}
				
			}
			else
				return end();
		}
		// iterator	find(const key_type& k)
		// {
		// 	typename AvlBST<value_type, key_compare, Alloc>::Node*	temp;

		// 	temp = __TreeRoot.searchNode(__TreeRoot.__root, k);
		// 	if (temp)
		// 		return (iterator(AvlBST<value_type, key_compare, Alloc>(__TreeRoot.__root, temp)));
			
		// 		return iterator(AvlBST<value_type, key_compare, Alloc>());
		// }
		allocator_type get_allocator() const
		{
			return allocator_type();
		};
		//! Currently they're public for testing only.
		//TODO: return it private after finishing tests.
		public:
			size_t											__Size;
			AvlBST<value_type, key_compare, Alloc>					__TreeRoot;
			// size_t			__Capacity; //<==== Not sure if there's a Capacity counter since it's a BST.
			allocator_type									__Alloc;
			key_compare										__cmp;

	};
	
};