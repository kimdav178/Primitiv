//
// Created by david on 30.04.2020.
//

#ifndef PRIMITIV_KEYBOARD_H
#define PRIMITIV_KEYBOARD_H

#include <iostream>
#include "display.h"

void keyboard(unsigned char key, int x, int y) {

    if (key == 27) {  // Отмена выбора примитива
        s[n].f1 = false;
        s[n].f3 = false;
        s[n].p1 = false;
    }

    if (key == '1') {   // Выбор круга
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(0, 0);          //Создаём вектор так, чтобы круг нужного размера
            int mod = glutGetModifiers();   // нарисовался в центре
            if (mod == GLUT_ACTIVE_ALT) {
                s[n].f1 = false;
                s[n].f3 = false;
                s[n].p1 = true;
            } else {
                s[n].f1 = true;
                s[n].f3 = false;
                s[n].p1 = false;
            };
            s[n].p = new Circle(v, 0.05, 1, 0, 0);
        } else {
            n = n;
        };
    }

    if (key == '2') {   // Выбор треугольника
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(-0.1, -0.05);    // Создаём векторы так, чтобы треугольник нужного
            Vector2D u(0, 0.1);         // размера нарисовался в центре
            Vector2D w(0.1, -0.05);
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT) {
                s[n].f1 = false;
                s[n].f3 = false;
                s[n].p1 = true;
            } else {
                s[n].f1 = true;
                s[n].f3 = false;
                s[n].p1 = false;
            };
            s[n].p = new Triangle(v, u, w, 1, 0, 0);
        } else {
            n = n;
        };
    }

    if (key == '3') {   // Выбор квадрата
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(-0.1, 0.1);      // Создаём векторы так, чтобы квадрат нужного размера
            Vector2D u(0.1, 0.1);       // нарисовался в центре
            Vector2D w(0.1, -0.1);
            Vector2D z(-0.1, -0.1);
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT) {
                s[n].f1 = false;
                s[n].f3 = false;
                s[n].p1 = true;
            } else {
                s[n].f1 = true;
                s[n].f3 = false;
                s[n].p1 = false;
            };
            s[n].p = new Square(v, u, w, z, 1, 0, 0);
        } else {
            n = n;
        };
    }

    if (key == '4') {   // Выбор прямоугольника
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(-0.2,0.1);       // Создаём векторы так, чтобы прямоугольник нужного
            Vector2D u(0.2, 0.1);       // размера нарисовался в центре
            Vector2D w(0.2, -0.1);
            Vector2D z(-0.2, -0.1);
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT) {
                s[n].f1 = false;
                s[n].f3 = false;
                s[n].p1 = true;
            } else {
                s[n].f1 = true;
                s[n].f3 = false;
                s[n].p1 = false;
            };
            s[n].p = new Rectangle(v, u, w, z, 1, 0, 0);
        } else {
            n = n;
        };
    }

    if (key == '5') {   // Выбор пружины
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(0, -0.2);    // Создаём вектор так, чтобы пружина нужного размера
            Vector2D u(0, 0.2);   // нарисовалась в центре
            s[n].f1 = false;
            s[n].f3 = true;
            s[n].p1 = false;
            Spring d(v, u, 0.1, 5);
            s[n].g = d;
        } else {
            n = n;
        };
    }

    if (key == '6') {       // Выбор блока
        if ((!(s[n].f2)) && (!(s[n].f4)) && (!(s[n].p2))) {
            Vector2D v(0, 0.2);     // Создаём вектор так, чтобы блок нужного размера
            Vector2D u(0, -0.1);       // нарисовался в центре
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT) {
                s[n].f1 = false;
                s[n].f3 = false;
                s[n].p1 = true;
            } else {
                s[n].f1 = true;
                s[n].f3 = false;
                s[n].p1 = false;
            };
            s[n].p = new Block(v, u, 0.1, 1, 0, 0);
        } else {
            n = n;
        };
    }

    if (key == 'w') {     // Двигать примитив вверх
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionUp(0.01f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.moveUp(0.01);
            } else {
                n = n;
            }
        };
    }

    if (key == 'a') {     // Двигать примитив влево
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionLeft(0.01f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.moveLeft(0.01);
            } else {
                n = n;
            }
        };
    }

    if (key == 's') {     // Двигать примитив вниз
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionDown(0.01f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.moveDown(0.01);
            } else {
                n = n;
            }
        };
    }

    if (key == 'd') {     // Двигать примитив вправо
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionRight(0.01f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.moveRight(0.01);
            } else {
                n = n;
            }
        };
    }

    //if ((key == 'r') && ((s[n].f) || (s[n].f2))) {    // Вращать примитив
    //    s[n].p.rotate(0.5f);
    //}

    if (key == '=') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeSize(1.1f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeSize(1.1);
            } else {
                n = n;
            }
        };
    }

    if (key == '7') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeHeight(1.1f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeHeight(1.1);
            } else {
                n = n;
            }
        };
    }

    if (key == '8') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeHeight(0.9f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeHeight(0.9);
            } else {
                n = n;
            }
        };
    }

    if (key == '9') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeWidth(1.1f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeWidth(1.1);
            } else {
                n = n;
            }
        };
    }

    if (key == '0') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeWidth(0.9f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeWidth(0.9);
            } else {
                n = n;
            }
        };
    }

    if (key == '-') {       // Уменьшить примитив в 10/9 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeSize(0.9f);
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.changeSize(0.9);
            } else {
                n = n;
            }
        };
    }

    if (key == 32) {       // Установить примитив или пружину
        if ((s[n].f1) || (s[n].f2)) {
            s[n].p->setColor(0, 0, 0);
            s[n].f1 = false;
            s[n].f2 = true;
            n++;
        } else {
            if ((s[n].f3) || (s[n].f4)) {
                s[n].g.setColor(0, 0, 0);
                s[n].f3 = false;
                s[n].f4 = true;
                n++;
            } else {
                if ((s[n].p1) || (s[n].p2)) {
                    s[n].p->setColor(0, 0, 0);
                    s[n].p1 = false;
                    s[n].p2 = true;
                    n++;
                } else {
                    n++;
                };
            };
        };
    };

    if (key == 127) {       // Удалить примитив или пружину
        s[n].f1 = false;
        s[n].f2 = false;
        s[n].f3 = false;
        s[n].f4 = false;
        s[n].p1 = false;
        s[n].p2 = false;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}

void special(int a, int x, int y) {
    if (a == GLUT_KEY_F1) {
        if (q) {
            q = false;
        } else {
            q = true;
        };
    }

    if (a == GLUT_KEY_RIGHT) {   // Выбрать следующий примитив
        if (s[n].f1) {
            s[n].f1 = false;
        };
        if (s[n].f3) {
            s[n].f3 = false;
        };
        if (s[n].p1) {
            s[n].p1 = false;
        };
        if (n<99) {
            n++;
        }
        else {
            n=0;
        };
    };

    if (a == GLUT_KEY_LEFT) {    // Выбрать предыдущий примитив
        if (s[n].f1) {
            s[n].f1 = false;
        };
        if (s[n].f3) {
            s[n].f3 = false;
        };
        if (s[n].p1) {
            s[n].p1 = false;
        };
        if (n>0) {
            n--;
        }
        else {
            n=99;
        };
    };

    if (a == GLUT_KEY_END) {    // Сбросить выбор
        n=100;
    }

    glutPostRedisplay(); //а это просто обязательная функция
}

#endif //PRIMITIV_KEYBOARD_H
