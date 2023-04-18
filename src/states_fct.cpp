/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** states_fct
*/

#include "main.hpp"

size_t set_state(int state)
{
    if (state == 1) {
        return (1);
    } else if (state == 0) {
        return (0);
    } else {
        return (42);
    }
}

std::string print_state(size_t state)
{
   if (state == 1) {
        return ("1");
    } else if (state == 0) {
        return ("0");
    } else {
        return ("U");
    } 
}