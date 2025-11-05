#include "basic.h"
#include <iostream>

void basic::init(const std::string& args){
    print("chcp 65001");
}
void basic::print(const std::string& message) {
    std::cout << message;
}

void basic::println(const std::string& message) {
    print(message);
    nwl();
}

void basic::print_rich(const std::string& foreground, const std::string& background, const std::string& type, const std::string& message) {
    set_clr(foreground, background, type);
    print(message);
    clrstyl();
}

void basic::print_rich(int foreground, int background, const std::string& type, const std::string& message) {
    set_clr(foreground, background, type);
    print(message);
    clrstyl();
}

int basic::find_char(std::string in, char target) {
    for (int i = 0; i < static_cast<int>(in.size()); ++i) {
        if (in[i] == target)
            return i;
    }
    return -1; 
}

std::string basic::prompt(const std::string& message) {
    std::string output;
    if (!message.empty())
        print(message + ": ");
    std::getline(std::cin, output);
    if (output.empty())
        std::getline(std::cin, output);
    return output;
}

void basic::set_clr(const std::string& foreground, const std::string& background, const std::string& type) {
    print(ascii_builder(foreground, background, type));
}

void basic::set_clr(int foreground, int background, const std::string& type) {
    print(ascii_builder(foreground, background, type));
}

void basic::nwl() {
    print("\n");
}

void basic::clear() {
    print("\033[H\033[2J");
}

void basic::clrstyl() {
    print("\x1b[0m");
}

void basic::mvcrs(int x, int y) {
    print("\033[" + std::to_string(y) + ";" + std::to_string(x) + "H");
}

void basic::del() {
    print("delete code");
}

// ----- Conversions -----
std::string basic::toStr(int message) {
    return std::to_string(message);
}

std::string basic::toStr(double message) {
    return std::to_string(message);
}

std::string basic::toStr(char message) {
    return std::string(1, message);
}

int basic::toInt(char message) {
    return message - '0';
}

int basic::toInt(const std::string& message) {
    return std::stoi(message);
}

// ----- Text styling -----
std::string basic::identify_type(const std::string& type) {
    if (type == "bold") return "1";
    if (type == "faint") return "2";
    if (type == "italic") return "3";
    if (type == "under") return "4";
    if (type == "blinking") return "5";
    if (type == "reverse") return "7";
    if (type == "hidden") return "8";
    if (type == "strike") return "9";
    if (type == "doubleUnder") return "21";
    if (type == "frame") return "51";
    if (type == "encircle") return "52";
    if (type == "overline") return "53";
    return "";
}

std::string basic::ascii_builder(const std::string& foreground, const std::string& background, const std::string& types) {
    std::string combined;
    std::string type_code = identify_type(types);
    std::string fore = foreground;
    std::string back = background;

    if (!fore.empty()) {
        fore = replace_char(fore, ',', ';');
        fore = "38;2;" + fore;
    }
    if (!back.empty()) {
        back = replace_char(back, ',', ';');
        back = "48;2;" + back;
    }

    if (!type_code.empty()) combined += type_code;
    if (!fore.empty()) {
        if (!combined.empty()) combined += ";";
        combined += fore;
    }
    if (!back.empty()) {
        if (!combined.empty()) combined += ";";
        combined += back;
    }

    return "\x1b[" + combined + "m";
}

std::string basic::ascii_builder(int fore, int back, const std::string& type) {
    std::string combined;
    std::string type_code = identify_type(type);

    if (!type_code.empty()) combined += type_code;

    if (fore != 999) {
        if (!combined.empty()) combined += ";";
        combined += "38;5;" + toStr(fore);
    }
    if (back != 999) {
        if (!combined.empty()) combined += ";";
        combined += "48;5;" + toStr(back);
    }

    return "\x1b[" + combined + "m";
}

std::string basic::replace_char(std::string in, char start_char, char replace_char) {
    for (char& c : in)
        if (c == start_char) c = replace_char;
    return in;
}

int basic::count_chars(const std::string& in, char find) {
    int counter = 0;
    for (char c : in)
        if (c == find) ++counter;
    return counter;
}

char basic::toChar(const std::string& message) {
    return message.empty() ? '\0' : message[0];
}

char basic::toChar(int message) {
    std::string temp = toStr(message);
    return temp.empty() ? '\0' : temp[0];
}

std::string basic::format_label(std::string in, int x, int x2) {
    if (x2 - x < static_cast<int>(in.size()))
        in.erase(x2 - x);
    return in;
}

void basic::replace(int x, int y, const std::string& message) {
    mvcrs(x, y);
    print(message);
}

// ----- Sleep -----
void basic::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void basic::sleep(double seconds) {
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}
