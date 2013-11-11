/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the documentation of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "openglwindow.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>

#include <QtCore/qmath.h>

//! [1]
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

TriangleWindow::TriangleWindow()
    : m_program(0)
    , m_frame(0)
{
}
//! [1]

//! [2]
int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(0);

    TriangleWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimating(true);

    return app.exec();
}
//! [2]


//! [3]
static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = colAttr;\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";
//! [3]

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
    /*const char *vsrc1 =
        "attribute highp vec4 vertex;\n"
        "attribute mediump vec3 normal;\n"
        "uniform mediump mat4 matrix;\n"
        "varying mediump vec4 color;\n"
        "void main(void)\n"
        "{\n"
        "    vec3 toLight = normalize(vec3(0.0, 0.3, 1.0));\n"
        "    float angle = max(dot(normal, toLight), 0.0);\n"
        "    vec3 col = vec3(0.40, 1.0, 0.0);\n"
        "    color = vec4(col * 0.2 + col * 0.8 * angle, 1.0);\n"
        "    color = clamp(color, 0.0, 1.0);\n"
        "    gl_Position = matrix * vertex;\n"
        "}\n";
    vshader1->compileSourceCode(vsrc1);*/

    QOpenGLShader *fshader1 = new QOpenGLShader(QOpenGLShader::Fragment, &m_program);
    fshader1->compileSourceFile(":/oglwindows/shaders/shader.frag");
    /*const char *fsrc1 =
        "varying mediump vec4 color;\n"
        "void main(void)\n"
        "{\n"
        "    gl_FragColor = color;\n"
        "}\n";
    fshader1->compileSourceCode(fsrc1);*/

    m_program.addShader(vshader1);
    m_program.addShader(fshader1);
    m_program.link();

    vertexAttr1 = m_program.attributeLocation("vVertex");
    QString fileName = QString("c:/images/target.jpg");
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
    vertices << QVector2D(0.0, 1.0);

}
//! [4]

//! [5]
void TriangleWindow::render()
{
    const qreal retinaScale = devicePixelRatio();
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
    glDisable(GL_CULL_FACE);

    ++m_frame;
}
//! [5]
