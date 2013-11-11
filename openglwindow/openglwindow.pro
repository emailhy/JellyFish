QT       += core gui opengl
TEMPLATE = app

SOURCES += \
    main.cpp \
    openglwindow.cpp

HEADERS += openglwindow.h

OTHER_FILES += shaders/shader.frag \
               shaders/shader.vert

RESOURCES += openglwindow.qrc
