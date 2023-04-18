/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** main
*/

#include "main.hpp"

int main(int ac, char **av)
{
    std::string name_file;
    std::size_t extension = 0;

    if (ac != 2) {
        std::cout << ERROR_NB_ARG;
        return 84;
    }
    name_file = av[1];
    extension = name_file.find(".nts");
    if (extension == std::string::npos || extension + 4 != name_file.length()) {
        std::cout << ERROR_FILE_EXETENSION;
        return 84;
    }
    return parserFile(av[1]);
}
