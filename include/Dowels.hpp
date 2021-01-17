/*
** EPITECH PROJECT, 2020
** 208dowels_2019
** File description:
** Dowels
*/

#ifndef DOWELS_HPP_
#define DOWELS_HPP_

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

class Dowels {
    public:
        Dowels();
        ~Dowels();

        void runDowels(char **av);
        std::vector<std::pair<std::string, int>> mergeSamples(std::vector<std::pair<std::string, int>> untreatedSampels);
        float calculateProbability(std::vector<std::pair<std::string, int>> samples);

        void displayValue(std::vector<std::pair<std::string, int>> tab, float probabilities);
        int isMerged(std::vector<std::pair<std::string, int>> untreatedSampels);

    protected:
    private:
};

#endif /* !DOWELS_HPP_ */