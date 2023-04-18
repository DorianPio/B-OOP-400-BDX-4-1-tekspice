/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** C4001_nor
*/

#include "C4514.hpp"

nts::C4514::C4514(std::string name)
{
    for (int i = 0; i < 24; i++) {
        this->pins[i] = 42;
        this->states_save[i] = 42;
        this->linked_component[i] = nullptr;
    }
    this->name = name;
    this->type = "4514";
}

void nts::C4514::simulate(std::size_t tick)
{
    nts::Tristate save = nts::Tristate::UNDEFINED;

    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < 24; i++) {
            save = this->compute(i);
            if (save == nts::Tristate::TRUE)
                this->pins[i] = 1;
            else if (save == nts::Tristate::FALSE)
                this->pins[i] = 0;
            else
                this->pins[i] = 42;
        }
    }
}

nts::Tristate nts::C4514::compute(std::size_t pin)
{
    if (this->pins[0] != 1 && pin != 1 && pin != 2 && pin != 20 && pin != 22 && pin != 0 && pin != 22) {
        return (nts::Tristate::UNDEFINED);
    }
    if (this->linked_component[pin] != nullptr) {
        return (this->linked_component[pin]->compute(this->linked_pins[pin]));
    } else {
        if (this->pins[22] == 1) {
            return (nts::Tristate::FALSE);
        }
    }
    if (this->pins[1] == 0 && this->pins[2] == 0 && this->pins[20] == 0 && this->pins[21] == 0 && pin == 10) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 0 && this->pins[20] == 0 && this->pins[21] == 0 && pin == 8) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 0 && this->pins[2] == 1 && this->pins[20] == 0 && this->pins[21] == 0 && pin == 9) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 0 && this->pins[21] == 0 && pin == 7) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 0 && this->pins[2] == 0 && this->pins[20] == 1 && this->pins[21] == 0 && pin == 6) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 0 && this->pins[20] == 1 && this->pins[21] == 0 && pin == 5) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 0 && this->pins[2] == 1 && this->pins[20] == 1 && this->pins[21] == 0 && pin == 4) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 1 && this->pins[21] == 0 && pin == 3) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 0 && this->pins[2] == 0 && this->pins[20] == 0 && this->pins[21] == 1 && pin == 17) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 0 && this->pins[20] == 0 && this->pins[21] == 1 && pin == 16) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 0 && this->pins[2] == 1 && this->pins[20] == 0 && this->pins[21] == 1 && pin == 19) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 0 && this->pins[20] == 1 && this->pins[21] == 1 && pin == 18) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 0 && this->pins[21] == 0 && pin == 13) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 0 && this->pins[21] == 1 && pin == 12) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 1 && this->pins[21] == 0 && pin == 15) {
        return (nts::Tristate::TRUE);
    } else if (this->pins[1] == 1 && this->pins[2] == 1 && this->pins[20] == 1 && this->pins[21] == 1 && pin == 15) {
        return (nts::Tristate::TRUE);
    } else {
        return (nts::Tristate::UNDEFINED);
    }
}

void nts::C4514::setSaveStates(std::size_t pin)
{
    for (int i = 0; i < 24; i++) {
        this->states_save[i] = set_state(this->pins[i]);
    }
}

void nts::C4514::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    this->linked_component[pin - 1] = other;
    this->linked_pins[pin - 1] = otherPin;
}

void nts::C4514::dump() const
{
    for (int i = 0; i < 24; i++) {
        std::cout << "  " << this->name << ": pin number :  " << i << ":  " << print_state(this->pins[i]) << std::endl;
    }
}

std::string nts::C4514::getName() const
{
    return this->name;
}