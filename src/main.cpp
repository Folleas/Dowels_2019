/*
** EPITECH PROJECT, 2020
** 208dowels_2019
** File description:
** main
*/

#include "Math.hpp"
#include "Dowels.hpp"

bool is_number(const std::string &s) {
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

void displayHelp()
{
    std::cout << "USAGE\n\t./208dowels O0 O1 O2 O3 O4 O5 O6 O7 O8\n\nDESCRIPTION\n\tOi\tsize of the observed class" << std::endl;
}

int errorHandling(int ac, char **av)
{
    int total = 0;

    if (ac != 10)
        return (0);
    for (std::size_t i = 1; i != ac; i++) {
        if (!is_number(av[i]))
            return (0);
    }
    for (std::size_t i = 1; i != ac; i++) {
        total += atoi(av[i]);
    }
    if (total != 100)
        return (0);
    return (1);
}

int main(int ac, char **av)
{
    Dowels dowels;

    if (ac == 2 && !strcmp(av[1], "-h")) {
        displayHelp();
        return (0);
    }
    if (!errorHandling(ac, av))
        return (84);
    dowels.runDowels(av);
    return (0);
}