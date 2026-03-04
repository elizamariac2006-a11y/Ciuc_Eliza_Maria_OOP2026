#pragma once
class CanvasExtra {
private:
    char** canva;
    const int lines, columns;
    bool isInTheCanva(int x, int y);
public:
    // contructor will call the clear method
    CanvasExtra(int lines, int columns);
    ~CanvasExtra();
    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);
    // tuples of x, y, value
    void set_pixels(int count, ...);
    void clear();
    void print() const;
};
