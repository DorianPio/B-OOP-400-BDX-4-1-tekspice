/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** false
*/

#include "false.hpp"

nts::False::False(std::string name)
{
    this->pins[0] = nts::Tristate::FALSE;
    this->name = name;
    this->states_save[0] = 42;
    this->type = "false";
}

void nts::False::simulate(std::size_t pin)
{
    return;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    if (set_state(this->pins[0]) == 1)
        return nts::Tristate::TRUE;
    else if (set_state(this->pins[0]) == 0)
        return nts::Tristate::FALSE;
    return (nts::Tristate::UNDEFINED);
}

void nts::False::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    return;
}

void nts::False::setSaveStates(std::size_t pin)
{
    this->states_save[0] = set_state(this->states_save[0]);
}

void nts::False::dump() const
{
    std::cout << "  " << this->name << ": " << print_state(this->pins[0]) << std::endl;
}

std::string nts::False::getName() const
{
    return this->name;
}