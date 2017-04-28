

#include <iostream>
#include <cmath>
#include "easygl.h"
#include "Polygon.h"
using namespace std;

Polygon::Polygon(string _name, string _colour, float xcen,
        float ycen, float xpoints[100], float ypoints[100], int maxPoints)
: Shape(_name, _colour, xcen, ycen) {

    for (int i = 0; i < maxPoints; i++) {
        relVertex[i].x = xpoints[i];
        relVertex[i].y = ypoints[i];
    }
    
    
    vertices = maxPoints;

}

void Polygon::print() const {

    Shape::print();
    cout << "polygon";
    for (int i = 0; i < vertices; i++) {
        cout << " (" << getXcen() + relVertex[i].x << ","
                << getYcen() + relVertex[i].y << ")";
    }
    cout << endl;


}

void Polygon::scale(float scaleFac) {
    for (int i = 0; i < vertices; i++) {
       relVertex[i].x *= scaleFac;
       relVertex[i].y *= scaleFac;
    }
}

float Polygon::computeArea() const {

    float area = 0; // Accumulates area in the loop
    int j = vertices - 1; // The last vertex is the 'previous' one to the first

    for (int i = 0; i < vertices; i++) {
         area = area +  (relVertex[j].x + relVertex[i].x) * (relVertex[j].y-relVertex[i].y);
         j = i; //j is previous vertex to i
    }
    return (area / 2);
}

float Polygon::computePerimeter() const {
   float perimeter = 0;
   float sideLength;
    int j = vertices - 1;
   t_point dist;
   
   for (int i = 0; i < vertices; i++) {
      dist = getVecBetweenPoints (relVertex[i], relVertex[j]);
      sideLength = sqrt (dist.x * dist.x + dist.y * dist.y);
      perimeter += sideLength;
      j = i;
   }
   return perimeter;
}

void Polygon::draw(easygl* window) const {
// Load up the data structure needed by easygl, and draw the triangle
   // using the easygl::draw_polygon call.
   t_point coords[vertices];  // This data type is in easygl_constants.h
   for (int i = 0; i < vertices; i++) {
       coords[i].x = getXcen() + relVertex[i].x;
       coords[i].y = getYcen() + relVertex[i].y;
   }
   window->gl_setcolor(getColour());
   window->gl_fillpoly(coords, vertices);
}

bool Polygon::pointInside(float x, float y) const {
   // Make a point that corresponds to where you clicked. Since all my
   // vertices are relative to the triangle center, it is more convenient
   // to also shift the click point so it is an offset from the triangle 
   // center.
   t_point click;
   click.x = x - getXcen();
   click.y = y - getYcen();
   
   // The test is that a horizontal line (ray) from x = -infinity to the click point
   // will cross (intersect) only one side of triangle to the left of the 
   // click point.  If the point is above or below the triangle, the ray will not
   // intersect any triangle sides. If the point is to the left of the triangle
   // the ray will also not intersect any sides to the left of the point.
   // If the point is to the right of the triangle, the ray will intersect
   // two sides of the triangle to its left. Only if the point is inside the 
   // triangle will the ray intersect exactly one side to the left of the point.
   
   t_point vecOfSide;
   float distanceAlongVector, yDistance;
   int endIndex;
   int sidesToLeft = 0;
   
   for (int istart = 0; istart < vertices; istart++) {
      endIndex = (istart + 1) % vertices; // Next vertex after istart
      vecOfSide = getVecBetweenPoints (relVertex[istart], relVertex[endIndex]);
      yDistance = (click.y - relVertex[istart].y);
      if (vecOfSide.y != 0) {
          distanceAlongVector = yDistance / vecOfSide.y;
      }
      else if (yDistance == 0) {
          distanceAlongVector = 0;
      }
      else {
          distanceAlongVector = 1e10; // Really infinity, but this is big enough
      }
      
      // We intersect this side if the distance (scaling) along the side vector to 
      // get to our "click" y point is between 0 and 1.  Count the first 
      // endpoint of the side as being part of the line (distanceAlongVector = 0)
      // but don't count the second endPoint; we'll intersect that point later 
      // when we check the next side.
      if (distanceAlongVector >= 0 && distanceAlongVector < 1) {
         float xIntersection = relVertex[istart].x + vecOfSide.x * distanceAlongVector;
         if (xIntersection <= click.x ) 
             sidesToLeft++;
      }
   }
   
   return (sidesToLeft == 1);

}


Polygon::~Polygon() {

}


t_point Polygon::getVecBetweenPoints (t_point start, t_point end) const {
   t_point vec;
   vec.x = end.x - start.x;
   vec.y = end.y - start.y;
   return (vec);
}
