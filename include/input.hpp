/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** input
*/

#include "main.hpp"

#ifndef INPUT_HPP_
#define INPUT_HPP_

namespace nts
{
    class Input : public IComponent {
        public:
            Input(std::string name);
            void simulate(std::size_t pin) override final;
            nts::Tristate compute(std::size_t pin) override final;
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) override final;
            void dump() const override final;
            void set_input(size_t state);
            void setSaveStates(std::size_t pin) override final;
            std::size_t getSaveStates() const override final {return states_save[0];};
            std::string getName() const override final;
            std::string getType() const override final {return this->type;};
        private:
            std::size_t states_save[1];
            std::size_t pins[1];
            std::string name;
            std::string type;
            std::size_t linked_pins[1];
            std::shared_ptr<IComponent> linked_component;
    };
}

#endif /* !INPUT_HPP_ */
