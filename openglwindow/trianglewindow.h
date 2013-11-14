
#include "openglwindow.h"
#include <QtGui/QOpenGLShaderProgram>

class TriangleWindow : public OpenGLWindow
{
public:
    TriangleWindow();

    void initialize();
    void render();

private:
    GLuint loadShader(GLenum type, const char *source);

    QVector<QVector3D> vertices;
    QVector<QVector3D> normals;

    int vertexAttr1;
    int textureMap1;
    int matrixUniform1;
    int textureUniform1;
    GLuint textureID;
    float m_brightness;

    QOpenGLShaderProgram m_program;
    int m_frame;
};

