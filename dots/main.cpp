#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// Basic class "Point"
class Point {
protected:
    double x, y;  // point coordinates
public:
    Point(double x, double y) : x(x), y(y) {}
};

// Bacis class "Sphere"
class Sphere : public Point {
protected:
    double radius;  // radius sphere
public:
    Sphere(double x1, double y1, double x2, double y2) : Point(x1, y1) {
        // calculate the radius using the coordinates of two points
        double dx = x2 - x1;
        double dy = y2 - y1;
        radius = sqrt(dx * dx + dy * dy);
    }
    double getr()
    {
        return radius;
    }
    double area() // is the area of the side surface of the sphere
    {
        return 4 * M_PI * radius * radius;
    }
    double volume() // sphere volume
    {
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }
};

// Derived class "Segment"
class Segment : public Point {
protected:
    double length;  // segment length
public:
    Segment(double x1, double y1, double x2, double y2) : Point(x, y) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        length = sqrt(dx * dx + dy * dy);
    }
    double getl()
    {
        return length;
    }
};

// Derived class "Spherical segment"
class SphericalSegment : public Segment, public Sphere {
public:
    SphericalSegment(double x1, double y1, double x2, double y2, double y3, double y4) : Sphere(x1, y1, x2, y2), Segment(x1, y3, x1, y4) {}
    double area() // area of a spherical segment
    { 
        return 2 * M_PI * radius * length;
    }
    double volume() // volume of the spherical segment
    { 
        return M_PI * length * length * (radius - length / 3);
    }
};

int main() {
    while (true)
    {
        double x1, y1, x2, y2, y3, y4;
        cout << "Enter the coordinates of the center of the sphere (first x, then y): ";
        cin >> x1 >> y1;
        cout << "Enter the coordinate of a point on the sphere (first x, then y): ";
        cin >> x2 >> y2;
        Sphere sphere(x1, y1, x2, y2);
        cout << "Radius of the sphere: " << sphere.getr() << endl;
        cout << "Area of the sphere: " << sphere.area() << endl;
        cout << "Volume of the sphere: " << sphere.volume() << endl;
        cout << "Enter the upper and lower y-coordinates for the segment height: ";
        cin >> y4 >> y3;
        SphericalSegment sphericalSegment(x1, y1, x2, y2, y3, y4);
        cout << "Hight of the spherical segment: " << sphericalSegment.getl() << endl;
        cout << "Area of the spherical segment: " << sphericalSegment.area() << endl;
        cout << "Volume of the spherical segment: " << sphericalSegment.volume() << endl;

        bool a;
        cout << "Would you like to do it again?\n"
            ">>> ";
        cin >> a;
        if (!a) break;
    }
    return 0;
}