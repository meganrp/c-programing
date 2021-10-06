#ifndef VECTORTYPES_H
#define VECTORTYPES_H

#include <stdio.h>

typedef float Vector2F[2];
typedef float Vector3F[3];
typedef float Vector4F[4];


void SumVector2(Vector2F v1, Vector2F v2) {

    Vector2F sum = {(v1[0] + v2[0]), (v1[1] + v2[1])};
    printf("[%f, %f] + [%f, %f] = [%f, %f]\n\n", v1[0], v1[1], v2[0], v2[1], sum[0], sum[1]);
}

void SumVector3(Vector3F v1, Vector3F v2) {

    Vector3F sum = {(v1[0] + v2[0]), (v1[1] + v2[1]), (v1[2] + v2[2])};
    printf("[%f, %f, %f] + [%f, %f, %f] = [%f, %f, %f]\n\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2], sum[0], sum[1], sum[2]);
}

void SumVector4(Vector4F v1, Vector4F v2) {

    Vector4F sum = {(v1[0] + v2[0]), (v1[1] + v2[1]), (v1[2] + v2[2]), (v1[3] + v2[3])};
    printf("[%f, %f, %f, %f] + [%f, %f, %f, %f] = [%f, %f, %f, %f]\n\n", v1[0], v1[1], v1[2], v1[3], v2[0], v2[1], v2[2], v2[3], sum[0], sum[1], sum[2], sum[3]);
}

void MultipyVector2(Vector2F v1, float multi) {

    Vector2F product = {(v1[0] * multi), (v1[1] * multi)};
    printf("%f * [%f, %f] = [%f, %f]\n\n", multi, v1[0], v1[1], product[0], product[1]);
}

void MultipyVector3(Vector3F v1, float multi) {
    
    Vector3F product = {(v1[0] * multi), (v1[1] * multi), (v1[2] * multi)};
    printf("%f * [%f, %f, %f] = [%f, %f, %f]\n\n", multi, v1[0], v1[1], v1[2], product[0], product[1], product[2]);
}

void MultipyVector4(Vector4F v1, float multi) {
    
    Vector4F product = {(v1[0] * multi), (v1[1] * multi), (v1[2] * multi), (v1[2] * multi)};
    printf("%f * [%f, %f, %f, %f] = [%f, %f, %f, %f]\n\n", multi, v1[0], v1[1], v1[2], v1[3], product[0], product[1], product[2], product[3]);
}

#endif 


