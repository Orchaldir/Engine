#include "Engine.hpp"


#include "Graphic/Window/iWindow.hpp"
#include "Graphic/Graphic_OpenGL.hpp"

#ifdef UNIX
#include "Utility/Library/Library_Linux.hpp"
#elif WIN

#endif


Engine::Engine(const string& pTitle, uint32 pSizeX, uint32 pSizeY) :
	mGraphicLibrary(0),
	mGraphic(0)
{
	cout << "Engine::Engine()" << endl;

	// load Graphic

	cout << " load graphic" << endl;

	mGraphicLibrary = new Utility::Library_Linux("Graphic_OpenGL");

	cout << " init graphic" << endl;

	mGraphic = new Graphic::Graphic_OpenGL(pTitle, pSizeX, pSizeY);
}

Engine::~Engine()
{
	cout << "Engine::~Engine()" << endl;

	if(0 != mGraphic)
	{
		delete mGraphic;
	}

	if(0 != mGraphicLibrary)
	{
		delete mGraphicLibrary;
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

