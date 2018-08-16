#include <iostream>
#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Light.h"

int Light::getNum(){
    return _num;
}

void Light::setNum(int x){
    _num = x;
}
