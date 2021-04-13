#include <stdio.h>
#include <stdlib.h>
#include "serialization/math.h"

int data[]          = {1, 2, 3, 45, 34, 567, 12, 34, 555, 67, 8};
const int size_data = sizeof(data)/ sizeof(data[0]);
const char* fname   = "data.txt";

unsigned int compare_two_array(int* arr1, int* arr2, unsigned int size)
{
    for (unsigned int i = 0; i < size; ++i)
    {
        if (arr1[i] != arr2[i])
            return 0;
    }

    return 1;
}

int main(int argc , char** argv)
{
    if (argv[1][0] == 'w')
    {
        FILE* file = fopen(fname, "wb");

        point2D_t* p    = make_point2D(rand() % 100, rand() % 10);
        vector_t* v     = make_vector(data, size_data);

        write_point2D_to_file(file, p);
        write_vector_to_file(file, v);

        print_point2D("write(p)", p);
        print_vector("write(v)", v);

        fclose(file);       
    }
    else if (argv[1][0] == 'r')
    {
        FILE* file = fopen(fname, "rb");

        point2D_t* p    = NULL;
        vector_t* v     = NULL;

        read_point2D_from_file(file, &p);
        read_vector_from_file(file, &v);

        print_point2D("read(p)", p);
        print_vector("read(v)", v);
        
        if (!compare_two_array(data, v->points_, size_data))
        {
            fprintf(stderr, "error of serialization struct point2D or/and vector\n");
            return -1;
        }

        fclose(file);
    }
    else
    {
        fprintf(stderr, "ERROR: this program dos not have [%c] argument!\n", argv[1][0]);
        return -1;
    }
      
    
    return 0;
}