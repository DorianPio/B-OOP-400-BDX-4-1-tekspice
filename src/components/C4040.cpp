/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** C4001_nor
*/

#include "C4008.hpp"

nts::C4008::C4008(std::string name)
{
    for (int i = 0; i < 16; i++) {
        this->pins[i] = 42;
        this->states_save[i] = 42;
        this->linked_component[i] = nullptr;
    }
    this->name = name;
    this->type = "4040";
}

void nts::C4008::simulate(std::size_t tick)
{
    nts::Tristate save = nts::Tristate::UNDEFINED;

    for (int f = 0; f < 2; f++) {
        for (int i = 0; i < 16; i++) {
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

static nts::Tristate sum(size_t pinA, size_t pinB, size_t pinC)
{
    int sum = pinA + pinB + pinC;

    if (pinA == 42 || pinB == 42 || pinC == 42)
        return nts::Tristate::UNDEFINED;
    return sum % 2 == 0 ? nts::Tristate::FALSE:nts::Tristate::TRUE;
}

static size_t sum_sizet(size_t pinA, size_t pinB, size_t pinC)
{
    int sum = pinA + pinB + pinC;

    if (pinA == 42 || pinB == 42 || pinC == 42)
        return 42;
    return sum % 2 == 0 ? 0:1;
}

nts::Tristate nts::C4008::compute(std::size_t pin)
{
    size_t sum_result = 0;
    if (pin == 9) {
        return (sum(this->pins[8], this->pins[6], this->pins[5]));
    }
    if (pin == 10) {
        return (sum(this->pins[3], this->pins[4], sum_sizet(this->pins[8], this->pins[6], this->pins[5])));
    }
    if (pin == 11) {
        return (sum(this->pins[3], this->pins[4], sum_sizet(this->pins[3], this->pins[4],
        sum_sizet(this->pins[8], this->pins[6], this->pins[5]))));
    }
    if (pin == 12) {
        return (sum(this->pins[14], this->pins[0], sum_sizet(this->pins[3], this->pins[4],
            sum_sizet(this->pins[3], this->pins[4], sum_sizet(this->pins[8], this->pins[6],
            this->pins[5])))));
    }
    if (pin == 13) {
        for (int i = 0; i < 16; i++) {
            if (i != 7 && i != 9 && i != 10 && i != 11 && i != 12 && i != 13 && i != 15) {
                if (this->pins[i] == 42)
                    return nts::Tristate::UNDEFINED;
                sum_result += this->pins[i]; 
            }
        }
        if (sum_result == 9)
            return nts::Tristate::TRUE;
        if (sum_result % 2 == 0)
            return nts::Tristate::TRUE;
        else
            return nts::Tristate::FALSE;
    }
    if (this->linked_component[pin] != nullptr) {
        return (this->linked_component[pin]->compute(this->linked_pins[pin]));
    } else {
        return (nts::Tristate::UNDEFINED);
    }
}

void nts::C4008::setSaveStates(std::size_t pin)
{
    for (int i = 0; i < 16; i++) {
        this->states_save[i] = set_state(this->pins[i]);
    }
}

void nts::C4008::setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin)
{
    this->linked_component[pin - 1] = other;
    this->linked_pins[pin - 1] = otherPin;
}

void nts::C4008::dump() const
{
    for (int i = 0; i < 16; i++) {
        std::cout << "  " << this->name << ": pin number :  " << i << ":  " << print_state(this->pins[i]) << std::endl;
    }
}

std::string nts::C4008::getName() const
{
    return this->name;
}