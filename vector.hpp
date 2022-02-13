#pragma once

#include <iostream>
#include <memory>

namespace ft{

	template < class T, class Alloc = std::allocator<T> > class vector
	{
		//! Member types.
		// Public--<begin>
		public:
			//! Typedefs only create a new alias for an existing type, you need to create a variable to hold that type before using it

			typedef T												value_type; 		//* First parametre of the templated class. (T)
			typedef Alloc											allocator_type; 	//* Second parametre of the templated class. (Alloc used to allocate memory)
			typedef	typename allocator_type::reference				reference; 			//* Reference to the allocator_type. (Equal to T&)
			typedef	typename allocator_type::const_reference		const_reference;	//* Const reference to the allocator_type. (Equal to const T&)
			typedef	typename allocator_type::pointer				pointer;			//* Pointer to the allocated object. (Equal to T*)
			typedef	typename allocator_type::const_pointer			const_pointer;		//* Const pointer to the allocated object. (Equal to const T*)
			// //TODO: implement the iterators to be used.
			// typedef	iterator<pointer>								iterator;
			// typedef	iterator<const_pointer>							const_iterator;
			// typedef													reverse_iterator;
			// typedef	xxx												const_reverse_iterator;
			// typedef	xxx												difference_type;
			// //TODO <=======================================>
			typedef	size_t											size_type;
		// Public--<end>
		//!=========================================
		//! Orthodox canonical form (Member functions)
		public:
		  	//* The default constructor.
			explicit vector( const allocator_type& alloc = allocator_type() ): __Vec(nullptr),
																	__Size(0), __Capacity(0), __Alloc(alloc)
			{
				//TODO: set the values to default ( 0/nullptr )
			};

			//* The fill constructor.
			explicit vector(size_type n, const value_type& val = value_type()
					, const allocator_type& alloc = allocator_type() ): __Vec(nullptr),
																	__Size(0), __Capacity(n), __Alloc(alloc)
			{
				__Vec = __Alloc.allocate(n);
				for (int i = 0; i < n; i++)
					__Alloc.construct(__Vec + i, val);
				LOG(__Vec[3]);
			};

			//* The range constructor.
			//TODO: implement the range constructor.
			// template <class InputIterator>
        	// vector (InputIterator first, InputIterator last,
            //     	const allocator_type& alloc = allocator_type());

			//* The copy constructor.
			// vector(const vector& x)
			// {
			// 	//TODO: implement the assignement operator.
			// 	*this = x;
			// }

			// vector(const vector& src);
			// vector& operator=(const vector& rhs);
			~vector( void )
			{
				//TODO: implement the fucking destructor.

			};
		//!=========================================

		//! Iterator member functions.
		public:
			//TODO
		//!=========================================

		//! Capacity member functions.
		public:
			size_type	size() const //* Returns __Size. (How many elements currently in the vector)
			{
				return	this->__Size;
			};
			size_type	max_size() const //* Returns the maximum allocation possible. (same value as allocate.max_size())
			{
				return __Alloc.max_size();
			};
			// void		resize(size_type n, value_type val = value_type());
			// void		reserve(size_type n);
			bool		empty() const
			{
				return __Size ? false : true; //! Still not tested.
			};
			// size_type	capacity() const;
		//!=========================================

		//! Element access member functions.
		// public:
		// 	reference			back();
		// 	const_reference		back() const; //TODO: Search what's the difference between this notation and the one above it.
		// 	reference			front();
		// 	const_reference		front() const;
		// 	reference			at(size_type n);
		// 	const_reference		at(size_type n) const;
		// 	reference			operator[](size_type n);
		// 	const_reference		operator[](size_type n) const;
		//!=========================================

		//! Modifiers member functions.
		// public:
			void			clear()
			{
				for (int i = 0; i < __Size; i++)
				{
					__Alloc.destroy(__Vec[i]);
				}
				__Size = 0;
				//TODO: Decide whether I reallocate memory for the container or not. (IMO it's better to reallocate to not waste space)
				//TODO: https://www.cplusplus.com/reference/vector/vector/assign/ "This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity."
			};
		// 	void			swap(Vector& x);
		// 	iterator		erase(iterator position);
		// 	iterator		erase(iterator first, iterator last);
		// 	iterator		insert(iterator position, const value_type& val);
		// 	void			insert(iterator position, size_type n, const value_type& val);
		// 	template<class InputIterator>
		// 	void			insert(iterator position, InputIterator first, InputIterator last);
		// 	void			pop_back();
		// 	void			push_back(const value_type& val);
		// 	template<class InputIterator>
		// 	void			assign(InputIterator first, InputIterator last);
			void			assign(size_type n, const value_type &val)
			{
				this->clear();
				//TODO: check if there's enough storage space, otherwise allocate new memory.
				if (n >= __Capacity)
				{
					//TODO:
				}

				//
				for (int i = 0; i < n; i++)
				{
					__Alloc.construct(__Vec[i], val);
				}
			};
		//!=========================================

		//! Allocator member function
		// public:
		// 	allocator_type get_allocator() const;


		private:
			pointer			__Vec;				//* The array of elements.
			size_t			__Size;				//* The current size of the vector, meaning how many elements currently holding.
			size_t			__Capacity;			//* The maximum size allocated for the vector.
			allocator_type	__Alloc;				//* The allocator to be used
	};
}
