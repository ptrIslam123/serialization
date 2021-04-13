#include "math.h"
//#define DEBUG_MATH


point2D_t*  
make_point2D(int x, int y)
{
    point2D_t* p = malloc(sizeof(point2D_t));
    
    p->x_ = x;
    p->y_ = y;

    return p;
}


vector_t*   
make_vector(int* data, unsigned int size)
{
    vector_t* v = malloc(sizeof(vector_t));
    v->points_  = malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i)
    {
        v->points_[i] = data[i];
    }

    v->size_ = size;

    return v;
}




void        
print_point2D(const char* msg, point2D_t* p)
{
    if (p == NULL)
        return;

    printf("%s = {x_ = %d\ty_ = %d}\n\n", msg, p->x_, p->y_);
}


void
print_vector(const char* msg, vector_t* v)
{
    if (v == NULL)
        return;

    printf("%s = {", msg);
    for (int i = 0; i < v->size_; ++i)
    {
        printf(" %d ", v->points_[i]);
    }
    printf("}\n\n");
}


void       
write_point2D_to_file(FILE* file, point2D_t* p)
{
    int32_t x = htonl( convert_to_int32(p->x_) );
    int32_t y = htonl( convert_to_int32(p->y_) );

    fwrite(&x, sizeof(int32_t), 1, file);
    fwrite(&y, sizeof(int32_t), 1, file);
}


void        
read_point2D_from_file(FILE* file, point2D_t** p)
{
    int32_t x = 0;
    int32_t y = 0;

    fread(&x, sizeof(int32_t), 1, file);
    fread(&y, sizeof(int32_t), 1, file);

    x = ntohl(x);
    y = ntohl(y);

    *p = make_point2D(convert_to_int(x), convert_to_int(y));

    #ifdef DEBUG_MATH
    printf("\t\t__begin_debug__:\n");
    printf("x = %d\ny = %d\n", x, y);
    printf("\t\t__end_debug__\n");
    #endif // !DEBUG_MATH
}  


void        
write_vector_to_file(FILE* file, vector_t* v)
{
    int32_t size    = htonl( convert_to_int32(v->size_) );
    int32_t* points = convert_to_int32_array(v->points_, v->size_);

    fwrite(&size, sizeof(int32_t), 1, file);
    fwrite(points, sizeof(int32_t), size, file);
}


void        
read_vector_from_file(FILE* file, vector_t** v)
{
    int32_t size    = 0;
    int32_t* points = NULL;

    fread(&size, sizeof(int32_t), 1, file);
    
    size            = ntohl(size);
    points          = malloc(sizeof(int32_t) * size);

    fread(points, sizeof(int32_t), size, file);

    *v = make_vector(
        convert_to_int_array(points, size),
        convert_to_int(size)
    );

    #ifdef DEBUG
    printf("\t\t__begin_debug__:\n");
    for (int32_t i = 0; i < size; ++i)
    {
        printf("points[%d] = %d\n", i, points[i]);
    }
    printf("\t\t__end_debug__\n");
    #endif // DEBUG

    free(points);
    points = NULL;
}



int*        
convert_to_int_array(int32_t* arr, uint32_t size)
{
    int* new_arr = malloc(sizeof(int) * convert_to_int(size));

    for (int i = 0; i < convert_to_int(size); ++i)
    {
        new_arr[i] = ntohl( convert_to_int(arr[i]) );
    }

    return new_arr;
}


int32_t*     
convert_to_int32_array(int* arr, unsigned int size)
{
    int32_t* new_arr = malloc(sizeof(int32_t) * size);

    for (int i = 0; i < size; ++i)
    {
        new_arr[i] = htonl( convert_to_int32(arr[i]) );
    }

    return new_arr;
}


inline
int32_t     
convert_to_int32(int val)
{
    return (int32_t)val;
}


inline
int         
convert_to_int(int32_t val)
{
    return (int)val;
}
