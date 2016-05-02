/*
 * PerlinNoise.cpp
 *
 *  Created on: 11 de abr de 2016
 *      Author: Kawai
 */

#include "PerlinNoise.h"

PerlinNoise::PerlinNoise(int width, int height, float amplitude, float persistance){
	this->width = width;
	this->height = height;
	this->amplitude = amplitude;
	this->persistance = persistance;
}

PerlinNoise::~PerlinNoise(){
}

float **PerlinNoise::generateSmoothNoise(float** baseNoise, int octave) {

	float **smoothNoise = Util::matrixAlloc(width,height);

	int period = 1 << octave;
	float frequency = 1.0 / period;

	for(int i = 0; i < width; i++){
		int i0 = (i / period) * period;
		int i1 = (i0 + period) % width;
		float hBlend = (i - i0) * frequency;

		for (int j = 0; j < height; j++){
			int j0 = (j / period) * period;
			int j1 = (j0 + period) % height;
			float vBlend = (j - j0) * frequency;

			float top = interpolate(baseNoise[i0][j0], baseNoise[i1][j0], hBlend);
			float bottom = interpolate(baseNoise[i0][j1], baseNoise[i1][j1], hBlend);

			smoothNoise[i][j] = interpolate(top, bottom, vBlend);
		}
	}
//	Util::printMatrix("Smooth Noise",smoothNoise,width,height);
	return smoothNoise;
}

float PerlinNoise::interpolate(float x0, float x1, float alpha) {
	return x0 * (1 - alpha) + alpha * x1;;
}

float **PerlinNoise::generateWhiteNoise(int seed) {
	float **noise = Util::matrixAlloc(width,height);
	srand(seed);
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			noise[i][j] = ((double)(rand()%1001))/1000;
		}
	}
//	Util::printMatrix("White Noise",noise,width,height);
	return noise;
}

float** PerlinNoise::generatePerlinNoise(float** baseNoise, int octaveCount) {
	float ***smoothNoise = new float**[octaveCount];

	float **perlinNoise = Util::matrixAlloc(width,height);
	float totalAmplitude = 0.0;

	for(int octave = octaveCount-1; octave >= 0; octave--){
		smoothNoise[octave] = generateSmoothNoise(baseNoise,octave);

		amplitude *= persistance;
		totalAmplitude += amplitude;

		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				perlinNoise[i][j] += smoothNoise[octave][i][j] * amplitude;
			}
		}
	}

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			perlinNoise[i][j] /= totalAmplitude;
		}
	}

	//
	for(int i = 0; i < octaveCount; i++){
		Util::matrixDealloc(smoothNoise[i],width,height);
	}
	delete[] smoothNoise;
//	Util::printMatrix("Perlin Noise",perlinNoise,width,height);
	return perlinNoise;
}

float** PerlinNoise::generatePerlinNoise(int seed, int octaveCount) {
	float **matrix = generatePerlinNoise(generateWhiteNoise(seed), octaveCount);
	return matrix;
}
