//
// Created by yop on 05/03/17.
//

#include "figures.hpp"


Coloriable::Coloriable(const char * coul) {
    strcpy(couleur, coul);
}

char * Coloriable::getCouleur() {
    return couleur;
}

void Coloriable::setCouleur(const char *coul) {
    strcpy(couleur, coul);
}

int Figure::count = 0;

Figure::Figure() {count++;}

int Figure::getCount() {
    return count;
}

Polygon::Polygon(int nombre_cotes) : nbCotes(nombre_cotes) {}

void Polygon::afficherCaracteristiques() const {
    cout << "[Polygon] Nombre de cotés : " << nbCotes << endl;
}

Rectangle::Rectangle(int h, int w) : Polygon(4), height(h), width(w) {}

void Rectangle::setWidth(int w) {
    width = w;
}

void Rectangle::setHeight(int h) {
    height = h;
}

void Rectangle::setSize(int h, int w) {
    height = h;
    width = w;
}

int Rectangle::getHeight() const {
    return height;
}

int Rectangle::getWidth() const {
    return width;
}

void Rectangle::afficherCaracteristiques()  const {
    cout << "[Rectangle] Hauteur : " << height << " | Largeur : " << width << endl;
}

int Rectangle::perimetre() const {
    return 2*height + 2*width;
}

Carre::Carre(int h) : Rectangle(h, h) {}

int Carre::getSide() const {
    return getHeight();
}

void Carre::setside(int s) {
    setSize(s, s);
}

TriangleEquilateral::TriangleEquilateral(int s) : Polygon(3), side(s) {}

void TriangleEquilateral::afficherCaracteristiques() const {
    cout << "[TriangleEquilateral] Taille d'un côté : " << side << endl;
}

int TriangleEquilateral::getSide() const {
    return side;
}

void TriangleEquilateral::setSide(int s) {
    side = s;
}

int TriangleEquilateral::perimetre() const {
    return 3 * side;
}

Cercle::Cercle(int r, char * couleur) : Coloriable(couleur), rayon(r) {}

int Cercle::getRayon() const {
    return rayon;
}

void Cercle::setRayon(int r) {
    rayon = r;
}

void Cercle::afficherCaracteristiques() const {
    cout << "[Cercle] Rayon : " << rayon << " | Couleur : " << couleur << endl;
}

int Cercle::perimetre() const {
    return int(2 * 3.14115 * rayon);
}


