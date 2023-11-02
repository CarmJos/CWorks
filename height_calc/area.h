// Defined a struct of point, and named it Point(x,y).
typedef struct point {
    double x;
    double y;
} Point;

// Defined a struct of circle, and named it Circle(Point(x,y), r).
typedef struct circle {
    Point center; // center point of the circle
    double radius;
} Circle;

// calculate the squared distance of two points
double distanceSquare(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// predicate the point(x, y) whether inside the circle(circleX, circleY, circleRadius)
int isInside(Point point, Circle circle) {
    return distanceSquare(point, circle.center) < circle.radius * circle.radius;
}