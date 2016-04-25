/*
 * Util.cpp
 *
 *  Created on: 25 de abr de 2016
 *      Author: Kawai
 */

#include "Util.h"


float** Util::matrixAlloc(int width, int height){
	float **m = new float*[width];
	for(int i = 0; i < width; i++){
		m[i] = new float[height]();
	}
	return m;
}

void Util::matrixDealloc(float **m, int width, int height){
	for(int i = 0; i < width; i++){
		delete[] m[i];
	}
	delete[] m;
}

void Util::printMatrix(std::string title, float **m, int width, int height) {
	std::cout << "=================== "<< title <<" ====================" << std::endl;
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			std::cout << std::setfill('0') << std::setw(10) << m[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "################################################" << std::endl;
}
