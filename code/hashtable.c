#define SIZE 256
int freq[SIZE];
void insert(char str[])
{
    // size of the string 'str'
    int n = strlen(str);
    // initialize all elements of freq[] to 0
    memset(freq, 0, sizeof(freq));
    // accumulate frequency of each character in 'str'
    for (int i = 0; i < n; i++)freq[(int)str[i]]=freq[(int)str[i]]+1;
}
