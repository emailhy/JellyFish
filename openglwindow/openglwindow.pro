QT       += core gui opengl
TEMPLATE = app

SOURCES += \
    main.cpp \
    openglwindow.cpp \
    trianglewindow.cpp

HEADERS += openglwindow.h \
           trianglewindow.h

OTHER_FILES += shaders/shader.frag \
               shaders/shader.vert

RESOURCES += openglwindow.qrc
