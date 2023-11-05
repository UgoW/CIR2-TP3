#include "header.h"

using namespace std;

A::A() {
/*
     * Name : A()
     * Description : Default constructor of A class
*/
    x = 0;
    cout << "1";
}

A::A(int px) {
/*
     * Name : A(int px)
     * Description : Constructor of A class
     * Parameters : px - value of x
*/
    x = px;
    cout << "2";
}

A::A(const A &pa) {
/*
     * Name : A(const A &pa)
     * Description : Copy constructor of A class
     * Parameters : pa - reference to an object of A class
*/
    x = pa.x;
    cout << "3";
}

// Implementation of B class
B::B(const A &pa) : a(pa) {
/*
     * Name : B(const A &pa)
     * Description : Constructor of B class
     * Parameters : pa - reference to an object of A class
*/
    cout << "4";
}

B::B(const A &pa, int py) {
/*
     * Name : B(const A &pa, int py)
     * Description : Constructor of B class
     * Parameters : pa - reference to an object of A class
     *              py - value of y
*/
    a = pa;
    y = py;
    cout << "5";
}

C::C(int pz) {
/*
     * Name : C(int pz)
     * Description : Constructor of C class
     * Parameters : pz - value of z
*/
    z = pz;
    cout << "6";
}

C::C(A pa) : B(pa) {
/*
     * Name : C(A pa)
     * Description : Constructor of C class
     * Parameters : pa - object of A class
*/
    z = 0;
    cout << "7";
}

C::C(const B &pb) : B(pb), a(1) {
/*
     * Name : C(const B &pb)
     * Description : Constructor of C class
     * Parameters : pb - reference to an object of B class
*/
    z = 0;
    cout << "8";
}

Circle::Circle(float r) : radius(r) {}

float Circle::get_area() const {
/*
    * Name : get_area()
    * Description : get aréa of circle
*/
    return M_PI * radius * radius;
}

float Circle::get_perimeter() const {
/*
    * Name : get_perimeter()
    * Description : get perimeter of circle
 */
    return 2 * M_PI * radius;
}

float Circle::estimate_pi(int num_points) {
    srand(static_cast<unsigned>(time(0)));
    int inside_circle = 0;
    for (int i = 0; i < num_points; i++) {
        float x = static_cast<float>(rand()) / RAND_MAX;
        float y = static_cast<float>(rand()) / RAND_MAX;
        if (x * x + y * y <= 1) {
            inside_circle++;
        }
    }
    return 4.0 * inside_circle / num_points;
}


Point2D::Point2D(float x, float y) : x(x), y(y) {}

Vecteur::Vecteur(float x, float y) : x(x), y(y) {}

Vecteur::Vecteur(Point2D p1, Point2D p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
}

Vecteur Vecteur::operator+(const Vecteur &other) {
    return Vecteur(x + other.x, y + other.y);
}

// Operator *
Vecteur Vecteur::operator*(float scalar) {
    return Vecteur(x * scalar, y * scalar);
}

// Opérator de verif ==
bool Vecteur::operator==(const Vecteur &other) {
    return x == other.x && y == other.y;
}

Point::Point(double x, double y) : x(x), y(y) {}

Polygon::Polygon(const vector<Point> &vertices) : vertices(vertices) {}

double Polygon::get_area() {
    double area = 0.0;
    int n = vertices.size();
    for (int i = 0; i < n; i++) {
        const Point &current = vertices[i];
        const Point &next = vertices[(i + 1) % n];
        area += (current.x * next.y - current.y * next.x);
    }
    return 0.5 * abs(area);
}

int main() {
    // Exercice 1
    C c1; // This will call C(int pz = 1)
    cout << endl;
    C c2(A(5)); // This will call C(A pa)
    cout << endl;
    B b1;
    cout << endl;
    B b2(A(10), 20);
    cout << endl;

    // Exercice 2
    Circle c(5);
    cout << "Air cercle: " << c.get_area() << endl;
    cout << "permimetre du cercle: " << c.get_perimeter() << endl;

    int num_points = 10000000;
    float estimated_pi = Circle::estimate_pi(num_points);
    cout << "Estimation Monte carlos " << estimated_pi << endl;

    // Exercice 3
    Point2D p1(1, 2);
    Point2D p2(3, 4);

    Vecteur v1(p1, p2);
    Vecteur v2(5, 6);

    Vecteur v3 = v1 + v2;
    Vecteur v4 = v1 * 2;

    if (v1 == v2) {
        cout << "v1 = v2." << endl;
    } else {
        cout << "v1 =! v2." << endl;
    }

    // Exercice 4
    vector<Point> triangle = {Point(0, 0), Point(4, 0), Point(2, 3)};
    vector<Point> square = {Point(0, 0), Point(4, 0), Point(4, 4), Point(0, 4)};
    vector<Point> rectangle = {Point(0, 0), Point(6, 0), Point(6, 3), Point(0, 3)};

    Polygon poly1(triangle);
    Polygon poly2(square);
    Polygon poly3(rectangle);

    cout << "Air triangle: " << poly1.get_area() << endl;
    cout << "Air carré: " << poly2.get_area() << endl;
    cout << "Air polignone: " << poly3.get_area() << endl;

    return 0;
}
