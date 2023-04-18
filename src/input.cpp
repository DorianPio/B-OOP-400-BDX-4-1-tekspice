/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** input
*/

#include "input.hpp"

nts::Input::Input(std::string name) : IComponent()
{
    this->pins[0] = 42;
    this->name = name;
    this->type = "input";
    this->states_save[0] = 42;
}

void nts::Input::simulate(std::size_t pin)
{
    nts::Tristate save =  this->compute(pin);

    if (save == nts::Tristate::UNDEFINED)
        this->pins[0] = 42;
    else if (save == nts::Tristate::TRUE)
        this->pins[0] = 1;
    else
        this->pins[0] = 0;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    if (this->states_save[0] == 0) {
        return (nts::Tristate::FALSE);
    } else if (this->states_save[0] == 1) {
        return (nts::Tristate::TRUE);
    } else {
        return (nts::Tristate::UNDEFINED);
    }
}

void nts::Input::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin == 1) {
        this->linked_component = other;
        this->linked_pins[0] = otherPin;
    } else {
        std::cerr << "You can't link this pin" << std::endl;
    }
}

void nts::Input::dump() const
{
    std::cout << "  " << this->name << ": " << print_state(this->pins[0]) << std::endl;
}

void nts::Input::set_input(size_t state)
{
    this->pins[0] = set_state(state);
}

void nts::Input::setSaveStates(std::size_t pin)
{
    // std::cout << pin << std::endl;
    this->states_save[0] = set_state(pin);
}

std::string nts::Input::getName() const
{
    return (this->name);
}