#ifndef _Graphic_OpenGL_h_
#define _Graphic_OpenGL_h_


#include "../Engine/Graphic/iGraphic.hpp"


namespace Graphic
{
	#ifdef UNIX
		#define DLL extern "C"
	#elif WIN
		#define DLL extern "C" __declspec( dllexport )
	#endif

	DLL iGraphic* createGraphic(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
	DLL void destroyGraphic(iGraphic* pGraphic);

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
