#ifndef _Library_Windows_h_
#define _Library_Windows_h_


#include "iLibrary.hpp"
#include "windows.h"


namespace Utility
{
	class Library_Windows : public iLibrary
	{
		private:

			HINSTANCE mHandle;

		public:

			Library_Windows(const string& pName);
			virtual ~Library_Windows();

			virtual void* getFunction(const string& pName) const;
	};
}

#endif
