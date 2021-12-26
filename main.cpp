#include <windows.h>
#include <GL/glut.h>

    //Initializes 3D rendering (memberikan inisialisai 3D)
    void initRendering() {
     glEnable(GL_DEPTH_TEST); //metode hidden_surface removal untuk mengatur sudut pandang kapan suatu objek tertutup dengan objek lain
     glEnable(GL_COLOR_MATERIAL); //
     glEnable(GL_LIGHTING); //Enable lighting
     glEnable(GL_LIGHT0); //Enable light #0
     glEnable(GL_LIGHT1); //Enable light #1
     glEnable(GL_NORMALIZE); //Automatically normalize normals
     glShadeModel(GL_SMOOTH); //Enable smooth shading
    }

    //Called when the window is resized
    void handleResize(int w, int h) {
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
    }

    float _angle = -70.0f;

        //Draws the 3D scene
    void drawScene() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glMatrixMode(GL_MODELVIEW); // keep it like this
     glLoadIdentity();

     glTranslatef(0.0f, 0.0f, -14.0f);

     //Add ambient light
     GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
     glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

     //Add positioned light
     GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
     GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
     glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

     //Add directed light
     GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
     //Coming from the direction (-1, 0.5, 0.5)
     GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
     glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
     glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

     glRotatef(10, 1.0f, 0.0f, 0.0f);
     glRotatef(-10, 0.0f, 0.0f, 1.0f);
     glRotatef(_angle,0.0f, 1.0f, 0.0f);
     //glRotatef(10, 1.0f, 0.0f, 0.0f);
     //glRotatef(-10, 0.0f, 0.0f, 1.0f);
     //glRotatef(_angle,0.0f, 1.0f, 0.0f);
      glColor3f(1.1f, 1.1f, 1.1f);

     glBegin(GL_QUADS);

     //Front sisi depan
     glNormal3f(0.0f, 0.0f, 1.0f);
     glVertex3f(-2.0f, -0.1f, 2.0f);
     glVertex3f(2.0f, -0.1f, 2.0f);
     glVertex3f(2.0f, 0.2f, 2.0f);
     glVertex3f(-2.0f, 0.2f, 2.0f);

     //Right sisi kanan
     glNormal3f(1.0f, 0.0f, 0.0f);
     glVertex3f(2.0f, -0.1f, -2.0f);
     glVertex3f(2.0f, 0.2f, -2.0f);
     glVertex3f(2.0f, 0.2f, 2.0f);
     glVertex3f(2.0f, -0.1f, 2.0f);

     //Back sisi belakang
     glNormal3f(0.0f, 0.0f, -1.0f);
     glVertex3f(-2.0f, -0.1f, -2.0f);
     glVertex3f(-2.0f, 0.2f, -2.0f);
     glVertex3f(2.0f, 0.2f, -2.0f);
     glVertex3f(2.0f, -0.1f, -2.0f);
