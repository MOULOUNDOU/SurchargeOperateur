#include <iostream>
#include "Point.hpp"
using namespace std;

// Définition du constructeur par défaut
Point::Point() : x(0), y(0) {}

// Définition du constructeur avec paramètres
Point::Point(double x, double y) : x(x), y(y) {}

// Définition de l'opérateur <<
ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

// Définition de l'opérateur >>
istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

// Définition de l'opérateur +
Point Point::operator+(const Point& temp) {
    return Point(x + temp.x, y + temp.y);
}

// Définition de l'opérateur -
Point Point::operator-(const Point& temp) {
    return Point(x - temp.x, y - temp.y);
}

// Définition de l'opérateur ==
bool Point::operator==(const Point& temp) {
    return (x == temp.x && y == temp.y);
}

// Définition de l'opérateur != en utilisant ==
bool Point::operator!=(const Point& temp) {
    return !(*this == temp);
}

// Définition de l'opérateur =
Point& Point::operator=(const Point& temp) {
    if (this != &temp) {  // Gestion de l'auto-affectation
        x = temp.x;
        y = temp.y;
    }
    return *this;
}

// Définition de l'opérateur +=
Point& Point::operator+=(const Point& temp) {
    x += temp.x;
    y += temp.y;
    return *this;
}

// Définition de l'opérateur -=
Point& Point::operator-=(const Point& temp) {
    x -= temp.x;
    y -= temp.y;
    return *this;
}

// Comparaison avec tolérance pour les doubles
bool Point::compareWithTolerance(const Point& other, double tolerance) {
    return (abs(x - other.x) < tolerance && abs(y - other.y) < tolerance);
}

int main() {
    // 1. Création de 2 points
    Point A(1, 2); 
    Point B(3, 4);
    Point C; 

    // 2. Lecture d’un point depuis le clavier
    cout << "Entrez un point (x y) : ";
    cin >> C;

    // 3. Affichage des points
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C (point entré) = " << C << endl;

    // 4. Calcul + et -
    Point D = A + B;  
    Point E = A - B;  

    cout << "A + B = " << D << endl;
    cout << "A - B = " << E << endl;

    // 5. Test de l'égalité ==
    if (A == B)
        cout << "A et B sont égaux." << endl;
    else
        cout << "A et B sont différents." << endl;

    // Test de l'opérateur !=
    if (A != B)
        cout << "A et B sont différents (utilisation de !=)." << endl;
    else
        cout << "A et B sont égaux (utilisation de !=)." << endl;

    // 6. Test de l'affectation =
    Point F;
    F = A;  // Affectation de A à F
    cout << "F (après affectation de A) = " << F << endl;

    // 7. Test des opérateurs += et -=
    A += B;  // A = A + B
    B -= A;  // B = B - A
    cout << "A après A += B: " << A << endl;
    cout << "B après B -= A: " << B << endl;

    // 8. Comparaison avec tolérance
    Point G(1.000001, 2.0);
    if (A.compareWithTolerance(G))
        cout << "A et G sont égaux (avec tolérance)." << endl;
    else
        cout << "A et G sont différents (avec tolérance)." << endl;

    return 0;
}
