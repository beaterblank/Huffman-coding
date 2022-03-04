//returns number of charecters in a text file
long int findSize(char* fname)
{
    FILE* iter = fopen(fname,"rb"); ;
    fseek(iter, 0L, SEEK_END);
    long int res = ftell(iter);
    fclose(iter);
    return res;
}
  