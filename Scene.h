#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QKeyEvent>
#include <QTimer>

class Scene : public QGLWidget
{
    Q_OBJECT

public:
    Scene( QWidget *parent = 0 );

private slots:
    void slotUpdate();

private:
    void initializeGL();
    void paintGL();
    void resizeGL( int w, int h );

    void keyPressEvent( QKeyEvent *event );

private:
    int m_i;
    QTimer m_timer;
};

#endif // SCENE_H
