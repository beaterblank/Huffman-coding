//reads the header part of the file (file should atleast be of size 512 bits)
unsigned short* readHeader(char* fname){
    FILE* iter = fopen(fname,"rb");
    unsigned short *buffer = (unsigned short *)malloc(sizeof(unsigned short *)*256);
    if(iter==NULL)return buffer;
    fread(buffer,sizeof(buffer),1,iter);
    fclose(iter);
    return buffer;
}
//reads the text in a text file
char* readText(char* fname,long int size){
    FILE* iter= fopen(fname,"rb");
    char *buffer = (char*)malloc(sizeof(char)*(int)size);
    if(iter==NULL)return buffer;
    fread(buffer,sizeof(buffer),1,iter);
    fclose(iter);
    return buffer;
}