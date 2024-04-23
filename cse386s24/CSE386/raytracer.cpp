/****************************************************
 * 2016-2023 Eric Bachmann and Mike Zmuda
 * All Rights Reserved.
 * NOTICE:
 * Dissemination of this information or reproduction
 * of this material is prohibited unless prior written
 * permission is granted.
 ****************************************************/
#include "raytracer.h"
#include "ishape.h"
#include "io.h"

 /**
  * @fn	RayTracer::RayTracer(const color &defa)
  * @brief	Constructs a raytracers.
  * @param	defa	The clear color.
  */

RayTracer::RayTracer(const color& defa)
	: defaultColor(defa) {
}

/**
 * @fn	void RayTracer::raytraceScene(FrameBuffer &frameBuffer, int depth, const IScene &theScene) const
 * @brief	Raytrace scene
 * @param [in,out]	frameBuffer	Framebuffer.
 * @param 		  	depth	   	The current depth of recursion.
 * @param 		  	theScene   	The scene.
 */

void RayTracer::raytraceScene(FrameBuffer& frameBuffer, int depth,
	const IScene& theScene) const {
	const RaytracingCamera& camera = *theScene.camera;
	const vector<VisibleIShapePtr>& objs = theScene.opaqueObjs;
	const vector<LightSourcePtr>& lights = theScene.lights;
	color defaultColor = frameBuffer.getClearColor();

	for (int y = 0; y < frameBuffer.getWindowHeight(); ++y) {
		for (int x = 0; x < frameBuffer.getWindowWidth(); ++x) {
			DEBUG_PIXEL = (x == xDebug && y == yDebug);
			if (DEBUG_PIXEL) {
				cout << "";
			}
			/* CSE 386 - todo  */
			Ray ray = camera.getRay(x, y);
			OpaqueHitRecord hit;
			VisibleIShape::findIntersection(ray, objs, hit);
			if (hit.t != FLT_MAX) {
				//color C = theScene.lights[0]->illuminate(hit.interceptPt, hit.normal, hit.material, camera.getFrame(), false);
				//frameBuffer.setColor(x, y, C);
				if (hit.texture != nullptr) {
					color texel = hit.texture->getPixelUV(hit.u, hit.v);
					frameBuffer.setColor(x, y, texel);
				}
				else {
					//color C = theScene.lights[0]->illuminate(hit.interceptPt, hit.normal, hit.material, camera.getFrame(), false);
					//frameBuffer.setColor(x, y, C);
					color finalColor = black;
					for (unsigned int i = 0; i < 1; i++) {
						bool isInShadow = lights[i]->pointIsInAShadow(hit.interceptPt, hit.normal, objs, camera.getFrame());
						finalColor += lights[i]->illuminate(hit.interceptPt, hit.normal, hit.material, camera.getFrame(), isInShadow);
					}
					frameBuffer.setColor(x, y, finalColor);
				}
			}
			else {
				frameBuffer.setColor(x, y, paleGreen);
			}
			frameBuffer.showAxes(x, y, ray, 0.25);			// Displays R/x, G/y, B/z axes
		}
	}

	frameBuffer.showColorBuffer();
}

/**
 * @fn	color RayTracer::traceIndividualRay(const Ray &ray,
 *											const IScene &theScene,
 *											int recursionLevel) const
 * @brief	Trace an individual ray.
 * @param	ray			  	The ray.
 * @param	theScene	  	The scene.
 * @param	recursionLevel	The recursion level.
 * @return	The color to be displayed as a result of this ray.
 */

color RayTracer::traceIndividualRay(const Ray& ray, const IScene& theScene, int recursionLevel) const {
	/* CSE 386 - todo  */
	// This might be a useful helper function.
	return black;
}
