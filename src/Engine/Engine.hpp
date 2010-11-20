#ifndef _Engine_h_
#define _Engine_h_


#include "DataTypes.hpp"
#include "Graphic/iGraphic.hpp"


class Engine
{
	private:

		Graphic::iGraphic* mGraphic;

	public:

		Engine(const string& pTitle, uint32 pSizeX, uint32 pSizeY);
		~Engine();

		void run();
};

#endif
