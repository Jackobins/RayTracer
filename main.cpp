#include <iostream>
#include "CoordFiles/point.h"
#include "CanvasFiles/canvas.h"
#include "CoordFiles/matrix.h"
#include "CoordFiles/matrixOps.h"
#include "SceneFiles/RayFiles/ray.h"
#include "SceneFiles/Shapes/sphere.h"
#include "SceneFiles/RayFiles/rayOps.h"
#include "CoordFiles/coordOps.h"
#include "SceneFiles/RayFiles/computation.h"
#include "SceneFiles/WorldFiles/worldOps.h"
#include "SceneFiles/WorldFiles/camera.h"

using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
#include <cstdlib> // for exit function
using namespace std;

int main() {

    sphere floor = sphere(1);
    floor.transform = matrixOps::scalingMatrix(10, 0.01, 10);
    floor.surfaceMaterial = material();
    floor.surfaceMaterial.surfaceColor = color(1,0.9,0.9);
    floor.surfaceMaterial.specular = 0;

    sphere leftWall = sphere(2);
    matrix scale = matrixOps::scalingMatrix(10, 0.01, 10);
    matrix rotateX = matrixOps::rotationMatrix(0, M_PI_2);
    matrix rotateY = matrixOps::rotationMatrix(1, -1 * M_PI_4);
    matrix translate = matrixOps::translationMatrix(0,0,5);
    matrix m = matrixOps::multiply(matrixOps::multiply(
            matrixOps::multiply(translate, rotateY), rotateX),
                                   scale);
    leftWall.transform = m;
    leftWall.surfaceMaterial = floor.surfaceMaterial;

    sphere rightWall = sphere(3);
    rotateY = matrixOps::rotationMatrix(1, M_PI_4);
    matrix m2 = matrixOps::multiply(matrixOps::multiply(
            matrixOps::multiply(translate, rotateY), rotateX),
                                    scale);
    leftWall.transform = m;
    rightWall.transform = m2;
    rightWall.surfaceMaterial = floor.surfaceMaterial;

    sphere middle = sphere(4);
    middle.transform = matrixOps::translationMatrix(-0.5,1,0.5);
    middle.surfaceMaterial = material();
    middle.surfaceMaterial.surfaceColor = color(0.1,1,0.5);
    middle.surfaceMaterial.diffuse = 0.7;
    middle.surfaceMaterial.specular = 0.3;

    sphere right = sphere(5);
    right.transform = matrixOps::multiply(matrixOps::translationMatrix(1.5,0.5,-0.5),
                                          matrixOps::scalingMatrix(0.5,0.5,0.5));
    right.surfaceMaterial = material();
    right.surfaceMaterial.surfaceColor = color(0.5, 1, 0.1);
    right.surfaceMaterial.diffuse = 0.7;
    right.surfaceMaterial.specular = 0.3;

    sphere left = sphere(6);
    left.transform = matrixOps::multiply(matrixOps::translationMatrix(-1.5,0.33,-0.75),
                                         matrixOps::scalingMatrix(0.33,0.33,0.33));
    left.surfaceMaterial = material();
    left.surfaceMaterial.surfaceColor = color(1, 0.8, 0.1);
    left.surfaceMaterial.diffuse = 0.7;
    left.surfaceMaterial.specular = 0.3;

    pointLight lightSource = pointLight(point(-10,10,-10),
                                        color(1,1,1));
    world w = world(lightSource, {floor, leftWall, rightWall,
                                  middle, left, right});
    camera cam = camera(720, 480, M_PI/3);
    cam.transform = worldOps::viewTransform(point(0, 1.5, -5),
                                          point(0,1,0),
                                          vec(0,1,0));

    canvas c = worldOps::render(cam, w, cam.transform.inverse());

////     Write data to file
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
