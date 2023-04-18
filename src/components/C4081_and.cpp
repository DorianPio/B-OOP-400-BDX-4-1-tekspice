/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** 4081_and
*/

#include "C4081_and.hpp"

nts::Tristate and_gate(size_t state1, size_t state2)
{
    if (state1 == 42 || state2 == 42) {
        return (nts::Tristate::UNDEFINED);
    } else if (state1 == 1 && state2 == 1) {
        return (nts::Tristate::TRUE);
    } else {
        return (nts::Tristate::FALSE);
    }
}

nts::C4081::C4081(std::string name)
{
    for (int i = 0; i < 14; i++) {
        this->pins[i] = 42;
        this->states_save[i] = 42;
        this->linked_component[i] = nullptr;
    }
    this->name = name;
    this->type = "C4081";
}

void nts::C4081::simulate(std::size_t tick)
{
    nts::Tristate save = nts::Tristate::UNDEFINED;

    for (int i = 0; i < 14; i++) {
        save = this->compute(i);
        if (save == nts::Tristate::TRUE)
            this->pins[i] = 1;
        else if (save == nts::Tristate::FALSE)
            this->pins[i] = 0;
        else
            this->pins[i] = 42;
    }
}

nts::Tristate nts::C4081::compute(std::size_t pin)
{
    if (pin == 2) {
        return (and_gate(set_state(this->pins[0]), set_state(this->pins[1])));
    } else if (pin == 3) {
        return (and_gate(set_state(this->pins[4]), set_state(this->pins[5])));
    } else if (pin == 9) {
        return (and_gate(set_state(this->pins[8]), set_state(this->pins[7])));
    } else if (pin == 10) {
        return (and_gate(set_state(this->pins[11]), set_state(this->pins[12])));
    }
    if (this->linked_component[pin] != nullptr) {
        return (this->linked_component[pin]->compute(this->linked_pins[pin]));
    } else {
        return (nts::Tristate::UNDEFINED);
    }
}

void nts::C4081::setSaveStates(std::size_t pin)
{
    for (int i = 0; i < 14; i++) {
        this->states_save[i] = set_state(this->pins[i]);
    }
}

void nts::C4081::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{   
    this->linked_component[pin - 1] = other;
    this->linked_pins[pin - 1] = otherPin;
}

void nts::C4081::dump() const
{
    for (int i = 0; i < 14; i++) {
        std::cout << "  " << this->name << ": pin number :  " << i << ":  " << print_state(this->pins[i]) << std::endl;
    }
}

std::string nts::C4081::getName() const
{
    return this->name;
}