CMAKE_MINIMUM_REQUIRED (VERSION 3.22)
PROJECT (raylib-game)

# replace 4.2.0 with raylib version you wanna use
SET (RAYLIB_VERSION 4.2.0)

FIND_PACKAGE (raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
IF (NOT raylib_FOUND) # If there's none, fetch and build raylib
    INCLUDE (FetchContent)
    FETCHCONTENT_DECLARE (
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FETCHCONTENT_GETPROPERTIES (raylib)
    IF (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        SET (FETCHCONTENT_QUIET NO)
        FETCHCONTENT_POPULATE (raylib)
        SET (
            BUILD_EXAMPLES
            OFF
            CACHE BOOL "" FORCE) # don't build the supplied examples
        ADD_SUBDIRECTORY (${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    ENDIF ()
ENDIF ()

SET (CMAKE_SHARED_LINKER_FLAGS
     "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

FILE (GLOB GAME_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
ADD_LIBRARY (
    ${PROJECT_NAME} SHARED
    ${GAME_SOURCES})
TARGET_LINK_LIBRARIES (${PROJECT_NAME} raylib)
