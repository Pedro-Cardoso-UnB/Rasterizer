#define MAX_DIMENSION 3
#include<iostream>
#include<string> 

class Vector{
    public:
        int coords [MAX_DIMENSION];
        std::string label;
        Vector(int inputcoord0, int inputcoord1, std::string inputlabel = ""){
            coords[0] = inputcoord0;
            coords[1] = inputcoord1;
            label = inputlabel;
        }
        Vector scale_by(int scalar, Vector target);
};