/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** C4001_nor
*/

#include "main.hpp"

#ifndef C4008_NOR_HPP_
#define C4008_NOR_HPP_

namespace nts
{
    class C4008 : public IComponent {
        public:
            C4008(std::string name);
            void simulate(std::size_t pin) override final;
            nts::Tristate compute(std::size_t pin) override final;
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) override final;
            void dump() const override final;
            std::string getName() const override final;
            void setSaveStates(std::size_t pin) override final;
            std::size_t getSaveStates() const override final {return states_save[0];};
            std::string getType() const override final {return this->type;};
        private:
            std::size_t states_save[16];
            std::size_t pins[16];
            std::string name;
            std::shared_ptr<nts::IComponent> linked_component[16];
            std::size_t linked_pins[16];
            std::string type;
    };
}

#endif /* !C4008_NOR_HPP_ */
