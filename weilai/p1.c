/* @date: 2021-07-03 20:42:37
@功能:
    删除给出字符串中重复出现的字符，输出删除后的字符串
@目的:

*/


#include <stdio.h>
#include <string.h>

char *  fun(char * old){
    int len = strlen(old); // strlen()能求出字符数组的长度，是根据字符串末尾的\0求出的
                            // 而对于普通数组没有\0结尾那么就无法准确算出字符串长度 
    //int len1  = sizeof(old)/sizeof(old[0]); // sizeof()求出字符指针变量所占的内存空间大小
                                            // 所以在64位机器上sizeof(old) = 8
                                            // old[0]为字符数组第一个元素，占1个字节，sizeof(old[0]) = 1
    //printf("fun = %d\n",len1);
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(old[i] == old[j]){
                for(int temp = j; temp < len; temp++){
                    old[temp] = old[temp+1];
                }
                j--; // 为了下一次循环，看新的字符串该位置old[j]是否仍是与old[i]相同的字符
                len--;
            }
        }
    }
    return old;

}
int main(void){
    char old[1024] = {0};
    scanf("%s",old);
    int len = sizeof(old)/sizeof(old[0]); // 数组名表示指针常量，在sizeof(old)表示整个数组所占的空间
    // char * p = old;
    // printf("p size = %ld\n",sizeof(p)); // p size = 8,sizeof(p)求出字符指针变量自身所占的内存
    printf("main = %d\n",len);
    printf("%s\n",old);
    printf("%s\n",fun(old));
    return 0;
}