#ifndef _Graphic_OpenGL_h_
#define _Graphic_OpenGL_h_


#include "iGraphic.hpp"


namespace Graphic
{
	class Graphic_OpenGL : public iGraphic
	{
		private:

			iWindow* mWindow;

		public:

			Graphic_OpenGL(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
			virtual ~Graphic_OpenGL();

			virtual iWindow* getWindow() const { return mWindow; }

			virtual GraphicEvent getEvent() const;
	};
}

#endif
