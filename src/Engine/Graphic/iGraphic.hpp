#ifndef _Graphic_h_
#define _Graphic_h_


#include "../DataTypes.hpp"


namespace Graphic
{
	enum GraphicEvent
	{
		 None,
		 Close,
		 Focus
	};


	class iWindow;


	class iGraphic
	{
		public:

			virtual ~iGraphic() {}

			virtual iWindow* getWindow() const = 0;

			virtual GraphicEvent getEvent() const = 0;
	};
}

#endif
