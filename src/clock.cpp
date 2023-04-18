/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** clock
*/

#include "clock.hpp"

nts::Clock::Clock(std::string name)
{
    this->pins[0] = nts::Tristate::UNDEFINED;
    this->name = name;
    this->type = "clock";
    this->states_save[0] = nts::Tristate::UNDEFINED;
}

void nts::Clock::simulate(std::size_t pin)
{
    if (this->states_save[0] == 1) {
        this->states_save[0] = 0;
    } else if (this->states_save[0] == 0) {
        this->states_save[0] = 1;
    }
    this->pins[0] = this->states_save[0];
}

std::string nts::Clock::getName() const
{
    return this->name;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (set_state(this->pins[0]) == 1)
        return nts::Tristate::TRUE;
    else if (set_state(this->pins[0]) == 0)
        return nts::Tristate::FALSE;
    return (nts::Tristate::UNDEFINED);
}

void nts::Clock::setLink(std::size_t pin,std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    return;
}

void nts::Clock::setSaveStates(std::size_t pin)
{
    if (pin == 0)
        this->states_save[0] = set_state(1);
    else if (pin == 1)
        this->states_save[0] = set_state(0);
    else
        this->states_save[0] = set_state(42);
}

void nts::Clock::dump() const
{
    std::cout << "  " << this->name << ": " << print_state(this->pins[0]) << std::endl;
}

void nts::Clock::set_input(size_t state)
{
    this->pins[0] = set_state(state);
}