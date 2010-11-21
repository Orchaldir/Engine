PROJECT(Engine)

SET(NAME Engine)

SET(HEADERS
	Graphic/Window/iWindow.hpp
	Graphic/iGraphic.hpp
	Utility/Library/iLibrary.hpp
	DataTypes.hpp
	Engine.hpp
	)

SET(SOURCES
	Engine.cpp
	)

IF(UNIX)
	SET(HEADERS ${HEADERS} 
    		Utility/Library/Library_Linux.hpp
    		)  
	SET(SOURCES ${SOURCES} 
    		Utility/Library/Library_Linux.cpp
    		)  
	SET_SOURCE_FILES_PROPERTIES(${SOURCES} COMPILE_FLAGS "-DUNIX -DMAJOR=${PROJECT_MAJOR_VERSION} -DMINOR=${PROJECT_MINOR_VERSION}")
ENDIF(UNIX)

IF(WIN32)
	SET(HEADERS ${HEADERS} 
    		Utility/Library/Library_Windows.hpp
    		)  
	SET(SOURCES ${SOURCES} 
    		Utility/Library/Library_Windows.cpp
    		)  
	SET_SOURCE_FILES_PROPERTIES(${SOURCES} COMPILE_FLAGS "-DWIN -DMAJOR=${PROJECT_MAJOR_VERSION} -DMINOR=${PROJECT_MINOR_VERSION}")
ENDIF(WIN32)

ADD_LIBRARY(${NAME} ${SOURCES} ${HEADERS})

IF(UNIX)
	TARGET_LINK_LIBRARIES(${NAME} ${CMAKE_DL_LIBS})
ENDIF(UNIX)

