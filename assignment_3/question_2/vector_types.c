#include "vector_types.h"

int main() {
    Vector2F v2test = {42, 23}; 
    Vector2F v2test2 = {24, 66};

    Vector3F v3test = {83, 33, 43}; 
    Vector3F v3test2 = {54, 23, 11};

    Vector4F v4test = {76, 57, 44, 12}; 
    Vector4F v4test2 = {14, 56, 94, 7};

    printf("For vector2F...\n");
    SumVector2(v2test, v2test2);
    MultipyVector2(v2test, 3);
    printf("\n\n");

    printf("For vector3F...\n");
    SumVector3(v3test, v3test2);
    MultipyVector2(v3test, 2);
    printf("\n\n");

    printf("For vector4F...\n");
    SumVector4(v4test, v4test2);
    MultipyVector2(v4test, 4);
    printf("\n\n");
}