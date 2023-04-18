/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** C4069_not
*/

#include "C4069_not.hpp"

nts::Tristate not_gate(size_t state)
{
    if (state == 42) {
        return (nts::Tristate::UNDEFINED);
    } else if (state == 1) {
        return (nts::Tristate::FALSE);
    } else {
        return (nts::Tristate::TRUE);
    }
}

nts::C4069::C4069(std::string name)
{
    for (int i = 0; i < 14; i++) {
        this->pins[i] = 42;
        this->states_save[i] = 42;
        this->linked_component[i] = nullptr;
    }
    this->name = name;
    this->type = "C4081";
}

void nts::C4069::simulate(std::size_t tick)
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

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    if ((pin - 1) % 2 != 0 && pin < 7) {
        return (not_gate(set_state(this->pins[pin - 1])));
    }
    if ((pin - 1) % 2 != 0 && pin >= 7 && pin != 13) {
        return (not_gate(set_state(this->pins[pin + 1])));
    }
    if (this->linked_component[pin] != nullptr) {
        return (this->linked_component[pin]->compute(this->linked_pins[pin]));
    } else {
        return (nts::Tristate::UNDEFINED);
    }
}

void nts::C4069::setSaveStates(std::size_t pin)
{
    for (int i = 0; i < 14; i++) {
        this->states_save[i] = set_state(this->pins[i]);
    }
}

void nts::C4069::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    this->linked_component[pin - 1] = other;
    this->linked_pins[pin - 1] = otherPin;
}

void nts::C4069::dump() const
{
    for (int i = 0; i < 14; i++) {
        std::cout << "  " << this->name << ": pin number :  " << i << ":  " << print_state(this->pins[i]) << std::endl;
    }
}

std::string nts::C4069::getName() const
{
    return this->name;
}