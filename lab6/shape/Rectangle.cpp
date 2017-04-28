

#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(string _name, string _colour, float _xcen, 
        float _ycen, float _width, float _height) : Shape(_name, _colour, _xcen, _ycen){
    
    width = _width;
    height = _height;
    
}

void Rectangle::print () const{
    
    Shape::print();
    cout<<"rectangle";
    cout<<" width: "<<width<<" height: "<<height<<endl;
     
            
}
void Rectangle::scale (float scaleFac){
    
    width *= scaleFac;
    height *= scaleFac;
    
}
float Rectangle::computeArea () const{
    
    return abs(width*height);
            
}
float Rectangle::computePerimeter () const{
 
    float perimeter;
    perimeter = 2*width + 2*height;
    
    return perimeter;
    
}
void Rectangle::draw (easygl* window) const{
   // Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   t_point coords[3];  // This data type is in easygl_constants.h
   
   coords[0].x = getXcen() - width/2; //top left
   coords[0].y = getYcen() + height/2;
   coords[1].x = getXcen() - width/2;//bottom left
   coords[1].y = getYcen() - height/2;
   coords[2].x = getXcen() + width/2;//bottom right
   coords[2].y = getYcen() - height/2;
   coords[3].x = getXcen() + width/2;//top right
   coords[3].y = getYcen() + height/2;
   
   window->gl_setcolor(getColour());
   
   //I used top left and bottom right coordinates to draw rectangle
   window ->gl_fillrect(coords[0].x,coords[0].y,coords[2].x,coords[2].y);
   
}
bool Rectangle::pointInside (float x, float y) const{
    
    float xLeft,xRight,yTop,yBottom;
    
    xLeft = getXcen() - width/2;
    xRight = getXcen() + width/2;
    yTop = getYcen() + height/2;
    yBottom = getYcen() - height/2;
    
    if(x >= xLeft && x <= xRight && y >= yBottom && y<= yTop)
        return true;
    else
        return false;
    
    
}


Rectangle::~Rectangle(){
    
}