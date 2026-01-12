#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>  // Pour utiliser std::abs (pour la tolérance)
using namespace std;

class Point {
private:
    double x, y;  // Coordonnées privées

public:
    // Constructeur par défaut
    Point();
    // Constructeur avec paramètres
    Point(double x, double y);

    // Surcharge de l'opérateur << pour l'affichage
    friend ostream& operator<<(ostream& os, const Point& p);

    // Surcharge de l'opérateur >> pour la lecture depuis le clavier
    friend istream& operator>>(istream& is, Point& p);

    // Surcharge de l'opérateur + pour l'addition
    Point operator+(const Point& temp);

    // Surcharge de l'opérateur - pour la soustraction
    Point operator-(const Point& temp);

    // Surcharge de l'opérateur == pour comparer deux points
    bool operator==(const Point& temp);

    // Surcharge de l'opérateur != pour comparer deux points
    bool operator!=(const Point& temp);

    // Surcharge de l'opérateur = pour l'affectation
    Point& operator=(const Point& temp);

    // Surcharge des opérateurs += et -=
    Point& operator+=(const Point& temp);
    Point& operator-=(const Point& temp);

    // Comparaison avec tolérance pour les doubles
    bool compareWithTolerance(const Point& other, double tolerance = 1e-6);
};

#endif // POINT_HPP
