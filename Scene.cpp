#include <QDebug>
#include "Scene.h"

Scene::Scene( QWidget *parent ) :
    QGLWidget( parent ),
    m_i( 0 )
{
    this->setFocusPolicy( Qt::StrongFocus );

    connect( &m_timer, SIGNAL( timeout() ),
             this, SLOT( slotUpdate() ) );
    m_timer.start( 50 );
}

void Scene::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void Scene::paintGL()
{
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );

    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 0.0f, 1.0f, 0.0f );

    glBegin( GL_LINES );
    glVertex2f( -50.0f + ( GLfloat ) m_i, -50.0f ); glVertex2f( 50.0f, 50.0f );
    glEnd();
}

void Scene::resizeGL( int w, int h )
{
    // Set Viewport to window dimensions
    glViewport( 0, 0, w, h );

    // Reset coordinate system
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    glOrtho( -100.0, 100.0, -100, 100.0, 1.0, -1.0);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void Scene::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() ) {
        case Qt::Key_Up:
            qDebug() << "Up";
            break;
        case Qt::Key_Down:
            qDebug() << "Down";
            break;
        case Qt::Key_Right:
            qDebug() << "Right";
            break;
        case Qt::Key_Left:
            qDebug() << "Left";
            break;
    }

    updateGL();
}

void Scene::slotUpdate()
{
    ++m_i;
    updateGL();
}
