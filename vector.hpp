#pragma once

#include <iostream>
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"


namespace ft{

	template<bool Cond, typename T = void>
	struct	enable_if{};
	
	template<typename T>
	struct	enable_if<true, T>
	{
		typedef T type;
	};
	template < class T, class Alloc = std::allocator<T> > class vector
	{
		//! Member types.
		// Public--<begin>
		public:
			//! Typedefs only create a new alias for an existing type, you need to create a variable to hold that type before using it

			typedef T												value_type; 		//* First parametre of the templated class. (T)
			typedef const T											const_value_type; 		//* First parametre of the templated class. (T)

			typedef Alloc											allocator_type; 	//* Second parametre of the templated class. (Alloc used to allocate memory)
			typedef	typename allocator_type::reference				reference; 			//* Reference to the allocator_type. (Equal to T&)
			typedef	typename allocator_type::const_reference		const_reference;	//* Const reference to the allocator_type. (Equal to const T&)
			typedef	typename allocator_type::pointer				pointer;			//* Pointer to the allocated object. (Equal to T*)
			typedef	typename allocator_type::const_pointer			const_pointer;		//* Const pointer to the allocated object. (Equal to const T*)
			// //TODO: implement the iterators to be used.
			typedef	random_access_iterator<value_type>									iterator;
			typedef random_access_iterator<const_value_type>							const_iterator;
			typedef random_reverse_iterator<iterator>									reverse_iterator;
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
																	__Size(0), __Capacity(0), __Alloc(alloc) { };

			//* The fill constructor.
			explicit vector(size_type n, const value_type& val = value_type()
					, const allocator_type& alloc = allocator_type() ): __Vec(nullptr),
																	__Size(n), __Capacity(n), __Alloc(alloc)
			{
				// this->assign(n, val);
				__Vec = __Alloc.allocate(n);
				for(int i = 0; i < n; i++)
					__Alloc.construct(__Vec + i, val);
			};

			//* The range constructor.
			//TODO: implement the range constructor.
			template <class InputIterator>
        	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
							typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
							: __Vec(nullptr), __Size(0), __Alloc(alloc)
			{
				__Capacity = std::distance(first, last);
				this->assign(first, last);
			};

			//* The copy constructor.
			vector(const vector& x): __Vec(nullptr), __Size(0), __Capacity(0), __Alloc(allocator_type())
			{
				//TODO: implement the assignement operator.
				*this = x;
			}

			// vector(const vector& src);
			vector& operator=(const vector& rhs)
			{
				if (__Size > 0)
				{
					for (int i = 0; i < __Size; i++)
						__Alloc.destroy(__Vec + i);
					__Alloc.deallocate(__Vec, __Capacity);
				}
				__Vec = __Alloc.allocate(rhs.__Capacity);
				for(int i = 0; i < rhs.__Size; i++)
					__Alloc.construct(__Vec + i, rhs.__Vec[i]);
				__Size = rhs.__Size;
				__Capacity = rhs.__Capacity;
				return *this;
			};
			~vector( void )
			{
				//TODO: implement the fucking destructor.
				for (int i = 0; i < __Size; i++)
					__Alloc.destroy(__Vec + i);
				__Alloc.deallocate(__Vec, __Capacity);
			};
		//!=========================================

		//! Iterator member functions.
		public:
			//TODO
			iterator	begin()
			{
				return iterator(__Vec);
			}
			const_iterator begin() const { return const_iterator(__Vec); }
			reverse_iterator	rbegin()
			{
				return reverse_iterator(end());
			}

			iterator	end()
			{
				return iterator(__Vec + __Size);
			}
			const_iterator end() const { return const_iterator(__Vec + __Size); }
			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			}
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
			void		resize(size_type n, value_type val = value_type())
			{
				if (n < __Size)
				{
					for (int i = n; i < __Size; i++)
						__Alloc.destroy(__Vec + i);
					return ;
				}
				else if (n > __Size)
				{
					this->reserve(n);
					for (int i = __Size; i < n; i++)
						__Alloc.construct(__Vec + i, val);
				}
			};

