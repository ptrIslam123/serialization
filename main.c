#include <stdio.h>
#include "serialization/math.h"


int data[]          = {1, 2, 3};
const int size_data = sizeof(data)/ sizeof(data[0]);
const char* fname   = "data.txt";

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
        
        fclose(file);
    }
    else
    {   
        printf("main is not hav input valid argument!\n");
        return -1;
    }
    
    return 0;
}