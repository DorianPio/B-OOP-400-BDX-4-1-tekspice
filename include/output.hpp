/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** output
*/

#include "main.hpp"

#include <memory>

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

namespace nts
{
    class Output : public IComponent {
        public:
            Output(std::string name);
            void simulate(std::size_t pin) override final;
            nts::Tristate compute(std::size_t pin) override final;
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) override final;
            void dump() const override final;
            std::string getName() const override final;
            void setSaveStates(std::size_t pin) override final;
            std::size_t getSaveStates() const override final {return states_save[0];};
            std::string getType() const override final {return this->type;};
        private:
            std::size_t states_save[1];
            std::size_t pins[1];
            std::string name;
            std::shared_ptr<nts::IComponent> linked_component;
            std::size_t linked_pins[1];
            std::string type;
    };
}

#endif /* !OUTPUT_HPP_ */