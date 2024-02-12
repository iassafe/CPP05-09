/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 09:50:23 by iassafe           #+#    #+#             */
/*   Updated: 2024/02/10 19:54:01 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Base.hpp"
# include"A.hpp"
# include"B.hpp"
# include"C.hpp"
int main() {
    std::srand(std::time(NULL)); // Seed for random number generation

    // Generate a random instance of A, B, or C
    Base* generatedInstance = generate();

    // Identify and print the type using pointer
    identify(generatedInstance);

    // Identify and print the type using reference (forbidden to use a pointer inside)
    identify(*generatedInstance);

    // Clean up memory
    delete generatedInstance;

    return 0;
}
