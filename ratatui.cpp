#include "ratatui.h"
#include "basic.h"

basic bi;

void ratatui::box(int x1, int y1, int x2, int y2) {
    // Normalize coordinates so x1 <= x2 and y1 <= y2
    int left = std::min(x1, x2);
    int right = std::max(x1, x2);
    int top = std::min(y1, y2);
    int bottom = std::max(y1, y2);

    // Top horizontal line
    for (int i = left; i <= right; i++) {
        bi.mvcrs(i, top);
        bi.print(ratatui::h);
    }

    // Bottom horizontal line
    for (int i = left; i <= right; i++) {
        bi.mvcrs(i, bottom);
        bi.print(ratatui::h);
    }

    // Left vertical line
    for (int j = top; j <= bottom; j++) {
        bi.mvcrs(left, j);
        bi.print(ratatui::v);
    }

    // Right vertical line
    for (int j = top; j <= bottom; j++) {
        bi.mvcrs(right, j);
        bi.print(ratatui::v);
    }

    // Replace corners
    bi.replace(left, top, ratatui::tl);
    bi.replace(right, top, ratatui::tr);
    bi.replace(left, bottom, ratatui::bl);
    bi.replace(right, bottom, ratatui::br);
}

void ratatui::box(int x1, int y1, int x2, int y2, std::string label, std::string label_pos) {
    // Draw box first
    ratatui::box(x1, y1, x2, y2);

    // Normalize coordinates
    int left = std::min(x1, x2);
    int right = std::max(x1, x2);
    int top = std::min(y1, y2);
    int bottom = std::max(y1, y2);

    // Format label to fit inside box width
    std::string lbl = bi.format_label(label, left, right);

    // Base vars
    std::string pos = label_pos;
    int offset_x = 0;
    int offset_y = 0;

    // --- Parse syntax: pos[:x_offset][;y_offset] ---
    size_t colon = label_pos.find(':');
    size_t semicolon = label_pos.find(';');

    if (colon != std::string::npos) {
        pos = label_pos.substr(0, colon);
        size_t end = (semicolon != std::string::npos && semicolon > colon) ? semicolon : std::string::npos;
        try {
            offset_x = std::stoi(label_pos.substr(colon + 1, end - (colon + 1)));
        } catch (...) {}
    }

    if (semicolon != std::string::npos) {
        if (pos.empty() || (colon == std::string::npos)) {
            pos = label_pos.substr(0, semicolon);
        }
        try {
            offset_y = std::stoi(label_pos.substr(semicolon + 1));
        } catch (...) {}
    }

    // --- Compute base coordinates for label ---
    int label_x = left;
    int label_y = top;

    if (pos == "top") {
        label_y = top;
        label_x = left + ((right - left) - (int)lbl.size()) / 2;
    }
    else if (pos == "bottom") {
        label_y = bottom;
        label_x = left + ((right - left) - (int)lbl.size()) / 2;
    }
    else if (pos == "center") {
        label_y = top + (bottom - top) / 2;
        label_x = left + ((right - left) - (int)lbl.size()) / 2;
    }
    else if (pos == "left") {
        label_y = top;
        label_x = left + 1;
    }
    else if (pos == "right") {
        label_y = top;
        label_x = right - (int)lbl.size() - 1;
    }
    else {
        // default to top
        label_y = top;
        label_x = left + ((right - left) - (int)lbl.size()) / 2;
    }

    // --- Apply offsets ---
    label_x += offset_x;
    label_y += offset_y;

    // --- Clamp to box area ---
    label_x = std::max(left, std::min(label_x, right - (int)lbl.size()));
    label_y = std::max(top, std::min(label_y, bottom));

    // --- Print label ---
    bi.mvcrs(label_x, label_y);
    bi.print(lbl);
}
void ratatui::text( int x, int y,std::string text){
    bi.mvcrs(x,y);
    bi.print(text);
}