/* @date: 2021-07-02 21:50:25
@功能:
    memcpy底层实现
@目的:

*/


#include <stdio.h>
#include <stddef.h>

void * memcpy1(void * dest, void * src, size_t count){
    if((src == NULL)||(dest == NULL)) return NULL;
    char * d;
    char * s;
    // 目标地址与源地址没有重叠或者目标地址小于源地址
    if(dest > (src+count)||dest<src){
        d = dest;
        s = src;
        while(count--){
            *d++ = *s++; // 从低地址开始复制 

        }

    }
    // 有内存重叠，且目标地址 大于 源地址
    else{
        d = (char *)(dest+count-1);
        s = (char *)(src+count-1);
        while(count--){
            *d-- = *s--; // 从高地址开始复制
        }
    }
    return dest;
}
// 没有考虑目标地址 与 源地址 之间有重叠的情况
void * memcpy2(void * dest,void * src,unsigned int count){
    if((dest == NULL)||(src == NULL)){
        return NULL;
    }
    char * d = (char *)dest;
    char * s = (char *)src;
    while(count--){
        *d++ = *s++;
    }
    return dest;
}
// 初始化默认\0，\0的ASCII码为0
int main(void){
    char src1[] = "aabbcc";
    char src2[] = "aabbcc";
    char dest[100]={0};
    char * ptr = "hdafhahd";
    memcpy1(src1+2,src1,4);
    memcpy2(src2+2,src2,4);
    printf("%s\n",src1);
    printf("%s\n",src2);
    return 0;
}

/*@在VScode中的输出：
---------------------------------
aaaabb
aaaaaa
---------------------------------
@总结：

*/
