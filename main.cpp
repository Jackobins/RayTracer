#include <iostream>
#include "CoordFiles/point.h"
#include "CanvasFiles/canvas.h"
#include "CoordFiles/matrix.h"
#include "CoordFiles/matrixOps.h"
#include "SceneFiles/RayFiles/ray.h"
#include "SceneFiles/Shapes/sphere.h"
#include "SceneFiles/RayFiles/rayOps.h"
#include "CoordFiles/coordOps.h"

using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib> // for exit function
using namespace std;

int main() {
    point rayOrigin = point(0 ,0, -5);
    float wallZ = 10;
    float wallSize = 7.0;
    int canvasPixels = 800;
    float pixelSize = wallSize / canvasPixels;
    float half = wallSize / 2;
    canvas c = canvas(canvasPixels, canvasPixels);
    color red = color(1, 0, 0);
    sphere s = sphere(1, matrix(4, 4, 1), material());
    s.surfaceMaterial.surfaceColor = color(0.3, 1, 0.1);
    matrix inverseTransform = s.transform.inverse();

    point lightPosition = point(-10, 10, -10);
    color lightColor = color(1,1,1);
    pointLight light = pointLight(lightPosition, lightColor);

    for (int i = 0; i < canvasPixels; i++) {
        float worldY = half - (pixelSize * i);
        for (int j = 0; j < canvasPixels; j++) {
            float worldX = (pixelSize * j) - half;
            point position = point(worldX, worldY, wallZ);
            vec direction = coordOps::coordToVec(
                    coordOps::subtract(position, rayOrigin)).normalize();
            ray r = ray(rayOrigin, direction);
            vector<intersection> xs = rayOps::intersect(s, r, inverseTransform);

            vector<intersection> hits = rayOps::hit(xs);
            if (!hits.empty()) {
                point point = r.position(hits[0].t);
                vec normal = s.normalAt(point, inverseTransform);
                vec eye = r.direction.negate();
                c.writePixel(i, j,
                             rayOps::lighting(s.surfaceMaterial, light,
                                              point, eye, normal));
            }
        }
    }

    // Write data to file
    ofstream outdata;
    outdata.open("output.txt");
    if (!outdata) {
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    outdata << c.toPPM();
    outdata.close();
    return 0;
}
