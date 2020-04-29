#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char** split(const char* str, const char* delim)
{
    char* str1 = (char*)str;
    int length=0;
    int count=0;

    while (str1) {
        char*tmp=strstr(str1, delim);
        if (tmp){
            length=tmp-str1;
            str1+=length+strlen(delim);
        }
        else
            str1=NULL;
        count++;
    }
    printf("count %d\n", count);
    str1=(char*)str;

    char** result=(char**)calloc(count+1,sizeof(char*));
    result[count]=NULL;
    if (result){
        for (int i=0;i<count;++i){
            char* tmp=strstr(str1,delim);
            if (tmp)
                length=tmp-str1;
            else
                length=strlen(str1);
            result[i]=(char*)calloc(length, sizeof(char*));
            strncpy(result[i], str1, length);
            str1 += length + strlen(delim);
        }
    }

    return result;
}

void delete_string_array(char **str)
{
    int i=0;
    while (str[i]){
        free(str[i]);
        ++i;
    }
    free(str);
}
int main ()
{
    char stringIn [1024];
    scanf("%s",stringIn);
    char delim [1024];
    scanf("%s",delim);
    char** rezult;
    rezult=(char**)calloc(2050,sizeof(char));//точно хватит в расщеплЄнной строке остаЄт€ столько же элементов плюс если будут пробелы
    rezult=split(stringIn,delim);
    int i=0;
    while (rezult[i]) {
    printf("%s\n",rezult[i]);
        ++i;
    }

    delete_string_array(rezult);
    return 0;
}
