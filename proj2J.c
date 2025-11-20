// Hadi Almarzooq
// CS 212
// PROJECT 2J DUE 11/14/2025

#include <stdio.h>

/* Place your struct definitions for Circle, Triangle, and Rectangle here */


typedef struct {

	double minX;
	double minY;
	double maxX;
	double maxY;

}Rectangle;

typedef struct{

	double radius;
	double originX;
	double originY;

}Circle;

typedef struct{

	double pt1X;
	double pt2X;
	double minY;
	double maxY;

}Triangle;


/* Define these 9 functions */
void InitializeCircle(Circle* circle, double radius, double originX, double originY)
{

	circle->radius = radius;
	circle->originX = originX;
	circle->originY = originY;

};

void InitializeRectangle(Rectangle* rec, double minX, double maxX, double minY, double maxY)
{

	rec->minX = minX;
	rec->maxX = maxX;
	rec->minY = minY;
	rec->maxY = maxY;

};

void InitializeTriangle(Triangle* triangle, double pt1X, double pt2X, double minY, double maxY)
{

	triangle->pt1X = pt1X;
	triangle->pt2X = pt2X;
	triangle->minY = minY;
	triangle->maxY = maxY;

};


double GetCircleArea(Circle * circle)
{

	return 3.14159*circle->radius*circle->radius;

};

double GetRectangleArea(Rectangle * rec)
{

	return (rec->maxX-rec->minX)*(rec->maxY-rec->minY);

};

double GetTriangleArea(Triangle * triangle)
{

	return (triangle->pt2X-triangle->pt1X)*(triangle->maxY-triangle->minY)/2;

};


void GetCircleBoundingBox(Circle * circle, double * bbox)
{


    bbox[0] = circle->originX - circle->radius;
    bbox[1] = circle->originX + circle->radius;
    bbox[2] = circle->originY - circle->radius;
    bbox[3] = circle->originY + circle->radius;

};

void GetRectangleBoundingBox(Rectangle * rec, double * bbox)
{

    bbox[0] = rec->minX;
    bbox[1] = rec->maxX;
    bbox[2] = rec->minY;
    bbox[3] = rec->maxY;

};

void GetTriangleBoundingBox(Triangle * triangle, double * bbox)
{

    bbox[0] = triangle->pt1X;
    bbox[1] = triangle->pt2X;
    bbox[2] = triangle->minY;
    bbox[3] = triangle->maxY;

};


/* DO NOT MODIFY AFTER THIS POINT */


void
PrintTriangle(Triangle *t)
{
    double bbox[4];
    double area;
    area = GetTriangleArea(t);
    GetTriangleBoundingBox(t, bbox);
    printf("Triangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

void
PrintRectangle(Rectangle *r)
{
    double bbox[4];
    double area;
    area = GetRectangleArea(r);
    GetRectangleBoundingBox(r, bbox);
    printf("Rectangle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

void
PrintCircle(Circle *c)
{
    double bbox[4];
    double area;
    area = GetCircleArea(c);
    GetCircleBoundingBox(c, bbox);
    printf("Circle has area %f and bounding box [%f->%f], [%f->%f]\n",
           area, bbox[0], bbox[1], bbox[2], bbox[3]);
}

int main()
{
    Circle c;
    Triangle t;
    Rectangle r;

    InitializeCircle(&c, 1, 0, 0);
    PrintCircle(&c);
    InitializeCircle(&c, 1.5, 6, 8);
    PrintCircle(&c);
    InitializeCircle(&c, 0.5, -3, 4);
    PrintCircle(&c);

    InitializeRectangle(&r, 0, 1, 0, 1);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1, 1.1, 10, 20);
    PrintRectangle(&r);
    InitializeRectangle(&r, 1.5, 3.5, 10, 12);
    PrintRectangle(&r);

    InitializeTriangle(&t, 0, 1, 0, 1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 1, 0, 0.1);
    PrintTriangle(&t);
    InitializeTriangle(&t, 0, 10, 0, 50);
    PrintTriangle(&t);
}
