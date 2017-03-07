//
// Created by yop on 05/03/17.
//

#ifndef TP_C_FIGURE_HPP
#define TP_C_FIGURE_HPP

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class Coloriable {
    public:
        Coloriable(char * coul);
        char * getCouleur();
        void setCouleur(char * coul);

    protected:
        char couleur[20];
};

class Figure {
    public:
        Figure();
        virtual int perimetre() const = 0;
        virtual void afficherCaracteristiques() const = 0;
        static int getCount();

    protected:
        static int count;
};

class Polygon : public Figure {
    public:
        Polygon(int nombre_cotes);
        void afficherCaracteristiques() const override;

    private:
        int nbCotes;
};

class Rectangle : public Polygon {
    public:
        Rectangle(int h, int w);
        virtual void afficherCaracteristiques() const override;
        virtual int perimetre() const override;
        // Setters
        void setWidth(int w);
        void setHeight(int h);
        void setSize(int h, int w);
        // Getters
        int getHeight() const;
        int getWidth() const;


    protected:
        int height;
        int width;

};

class Carre : public Rectangle {
    public:
        Carre(int s);
        int getSide() const;
        void setside(int s);


};

class TriangleEquilateral : public Polygon {
    public:
        TriangleEquilateral(int s);
        virtual void afficherCaracteristiques() const override;
        virtual int perimetre() const override;
        // Setters
        void setSide(int s);
        // Getters
        int getSide() const;

    private:
        int side;
};

class Cercle : public Figure, Coloriable {
    public:
        Cercle(int r, char * couleur);
        virtual void afficherCaracteristiques() const override;
        virtual int perimetre() const override;
        int getRayon() const;
        void setRayon(int r);

    private:
        int rayon;
};


#endif //TP_C_FIGURE_HPP
