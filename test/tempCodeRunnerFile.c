char * trim(char * src){
    if(src == NULL || *src == '\0') return src;
    while(*src == ' ') src++;
    char * tail = src + strlen(src);
    while(*(--tail) == ' ')
        *(tail) = '\0';
    return src;
}
int main(void){
    char src[] = "  abc ";
    char * str = trim(src);
    printf("%s\n",str);
    return 0;
}