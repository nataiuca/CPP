/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:17:22 by natferna          #+#    #+#             */
/*   Updated: 2025/11/16 23:17:22 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
if (argc != 2) {
std::cerr << "Error: could not open file." << std::endl;
return 1;
}
BitcoinExchange btc;
// Asumimos que la DB proporcionada (data.csv) está en el mismo directorio y se llama data.csv
btc.loadDatabase("data.csv");
btc.processInput(argv[1]);
return 0;
}