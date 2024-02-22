/****************************************************
 * 2016-2023 Eric Bachmann and Mike Zmuda
 * All Rights Reserved.
 * NOTICE:
 * Dissemination of this information or reproduction
 * of this material is prohibited unless prior written
 * permission is granted.
 ****************************************************/

#include <ctime>
#include <vector>
#include "defs.h"
#include "utilities.h"
#include "framebuffer.h"
#include "colorandmaterials.h"
#include "rasterization.h"
#include "io.h"

FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

void render() {
	frameBuffer.clearColorBuffer();
	drawLine(frameBuffer, 0, 0, 100, 100, red);
	drawLine(frameBuffer, 100, 100, 200, 100, blue);
	frameBuffer.showColorBuffer();
}

void resize(int width, int height) {
	frameBuffer.setFrameBufferSize(width, height);
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	cout << "approximatelyEqual: " << approximatelyEqual(3.000000, 3.0000000001) << endl;
	cout << "approximatelyEqual: " << approximatelyEqual(3.000000, 3.1) << endl;

	double a = 34.6;
	double b = 54.5;

	cout << "before swap: " << a << " " << b << endl;
	swap(a, b);
	cout << "after swap: " << a << " " << b << endl;

	cout << "approximatelyZero: " << approximatelyZero(0.0000001) << endl;
	cout << "approximatelyZero: " << approximatelyZero(0) << endl;
	cout << "approximatelyZero: " << approximatelyZero(0.1) << endl;

	cout << normalizeDegrees(0) << endl;
	cout << normalizeDegrees(1.75) << endl;
	cout << normalizeDegrees(-1) << endl;
	cout << normalizeDegrees(-721) << endl;

	cout << normalizeRadians(0) << endl;
	cout << normalizeRadians(1) << endl;
	cout << normalizeRadians(2 * PI) << endl;
	cout << normalizeRadians(-31 * PI) << endl;

	cout << rad2deg(3 * PI / 4) << endl;
	cout << rad2deg(PI / 6) << endl;
	cout << rad2deg(2 * PI / 3) << endl;
	cout << rad2deg(0) << endl;
	cout << deg2rad(0) << endl;
	cout << deg2rad(60) << endl;
	cout << deg2rad(150) << endl;

	cout << min(150, 200, 300) << endl;
	cout << max(150, 200, 300) << endl;
	cout << max(0, 0, 0) << endl;
	cout << max(-10, -20, -30) << endl;
	cout << min(15, -20, 30) << endl;

	cout << "Distances" << endl;
	cout << distanceFromOrigin(0, 1) << endl;
	cout << distanceFromOrigin(1, 0) << endl;
	cout << distanceFromOrigin(1, 1) << endl;
	cout << distanceFromOrigin(-10, 30) << endl;

	cout << distanceBetween(0, 0, 1, 1) << endl;
	cout << distanceBetween(1, 1, 0, 0) << endl;
	cout << distanceBetween(10, 10, 11, 11) << endl;
	cout << distanceBetween(100, 100, 99, 99) << endl;
	cout << distanceBetween(54, 1, -34, -99) << endl;
	
	cout << "Area of Triangle" << endl;
	cout << areaOfTriangle(3, 4, 5) << endl;
	cout << areaOfTriangle(-3, 4, 5) << endl;
	cout << areaOfTriangle(3, 4, 50) << endl;
	cout << areaOfTriangle(3, 4, 7) << endl;
	cout << areaOfTriangle(-3, -4, -7) << endl;
	cout << areaOfTriangle(1, 222, 224) << endl;
	cout << areaOfTriangle(0, 0, 0) << endl;

	cout << "Area of Triangle (Points)" << endl;
	cout << areaOfTriangle(0, 0, 3, 0, 0, 4) << endl;
	cout << areaOfTriangle(1, 1, 5, 4, 10, 2) << endl;
	cout << areaOfTriangle(2, 9, 5, 3, 10, 6) << endl;
	cout << areaOfTriangle(-2, 3, 4, -1, -3, -4) << endl;

	cout << "Points on Unit Circle" << endl;
	double x, y = 0;
	pointOnUnitCircle(0.19 * PI, x, y);
	cout << x << ' ' << y << endl;
	pointOnUnitCircle(2 * PI, x, y);
	cout << x << ' ' << y << endl;
	pointOnUnitCircle(1 * PI, x, y);
	cout << x << ' ' << y << endl;
	pointOnUnitCircle(754, x, y);
	cout << x << ' ' << y << endl;
	pointOnUnitCircle(1.22 * PI, x, y);
	cout << x << ' ' << y << endl;

	cout << "Points on Circle" << endl;
	dvec2 ptr1(3, 4);
	cout << pointOnCircle(ptr1, 7, 34) <<  endl;
	dvec2 ptr2(-2, -3);
	cout << pointOnCircle(ptr2, 4.5, -4) << endl;

	cout << "Direction In Radians" << endl;
	cout << directionInRadians(dvec2(0, 0), dvec2(2, 2)) << endl;
	cout << directionInRadians(dvec2(2, 10), dvec2(3, 11)) << endl;
	cout << directionInRadians(dvec2(2, 2), dvec2(2, 0)) << endl;
	cout << directionInRadians(dvec2(1, -1), dvec2(1.3420, -1.93969)) << endl;
	cout << directionInRadians(dvec2(2, 2)) << endl;
	cout << directionInRadians(dvec2(0, -2)) << endl;
	cout << directionInRadians(0, 0, 2, 2) << endl;
	cout << directionInRadians(2, 10, 3, 11) << endl;
	cout << directionInRadians(2, 2, 2, 0) << endl;
	cout << directionInRadians(-10, 5, 15, -5) << endl;
	cout << directionInRadians(dvec2(- 10, 5), dvec2(15, -5)) << endl;
	cout << directionInRadians(-21.56, 3.70, 9.92, -15.40) << endl;
	cout << directionInRadians(9.92, -15.40 , -21.56, 3.70) << endl;

	cout << "Mapping" << endl;
	cout << map(2, 0, 5, 10, 11) << endl;
	cout << map(0, -10, 10, 0, 100) << endl;

	cout << "Quadratic Equation" << endl;
	cout << quadratic(1.500000, 5.20000000, 0.500000000) << endl;
	cout << quadratic(-0.1, 0.2, 0.5) << endl;
	cout << quadratic(-1.5, 3, 3) << endl;
	cout << quadratic(3, 6, 3) << endl;
	cout << quadratic(-1, 2, 5) << endl;
	cout << quadratic(1, 2, 1) << endl;
	cout << quadratic(1, -2, 1) << endl;
	cout << quadratic(3, 4, 1) << endl;
	cout << quadratic(1, 4, 3) << endl;
	cout << quadratic(-3, 4, -1) << endl;

	double roots[2];
	int numRoots = quadratic(-1, 2, 5, roots);
	if (numRoots == 0) {
		cout << "There are no real roots" << endl;
	}
	else if (numRoots == 1) {
		cout << "Only one root: " << roots[0] << endl;
	}
	else if (numRoots == 2) {
		if (roots[0] > roots[1])
			cout << "Something is wrong. This should not happen" << endl;
		else
			cout << "Two roots: " << roots[0] << " and " << roots[1] << endl;
	}
	else {
		cout << "Something is wrong. This should not happen" << endl;
	}

	cout << "Double It" << endl;
	cout << doubleIt(dvec2(1.8, 0)) << endl;

	cout << "My Normalize" << endl;
	cout << myNormalize(dvec3(4.2, 6.5, 7.12)) << endl;
	cout << myNormalize(dvec3(1, 1, 1)) << endl;
	cout << myNormalize(dvec3(-3, -3, -3)) << endl;

	cout << "Is Orthogonal" << endl;
	cout << isOrthogonal(dvec3(1, 0, 0), dvec3(0, 1, 0)) << endl;
	cout << isOrthogonal(dvec3(1, 2, -1), dvec3(-2, 1, 0)) << endl;
	cout << isOrthogonal(dvec3(-2, -1, -3), dvec3(1, 1, -4)) << endl;

	cout << "Is Acute Angle" << endl;
	cout << formAcuteAngle(dvec3(1, 0, 0), dvec3(0, 1, 0)) << endl;
	cout << formAcuteAngle(dvec3(1, 2, -1), dvec3(-2, 1, 0)) << endl;
	cout << formAcuteAngle(dvec3(-2, -1, -3), dvec3(1, 1, -4)) << endl;

	cout << "Cosine Between" << endl;
	cout << cosBetween(dvec2(1.0, 0.0), dvec2(1.0, 0.0)) << endl;
	cout << cosBetween(dvec2(1.0, 0.0), dvec2(1.0, 1.0)) << endl;
	cout << cosBetween(dvec2(-1.0, glm::sqrt(3.0)), dvec2(-1.0, 0.0)) << endl;
	cout << cosBetween(dvec2(-1.0, glm::sqrt(3.0)), dvec2(1.0, glm::sqrt(3.0))) << endl;
	cout << cosBetween(dvec3(1, 3, 8), dvec3(6, -1, -9)) << endl;
	cout << cosBetween(dvec4(22, 13, -44, 12.8), dvec4(-55, 108, 99, 45.5)) << endl;

	cout << "Area Of Parallelogram" << endl;
	cout << areaOfParallelogram(dvec3(1.0, 0.0, 0.0), dvec3(0.0, 1.0, 0.0)) << endl;
	cout << areaOfParallelogram(dvec3(1.0, 1.0, 1.0), dvec3(1.0, 0.0, 1.0)) << endl;
	cout << areaOfParallelogram(dvec3(-12, 19, 37), dvec3(42.8, -128.7, 1.6)) << endl;

	cout << "Area Of Triangle" << endl;
	cout << areaOfTriangle(dvec3(0.0, 0.0, 0.0), dvec3(1.0, 0.0, 0.0), dvec3(0.0, 1.0, 0.0)) << endl;
	cout << areaOfTriangle(dvec3(-10.0, -10.0, -10.0), dvec3(-11.0, -10.0, -10.0), dvec3(-10.0, -11.0, -10.0)) << endl;
	cout << areaOfTriangle(dvec3(-12.1, -112, 87), dvec3(-11.0, 12, 9), dvec3(-10.0, 111, 0)) << endl;

	cout << "Pointing Vector" << endl;
	cout << pointingVector(dvec3(0.0000000000, - 0.4142135624, 2.0000000000), dvec3(1.0000000000, 1.0000000000, 1.0000000000)) << endl;
	/*
	graphicsInit(argc, argv, __FILE__);

	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboardUtility);
	glutMouseFunc(mouseUtility);

	frameBuffer.setClearColor(paleGreen);

	glutMainLoop();
	*/
	return 0;
}