#include "huffman.c"
#include "binToStr.c"

int search(Hnode* tree,char ch,int count){
    if(tree){
        if(tree->c.charecter==ch)return (count==0)?1:count;
        int l =  search(tree->left,ch,count+1);
        int r =  search(tree->right,ch,count+1);
        return (l>r)?l:r; 
    }
    return 0;
}

void binstream(Hnode* tree,char ch,char* bin){
    if(tree && search(tree->left,ch,0)){
        strcat(bin,"0");
        //printf("left\n");
        binstream(tree->left,ch,bin);
    }
    if(tree && search(tree->right,ch,0)){
        strcat(bin,"1");
        //printf("right\n");
        binstream(tree->right,ch,bin);
    }
}   

char* charFromTree(Hnode* tree,char ch){
    int l = search(tree,ch,0);
    if(l>0){
        char* bin = (char*)malloc(sizeof(char)*(l-1));
        binstream(tree,ch,bin);
        // printf("\nfinding %c : ",ch);
        // printf("\npath is :%s",bin);
        // printf("\nchar encode is : %s\n",bin_str(bin,l));
        return bin_str(bin,l);
    }
    return NULL;
}

int getSize(Hnode* tree,char* str,long int length){
    int ret = 0;
    for(long int i=0;i<length;i++){
        int s=search(tree,str[(int)i],0);
        if(s>0){
            ret+= (s-1);
        }
    }
    return ret;
}

char* getbin(Hnode* tree,char* str,long int length){
    char* bin = (char*)malloc(sizeof(char)*(int)length);
    for(int i = 0;i<(int)length;i++){
        char ch = str[i]; 
        int l = search(tree,ch,0);
        char* cbin = (char*)malloc(sizeof(char)*(l-1));
        binstream(tree,ch,cbin);
        strcat(bin,cbin);
    }
    return bin_str(bin,strlen(bin));
}
