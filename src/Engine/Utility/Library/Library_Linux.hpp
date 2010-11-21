#ifndef _Library_Linux_h_
#define _Library_Linux_h_


#include "iLibrary.hpp"


namespace Utility
{
	class Library_Linux : public iLibrary
	{
		private:

			void* mHandle;

		public:

			Library_Linux(const string& pName);
			virtual ~Library_Linux();

			virtual void* getFunction(const string& pName) const;
	};
}

#endif
