#ifndef COLOR_H
#define COLOR_H

struct Color {

    unsigned char red, green, blue, alpha;

    Color(void){
        this->red = 255; this->green = 255; this->blue = 255, this->alpha = 255;
    }

    Color(unsigned char r, unsigned char g, unsigned char b):Color(){
        this->red = r; this->green = g; this->blue = b;
    }

    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a):Color(r, g, b){
        this->alpha = a;
    }

};

#endif // COLOR_H