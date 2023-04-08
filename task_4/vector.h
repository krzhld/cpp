#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    float x;
    float y;
public:
    void init(float x, float y) { this->x = x; this->y = y; }
    float getX(void) { return x; }
    float getY(void) { return y; }
    void add(float add_x, float add_y) { x += add_x; y += add_y; }
    void multiply(float multiply_x, float multiply_y) { x *= multiply_x; y *= multiply_y; }
};

#endif
