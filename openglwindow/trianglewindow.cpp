#include "trianglewindow.h"
#include <QtGui/QMatrix4x4>

#include <QtGui/QScreen>
#include <QtCore/qmath.h>

TriangleWindow::TriangleWindow()
    : m_program(0)
    , m_frame(0)
{
}
//! [4]
GLuint TriangleWindow::loadShader(GLenum type, const char *source)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, 0);
    glCompileShader(shader);
    return shader;
}

void TriangleWindow::initialize()
{
    QOpenGLShader *vshader1 = new QOpenGLShader(QOpenGLShader::Vertex, &m_program);
    vshader1->compileSourceFile(":/oglwindows/shaders/shader.vert");


    QOpenGLShader *fshader1 = new QOpenGLShader(QOpenGLShader::Fragment, &m_program);
    fshader1->compileSourceFile(":/oglwindows/shaders/shader.frag");

   // m_program.addShader(vshader1);
   // m_program.addShader(fshader1);
   // m_program.link();

    vertexAttr1 = m_program.attributeLocation("vVertex");
    /*QString fileName = QString("c:/images/target.jpg");
    QImage testimg(fileName);
    int texture_width = testimg.width();
    int texture_height = testimg.height();

    QOpenGLContext *ctx = QOpenGLContext::currentContext();
    Q_ASSERT(ctx != 0);

    glGenTextures(1, &textureID);
    ctx->functions()->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_width, texture_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, testimg.scanLine(0));

    matrixUniform1 = m_program.uniformLocation("matrix");
    textureUniform1 = m_program.uniformLocation("textureMap");

    vertices.clear();
    normals.clear();

    vertices << QVector2D(0.0, 0.0);
    vertices << QVector2D(1.0, 0.0);
    vertices << QVector2D(1.0, 1.0);
    vertices << QVector2D(0.0, 1.0);*/

}

void TriangleWindow::render()
{
    /*const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 modelview;
    modelview.rotate(0.0, 0.0f, 1.0f, 0.0f);
    modelview.rotate(0.0, 1.0f, 0.0f, 0.0f);
    modelview.rotate(0.0, 0.0f, 0.0f, 1.0f);
    modelview.scale(1.0);
    modelview.translate(0.0f, -0.2f, 0.0f);

    m_program.bind();
    QOpenGLContext *ctx = QOpenGLContext::currentContext();
    Q_ASSERT(ctx != 0);
    ctx->functions()->glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    m_program.setUniformValue(matrixUniform1, modelview);
    m_program.setUniformValue(textureUniform1, 0);

    m_program.setUniformValue("brightness", m_brightness);
    m_program.enableAttributeArray(vertexAttr1);
    //m_program.setUniformValue(textureMap1, GL_TEXTURE0);;
    m_program.setAttributeArray(vertexAttr1, vertices.constData());
    //m_program.setAttributeArray(normalAttr1, normals.constData());
    //glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    glDrawArrays(GL_QUADS, 0, 4);
    //m_program.disableAttributeArray(normalAttr1);
    m_program.disableAttributeArray(vertexAttr1);


    m_program.release();

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);*/

    ++m_frame;
}
//! [5]
