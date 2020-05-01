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
#include "keyboard.h"
#include "display.h"
using namespace std;

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