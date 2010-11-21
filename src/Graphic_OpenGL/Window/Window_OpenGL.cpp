#include "Window_OpenGL.hpp"


#include "SDL.h"
#include "SDL_opengl.h"


namespace Graphic
{
	Window_OpenGL::Window_OpenGL(const string& pTitle, uint32 pSizeX, uint32 pSizeY) :
		mTitle(pTitle),
		mSizeX(pSizeX),
		mSizeY(pSizeY)
	{
		SDL_SetVideoMode(mSizeX, mSizeY, 32, SDL_OPENGL);
		SDL_WM_SetCaption(mTitle.c_str(), 0);
	}

	Window_OpenGL::~Window_OpenGL()
	{

	}

	void Window_OpenGL::start2d() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(1.0f, 0.0f, 0.0f);
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, mSizeX, mSizeY, 0, -100, 100);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glDisable(GL_DEPTH_TEST);
		glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);

		// test
		glBegin(GL_TRIANGLES);
			glVertex2i(100, 100);
			glVertex2i(700, 200);
			glVertex2i(300, 500);
		glEnd();
	}

	void Window_OpenGL::end2d() const
	{
		glDisable(GL_BLEND);
		glEnable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		SDL_GL_SwapBuffers();
	}

	void Window_OpenGL::setTitle(const string& pTitle)
	{
		mTitle = pTitle;
		SDL_WM_SetCaption(mTitle.c_str(), 0);
	}
}

