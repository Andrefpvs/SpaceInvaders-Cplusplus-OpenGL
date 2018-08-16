#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Camera.h"

int Camera::getNum(){
    return _num;
}

void Camera::setNum(int x){
    _num = x;
}
