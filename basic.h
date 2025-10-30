#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

class basic {
public:

    std::string format_label(std::string in, int x, int x2);
    std::string identify_type(std::string type);
    int find_char(std::string in, char target);

    std::string ascii_builder(std::string foreground, std::string background, std::string types);
    std::string ascii_builder(int fore, int back, std::string type);
    void print(std::string message);

    
    void println(std::string message);

    
    void print_rich(std::string foreground, std::string background, std::string type, std::string message);
    void print_rich(int foreground, int background, std::string type, std::string message);

    
    std::string prompt(std::string message);


    void set_clr(std::string foreground, std::string background, std::string type);
    void set_clr(int foreground, int background, std::string type);
    
    void nwl();

    
    void clear();

    
    void clrstyl();

    
    void mvcrs(int x, int y);


    void del();

    std::string toStr(int message);
    
    std::string toStr(double message);

    std::string toStr(char message);
    int toInt(char message);
    int toInt(std::string message);

    std::string replace_char(std::string in, char start_char, char replace_char);
    int count_chars(std::string in, char fing);

    char toChar(std::string message);
    char toChar(int message);
    void replace(int x,int y,std::string message);
};

#endif