#include <stdio.h>
#include<string.h>

int main(void){
    char a[4] = {'a','b','c','d'};
    char b[4] = {0};
    char * s = "(u(love)i)";
    char s2[] = "(u(love)i)";
    char * str = "ulovei";
    char s1[] = "ulovei";
    char * s3[] = {"abcdef"};
    // printf("%ld %ld\n",sizeof(a),sizeof(b)); // 64位的机器，地址用8个字节表示
    // printf("%ld %ld\n",strlen(a),strlen(b));
    // printf("%ld\n",sizeof(long));
    // printf("%ld  %ld\n",sizeof(float),sizeof(double));
    printf("sizeof(s[0]) = %ld\n",sizeof(s[0])); // s[0]为字符串中第一个元素，为char 类型，占1个字节
    printf("sizeof(s)/sizeof(s[0]) = %ld\n",sizeof(s)/sizeof(s[0]));
    printf("sizeof(s) = %ld\n",sizeof(s)); // s为char *类型的指针变量，在64位机器上占8个字节
    printf("sizeof(s2) = %ld\n",sizeof(s2));    
    printf("strlen(s) = %ld\n",strlen(s));

    printf("sizeof(str) = %ld\n",sizeof(str));
    printf("sizeof(s1) = %ld\n",sizeof(s1)); 
    printf("strlen(s1) = %ld\n",strlen(s1)); 
    printf("sizeof(*s3) = %ld\n",sizeof(*s3));  // *s3为s3数组的第一个元素，而s3数组每个元素的类型为char *类型
                                               // *s3本质为char * ,是一个指针变量，指向s3数组的第一个元素
    return 0;
}

/*在VScode中的输出：
sizeof(s[0]) = 1
sizeof(s)/sizeof(s[0]) = 8
sizeof(s) = 8
sizeof(s2) = 11
strlen(s) = 10
sizeof(str) = 8
sizeof(s1) = 7
strlen(s1) = 6
sizeof(*s3) = 8
总结：
sizeof 用来求数据类型或变量所占的内存大小，单位为字节
strlen计算字符串长度，不包括字符串结束符\0
*/
