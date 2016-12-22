#pragma once

#include <SDL.h>
#include <iostream>
#include "../List/List.h"
#include "../List/List.hpp"
#include "../Model/Object.h"
#include "SdlString.h"

class Renderer
{
public:

	Renderer();
	void createRenderer(SDL_Window* window);
	SDL_Renderer* getRenderer();
	void freeMemory();
	void renderObjects();
	void renderText();
	void renderAll();
	void renderShow();
	void renderClear();
	void add(Object* object);
	void add(SdlString* object);
	static void getDesktopResolution(int& width, int& height);
	void scaleImage(int gameWidth, int gameHeight);
	void renderPart(const SDL_Rect& camera);
	void showAll();

private:

	void initCamera();
	SDL_Rect getScaledRect(const SDL_Rect& rect);
	ListIterator<Object*>
	removeObject(ListIterator<Object*> i);

	ListIterator<SdlString*>
	removeText(ListIterator<SdlString*> i);

	SDL_Renderer* renderer_;
	SDL_Window* windowPtr_;
	List<Object*> objects_;
	List<SdlString*> text_;

	float showingWidthScale_;
	float showingHeightScale_;
	SDL_Texture* camera_;
};
