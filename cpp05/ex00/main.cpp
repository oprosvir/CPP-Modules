/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:37:09 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/25 16:01:21 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
    Bureaucrat defaultGuy;
    std::cout << "Default: " << defaultGuy << std::endl;

    std::cout << "------------------------" << std::endl;

    Bureaucrat original("Edward", 42);
    Bureaucrat copy(original);
    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy:     " << copy << std::endl;

    std::cout << "------------------------" << std::endl;

    Bureaucrat* heap = new Bureaucrat("Frank", 77);
    std::cout << "Heap object: " << *heap << std::endl;
    delete heap;

    std::cout << "------------------------" << std::endl;

    Bureaucrat first("Garry", 100);
    Bureaucrat second("Henry", 50);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "first:  " << first << std::endl;
    std::cout << "second: " << second << std::endl;

    first = second;

    std::cout << "After assignment:" << std::endl;
    std::cout << "first:  " << first << std::endl;
    std::cout << "second: " << second << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << "Bulk test: valid and invalid grades" << std::endl;

    int testGrades[] = {1, 42, 150, 0, -1, 151, 999};
    for (int i = 0; i < 7; ++i) {
        try {
            std::cout << "Creating Bureaucrat with grade: " << testGrades[i] << std::endl;
            Bureaucrat test("Test", testGrades[i]);
            std::cout << "✓ Success: " << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "✗ Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "------------------------" << std::endl;
    
    try {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;

        std::cout << "Trying to increment Alice..." << std::endl;
        a.incrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;

        std::cout << "Trying to decrement Bob..." << std::endl;
        b.decrementGrade();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }    

    return 0;
}