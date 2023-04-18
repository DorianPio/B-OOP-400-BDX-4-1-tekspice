/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** command
*/

#include "main.hpp"
#include <signal.h>

static size_t check_smaller(std::string name, std::string place, size_t i, size_t old_place)
{
    if (place.compare(0, name.length(), name) < 0)
        return old_place;
    return i;
}

static std::vector<std::string> order_print(std::vector<std::shared_ptr<nts::IComponent>> component, std::vector<std::string> order) 
{

    std::vector<std::string> save_component;
    size_t i = 0;
    size_t place = 0;

    for (size_t f = 0; f < component.size(); f++) {
        if (component[f]->getType() != "output") {
            save_component.emplace_back(component[f]->getName());
        }
    }
    if (save_component.size() == 0)
        exit(84);
    for (int j = 0; save_component.size() > 0; j++) {
        for (i = 0; i < save_component.size(); i++) {
            place = check_smaller(save_component[i], save_component[place], i , place);
        }
        order.push_back(save_component[place]);
        save_component.erase(save_component.begin() + place);
        place = 0;
    }
    return order;
}

static std::vector<std::string> dump_order(std::vector<std::shared_ptr<nts::IComponent>> component, std::vector<std::string> order) 
{

    std::vector<std::string> save_component;
    size_t i = 0;
    size_t place = 0;

    for (size_t f = 0; f < component.size(); f++) {
        if (component[f]->getType() != "output") {
            save_component.emplace_back(component[f]->getName());
        }
    }
    if (save_component.size() == 0)
        exit(84);
    for (int j = 0; save_component.size() > 0; j++) {
        for (i = 0; i < save_component.size(); i++) {
            place = check_smaller(save_component[i], save_component[place], i , place);
        }
        order.push_back(save_component[place]);
        save_component.erase(save_component.begin() + place);
        place = 0;
    }
    return order;
}

static size_t check_smaller_output(std::string name, std::string place, size_t i, size_t old_place)
{
    if (place.compare(0, name.length(), name) < 0)
        return old_place;
    return i;
}

static std::vector<std::string> order_print_output(std::vector<std::shared_ptr<nts::IComponent>> component, std::vector<std::string> order) 
{

    std::vector<std::string> save_component;
    size_t i = 0;
    size_t place = 0;

    for (size_t f = 0; f < component.size(); f++) {
        if (component[f]->getType() == "output") {
            save_component.emplace_back(component[f]->getName());
        }
    }
    if (save_component.size() == 0)
        exit(84);
    for (int j = 0; save_component.size() > 0; j++) {
        for (i = 0; i < save_component.size(); i++) {
            place = check_smaller_output(save_component[i], save_component[place], i , place);
        }
        order.push_back(save_component[place]);
        save_component.erase(save_component.begin() + place);
        place = 0;
    }
    return order;
}


static void display(std::vector<std::shared_ptr<nts::IComponent>> component)
{
    std::vector<std::string> order;
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s): " << std::endl;

    order = order_print(component, order);
    for (; order.size() > 0;) {
        for (int i = 0; i < component.size(); i++) {
            if (order[0] == component[i]->getName()) {
                if (component[i]->getType() != "output") {
                    component[i]->dump();
                    order.erase(order.begin());
                }
            }
        }
    }
    order = order_print_output(component, order);
    std::cout << "output(s): " << std::endl;
    for (; order.size() > 0;) {
        for (int i = 0; i < component.size(); i++) {
            if (order[0] == component[i]->getName()) {
                if (component[i]->getType() == "output") {
                    component[i]->dump();
                    order.erase(order.begin());
                }
            }
        }
    }
}

static void simulate(std::vector<std::shared_ptr<nts::IComponent>> component)
{
    tick += 1;
    int save = 0;
    std::vector<std::shared_ptr<nts::IComponent>> out_save;

    for (int i = 0; i < component.size(); i++) {
        save = component[i]->getSaveStates();
        if (component[i]->getType() == "output")
            out_save.push_back(component[i]);
        else
            component[i]->simulate(save);
    }
    for (int i = 0; i < out_save.size(); i++) {
        save = out_save[i]->getSaveStates();
        out_save[i]->simulate(save);
    }
}

static void quitt_loop(int signum)
{
    if (signum == 2)
        loop_active = true;
}

static void loop(std::vector<std::shared_ptr<nts::IComponent>> component)
{
    while (!loop_active) {
        signal(SIGINT, quitt_loop);
        simulate(component);
        display(component);
    }
}

static void dump(std::vector<std::shared_ptr<nts::IComponent>> component)
{
    std::vector<std::string> order;
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s): " << std::endl;

    order = dump_order(component, order);
    for (; order.size() > 0;) {
        for (int i = 0; i < component.size(); i++) {
            if (order[0] == component[i]->getName()) {
                if (component[i]->getType() != "output") {
                    component[i]->dump();
                    order.erase(order.begin());
                }
            }
        }
    }
    order = order_print_output(component, order);
    std::cout << "output(s): " << std::endl;
    for (; order.size() > 0;) {
        for (int i = 0; i < component.size(); i++) {
            if (order[0] == component[i]->getName()) {
                if (component[i]->getType() == "output") {
                    component[i]->dump();
                    order.erase(order.begin());
                }
            }
        }
    }
}

static bool check_component_define(std::vector<std::shared_ptr<nts::IComponent>> component,
std::string command)
{
    int save_egal = command.find("=");
    std::string command_finish = command;
    std::string value = command;
    bool find_component = false;
    int i = 0;
    int test = 0;

    if (save_egal == std::string::npos)
        return false;
    command_finish.erase(save_egal, command_finish.length() - save_egal);
    for (; i < component.size(); i++) {
        if (component[i]->getName() == command_finish) {
            find_component = true;
            break;
        }
    }
    if (!find_component)
        return false;
    value = &value[save_egal + 1];
    if (value == "")
        return false;
    test = atoi(value.c_str());
    component[i]->setSaveStates(test);
    component[i]->getSaveStates();
    return true;
}

bool check_command(std::string command,
std::vector<std::shared_ptr<nts::IComponent>> component)
{
    if (command == "display")
        display(component);
    else if (command == "simulate")
        simulate(component);
    else if (command == "loop") {
        loop_active = false;
        loop(component);
    }
    else if (command == "dump")
        dump(component);
    else if (command == "exit")
        return true;
    else
        if (check_component_define(component, command) == false)
            return false;
    return true;
}