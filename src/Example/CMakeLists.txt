PROJECT(Example)

SET(NAME Example)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/Engine)
LINK_DIRECTORIES(${OUTPUT_PATH})

SET(SOURCES
	main.cpp
	)

SET_SOURCE_FILES_PROPERTIES(${SOURCES} COMPILE_FLAGS "-DMAJOR=${PROJECT_MAJOR_VERSION} -DMINOR=${PROJECT_MINOR_VERSION}")

ADD_EXECUTABLE(${NAME} ${SOURCES})

TARGET_LINK_LIBRARIES(${NAME} Engine)

IF(UNIX)
	TARGET_LINK_LIBRARIES(${NAME} ${CMAKE_DL_LIBS})
ENDIF(UNIX)

