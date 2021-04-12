#ifndef _MATH_H_
#define _MATH_H_

#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdint.h>

typedef struct point2D
{
    int             x_;
    int             y_;

} point2D_t;


typedef struct vector
{
    int*            points_;
    unsigned int    size_;

} vector_t;


point2D_t*  make_point2D(int x, int y);
vector_t*   make_vector(int* data, unsigned int size);

void        print_point2D(const char* msg, point2D_t* p);
void        print_vector(const char* msg, vector_t* v);

void        write_point2D_to_file(FILE* file, point2D_t* p);
void        read_point2D_from_file(FILE* file, point2D_t** p);

void        write_vector_to_file(FILE* file, vector_t* v);
void        read_vector_from_file(FILE* file, vector_t** v);

int32_t     convert_to_int32(int val);
int         convert_to_int(int32_t val);
int*        convert_to_int_array(int32_t* arr, uint32_t size);
int32_t*    convert_to_int32_array(int* arr, unsigned int size);

#endif // !_MATH_H_
