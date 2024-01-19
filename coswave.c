#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int length, status, i;
    short int *x;
    float freq;
    double arg, twopi;
    FILE *file_id;

    length = 8000;
    freq = 0.025;
    twopi = 8.0 * atan(1.0);
    arg = twopi * freq;

    x = (short int *) calloc(length, sizeof(short int));
    if(!x) {
        printf("Unable to allocate space for samples\n");
        exit(1);
    }

    for(i=0; i<length; i++)
        x[i] = (short int) 32000 * cos(i*arg);

    file_id = fopen("cosine.dat", "wb");
    
    if(file_id == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    status = fwrite(x, sizeof(short int), length, file_id);
    
    if(status < length) {
        printf("Unable to write all samples\n");
        exit(1);
    }

    fclose(file_id);
    return 0;
}