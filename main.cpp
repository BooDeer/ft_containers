/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboudhir <hboudhir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:54:59 by hboudhir          #+#    #+#             */
/*   Updated: 2022/02/10 11:47:36 by hboudhir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "stack.hpp"
#include "macro.hpp"
#include <stack>
#include <vector>


int main( void )
{
	LOG("============================== STD::VECTOR  ==============================\n\n");
	std::vector<int> testV;
	
	LOG("=============================== FT::STACK  ===============================\n\n");
	std::stack<int> test1;

	LOG("=============================== STD::STACK ===============================\n\n");
	
	ft::stack<int> test2;

	
	return (0);
}