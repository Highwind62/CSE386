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
	const vector<VisibleIShapePtr>& opaqueObjs = theScene.opaqueObjs;
	const vector<TransparentIShapePtr>& transObjs = theScene.transparentObjs;
	const vector<LightSourcePtr>& lights = theScene.lights;
	color defaultColor = frameBuffer.getClearColor();

	for (int y = 0; y < frameBuffer.getWindowHeight(); ++y) {
		for (int x = 0; x < frameBuffer.getWindowWidth(); ++x) {
			DEBUG_PIXEL = (x == xDebug && y == yDebug);
			if (DEBUG_PIXEL) {
				cout << "";
			}
			/* CSE 386 - todo  */
			// Transparency
			Ray ray = camera.getRay(x, y);
			OpaqueHitRecord hit;
			TransparentHitRecord transHit;
			VisibleIShape::findIntersection(ray, opaqueObjs, hit);
			TransparentIShape::findIntersection(ray, transObjs, transHit);
			color source = transHit.transColor;

			// Backface correction and normal negation
			dvec3 d = glm::normalize(camera.getFrame().origin - hit.interceptPt);
			if (glm::dot(d, -hit.normal) > 0) {
				hit.normal = -hit.normal;
			}
			//
			if (hit.t != FLT_MAX) {
				color finalColor = black;
				for (unsigned int i = 0; i < lights.size(); i++) {
					bool isInShadow = lights[i]->pointIsInAShadow(hit.interceptPt, hit.normal, opaqueObjs, camera.getFrame());
					finalColor += lights[i]->illuminate(hit.interceptPt, hit.normal, hit.material, camera.getFrame(), isInShadow);
				}
				
				if (hit.texture != nullptr) {
					color texel = hit.texture->getPixelUV(hit.u, hit.v);
					finalColor = 0.5 * finalColor + 0.5 * texel;
				}

				if (transHit.t < hit.t) {
					finalColor = (1 - transHit.alpha) * finalColor + transHit.alpha * source;
				}

				frameBuffer.setColor(x, y, finalColor);
			}
			else {
				color background = paleGreen;

				if (transHit.t < hit.t) {
					background = (1 - transHit.alpha) * background + transHit.alpha * source;
				}

				frameBuffer.setColor(x, y, background);
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
