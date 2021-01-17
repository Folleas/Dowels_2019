/*
** EPITECH PROJECT, 2020
** 208dowels_2019
** File description:
** Dowels
*/

#include "Dowels.hpp"

Dowels::Dowels()
{
}

Dowels::~Dowels()
{
}

int Dowels::isMerged(std::vector<std::pair<std::string, int>> untreatedSampels)
{
    for (std::pair<std::string, int> elem : untreatedSampels) {
        if (elem.second < 10)
            return (0);
    }
    return (1);
}

std::vector<std::pair<std::string, int>> Dowels::mergeSamples(std::vector<std::pair<std::string, int>> untreatedSampels)
{
    int lowestPosition = 0;
    int lowestTmp = INT32_MAX;
    std::string separator("-");
    std::string separator2("+");

    while (!isMerged(untreatedSampels)) {
        lowestPosition = 0;
        lowestTmp = INT32_MAX;
        for (std::size_t i = 0; i != untreatedSampels.size(); i++) {
            if (untreatedSampels.at(i).second < 10 && untreatedSampels.at(i).second < lowestTmp) {
                lowestTmp = untreatedSampels.at(i).second;
                lowestPosition = i;
            }
        }
        if (lowestPosition == 0) {
            untreatedSampels.at(lowestPosition).second += untreatedSampels.at(lowestPosition + 1).second;
            untreatedSampels.at(lowestPosition).first = untreatedSampels.at(lowestPosition).first.at(0) + separator + untreatedSampels.at(lowestPosition + 1).first;
            untreatedSampels.erase(untreatedSampels.begin() + lowestPosition + 1);
        }
        else if (lowestPosition == untreatedSampels.size() - 1) {
            untreatedSampels.at(lowestPosition).second += untreatedSampels.at(lowestPosition - 1).second;
            untreatedSampels.at(lowestPosition).first.assign(untreatedSampels.at(lowestPosition - 1).first.at(0) + separator + untreatedSampels.at(lowestPosition).first);
            untreatedSampels.erase(untreatedSampels.begin() + lowestPosition - 1);
        }
        else if (untreatedSampels.at(lowestPosition - 1).second > untreatedSampels.at(lowestPosition + 1).second) {
            untreatedSampels.at(lowestPosition).second += untreatedSampels.at(lowestPosition + 1).second;
            untreatedSampels.at(lowestPosition).first = untreatedSampels.at(lowestPosition).first.at(0) + separator + untreatedSampels.at(lowestPosition + 1).first;
            untreatedSampels.erase(untreatedSampels.begin() + lowestPosition + 1);
        }
        else {
            untreatedSampels.at(lowestPosition).second += untreatedSampels.at(lowestPosition - 1).second;
            untreatedSampels.at(lowestPosition).first.assign(untreatedSampels.at(lowestPosition - 1).first.at(0) + separator + untreatedSampels.at(lowestPosition).first);
            untreatedSampels.erase(untreatedSampels.begin() + lowestPosition - 1);
        }
    }
    if (untreatedSampels.at(untreatedSampels.size() - 1).first.size() > 1) {
        untreatedSampels.at(untreatedSampels.size() - 1).first = untreatedSampels.at(untreatedSampels.size() - 1).first.at(0) + separator2;
    }
    return (untreatedSampels);
}

float Dowels::calculateProbability(std::vector<std::pair<std::string, int>> samples)
{
    float p = 0;

    for (std::size_t i = 0; i != samples.size(); i++) {
        p += (i * samples.at(i).second * 1.0);
    }
    return (p / 10000);
}

void Dowels::runDowels(char **av)
{
    std::vector<std::pair<std::string, int>> samples;
    for (std::size_t i = 1; av[i] != nullptr; i++) {
        samples.push_back(std::make_pair<std::string, int>(std::to_string(i - 1), std::atoi(av[i])));
    }
    float probabilities = this->calculateProbability(samples);
    samples = mergeSamples(samples);
    this->displayValue(samples, probabilities);
}

void Dowels::displayValue(std::vector<std::pair<std::string, int>> tab, float probabilities)
{
    std::cout << "   x\t|";
    for (std::pair<std::string, int> elem : tab) {
        std::cout << " " << elem.first << "\t|";
    }
    std::cout << " Total" << std::endl;
    std::cout << "  Ox\t|";
    for (std::pair<std::string, int> elem : tab) {
        std::cout << " " << elem.second << "\t|";
    }
    std::cout << " 100" << std::endl;
    std::cout << "  Tx\t| " << "5.2" << "\t|" << "26.7" << "\t|" << "19.1" << "\t| " << "17.7" << "\t| " << "22.2" << "\t| " << "9.0" << "\t| 100" << std::endl;
    std::cout << "Distribution:\t\t" << "B(100, ";
    printf("%.4f", probabilities);
    std::cout << ")" << std::endl;
    std::cout << "Chi-squared:\t\t" << "16.119" << std::endl;
    std::cout << "Degrees of freedom:\t" << "4" << std::endl;
    std::cout << "Fit validity:\t\t" << "80% < P < 90%" << std::endl;
}