/* 
 * File:   Polygon.h
 * Author: hossa172
 *
 * Created on December 5, 2016, 11:10 PM
 */

#ifndef POLYGON_H
#define	POLYGON_H


#include "Shape.h"
#include "easygl.h"

class Polygon : public Shape{
    private:
        t_point relVertex[100];   
        int vertices;
        
    public:
    Polygon (string _name, string _colour,float xcen, float ycen, float xpoints[100], float ypoints[100], int maxPoints);
    ~Polygon();
    void print () const;
    void scale (float scaleFac);
    float computeArea () const;
    float computePerimeter () const;
    void draw (easygl* window) const;
    bool pointInside (float x, float y) const;
    t_point getVecBetweenPoints (t_point start, t_point end) const; 
};


#endif	/* POLYGON_H */

