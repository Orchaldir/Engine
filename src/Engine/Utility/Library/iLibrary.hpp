#ifndef _iLibrary_h_
#define _iLibrary_h_


#include "../../DataTypes.hpp"


namespace Utility
{
	class iLibrary
	{
		public:

			virtual ~iLibrary() {}

			virtual void *getFunction(const string& pName) const = 0;
	};
}

#endif
