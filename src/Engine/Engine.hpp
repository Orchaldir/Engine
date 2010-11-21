#ifndef _Engine_h_
#define _Engine_h_


#include "DataTypes.hpp"
#include "Graphic/iGraphic.hpp"
#include "Utility/Library/iLibrary.hpp"


typedef Graphic::iGraphic* (*createGraphic)(const string&, uint32, uint32);
typedef void (*destroyGraphic)(Graphic::iGraphic*);


class Engine
{
	private:

		Utility::iLibrary*	mGraphicLibrary;
		createGraphic		mCreateGraphic;
		destroyGraphic		mDestroyGraphic;
		Graphic::iGraphic*	mGraphic;

	public:

		Engine(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
		~Engine();

		void run();
};

#endif
