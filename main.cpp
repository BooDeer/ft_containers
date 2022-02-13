/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:54:59 by hboudhir          #+#    #+#             */
/*   Updated: 2022/02/12 19:06:15 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "macro.hpp"
// #include "stack.hpp"
// #include <stack>
#include <vector>
// #include <map>
#include "vector.hpp"

/*
	// template <class iter>
	// size_t do_distance(iter it,iter end, std::random_access_iterator_tag)
	// {
	// 	return end - it;
	// }

	// template <class iter>
	// size_t do_distance(iter it,iter end, std::input_iterator_tag)
	// {
	// 	size_t k = 0;
	// 	while(it != end)
	// 		k++, it++;
	// 	return k;
	// }

	// template <class iter>
	// size_t ft_distance(iter it, iter end)
	// {
	// 	do_distance(it,end, iterator_triats<iter>::iterator_category())
	// }

	// template <class T>
	// void	print(void)
	// {
	// 	T* c;
	// 	std::cout << "test" << std::endl;
	// }

	// template<>
	// void	print<int>( void )
	// {
	// 	std::cout << "test22" << std::endl;
	// }
*/	

int main( void )
{
	
	LOG("\n\n=============================== STD::MAP  ================================\n\n");
	ft::vector<std::string>	test(5, "tet");
	
	LOG(test.max_size());

	
	LOG("============================== STD::VECTOR  ==============================\n\n");
	std::vector<int> testV(3, 5);

	testV.assign(1, 1);
	LOG(!testV.empty());













	return (0);
}