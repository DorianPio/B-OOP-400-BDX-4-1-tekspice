/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** clock
*/

#include "main.hpp"

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

namespace nts
{
    class Clock : public IComponent {
        public:
            Clock(std::string name);
            void simulate(std::size_t pin) override final;
            nts::Tristate compute(std::size_t pin) override final;
            void setLink(std::size_t pin, std::shared_ptr<nts::IComponent> other, std::size_t otherPin) override final;
            void dump() const override final;
            void set_input(size_t state);
            std::string getName() const override final;
            std::string getType() const override final {return this->type;};
            void setSaveStates(std::size_t pin) override final;
            std::size_t getSaveStates() const override final {return states_save[0];};
        private:
            std::size_t states_save[1];
            std::size_t pins[1];
            std::string name;
            std::string type;
            std::shared_ptr<IComponent> link[1];
    };
}

#endif /* !CLOCK_HPP_ */