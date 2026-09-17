#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x, y;

    Point() : x(0), y(0) {}
    Point(long long _x, long long _y) : x(_x), y(_y) {}

    Point operator-(const Point &other) const
    {
        return Point(x - other.x, y - other.y);
    }

    long long operator^(const Point &other) const
    {
        return x * other.y - y * other.x;
    }
};

// Cross product of vectors (p1->p2) and (p1->p3)
// Returns > 0 (LEFT), < 0 (RIGHT), == 0 (COLLINEAR)
long long cross_product(const Point &p1, const Point &p2, const Point &p3)
{
    return (p2 - p1) ^ (p3 - p1);
}

// Given three collinear points p, q, r, checks if point q lies on segment 'pr'
bool on_segment(const Point &p, const Point &q, const Point &r)
{
    return q.x >= min(p.x, r.x) && q.x <= max(p.x, r.x) &&
           q.y >= min(p.y, r.y) && q.y <= max(p.y, r.y);
}

void solve()
{
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    cin >> p3.x >> p3.y >> p4.x >> p4.y;

    long long c1 = cross_product(p1, p2, p3);
    long long c2 = cross_product(p1, p2, p4);
    long long c3 = cross_product(p3, p4, p1);
    long long c4 = cross_product(p3, p4, p2);

    // General case: opposite orientations across both segments
    bool opposite_1 = (c1 > 0 && c2 < 0) || (c1 < 0 && c2 > 0);
    bool opposite_2 = (c3 > 0 && c4 < 0) || (c3 < 0 && c4 > 0);

    if (opposite_1 && opposite_2)
    {
        cout << "YES\n";
        return;
    }

    // Special cases: Collinear points falling inside the bounding box
    if (c1 == 0 && on_segment(p1, p3, p2))
    {
        cout << "YES\n";
        return;
    }
    if (c2 == 0 && on_segment(p1, p4, p2))
    {
        cout << "YES\n";
        return;
    }
    if (c3 == 0 && on_segment(p3, p1, p4))
    {
        cout << "YES\n";
        return;
    }
    if (c4 == 0 && on_segment(p3, p2, p4))
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}