//writes a given binary stream to the given file
void writeText(char* fname, char* buffer) {
    FILE* iter= fopen(fname,"wb");
    fwrite(buffer,1,sizeof(buffer),iter);
    fclose(iter);
}