#ifndef _Window_OpenGL_h_
#define _Window_OpenGL_h_


#include "../../DataTypes.hpp"
#include "iWindow.hpp"


namespace Graphic
{
	class Window_OpenGL : public iWindow
	{
		private:

			string mTitle;
			uint32 mSizeX, mSizeY;

		public:

			// create and delete
			Window_OpenGL(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
			virtual ~Window_OpenGL();

			virtual void start2d() const;
			virtual void end2d() const;

			virtual uint32 getWidth()  const { return mSizeX; }
			virtual uint32 getHeight() const { return mSizeY; }
			virtual scalar getRatio()  const { return mSizeX / static_cast<scalar>(mSizeY); }

			virtual void setTitle(const string& pTitle);
	};
}

#endif