			void		reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("ft::vector");
				if (n > __Capacity)
				{
					pointer newVec;
					__Capacity = n; //? Reserve takes directly the n size. (doesn't multiply the old capacity by 2)
					newVec = __Alloc.allocate(__Capacity);
					for(int i = 0; i < __Size; i++)
					{
						__Alloc.construct(newVec + i, *(__Vec + i));
						__Alloc.destroy(__Vec + i);
					}
					if (__Capacity) //? Is it needed to be checked?
						__Vec = newVec;
				}
			};
			bool		empty() const
			{
				return __Size ? false : true; //! Still not tested.
			};
			size_type	capacity() const
			{
				return __Capacity;
			};
		//!=========================================

		//! Element access member functions.
		// public:
			reference			back()
			{
				return __Vec[__Size - 1];
			};
			const_reference		back() const
			{
				return __Vec[__Size - 1];
			};
			reference			front()
			{
				return __Vec[0];
			};
			const_reference		front() const
			{
				return __Vec[0];
			};
			reference			at(size_type n)
			{
				if (n < 0 || n >= __Size)
					throw std::out_of_range("ft::vector");
				return __Vec[n];
			};
			const_reference		at(size_type n) const
			{
				if (n < 0 || n >= __Size)
					throw std::out_of_range("ft::vector");
				return __Vec[n];
			};
			reference			operator[](size_type n)
			{
				return __Vec[n];
			};
			const_reference		operator[](size_type n) const
			{
				return __Vec[n];
			};
		//!=========================================

		//! Modifiers member functions.
		// public:
		void			clear()
		{
			for (int i = 0; i < __Size; i++)
			{
				__Alloc.destroy(__Vec + i);
			}
			__Size = 0;
			//TODO: Decide whether I reallocate memory for the container or not. (IMO it's better to reallocate to not waste space)
			//TODO: https://www.cplusplus.com/reference/vector/vector/assign/ "This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity."
		};
			void			swap(vector& x)
			{
				vector tmp = *this;

				*this = x;
				x = tmp;
			};
		// 	iterator		erase(iterator position);
			// iterator		erase(iterator first, iterator last)
			// {
			// 	ptrdiff_t distance;

			// 	distance = last - first;
			// 	if (__Size + distance > __Capacity)
			// 		this->reserve(__Size + distance);
			// 	for (int i )
			// };
			iterator		insert(iterator position, const value_type& val)
			{
				ptrdiff_t	distance;

				distance = std::distance(this->begin(), position);
				if (__Size + 1 > __Capacity)
					this->reserve(__Capacity * 2);
				for (int i = distance; i <= __Size; i++)
					__Vec[i + 1] = __Vec[i];
				//? Should I construct the inserted element or just copy it?
				// __Vec[distance] = val;
				__Alloc.construct(__Vec + distance, val);
				__Size++;
				return (this->begin());
			};
			void			insert(iterator position, size_type n, const value_type& val)
			{
				std::ptrdiff_t	distance;
				
				distance = std::distance(this->begin(), position);
				if (__Size + n > __Capacity)
				{
					if (__Size + n > __Capacity * 2)
						this->reserve(__Size + n);
					else
						this->reserve(__Capacity * 2);
				}
				for (int i = distance + n; i < __Size + n; i++)
					__Vec[i + 1] = __Vec[i];
				for(int i = distance; i < distance + n; i++)
				{
					__Alloc.construct(__Vec + i, val);
				}
				__Size += n;
			};
			template<class InputIterator>
			void			insert(iterator position, InputIterator first, InputIterator last,
									typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				std::ptrdiff_t distance, n;
				distance = std::distance(first, last);		// correct
				n = std::distance(this->begin(), position); // correct
				if (__Size + distance > __Capacity)
				{
					if (__Size + distance > __Capacity * 2)
						this->reserve(__Size + distance);
					else
						this->reserve(__Capacity * 2);
				}
				//* Moving the old element by <distance> to the right.
				for (int i = __Size + distance - 1; i > n + distance; i--)
				{
					int	j = 1;
					__Vec[i] = __Vec[__Size - j];
					j++;
					// LOG("Moving: " << __Vec[i] << "To: " << __Vec[i + distance]);
				}
				// //* Inserting the element from n to n+distance
				for(int i = n; i - n !=  distance; i++)
				{
					__Alloc.construct(__Vec + i, *(first + i - n));
				}
				// 	// __Alloc.construct(__Vec + i, first + i);
				__Size += distance;
			};
			void			pop_back()
			{
				__Alloc.destroy(__Vec + __Size);
				if (__Size > 0)
					__Size--;
			};
			void			push_back(const value_type& val)
			{
				if (__Size + 1 > __Capacity)
				{
					if (!__Capacity)
						this->reserve(__Size + 1);
					else
					{
						__Capacity *= 2;
						this->reserve(__Capacity);
					}
				}
				__Alloc.construct(__Vec + __Size, val);
				__Size++;
			};

			template<class InputIterator>
			void			assign(InputIterator first, InputIterator last,
							typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				std::ptrdiff_t distance = last - first;

				// this->clear();
				LOG("==================>" << distance);
				if (distance > __Capacity)
				{
					__Capacity *= 2;
					if (!__Capacity)
						__Capacity = distance;
					__Alloc.deallocate(__Vec, __Capacity);
					__Vec = __Alloc.allocate(__Capacity);
				}

				for (int i = 0; i < distance; i++)
				{
					if (i < __Size)
						__Alloc.destroy(__Vec + i);
					__Alloc.construct(__Vec + i, first[i]);
				}
				__Size = distance;
			};
			
			//* Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			void			assign(size_type n, const value_type &val)
			{
				// this->clear();
				//* If there isn't enough storage allocated, reallocating enough space.
				//? Is multiplying the already existing capacity by two a good idea?
				if (n > __Capacity)
				{
					__Capacity *= 2;
					if (!__Capacity)
						__Capacity = n;
					__Alloc.deallocate(__Vec, __Capacity);
					__Vec = __Alloc.allocate(__Capacity);
				}

				//* Filling the vector with the new values.
				for (int i = 0; i < n; i++)
				{
					if (i < __Size)
						__Alloc.destroy(__Vec + i);
					__Alloc.construct(__Vec + i, val);
				}
				__Size = n;
			};
		//!=========================================

		//! Allocator member function
		public:
			//? Not sure if this is correct or not, to be checked later :D
			allocator_type get_allocator() const
			{
				return allocator_type(__Alloc);
			};


		private:
			pointer			__Vec;				//* The array of elements.
			size_t			__Size;				//* The current size of the vector, meaning how many elements currently holding.
			size_t			__Capacity;			//* The maximum size allocated for the vector.
			allocator_type	__Alloc;			//* The allocator to be used
	};
}
