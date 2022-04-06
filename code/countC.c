//dataStructure to store count of charecters;
typedef struct countC
{
    int charecter;
    int count;
}countC;

countC initCountC(int ch,int count){
    countC temp;
    temp.charecter = ch;
    temp.count = count;
    return temp; 
}