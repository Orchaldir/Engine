#ifndef _Engine_h_
#define _Engine_h_


#include "DataTypes.hpp"
#include "Graphic/iGraphic.hpp"
#include "Utility/Library/iLibrary.hpp"


class Engine
{
	private:

		Utility::iLibrary* mGraphicLibrary;
		Graphic::iGraphic* mGraphic;

	public:

		Engine(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
		~Engine();

		void run();
};

#endif
