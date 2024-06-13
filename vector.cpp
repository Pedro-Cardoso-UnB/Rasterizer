#include<./vector.h>

Vector scale_by(int scalar, Vector target){
    Vector result(target.coords[0]*scalar, target.coords[1]*scalar, target.label);
    return result;
}