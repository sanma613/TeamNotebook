#include <iostream>
using namespace std;

struct Point
{
    long long x, y;

    // Constructores
    Point() : x(0), y(0) {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    // Resta de puntos: (P2 - P1) genera el Vector de P1 a P2
    Point operator-(const Point &other) const
    {
        return Point(x - other.x, y - other.y);
    }

    // Suma de vectores
    Point operator+(const Point &other) const
    {
        return Point(x + other.x, y + other.y);
    }

    // Operador '^' sobrecargado para el Producto Cruz (V1 ^ V2)
    long long operator^(const Point &other) const
    {
        return x * other.y - y * other.x;
    }

    // Operador '*' sobrecargado para el Producto Punto (V1 * V2)
    long long operator*(const Point &other) const
    {
        return x * other.x + y * other.y;
    }

    // Comparador para poder ordenar puntos (primero por X, luego por Y)
    bool operator<(const Point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

// Función auxiliar: Producto cruz de los vectores (P1->P2) y (P1->P3)
// Retorna > 0 (IZQUIERDA), < 0 (DERECHA), == 0 (COLINEAL)
long long cross_product(const Point &p1, const Point &p2, const Point &p3)
{
    return (p2 - p1) ^ (p3 - p1);
}

void solve()
{
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int px1, py1, px2, py2, px3, py3;
        cin >> px1 >> py1 >> px2 >> py2 >> px3 >> py3;

        Point p1(px1, py1);
        Point p2(px2, py2);
        Point p3(px3, py3);

        long long cp = cross_product(p1, p2, p3);

        if (cp > 0)
        {
            cout << "LEFT\n";
        }
        else if (cp < 0)
        {
            cout << "RIGHT\n";
        }
        else
        {
            cout << "TOUCH\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}