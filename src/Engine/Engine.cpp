#include "Engine.hpp"


#include "Graphic/Window/iWindow.hpp"
#include "Graphic/Graphic_OpenGL.hpp"


Engine::Engine(const string& pTitle, uint32 pSizeX, uint32 pSizeY)
{
	cout << "Engine::Engine()" << endl;
	mGraphic = new Graphic::Graphic_OpenGL(pTitle, pSizeX, pSizeY);
}

Engine::~Engine()
{
	cout << "Engine::~Engine()" << endl;

	if(0 != mGraphic)
	{
		delete mGraphic;
	}
}

void Engine::run()
{
	cout << "Engine::run()" << endl;

	Graphic::iWindow* fWindow = mGraphic->getWindow();

	while(true)
	{
		Graphic::GraphicEvent fEvent = mGraphic->getEvent();

		if(Graphic::Close == fEvent)
		{
			cout << "Engine::run(): window closed" << endl;
			return;
		}
		else if(Graphic::Focus == fEvent)
		{
			cout << "Engine::run(): regained focus" << endl;
		}

		fWindow->start2d();

		fWindow->end2d();
	}
}

