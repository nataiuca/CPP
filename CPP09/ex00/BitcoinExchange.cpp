/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natferna <natferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:18:37 by natferna          #+#    #+#             */
/*   Updated: 2025/11/16 23:18:37 by natferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

/* ============================================================
   CANONICAL FORM
   ============================================================ */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
: db(other.db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->db = other.db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* ============================================================
   AUXILIAR: VALIDAR NÚMERO POSITIVO
   ============================================================ */

static bool isValidNumber(const std::string &s) {
    if (s.empty())
        return false;

    bool hasDigit = false;
    bool hasDot = false;

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            hasDigit = true;
            continue;
        }

        if (c == '.') {
            if (hasDot)
                return false;
            hasDot = true;
            continue;
        }

        return false;
    }

    return hasDigit;
}

/* ============================================================
   REAL TRIM (elimina espacios, tabs y whitespace real)
   ============================================================ */

static void realTrim(std::string &s) {
    if (s.empty())
        return;

    size_t start = s.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) {
        s.clear();
        return;
    }

    size_t end = s.find_last_not_of(" \t\n\r\f\v");

    s = s.substr(start, end - start + 1);
}

/* ============================================================
   DATABASE LOAD
   ============================================================ */

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(1);
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, priceStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, priceStr))
            continue;

        if (date == "date")
            continue;

        // Convertir coma a punto (necesario según la DB)
        for (size_t i = 0; i < priceStr.size(); ++i) {
            if (priceStr[i] == ',')
                priceStr[i] = '.';
        }

        realTrim(date);
        realTrim(priceStr);

        double price = std::atof(priceStr.c_str());
        db[date] = price;
    }
}

/* ============================================================
   DATE VALIDATION
   ============================================================ */

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (y < 0)
        return false;
    if (m < 1 || m > 12)
        return false;

    int mdays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y))
        mdays[2] = 29;

    if (d < 1 || d > mdays[m])
        return false;

    return true;
}

/* ============================================================
   PARSE INPUT LINE
   ============================================================ */

bool BitcoinExchange::parseLine(const std::string &line, std::string &date,
                                std::string &valueStr) const {
    std::size_t sep = line.find('|');
    if (sep == std::string::npos)
        return false;

    date = line.substr(0, sep);
    valueStr = line.substr(sep + 1);

    realTrim(date);
    realTrim(valueStr);

    return true;
}

/* ============================================================
   GET PRICE FOR GIVEN DATE
   ============================================================ */

double BitcoinExchange::getPriceForDate(const std::string &date) const {
    std::map<std::string,double>::const_iterator it = db.lower_bound(date);

    if (it == db.end())
        return db.rbegin()->second;

    if (it->first == date)
        return it->second;

    if (it == db.begin())
        return it->second;

    --it;
    return it->second;
}

/* ============================================================
   HANDLE LINE
   ============================================================ */

void BitcoinExchange::handleLine(const std::string &line) const {
    std::string date, valueStr;

    if (!parseLine(line, date, valueStr)) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }

    if (!isValidDate(date)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }

    if (!isValidNumber(valueStr)) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }

    double value = std::atof(valueStr.c_str());

    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }

    if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }

    double price = getPriceForDate(date);
    double result = value * price;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    std::cout << date << " => " << valueStr
              << " = " << result << std::endl;
}

/* ============================================================
   PROCESS INPUT FILE
   ============================================================ */

void BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        std::exit(1);
    }

    std::string line;

    if (std::getline(file, line)) {
        if (!(line.find("date") != std::string::npos &&
              line.find("value") != std::string::npos)) {
            handleLine(line);
        }
    }

    while (std::getline(file, line)) {
        if (!line.empty())
            handleLine(line);
    }
}
