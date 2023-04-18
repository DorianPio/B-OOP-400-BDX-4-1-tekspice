/*
** EPITECH PROJECT, 2021
** src
** File description:
** main
*/

#include "IComponent.hpp"

#ifndef MAIN_HPP_
#define MAIN_HPP_

#define ERROR_NB_ARG "ERROR - Need two arguments - ./nanotekspice file.nts\n"
#define ERROR_FILE_EXETENSION "ERROR - File extension must be .nts\n"
#define ERROR_RETURN 84

int parserFile(char *filename);
bool check_command(std::string command, std::vector<std::shared_ptr<nts::IComponent>> component);
size_t set_state(int state);
std::string print_state(size_t state);

extern std::unordered_map<std::string, std::string> chipsets;
extern std::unordered_map<std::string, std::string> links;
extern std::vector<std::string> all_info;
extern int tick;
extern bool loop_active;

int build_model();

#endif /* !MAIN_HPP_ */
