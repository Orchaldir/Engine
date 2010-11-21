#include "Graphic_OpenGL.hpp"


#include "Window/Window_OpenGL.hpp"


#include "SDL.h"
#include "SDL_opengl.h"


namespace Graphic
{
	DLL iGraphic* createGraphic(const string& pTitle, uint32 pSizeX, uint32 pSizeY)
	{
		return new Graphic_OpenGL(pTitle, pSizeX, pSizeY);
	}

	DLL void destroyGraphic(iGraphic* pGraphic)
	{
		if(0 != pGraphic)
		{
			delete pGraphic;
		}
	}


	Graphic_OpenGL::Graphic_OpenGL(const string& pTitle, uint32 pSizeX, uint32 pSizeY) :
		mWindow(0)
	{
		mWindow = new Window_OpenGL(pTitle, pSizeX, pSizeY);

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glShadeModel(GL_SMOOTH);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_DEPTH_TEST);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
	}

	Graphic_OpenGL::~Graphic_OpenGL()
	{
		if(0 != mWindow)
		{
			delete mWindow;
		}
	}

	GraphicEvent Graphic_OpenGL::getEvent() const
	{
		SDL_Event fEvent;

		while(SDL_PollEvent(&fEvent))
		{
			if(SDL_ACTIVEEVENT == fEvent.type)
			{
				if(fEvent.active.state & SDL_APPACTIVE)
				{
					if(1 == fEvent.active.gain)
					{
						return Focus;
					}
				}
			}
			else if(SDL_QUIT == fEvent.type)
			{
				return Close;
			}
			else if(SDL_MOUSEBUTTONDOWN == fEvent.type)
			{
				SDL_PushEvent(&fEvent);
				return None;
			}
			else if(SDL_MOUSEBUTTONUP == fEvent.type)
			{
				SDL_PushEvent(&fEvent);
				return None;
			}
		}

		return None;
	}
}

