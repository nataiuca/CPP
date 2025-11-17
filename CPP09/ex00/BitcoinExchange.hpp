/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:18:27 by natferna          #+#    #+#             */
/*   Updated: 2025/11/16 23:18:27 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
public:
BitcoinExchange();
BitcoinExchange(const BitcoinExchange &other);
BitcoinExchange &operator=(const BitcoinExchange &other);
~BitcoinExchange();

void loadDatabase(const std::string &filename); // Carga el CSV de la DB
void processInput(const std::string &filename); // Procesa el archivo de entrada

private:
std::map<std::string, double> db; // date -> price

bool isValidDate(const std::string &date) const;
bool isLeapYear(int year) const;
bool parseLine(const std::string &line, std::string &date, std::string &valueStr) const;
double getPriceForDate(const std::string &date) const; // busca value <= date (closest lower)
void handleLine(const std::string &line) const;
};

#endif