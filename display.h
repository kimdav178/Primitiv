//
// Created by david on 30.04.2020.
//

#ifndef PRIMITIV_DISPLAY_H
#define PRIMITIV_DISPLAY_H

#include <iostream>
#include <cstdio>

struct stru {
    bool f1 = false;     // Выбор примитива
    bool f2  = false;    // Вставка примитива
    bool f3 = false;    // Выбор пружины
    bool f4 = false;    // Вставка пружины
    bool p1 = false;    // Выбор полигона
    bool p2 = false;    // Вставка полигона
    Primitiv* p;    // Указатель на примитивы
    Spring g;   // Пружина
};
stru s[100];    // Создаём массив таких структур
unsigned int n=0;   // Текущий элемент массива
bool q = false;
char text[10] = {0};

void renderBitmapString(
        float x,
        float y,
        void *font,
        char *string) {

    char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(10);
    glColor3d(0,0,0);
    renderBitmapString(-0.95,0.9,GLUT_BITMAP_TIMES_ROMAN_24, "F1 - Help");
    sprintf(&text[0],"%u", n);
    renderBitmapString(0.95,0.9,GLUT_BITMAP_TIMES_ROMAN_24, text);
    for (unsigned int i=0; i<100; i++) {
        if (q) {
            glColor3d(0,0,0);
            renderBitmapString(-0.95,0.8,GLUT_BITMAP_TIMES_ROMAN_24, "1 - select a circle");
            renderBitmapString(-0.95,0.7,GLUT_BITMAP_TIMES_ROMAN_24, "2 - select a triangle");
            renderBitmapString(-0.95,0.6,GLUT_BITMAP_TIMES_ROMAN_24, "3 - select a square");
            renderBitmapString(-0.95,0.5,GLUT_BITMAP_TIMES_ROMAN_24, "4 - select a rectangle");
            renderBitmapString(-0.95,0.4,GLUT_BITMAP_TIMES_ROMAN_24, "5 - select a spring");
            renderBitmapString(-0.95,0.3,GLUT_BITMAP_TIMES_ROMAN_24, "6 - select a block");
            renderBitmapString(-0.95,0.2,GLUT_BITMAP_TIMES_ROMAN_24, "ALT + NUMBER - select a painted figure");
            renderBitmapString(-0.95,0.1,GLUT_BITMAP_TIMES_ROMAN_24, "Esc - cancel choice");
            renderBitmapString(-0.95,0.0,GLUT_BITMAP_TIMES_ROMAN_24, "'7' - '=' - change scale");
            renderBitmapString(-0.95,-0.1,GLUT_BITMAP_TIMES_ROMAN_24, "W, A, S, D - move figure");
            renderBitmapString(-0.95,-0.2,GLUT_BITMAP_TIMES_ROMAN_24, "Space - set figure");
            renderBitmapString(-0.95,-0.3,GLUT_BITMAP_TIMES_ROMAN_24, "Delete - delete figure");
            renderBitmapString(-0.95,-0.4,GLUT_BITMAP_TIMES_ROMAN_24, "Left, right - switch between figures");
            renderBitmapString(-0.95,-0.5,GLUT_BITMAP_TIMES_ROMAN_24, "Press F1 again to close the info");
        };

        if ((s[i].f2) || (s[i].f1)) {
            glBegin(GL_LINE_LOOP);
            if (i == n) {   // Если объект выбран, рисуем его красным
                s[i].p->setColor(1.0f, 0.0f, 0.0f);
                s[i].p->paintLines();
            } else {
                s[i].p->setColor(0,0,0);
                s[i].p->paintLines();   // Если уже нарисован, оставляем, как есть
            }
            glEnd();
        };

        if ((s[i].f4) || (s[i].f3)) {      // То же самое с пружиной
            glBegin(GL_LINE_LOOP);
            if (i == n) {
                s[i].g.setColor(1.0f, 0.0f, 0.0f);
                s[i].g.paintVertic();
            } else {
                s[i].g.setColor(0,0,0);
                s[i].g.paintVertic();
            };
            glEnd();
        };

        //if (s[i].f1) {   // Если объект выбран, рисуем его красным
        //    glBegin(GL_LINE_LOOP);
        //    s[i].p->setColor(1.0f, 0.0f, 0.0f);
        //    s[i].p->paintLines();
        //    glEnd();
        //};

        //if (s[i].f3) {      // То же самое с пружиной
        //    glBegin(GL_LINE_LOOP);
        //    s[i].g.setColor(1.0f, 0.0f, 0.0f);
        //    s[i].g.paintVertic();
        //   glEnd();
        //};

        if ((s[i].p2) || (s[i].p1)) {
            glBegin(GL_POLYGON);
            if (i == n) {   // Если объект выбран, рисуем его красным
                s[i].p->setColor(1.0f, 0.0f, 0.0f);
                s[i].p->paintPolygon();
            } else {
                s[i].p->setColor(0,0,0);
                s[i].p->paintPolygon();   // Если уже нарисован, оставляем, как есть
            }
            glEnd();
        };

        //if (s[i].p1) {   // Если объект выбран, рисуем его красным
        //    glBegin(GL_POLYGON);
        //    s[i].p->setColor(1.0f, 0.0f, 0.0f);
        //    s[i].p->paintPolygon();
        //    glEnd();
        //};
    }
    //glFlush();
    glutSwapBuffers();
};

#endif //PRIMITIV_DISPLAY_H
