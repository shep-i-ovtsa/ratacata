#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>
#include <chrono>
#include <thread>
class basic {
public:
    void init(const std::string& args);
    std::string format_label(std::string in, int x, int x2);
    std::string identify_type(const std::string& type);
    int find_char(std::string in, char target);

    std::string ascii_builder(const std::string& foreground, const std::string& background, const std::string& types);
    std::string ascii_builder(int fore, int back, const std::string& type);
    void print(const std::string& message);
    void sleep(int ms);
    void sleep(double seconds);
    
    void println(const std::string& message);

    
    void print_rich(const std::string& foreground, const std::string& background, const std::string& type, const std::string& message);
    void print_rich(int foreground, int background, const std::string& type, const std::string& message);

    
    std::string prompt(const std::string& message);


    void set_clr(const std::string& foreground, const std::string& background, const std::string& type);
    void set_clr(int foreground, int background, const std::string& type);
    
    void nwl();

    
    void clear();

    
    void clrstyl();

    
    void mvcrs(int x, int y);


    void del();

    std::string toStr(int message);
    
    std::string toStr(double message);

    std::string toStr(char message);
    int toInt(char message);
    int toInt(const std::string& message);

    std::string replace_char(std::string in, char start_char, char replace_char);
    int count_chars(const std::string& in, char fing);

    char toChar(const std::string& message);
    char toChar(int message);
    void replace(int x,int y,const std::string& message);
};

#endif