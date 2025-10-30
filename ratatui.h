#ifndef RATATUI_H
#define RATATUI_H
#pragma once
#include "basic.h"
class ratatui{
private:
    const char *tl = "┌";
    const char *tr = "┐";
    const char *bl = "└";
    const char *br = "┘";
    const char *h  = "─";
    const char *v  = "│";  
public:
    void box(int x, int y, int x2, int y2);
    void box(int x, int y, int x2, int y2, std::string label, std::string label_pos);
    //circle
    //menu
    //bar
    //bar_vert
    //screen
    void text( int x, int y, std::string text);
    //text_box
    //button
    //checkbox
    //slider
    //spin_box
    //combo_box
    //status_bar
    //Tree view
    //table
    //windows
    //panels
    //grouping
};
#include <string>
#include <vector>
#include <memory>
/*
class Widget {
protected:
    int x, y, width, height;
    std::string foreground, background, style_type;
    bool visible = true;
    basic* renderer; // uses your basic API to draw

public:
    Widget(int x, int y, int w, int h, basic* renderer)
        : x(x), y(y), width(w), height(h), renderer(renderer) {}

    virtual void draw() = 0;  // each widget defines its render logic
    virtual void set_style(std::string fg, std::string bg, std::string type) {
        foreground = fg; background = bg; style_type = type;
    }

    void show() { visible = true; }
    void hide() { visible = false; }

    virtual ~Widget() = default;
};

*/
#endif