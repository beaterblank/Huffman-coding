#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "code/encode.c"

int main(){
    encode("test.txt","table.huff","output.huff");
    return 0;
}