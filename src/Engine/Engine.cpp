#include "Engine.hpp"


#include "Graphic/Window/iWindow.hpp"


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

	#ifdef UNIX
		mGraphicLibrary = new Utility::Library_Linux("Graphic_OpenGL");
	#elif WIN

	#endif

	mCreateGraphic = reinterpret_cast<createGraphic>(mGraphicLibrary->getFunction("createGraphic"));

	if(0 == mCreateGraphic)
	{
		cout << " couldn't load \"createGraphic\"" << endl;
		return;
	}

	mDestroyGraphic = reinterpret_cast<destroyGraphic>(mGraphicLibrary->getFunction("destroyGraphic"));

	if(0 == mDestroyGraphic)
	{
		cout << " couldn't load \"destroyGraphic\"" << endl;
		return;
	}

	cout << " init graphic" << endl;

	mGraphic = mCreateGraphic(pTitle, pSizeX, pSizeY);
}

Engine::~Engine()
{
	cout << "Engine::~Engine()" << endl;

	if(0 != mGraphic)
	{
		mDestroyGraphic(mGraphic);
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

