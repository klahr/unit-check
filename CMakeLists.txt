cmake_minimum_required (VERSION 3.15)
project (unit-check
	VERSION
		1.0.0
	DESCRIPTION
		"UnitCheck"
	LANGUAGES
		C
)

add_compile_options(-Wall -Wextra -pedantic)

set(CMAKE_INSTALL_PREFIX /usr CACHE PATH "Install path prefix." FORCE)

add_library(${PROJECT_NAME} SHARED
	src/uc.c
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

include_directories(
	include
)

install(DIRECTORY include/unit-check/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/unit-check FILES_MATCHING PATTERN "*.h")
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

add_custom_target(uninstall COMMAND rm -rf ${CMAKE_INSTALL_PREFIX}/include/unit-check; rm -rf ${CMAKE_INSTALL_PREFIX}/lib/libunit-check*)
