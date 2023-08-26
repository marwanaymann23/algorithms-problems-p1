#include<iostream>
#include <valarray>
#include <cfloat>

using namespace std;

struct point {
    int x;
    int y;
};

//The following two functions are qsort comparators
int compareX(const void* a, const void* b) { //Compare points according to x-coordinate
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return(p1->x - p2->x);
}
int compareY(const void* a, const void* b) { //Compare points according to y-coordinate
    point* p1 = (point*)a;
    point* p2 = (point*)b;
    return (p1->y - p2->y);
}

//Find euclidean distance between two points
float findDistance(point p1, point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

//Find smallest distance by brute force
float bruteForce(point points[], int size) {
    float minDistance = FLT_MAX;
    float currentDistance = 0;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            currentDistance = findDistance(points[i], points[j]);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
            }
        }
    }
    return minDistance;
}

//Takes two floats and returns the smaller one
float min(float x, float y) {
    if (x < y) return x;
    else return y;
}

//Finds the smallest distance between two points within a strip
float stripMinDistance(point strip[], int size, float d) {
    float minDistance = d;
    float currentDistance = 0;
    //Sort points in strip according to y-coordinate
    qsort(strip, size, sizeof(point), compareY);

    for (int i = 0; i < size; i++) {
        //This loop will run at most 6 times
        for (int j = i + 1; j < size && strip[j].y - strip[i].y < minDistance; j++) {
            currentDistance = findDistance(strip[i], strip[j]);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
            }
        }
    }
    return minDistance;
}

float closestPoints(point points[], int size) {
    //If 2 or 3 points remain use brute force (base case)
    if (size < 4) {
        return bruteForce(points, size);
    }

    //Find middle point
    int middle = size / 2;
    point middlePoint = points[middle];

    //Find the smallest point on the left, the smallest point on the right, delta is the minimum between them
    float delta = min(closestPoints(points, middle), closestPoints(points + middle, size - middle));

    //Build the strip
    point* strip = new point[size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (abs(points[i].x - middlePoint.x) < delta) {
            strip[j] = points[i];
            j++;
        }
    }

    //Return minimum of closest points in strip and delta
    return min(delta, stripMinDistance(strip, j, delta));
}

//Master function
float closestPair(point points[], int size) {
    //Sort points according to x-coordinate
    qsort(points, size, sizeof(point), compareX);

    return closestPoints(points, size);
}

int main()
{
    point P[] = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closestPair(P, n);
    return 0;
}