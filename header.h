#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <cmath>

/**
 * Classe de base A.
 */
class A {
public:
    A();           // Constructeur par défaut
    A(int px);     // Constructeur avec paramètre x
    A(const A &pa); // Constructeur de copie

protected:
    int x; // Attribut x
};

/**
 * Classe B dérivée de A.
 */
class B {
protected:
    A a;    // Objet A
    int y;  // Attribut y

public:
    B(const A &pa = A());    // Constructeur avec paramètre A par défaut
    B(const A &pa, int py);  // Constructeur avec paramètres A et y
};

/**
 * Classe C dérivée de B.
 */
class C : public B {
protected:
    A a;    // Redéfinition de l'objet A
    int z;  // Attribut z

public:
    C(int pz = 1);   // Constructeur avec paramètre z par défaut
    C(A pa);         // Constructeur avec paramètre A
    C(const B &pb);  // Constructeur avec paramètre B
};

// Exercice 2

/**
 * Classe de base Shape avec des fonctions virtuelles pures pour l'aire et le périmètre.
 */
class Shape {
public:
    virtual float get_area() const = 0;
    virtual float get_perimeter() const = 0;
};

/**
 * Classe Circle dérivée de Shape pour représenter un cercle.
 */
class Circle : public Shape {
private:
    float radius; // Rayon du cercle

public:
    Circle(float r);          // Constructeur avec paramètre de rayon
    float get_area() const override;       // Implémentation de l'aire
    float get_perimeter() const override;  // Implémentation du périmètre
    static float estimate_pi(int num_points);  // Estimation de π
};

/**
 * Classe Point2D pour représenter un point en 2D avec des coordonnées x et y.
 */
class Point2D {
public:
    float x, y;
    Point2D(float x, float y); // Constructeur avec coordonnées x et y
};

// Exercice 3

/**
 * Classe Vecteur pour représenter un vecteur en 2D avec des composantes x et y.
 */
class Vecteur {
public:
    float x, y;
    Vecteur(float x, float y);           // Constructeur avec composantes x et y
    Vecteur(Point2D p1, Point2D p2);     // Constructeur à partir de deux points
    Vecteur operator+(const Vecteur &other);  // Opérateur d'addition de vecteurs
    Vecteur operator*(float scalar);          // Opérateur de multiplication par un scalaire
    bool operator==(const Vecteur &other);    // Opérateur d'égalité de vecteurs
};

// Exercice 4

/**
 * Classe Point pour représenter un point en 2D avec des coordonnées x et y.
 */
class Point {
public:
    double x, y;
    Point(double x, double y); // Constructeur avec coordonnées x et y
};

/**
 * Classe Polygon pour représenter un polygone avec une liste de sommets.
 */
class Polygon {
public:
    std::vector<Point> vertices; // Liste de sommets
    Polygon(const std::vector<Point> &vertices); // Constructeur avec une liste de sommets
    double get_area(); // Calcul de l'aire du polygone
};

#endif  // HEADER_H
