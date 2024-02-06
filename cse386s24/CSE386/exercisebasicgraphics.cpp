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

	cout << normalizeDegrees(0) << endl;
	cout << normalizeDegrees(1.75) << endl;
	cout << normalizeDegrees(-1) << endl;
	cout << normalizeDegrees(-721) << endl;

	cout << normalizeRadians(0) << endl;
	cout << normalizeRadians(1) << endl;
	cout << normalizeRadians(3 * PI) << endl;
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