/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdusunen <mdusunen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:03:33 by mdusunen          #+#    #+#             */
/*   Updated: 2025/09/23 19:04:25 by mdusunen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::cout << "=========PHONEBOOK==========" << std::endl;
    std::string command;
    while (true)
    {
        std::cout << "Enter command (add, search, exit): ";
        if (!std::getline(std::cin, command))
        {
            break;
        }
        if (command == "exit")
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else if (command == "add")
        {
            phoneBook.addContact();
        }
        else if (command == "search")
        {
            phoneBook.searchContact();
        }
        else
        {
            std::cout << "Unknown command. Please use add, search, or exit." << std::endl;
        }
    }
    return 0;
}