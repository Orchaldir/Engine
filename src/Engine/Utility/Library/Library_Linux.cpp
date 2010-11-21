#include "Library_Linux.hpp"


#include <dlfcn.h>
#include <stdio.h>


namespace Utility
{
	Library_Linux::Library_Linux(const string& pName)
	{
		const string fComplateName = "./lib" + pName + ".so";
		cout << "Library_Linux::loadLibrary(\"" << fComplateName << "\")" << endl;

		mHandle = dlopen(fComplateName.c_str(), RTLD_LAZY);

		if(0 == mHandle)
		{
			cout << "ERROR:" << dlerror() << endl;
		}
	}

	Library_Linux::~Library_Linux()
	{
		if(0 != mHandle)
		{
			dlclose(mHandle);
			mHandle = 0;
		}
	}

	void* Library_Linux::getFunction(const string& pName) const
	{
		assert(0 != mHandle && "Library handle invalid!");

		return dlsym(mHandle, pName.c_str());
	}
}
