#define SIZE 256
int freq[SIZE];
//insert a string into freq
void insert(char str[])
{
    int n = strlen(str);
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)freq[(int)str[i]]=freq[(int)str[i]]+1;
}
