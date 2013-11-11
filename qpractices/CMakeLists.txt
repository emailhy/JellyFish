find_package(Qt5Widgets)
find_package(Qt5OpenGL)
find_package(OpenGL)

set (SRCS main.cpp
          openglwindow.cpp
          )
set (HDRS openglwindow.h)

#set (UIS )
		  
#qt5_wrap_ui(UI_FORMS ${UIS})
# Tell CMake to create the helloworld executable
add_executable(qpractice0001 ${SRCS} ${HDRS} ${UI_FORMS})

# Use the Widgets module from Qt 5.
target_link_libraries(qpractice0001 Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES})