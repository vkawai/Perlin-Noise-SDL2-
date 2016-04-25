/*
 * Util.cpp
 *
 *  Created on: 25 de abr de 2016
 *      Author: Kawai
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>
#include <iomanip>
#include <string>

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 500

//#define DEBUG

namespace Util{
	float** matrixAlloc(int width, int height);
	void matrixDealloc(float **m, int width, int height);
	void printMatrix(std::string title, float **m, int width, int height);
}

#endif
