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
#include "SceneFiles/Shapes/plane.h"
#include "SceneFiles/patternFiles/stripes.h"
#include "SceneFiles/patternFiles/patternOps.h"
#include "SceneFiles/patternFiles/gradient.h"
#include "SceneFiles/patternFiles/ring.h"
#include "SceneFiles/patternFiles/checkers.h"
#include "SceneFiles/patternFiles/blendedPattern.h"

using std::cerr;
using std::endl;
#include <fstream>
using std::ofstream;
using namespace std;

int main() {
    pattern* checkerPattern = new checkers(color(1,1,1), color(0,0,0));

    shape* floor = new plane();
    floor->surfaceMaterial.pattern = checkerPattern;
    floor->surfaceMaterial.reflective = 0.3;

    shape* leftWall = new plane();
    matrix transform = matrixOps::multiply(matrixOps::rotationMatrix(1, -M_PI_4),
                                           matrixOps::rotationMatrix(0, M_PI_2));
    transform = matrixOps::multiply(matrixOps::translationMatrix(0,0,5), transform);
    leftWall->setTransform(transform);

    shape* rightWall = new plane();
    matrix transform2 = matrixOps::multiply(matrixOps::rotationMatrix(1, M_PI_4),
                                            matrixOps::rotationMatrix(0, M_PI_2));
    transform2 = matrixOps::multiply(matrixOps::translationMatrix(0,0,5), transform2);
    rightWall->setTransform(transform2);

    shape* middle = new sphere();
    middle->setTransform(matrixOps::translationMatrix(-0.5,1,0.5));
    middle->surfaceMaterial = material();
    middle->surfaceMaterial.surfaceColor = color(0.1,1,0.5);
    middle->surfaceMaterial.diffuse = 0.7;
    middle->surfaceMaterial.specular = 0.3;
    middle->surfaceMaterial.pattern = new stripes(color(0,1,0), color(1,0,0));
    middle->surfaceMaterial.pattern->setTransform(matrixOps::scalingMatrix(0.5,0.5,0.5));
    middle->surfaceMaterial.reflective = 0.8;

    shape* right = new sphere();
    right->setTransform(matrixOps::multiply(matrixOps::translationMatrix(1.5,0.5,-0.5),
                                        matrixOps::scalingMatrix(0.5,0.5,0.5)));
    right->surfaceMaterial = material();
    right->surfaceMaterial.surfaceColor = color(1, 0.5, 0.1);
    right->surfaceMaterial.diffuse = 0.7;
    right->surfaceMaterial.specular = 0.3;
    right->surfaceMaterial.reflective = 0.2;

    shape* left = new sphere();
    left->setTransform(matrixOps::multiply(matrixOps::translationMatrix(-1.5,0.33,-0.75),
                                       matrixOps::scalingMatrix(0.33,0.33,0.33)));
    left->surfaceMaterial = material();
    left->surfaceMaterial.surfaceColor = color(1, 0.8, 0.1);
    left->surfaceMaterial.diffuse = 0.7;
    left->surfaceMaterial.specular = 0.3;
    left->surfaceMaterial.reflective = 0.2;

    pointLight lightSource = pointLight(point(-10,10,-10),
                                        color(1,1,1));
    world* w = new world(lightSource, {floor, leftWall, rightWall, middle, left, right});
    camera* cam = new camera(480, 360, M_PI/3);
    cam->setTransform(worldOps::viewTransform(point(0, 1.5, -5),
                                             point(0,1,0),
                                             vec(0,1,0)));

    canvas c = worldOps::render(cam, w);

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
