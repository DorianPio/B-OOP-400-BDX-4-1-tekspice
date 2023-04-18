/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** IComponent
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <stdexcept>

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent
    {
        public:
            IComponent() = default;
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::string getName() const = 0;
            virtual size_t getSaveStates() const = 0;
            virtual void setSaveStates(std::size_t pin) = 0;
            virtual std::string getType() const = 0;
    };
};


#endif /* !ICOMPONENT_HPP_ */
