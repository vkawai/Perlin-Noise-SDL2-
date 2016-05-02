/*
 * PerlinNoise.h
 *
 *  Created on: 11 de abr de 2016
 *      Author: Kawai
 */

#ifndef PERLINNOISE_H_
#define PERLINNOISE_H_

#include <cstdlib>
#include <ctime>
#include "Util.h"

class PerlinNoise {
private:
public:
	int width;
	int height;
	float amplitude;
	float persistance;

	PerlinNoise(int width, int height, float amplitude = 0.5, float persistance = 0.5);
	virtual ~PerlinNoise();

	float **generateWhiteNoise(int seed = 128);
	float interpolate(float x0, float x1, float alpha);
	float **generateSmoothNoise(float** baseNoise, int octave);
	float **generatePerlinNoise(float **baseNoise, int octaveCount);
	float **generatePerlinNoise(int seed, int octaveCount);
};

#endif /* PERLINNOISE_H_ */
