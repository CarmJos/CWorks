// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2024. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

// Defined a struct of point, and named it Point(x,y).
#ifndef AREA_H
#define AREA_H

typedef struct point {
    const double x;
    const double y;
} Point;

// Defined a struct of circle, and named it Circle(Point(x,y), r).
typedef struct circle {
    Point center; // center point of the circle
    double radius;
} Circle;

static double square(const double x) {
    return x * x;
}

// calculate the squared distance of two points
static double distanceSquared(const Point p1, const Point p2) {
    return square(p1.x - p2.x) + square(p1.y - p2.y);
}

// predicate the point(x, y) whether inside the circle(circleX, circleY, circleRadius)
static int isInside(const Point point, const Circle circle) {
    return distanceSquared(point, circle.center) < square(circle.radius);
}
#endif // AREA_H
