#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// Базовий клас "Точка"
class Point {
protected:
    double x, y;  // координати точки
public:
    Point(double x, double y) : x(x), y(y) {}
};

// Похідний клас "Куля"
class Sphere : public Point {
protected:
    double radius;  // радіус кулі
public:
    Sphere(double x, double y, double r) : Point(x, y), radius(r) {}
    double area() {  // площа бічної поверхні кулі
        return 4 * M_PI * radius * radius;
    }
    double volume() {  // об'єм кулі
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }
};

// Похідний клас "Відрізок"
class Segment : public Point {
protected:
    double length;  // довжина відрізка
public:
    Segment(double x, double y, double l) : Point(x, y), length(l) {}
};

// Похідний клас "Кульовий сегмент"
class SphericalSegment : public Segment {
protected:
    double radius;  // радіус кульового сегмента
public:
    SphericalSegment(double x, double y, double l, double r) : Segment(x, y, l), radius(r) {}
    double area() { // площа кульового сегмента
        return 2 * M_PI * radius * length;
    }
    double volume() { // об'єм кульового сегмента
        return M_PI * length * length * (radius - length / 3);
    }
};

int main() {
    double x, y, r, l, seg_r;
    cout << "Enter coordinates and radius for the sphere: ";
    cin >> x >> y >> r;
    Sphere sphere(x, y, r);
    cout << "Area of the sphere: " << sphere.area() << endl;
    cout << "Volume of the sphere: " << sphere.volume() << endl;
    cout << "Enter coordinates and length for the segment: ";
    cin >> x >> y >> l;
    Segment segment(x, y, l);
    cout << "Enter radius for the spherical segment: ";
    cin >> seg_r;
    SphericalSegment sphericalSegment(x, y, l, seg_r);
    cout << "Area of the spherical segment: " << sphericalSegment.area() << endl;
    cout << "Volume of the spherical segment: " << sphericalSegment.volume() << endl;
    return 0;
}