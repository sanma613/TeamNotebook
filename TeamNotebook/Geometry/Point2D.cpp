#include <iostream>
using namespace std;

struct Point
{
    long long x, y;

    Point() : x(0), y(0) {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    Point operator-(const Point &other) const { return Point(x - other.x, y - other.y); }
    Point operator+(const Point &other) const { return Point(x + other.x, y + other.y); }
    long long operator^(const Point &other) const { return x * other.y - y * other.x; } // Producto Cruz
    long long operator*(const Point &other) const { return x * other.x + y * other.y; } // Producto Punto

    bool operator<(const Point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

// Retorna > 0 (IZQUIERDA), < 0 (DERECHA), == 0 (COLINEAL)
long long cross_product(const Point &p1, const Point &p2, const Point &p3)
{
    return (p2 - p1) ^ (p3 - p1);
}