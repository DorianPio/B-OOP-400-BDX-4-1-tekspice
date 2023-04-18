/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** C4071_or
*/

#include "main.hpp"

#ifndef C4071_OR_HPP_
#define C4071_OR_HPP_

namespace nts
{
    class C4071 : public IComponent {
        public:
            C4071(std::string name);
            void simulate(std::size_t pin) override final;
            nts::Tristate compute(std::size_t pin) override final;
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) override final;
            void dump() const override final;
            std::string getName() const override final;
            void setSaveStates(std::size_t pin) override final;
            std::size_t getSaveStates() const override final {return states_save[0];};
            std::string getType() const override final {return this->type;};
        private:
            std::size_t states_save[13];
            std::size_t pins[13];
            std::string name;
            std::shared_ptr<nts::IComponent> linked_component[13];
            std::size_t linked_pins[13];
            std::string type;
    };
}

#endif /* !C4071_OR_HPP_ */
