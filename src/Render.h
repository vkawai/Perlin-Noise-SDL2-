/*
 * render.h
 *
 *  Created on: 11 de abr de 2016
 *      Author: Kawai
 */

#ifndef RENDER_H_
#define RENDER_H_

#include "PerlinNoise.h"
#include <SDL2/SDL.h>
#include "Util.h"

class Render {
protected:
	bool exit;
	SDL_Event e;
	SDL_Window *gWindow;
	SDL_Surface *gScreenSurface;
	SDL_Renderer *gRenderer;

public:
	Render();
	virtual ~Render();

	void run();

	void setup();
	void input(double delta);
	void update(double delta);
	void render(double delta);

	void ss(char* title);
};

#endif /* RENDER_H_ */
