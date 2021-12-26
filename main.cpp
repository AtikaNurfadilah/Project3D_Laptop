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
