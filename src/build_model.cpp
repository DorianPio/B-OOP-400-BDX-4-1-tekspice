/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** build_model
*/

//itr->first == second column
#include "input.hpp"
#include "output.hpp"
#include "false.hpp"
#include "true.hpp"
#include "clock.hpp"
#include "C4081_and.hpp"
#include "C4071_or.hpp"
#include "C4069_not.hpp"
#include "C4030_xor.hpp"
#include "C4011_nand.hpp"
#include "C4001_nor.hpp"
#include "C4514.hpp"
#include "C4008.hpp"

static int display_terminal_prompt(std::vector<std::shared_ptr<nts::IComponent>> component)
{
    std::string command;

    while (command != "exit") {
        std::cin >> command;
        if (!std::cin.good()) {
            std::cout << "> (CTRL+D)";
            break;
        }
        if (!check_command(command, component))
            std::cerr << "Error command " + command + " doesn't exist" << std::endl;
        else
            std::cout << "> " + command << std::endl;
    }
    return 0;
}

size_t get_pin(std::string link)
{
    int i = 0;
    size_t save = 0;

    while (link[i] != ':' && link[i] != '\0') {
        i += 1;
    }
    i += 1;
    while (i < link.length()) {
        save = save * 10 + (link[i] - 48);
        i += 1;
    }
    return (save);
}

int my_find(std::string str, std::string tofind)
{
    int i = 0;
    int nb = 0;

    while (i != str.size()) {
        if (str[i] == tofind[nb])
            nb += 1;
        else {
            nb = 0;
        }
        if (nb == tofind.size())
            return (1);
        i += 1;
    }
    return (0);
}

int get_component(std::unordered_map<std::string, std::string>::iterator itr,
std::vector<std::shared_ptr<nts::IComponent>> component)
{
     for (int i = 0; i < component.size(); i++) {
        if (my_find(itr->second, component[i]->getName()) == 1) {
            return (i);
        }
    }
    return (-1);
}

static std::string get_component_name(std::string name)
{
    int i = 0;

    while(name[i] != ':' && name[i] != '\0') {
        i++;
    } 
    name.erase(i, name.length() - i);
    return name;
}

int build_model()
{
    std::unordered_map<std::string, std::string>::iterator itr;
    std::vector<std::shared_ptr<nts::IComponent>> component;
    std::string value;
    int i = 0;

    for (itr = chipsets.begin(); itr != chipsets.end(); itr++) {
        value = itr->second;
        if (value == "input") {
            component.emplace_back(new nts::Input(itr->first));
        } else if (value == "output") {
            component.emplace_back(new nts::Output(itr->first));
        } else if (value == "true") {
            component.emplace_back(new nts::True(itr->first));
        } else if (value == "false") {
            component.emplace_back(new nts::False(itr->first));
        } else if (value == "clock") {
            component.emplace_back(new nts::Clock(itr->first));
        } else if (value == "4081") {
            component.emplace_back(new nts::C4081(itr->first));
        } else if (value == "4071") {
            component.emplace_back(new nts::C4071(itr->first));
        } else if (value == "4001") {
            component.emplace_back(new nts::C4001(itr->first));
        } else if (value == "4011") {
            component.emplace_back(new nts::C4011(itr->first));
        } else if (value == "4069") {
            component.emplace_back(new nts::C4069(itr->first));
        } else if (value == "4030") {
            component.emplace_back(new nts::C4030(itr->first));
        } else if (value == "4514") {
            component.emplace_back(new nts::C4514(itr->first));
        } else if (value == "4008") {
            component.emplace_back(new nts::C4008(itr->first));
        } else {
            exit(84);
        }
    }
    for (itr = links.begin(); itr != links.end(); itr++) {
        for (i = 0; i < component.size(); i++) {
            if (get_component_name(itr->first) == component[i]->getName()) {
                break;
            }
        }
        int component_place = get_component(itr, component);
        if (component_place < 0) {
            std::cerr << "Component doesn't exist\n";
            return ERROR_RETURN;
        }
        if (component[component_place]->getType() != "output") {
            component[i]->setLink(get_pin(itr->first), component[component_place], get_pin(itr->second));
        } else {
            component[component_place]->setLink(get_pin(itr->second), component[i], get_pin(itr->first));
        }
    }
    return display_terminal_prompt(component);
}