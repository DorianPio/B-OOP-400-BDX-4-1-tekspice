/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** input
*/

#include "output.hpp"

nts::Output::Output(std::string name)
{
    this->pins[0] = 42;
    this->states_save[0] = 42;
    this->name = name;
    this->linked_component = nullptr;
    this->type = "output";
}

void nts::Output::simulate(std::size_t pin)
{
    // nts::Tristate save =  this->compute(pin);
    
    // if (save == nts::Tristate::UNDEFINED)
    //     this->pins[0] = 42;
    // else if (save == nts::Tristate::TRUE)
    //     this->pins[0] = 1;
    // else
    //     this->pins[0] = 0;
    if (this->linked_component != nullptr) {
        this->pins[0] = this->linked_component->compute(this->linked_pins[0]);
    }
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
    if (set_state(pin) == 1)
        return nts::Tristate::TRUE;
    else if (set_state(pin) == 0)
        return nts::Tristate::FALSE;
    return (nts::Tristate::UNDEFINED);
}

void nts::Output::setSaveStates(std::size_t pin)
{
    this->states_save[0] = set_state(pin);
}

void nts::Output::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    if (pin == 1) {
        this->linked_component = other;
        this->linked_pins[0] = otherPin - 1;
    } else {
        std::cerr << "You can't link this pin" << std::endl;
    }
}

void nts::Output::dump() const
{
    std::cout << "  " << this->name << ": " << print_state(this->pins[0]) << std::endl;
}

std::string nts::Output::getName() const
{
    return this->name;
}