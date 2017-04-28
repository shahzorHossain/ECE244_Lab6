/* 
 * File:   Circle.h
 * Author: hossa172
 *
 * Created on December 5, 2016, 11:10 PM
 */

#ifndef CIRCLE_H
#define	CIRCLE_H


#include "Shape.h"
#include "easygl.h"

class Circle : public Shape{
    private:
        float radius;
        
    public:
        Circle (string _name, string _colour, float _xcen, float _ycen,
                float radius);
        
        virtual ~Circle();
        virtual void print () const;
        virtual void scale (float scaleFac);
        virtual float computeArea () const;
        virtual float computePerimeter () const;
        virtual void draw (easygl* window) const;
        virtual bool pointInside (float x, float y) const;
};



#endif	/* CIRCLE_H */

