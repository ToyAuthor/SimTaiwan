
set(name SimTaiwan)

project(Game)

if(MINGW)
	add_definitions(-O2 -g -Wall -Wextra -Werror -std=c++11)
elseif(UNIX)
	add_definitions(-O2 -g -Wall -Wextra -Werror -std=c++11)
endif()

file(COPY ${PROJECT_SOURCE_DIR}/resource DESTINATION ${PROJECT_BINARY_DIR})

file(GLOB SOURCE *.cpp */*.cpp)

set(LIB
	toy
	toy_graph
	toy_file
	#sfml-main
	sfml-system
	sfml-window
	freetype
)

if(WIN32)
	set(MY_SDK        "D:/sdk" )
elseif(UNIX)
	set(MY_SDK        "$ENV{HOME}/sdk" )
endif()

set(inc_dir
	${PROJECT_SOURCE_DIR}
	${MY_SDK}/ToyBox/include
	${MY_SDK}/SFML/include
	${MY_SDK}/freetype
	${MY_SDK}/boost
)

set(lib_dir
	${MY_SDK}/ToyBox/lib
	${MY_SDK}/SFML/lib
	${MY_SDK}/freetype
)

include_directories(${inc_dir})
link_directories(${lib_dir})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_executable(${name} ${SOURCE})

target_link_libraries(${name} ${LIB})

if(MSVC)
	set_target_properties(${name} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY            ${TOY_OUTPUT_PATH}
		RUNTIME_OUTPUT_DIRECTORY_DEBUG      ${TOY_OUTPUT_PATH}
		RUNTIME_OUTPUT_DIRECTORY_RELEASE    ${TOY_OUTPUT_PATH}
		ARCHIVE_OUTPUT_DIRECTORY            ${TOY_OUTPUT_PATH}
		ARCHIVE_OUTPUT_DIRECTORY_DEBUG      ${TOY_OUTPUT_PATH}
		ARCHIVE_OUTPUT_DIRECTORY_RELEASE    ${TOY_OUTPUT_PATH}
	)
endif()
