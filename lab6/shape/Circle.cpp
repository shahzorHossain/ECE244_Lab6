

#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Circle.h"
using namespace std;

Circle::Circle(string _name, string _colour, float _xcen, 
        float _ycen, float _radius) : Shape(_name, _colour, _xcen, _ycen){
    
    radius = _radius;
    
}

void Circle::print () const{
  
    Shape::print();
    cout<<"circle";
    cout<<" radius: "<<radius<<endl;
     
            
}
void Circle::scale (float scaleFac){
    
    radius *= scaleFac;
    
    
}
float Circle::computeArea () const{
    
    return abs(PI * pow(radius,2));
            
}
float Circle::computePerimeter () const{
 
    float perimeter;
    perimeter = 2*PI*radius;
    
    return perimeter;
    
}
void Circle::draw (easygl* window) const{
      
   window->gl_setcolor(getColour());
   
   //starts at zero, and rotates 360 degrees
   window ->gl_fillarc(getXcen(), getYcen(), radius, 0, 360);
   
}
bool Circle::pointInside (float x, float y) const{
    
    if(x <= (getXcen()+radius)  && x >= (getXcen()-radius) &&
            y <= (getYcen()+radius) && y >= (getYcen()-radius))
        return true;
    else
        return false;
    
    
}


Circle::~Circle(){
    
}