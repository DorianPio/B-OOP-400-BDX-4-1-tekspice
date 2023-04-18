/*
** EPITECH PROJECT, 2021
** B-OOP-400-BDX-4-1-tekspice-dorian.pio
** File description:
** parser
*/

#include "main.hpp"
#include <fstream>
#include <iterator>

std::unordered_map<std::string, std::string> chipsets;
std::unordered_map<std::string, std::string> links;
std::vector<std::string> all_info;
int tick = 0;
bool loop_active = true;

int check_existence(std::string tmp)
{
    std::unordered_map<std::string, std::string>::iterator itr;
 
    for (itr = chipsets.begin(); itr != chipsets.end(); itr++) {
        if (tmp == itr->first) {
            std::cerr << "Chipsets already exist" << std::endl;
            return ERROR_RETURN;
        }
        if (tmp == "") {
            std::cerr << "Chipsets needs a name" << std::endl;
            return ERROR_RETURN;
        }
    }
    return 0;
}

static int check_pres_in_map(std::string assign, std::string value)
{
    std::unordered_map<std::string, std::string>::iterator itr;
    bool find_value = false;
    bool find_link = false;


    for (itr = chipsets.begin(); itr != chipsets.end(); itr++) {
        if (itr->first == assign)
            find_link = true;
        if (itr->first == value)
            find_value = true;
    }
    if (find_link && find_value)
        return 0;
    return ERROR_RETURN;
}

static int check_value()
{
    std::string variable;
    std::string assign;
    std::string tmp;
    int find_v = 0;
    int find_a = 0;
    std::unordered_map<std::string, std::string>::iterator itr;

    for (itr = links.begin(); itr != links.end(); itr++) {
        find_a = itr->first.find(':');
        find_v = itr->second.find(':');
        if (find_a == std::string::npos || find_v == std::string::npos)
            return ERROR_RETURN;
        variable = itr->second;
        variable.erase(find_v, itr->second.length() - find_v);
        assign = itr->first;
        assign.erase(find_a, assign.length() - find_a);
        if (check_pres_in_map(assign, variable) == ERROR_RETURN)
            return ERROR_RETURN;
    }
    return 0;
}

int check_links()
{
    int i = 0;
    int find_spaces = 0;
    std::string key;
    std::string value;

    for (; all_info[i] != ".links:" && i < all_info.size(); i++);
    for (i += 1; i < all_info.size(); i++) {
        find_spaces = all_info[i].find(' ');
        if (find_spaces == std::string::npos)
            return ERROR_RETURN;
        key = all_info[i];
        key.erase(find_spaces, key.length() - find_spaces);
        for (; all_info[i][find_spaces] == ' '; find_spaces++);
        value = &all_info[i][find_spaces];
        links.insert(std::pair<std::string, std::string>
        (value, key));
    }
    if (check_value() == ERROR_RETURN)
        return ERROR_RETURN;
    return 0;
}

int check_parsing()
{
    bool find_chipset = false;
    int find_spaces = 0;
    std::string save;
    std::string tmp;

    if (all_info.size() == 0)
        return ERROR_RETURN;
    for (int i = 0; i < all_info.size(); i++) {
        if (all_info[i].find(".chipsets:") != std::string::npos)
            find_chipset = true;
    }
    if (!find_chipset)
        return ERROR_RETURN;
    for (int i = 0; i < all_info.size(); i++) {
        if (all_info[i] == ".links:")
            break;
        find_spaces = all_info[i].find(' ');
        if (find_spaces == std::string::npos)
            continue;
        save = all_info[i];
        save.erase(find_spaces, save.length() - find_spaces);
        for (; all_info[i][find_spaces] == ' '; find_spaces++);
        tmp = &all_info[i][find_spaces];
        if (check_existence(tmp) == ERROR_RETURN)
            return ERROR_RETURN;
        chipsets.insert(std::pair<std::string, std::string>(tmp, save));
    }
    if (check_links() == ERROR_RETURN)
        return ERROR_RETURN;
    return 0;
}

int parserFile(char *filename)
{
    std::ifstream dataFile;
    std::string save = "";

    dataFile.open(filename);
    for (; std::getline(dataFile, save, '\n');) {
        if (save[0] == '#' || save == "")  {
            continue;   
        }
        if (save.find("#") != std::string::npos) {
            save.erase(save.find("#"), save.length() - save.find('#'));
        }
        all_info.push_back(save);
    }
    if (check_parsing() == ERROR_RETURN)
        return ERROR_RETURN;
    return build_model();
}