#include "basic.h"

    std::string clear_code;
    void basic::print(std::string message){
        std::cout << message;
    }

    void basic::println(std::string message){
        print(message);
        nwl();
    }

    void basic::print_rich(std::string foreground, std::string background, std::string type, std::string message){
        set_clr(foreground,background,type);
        print(message);
        clrstyl();
    }
    int basic::find_char(std::string in, char target){
        int counter = -99; //not found code
        for(int i =0; i > in.size(); i++){
            if(in[i] == target){
                counter = i;
            }
        }
        return (counter);
    }
    void basic::print_rich(int foreground, int background, std::string type, std::string message){
        set_clr(foreground,background,type);
        print(message);
        clrstyl();
    }
    std::string basic::prompt(std::string message){
        std::string output;
        if (!message.empty())
            print(message + ":");
        std::getline(std::cin, output);
        if (output.empty()) { // handles leftover newlines from previous input
            std::getline(std::cin, output);
        }
        return output;
    }



    void basic::set_clr(std::string foreground, std::string background, std::string type){
        print(ascii_builder(foreground,background,type));
    }
    void basic::set_clr(int foreground, int background, std::string type){
        print(ascii_builder(foreground,background,type));
    }

    void basic::nwl(){
        print("\n");
    }

    void basic::clear(){
        print("\033[H\033[2J");
    }

    void basic::clrstyl(){
        print("\x1b[0m");
    }

    void basic::mvcrs(int x, int y){
        print("\033["+std::to_string(y)+";"+std::to_string(x)+"H");
    }

    void basic::del(){
        print("delete code");
    }

    std::string basic::toStr(int message){
        return std::to_string(message);
    }
    std::string basic::toStr(double message){
        return std::to_string(message);
    }
    std::string basic::toStr(char message){
        std::string output = {message};
        return output;
    }
    


    int basic::toInt(char message){
        return(message - 0);
    }
    int basic::toInt(std::string message){
        return(std::stoi(message));
    }
    std::string basic::identify_type(std::string type){
        if(type == "bold"){return "1";}
        if(type == "faint"){return "2";}
        if(type == "italic"){return "3";}
        if(type == "under"){return "4";}
        if(type == "blinking"){return "5";}
        if(type == "reverse"){return "7";}
        if(type == "hidden"){return "8";}
        if(type == "strike"){return "9";}
        if(type == "doubleUnder"){return "21";}
        if(type == "frame"){return "51";}
        if(type == "encircle"){return "52";}
        if(type == "overline"){return "53";}        
        return "";
    }
    std::string basic::ascii_builder(std::string foreground, std::string background, std::string types) {
        std::string operation;
        std::string base_code = "\x1b["; //code start
        std::string escape_code;
        std::string combined;

        std::string type_code = identify_type(types);
       //"r,g,b"
        if (!foreground.empty()) {
            foreground = replace_char(foreground, ',', ';');
            foreground = "38;2;" + foreground; //38;2;r;g;b for foreground
        }

        if (!background.empty()) {
            background = replace_char(background, ',', ';');
            background = "48;2;" + background; //48;2;r;g;b for background
        }

        //combine
        if (!type_code.empty()) combined += type_code;
        if (!foreground.empty()) {
            if (!combined.empty()) combined += ";";
            combined += foreground;
        }
        if (!background.empty()) {
            if (!combined.empty()) combined += ";";
            combined += background;
        }

        escape_code = base_code + combined + "m";
        return escape_code;
    }
    std::string basic::ascii_builder(int fore, int back, std::string type) {
        std::string base_code = "\x1b[";
        std::string combined;

        std::string type_code = identify_type(type);

        if (!type_code.empty()) combined += type_code;

        // 8-bit foreground color
        if (fore != 999) {
            if (!combined.empty()) combined += ";";
            combined += "38;5;" + toStr(fore);
        }

        // 8-bit background color
        if (back != 999) {
            if (!combined.empty()) combined += ";";
            combined += "48;5;" + toStr(back);
        }

        return base_code + combined + "m";
    }

    std::string basic::replace_char(std::string in, char start_char, char replace_char){
        for(int i = 0; i < in.length(); i++){
            if(in[i] == start_char){
                in[i] = replace_char;
            }
        }
        return(in);
    }
    int basic::count_chars(std::string in, char find){
        int counter = 0;
        for(int i = 0; i < in.length(); i++){
            if(in[i] == find){
                counter++;
            }
        }
        return counter;
    }
    char basic::toChar(std::string message){
        return message[0];
    }
    char basic::toChar(int message){
        std::string temp = toStr(message);
        return(temp[0]);
    }
    std::string basic::format_label(std::string in, int x, int x2){
        if(x2-x < in.size()){
            in.erase(x2-x);
        }
        
        return(in);
    }
    void basic::replace(int x, int y, std::string message){
        mvcrs(x,y);
        //del();
        print(message);
    }
    void clear_fg();
    void clear_bg();
    void clear_type();