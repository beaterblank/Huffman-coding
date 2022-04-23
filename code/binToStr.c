char* concat(char binary[],int length,int times,char ch){
    char* temp = (char*)malloc(sizeof(char)*(length+times));
    strcpy(temp,binary);
    for(int i=0;i<times;i++)strncat(temp,&ch,1);
    return temp;
}   

int getExtra(int length){return 8*((length/8)+1)-length;}

char* check(char binary[],int length){
    if(length%8!=0)return concat(binary,length,getExtra(length),'0');
    return binary;
}

int binDec(char binary[],int from,int to)
{
    if(to-from!=7)return -1;
	int decimal = 0;
	int position = 0;
	int index = to;
	while (index >= from)
	{
		decimal = decimal + (binary[index] - 48) * pow(2, position);
		index--;
		position++;
	}
	return decimal;
}

char* bin_str(char binary[],int length){
    char *bin = check(binary,length);
    length = getExtra(length)+length;
    
    int from = 0;
    int to = 7;
    
    char *ret = (char*)malloc(sizeof(char)*((length/8)));
    
    while(to<length){
        char ch = (char)binDec(bin,from,to);
        strncat(ret,&ch,1);
        from+=8;
        to+=8;
    }
    return ret;
}