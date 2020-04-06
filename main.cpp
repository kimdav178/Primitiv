//
// Created by david on 01.04.2020.
//

#include <GL/glut.h>  //библиотека GLUT
#include "Circle.cpp"
#include "Rectangle.cpp"
#include "Spring.cpp"
#include "Square.cpp"
#include "Triangles.cpp"
#include "Block.cpp"
#include "Vector2D.h"
#include "Primitiv.h"
using namespace std;

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

    if ((key == 'w') || (key == 'ц')) {     // Двигать примитив вверх
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionUp(0.01f);
        } else {
            n = n;
        };
    }

    if ((key == 'a') || (key == 'ф')) {     // Двигать примитив влево
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionLeft(0.01f);
        } else {
            n = n;
        };
    }

    if ((key == 's') || (key == 'ы')) {     // Двигать примитив вниз
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionDown(0.01f);
        } else {
            n=n;
        };
    }

    if ((key == 'd') || (key == 'в')) {     // Двигать примитив вправо
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changePositionRight(0.01f);
        } else {
            n = n;
        };
    }

    //if ((key == 'r') && ((s[n].f) || (s[n].f2))) {    // Вращать примитив
    //    s[n].p.rotate(0.5f);
    //}

    if (key == '=') {       // Увеличить примитив в 1.1 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeSize(1.1f);
        } else {
            n = n;
        };
    }

    if (key == '-') {       // Уменьшить примитив в 10/9 раза
        if ((s[n].f1) || (s[n].f2) || (s[n].p1) || (s[n].p2)) {
            s[n].p->changeSize(0.9f);
        } else {
            n = n;
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLineWidth(10);
    for (unsigned int i=0; i<100; i++) {
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

void changeSize(int w, int h) {

    // предупредим деление на ноль
    // если окно сильно перетянуто будет
    if(h == 0)
        h = 1;
    float ratio = 1.0* w / h;

    // используем матрицу проекции
    glMatrixMode(GL_PROJECTION);

    // Reset матрицы
    glLoadIdentity();

    // определяем окно просмотра
    glViewport(0, 0, w, h);

    // установить корректную перспективу.
    gluPerspective(45.0f,ratio,0.1f,100.0f);

    // вернуться к модели
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //параметры окна(двойная буферизация и всё такое)
    glutInitWindowSize(1200, 800);  //это размеры окна
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Physics");  //это название создающегося окна
    glClearColor(1, 1, 1, 0);   //цвет фона
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-300, 300, -200, 200, -100, 100);
    //glEnable(GL_DEPTH_TEST);  //тест глубины или что-то такое
    //glEnable(GL_ALPHA_TEST); //включаем прозрачность
    //glEnable(GL_BLEND);  //разрешаем мешать цвета
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  //устанавдиваем уровень прозрачности - пока до конца не разобрался

    glutDisplayFunc(display);
    glutIdleFunc(display);
    //glutReshapeFunc(changeSize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMainLoop();
    return 1;
}