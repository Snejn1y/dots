#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

// ������� ���� "�����"
class Point {
protected:
    double x, y;  // ���������� �����
public:
    Point(double x, double y) : x(x), y(y) {}
};

// �������� ���� "����"
class Sphere : public Point {
protected:
    double radius;  // ����� ���
public:
    Sphere(double x, double y, double r) : Point(x, y), radius(r) {}
    double area() // ����� ���� ������� ���
    {  
        return 4 * M_PI * radius * radius;
    }
    double volume() // ��'�� ���
    {  
        return 4.0 / 3.0 * M_PI * radius * radius * radius;
    }
};

// �������� ���� "³�����"
class Segment : public Point {
protected:
    double length;  // ������� ������
public:
    Segment(double x, double y, double l) : Point(x, y), length(l) {}
};

// �������� ���� "�������� �������"
class SphericalSegment : public Segment {
protected:
    double radius;  // ����� ��������� ��������
public:
    SphericalSegment(double x, double y, double l, double r) : Segment(x, y, l), radius(r) {}
    double area() // ����� ��������� ��������
    { 
        return 2 * M_PI * radius * length;
    }
    double volume() // ��'�� ��������� ��������
    { 
        return M_PI * length * length * (radius - length / 3);
    }
};

int main() {
    while (true)
    {
        double x, y, r, l, seg_r;
        cout << "Enter the coordinates of the sphere, first the x-coordinate and then the y-coordinate: ";
        cin >> x >> y;
        cout << "Enter the radius of the sphere: ";
        cin >> r;
        Sphere sphere(x, y, r);
        cout << "Area of the sphere: " << sphere.area() << endl;
        cout << "Volume of the sphere: " << sphere.volume() << endl;
        cout << "Enter the coordinates for the segment, first the x-coordinate and then the y-coordinate: ";
        cin >> x >> y;
        cout << "Enter the height of the segment: ";
        cin >> l;
        Segment segment(x, y, l);
        cout << "Enter radius for the spherical segment: ";
        cin >> seg_r;
        SphericalSegment sphericalSegment(x, y, l, seg_r);
        cout << "Area of the spherical segment: " << sphericalSegment.area() << endl;
        cout << "Volume of the spherical segment: " << sphericalSegment.volume() << endl;

        bool a;
        cout << "Would you like to do it again?\n"
            ">>>";
        cin >> a;
        if (!a) break;
    }
    return 0;
}