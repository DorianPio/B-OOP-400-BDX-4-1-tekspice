/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** true
*/

#include "true.hpp"

nts::True::True(std::string name)
{
    this->pins[0] = nts::Tristate::TRUE;
    this->name = name;
    this->states_save[0] = 42;
    this->type = "true";
}

void nts::True::simulate(std::size_t pin)
{
    return;
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    if (set_state(this->pins[0]) == 1)
        return nts::Tristate::TRUE;
    else if (set_state(this->pins[0]) == 0)
        return nts::Tristate::FALSE;
    return (nts::Tristate::UNDEFINED);
}

void nts::True::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    return;
}

void nts::True::dump() const
{
    std::cout << "  " << this->name << ": " << print_state(this->pins[0]) << std::endl;
}

void nts::True::setSaveStates(std::size_t pin)
{
    this->states_save[0] = set_state(this->states_save[0]);
}

std::string nts::True::getName() const
{
    return (this->name);
}