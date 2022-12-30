//
// Created by Jack Wang on 12/23/2022.
//

#include "canvas.h"
#include <iostream>

canvas::canvas(int height, int width) {
    for (int i = 0; i < height; i++) {
        vector<color> row;
        for (int j = 0; j < width; j++) {
            row.push_back(color(0,0,0));
        }
        frame.push_back(row);
    }
}

void canvas::writePixel(int row, int column, color color) {
    if ((int)row < frame.size() && (int)column < frame[0].size()) {
        frame[(int)row][(int)column] = color;
    }
}

string canvas::toPPM() {
    string output = "P3\n";
    output.append(to_string(frame[0].size()));
    output.append(" ");
    output.append(to_string(frame.size()));
    output.append("\n255\n");

    for (int i = 0; i < frame.size(); i++) {
        size_t rowLength = 0;
        for (int j = 0; j < frame[0].size(); j++) {
            string redString = to_string((int)(frame[i][j].r * 255));
            if (rowLength + redString.length() + 1 > 70) {
                output.append("\n");
                rowLength = 0;
            } else {
                if (rowLength != 0) {
                    output.append(" ");
                }
                rowLength += 1;
            }
            output.append(redString);
            rowLength += redString.length();

            string greenString = to_string((int)(frame[i][j].g * 255));
            if (rowLength + greenString.length() + 1 > 70) {
                output.append("\n");
                rowLength = 0;
            } else {
                if (rowLength != 0) {
                    output.append(" ");
                }
                rowLength += 1;
            }
            output.append(greenString);
            rowLength += greenString.length();

            string blueString = to_string((int)(frame[i][j].b * 255));
            if (rowLength + blueString.length() + 1 > 70) {
                output.append("\n");
                rowLength = 0;
            } else {
                if (rowLength != 0) {
                    output.append(" ");
                }
                rowLength += 1;
            }
            output.append(blueString);
            rowLength += blueString.length();
        }
        output.append("\n");
    }
    output.append("\n");
    return output;
}

size_t canvas::height() {
    return frame.size();
}

size_t canvas::width() {
    return frame[0].size();
}
