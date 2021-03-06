if(NOT EGL_PACKAGE_DIR)
	message("ERROR: EGL_PACKAGE_DIR requires to be set")
endif(NOT EGL_PACKAGE_DIR)

if(MSVC AND NOT CMAKE_CL_64)
	set(BINARY_DIRECTORY "win32")
endif(MSVC AND NOT CMAKE_CL_64)

if(MSVC AND CMAKE_CL_64)
	set(BINARY_DIRECTORY "win64")
endif(MSVC AND CMAKE_CL_64)

set(EGL_INCLUDE_DIR ${EGL_PACKAGE_DIR}/egl)

set(EGL_LIBRARY_DIR ${EGL_PACKAGE_DIR}/lib/${BINARY_DIRECTORY})
set(EGL_FOUND "YES")

set(EGL_LIBRARY libEGL)

include_directories(${EGL_INCLUDE_DIR})
link_directories(${EGL_LIBRARY_DIR})
