#include "Library_Windows.hpp"


namespace Utility
{
	Library_Windows::Library_Windows(const string& pName)
	{
		const string fComplateName = pName + ".dll";
		cout << "Library_Windows::loadLibrary(\"" << fComplateName << "\")" << endl;

		mHandle = LoadLibrary(fComplateName.c_str());

		if(0 == mHandle)
		{
			cout << "ERROR:" << GetLastError() << endl;
		}
	}

	Library_Windows::~Library_Windows()
	{
		if(0 != mHandle)
		{
			FreeLibrary(mHandle);
			mHandle = 0;
		}
	}

	void* Library_Windows::getFunction(const string& pName) const
	{
		assert(0 != mHandle && "Library handle invalid!");

		void* fFunction = GetProcAddress(mHandle, pName.c_str());

		if(0 == fFunction)
		{
			cout << "ERROR:" << GetLastError() << endl;
		}

		return fFunction;
	}
}
