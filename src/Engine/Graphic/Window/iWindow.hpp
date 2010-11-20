#ifndef _iWindow_h_
#define _iWindow_h_


#include "../../DataTypes.hpp"


namespace Graphic
{
	class iWindow
	{
		public:

			virtual ~iWindow() {}

			virtual void start2d() const = 0;
			virtual void end2d() const = 0;

			virtual uint32 getWidth() const = 0;
			virtual uint32 getHeight() const = 0;
			virtual scalar getRatio() const = 0;

			virtual void setTitle(const string& pTitle) = 0;
	};
}

#endif
