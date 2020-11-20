#include "fchlib_string.h"
size_t fchlib_str_count(const char* str,const char* search) {
    size_t len = strlen(search);
    size_t occurrences = 0;
    char* inter = strstr(str,search);
    if (strlen(search)>0) {
        while (inter != (char*)NULL) {
            ++occurrences;
            inter = strstr(inter+len,search);
        }
    }
    return occurrences;
}
bool fchlib_str_contains(const char* self,const char* search) {
    return strstr(self,search) != (char*)NULL;
}
int fchlib_str_find(const char* str,const char* search) {
    char* index = strstr(str,search);
    if (index != (char*)NULL) {
        return fchlib_str_character_distance(str,index);
    }
    return -1;
}
size_t fchlib_str_character_distance(const char* start,const char* end) {
    unsigned distance = 0;
    const char* index;
    short increment = (start<=end)?1:-1;
    for (index=start; index!=end; index=index+increment) {
        ++distance;
    }
    return distance;
}
char* fchlib_str_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace) {
    size_t len = 0;
    size_t len_rm = strlen(str_rm);
    size_t size_new = 0;
    char* start = str;
    char* _new = (char*)NULL;
    char* inter = strstr(str,str_rm);
    if ((inter != (char*)NULL) && (strlen(str_rm)!=0)) {
        size_new = strlen(str)+fchlib_str_count(str,str_rm)*(strlen(str_new)-strlen(str_rm))+1;
        _new = (char*)calloc(size_new,1);
        if (maxreplace==0) {
            maxreplace = fchlib_str_count(str,str_rm)+1;
        }
        while (inter != (char*)NULL && maxreplace-->0) {
            len = fchlib_str_character_distance(start,inter);
            strncat(_new,start,len);
            strcat(_new,str_new);
            start = inter+len_rm;
            inter = strstr(start,str_rm);
        }
        if (*start!='\0') {
            strcat(_new,start);
        }
        strcpy(str,_new);
        free(_new);
        _new = (char*)NULL;
    }
    return str;
}
char* fchlib_str_to_upper(char* str) {
    char* inter = NULL;
    for (inter = str; *inter ; inter++) {
        *inter = (char)toupper(*inter);
    }
    return str;
}
char* fchlib_str_to_lower(char* str) {
    char* inter = NULL;
    for (inter = str; *inter ; inter++) {
        *inter = (char)tolower(*inter);
    }
    return str;
}
char* fchlib_str_remove(char* str,const char* str_rm, size_t maxremove) {
    unsigned len_rm = strlen(str_rm);
    char* inter = strstr(str,str_rm);
    if (maxremove==0) {
        maxremove = fchlib_str_count(str,str_rm)+1;
    }
    while (inter != (char*)NULL && maxremove-->0) {
        strcpy(inter,inter+len_rm);
        inter = strstr(inter,str_rm);
    }
    inter = (char*)NULL;
    return str;
}
char* fchlib_str_repeat(char* str,int maxrepeat) {
    char* tmp = (char*)calloc(strlen(str),1);
    if (tmp != NULL) {
        strcpy(tmp,str);
        for (; maxrepeat>1; --maxrepeat) {
            strcat(str,tmp);
        }
        free(tmp);
        tmp = (char*)NULL;
    }
    return str;
}
char* fchlib_str_reverse(char* str) {
    unsigned start = 0;
    unsigned end = strlen(str)-1;
    char tmp = '\0';
    for (; start<=end; ++start,--end) {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
    }
    return str;
}
StringArray* fchlib_str_split(char* str,const char* sep,size_t maxsplit) {
    size_t len_sep = strlen(sep);
    size_t str_size = 0;
    StringArray* str_array = (StringArray*)calloc(1,sizeof(StringArray*));
    str_array->strings = (char**)calloc(fchlib_str_count(str,sep)+1,sizeof(char*));
    char* inter = strstr(str,sep);
    char* tmp = str;
    if (maxsplit==0) {
        maxsplit = fchlib_str_count(str,sep);
    }
    while (inter != (char*)NULL && maxsplit-->0) {
        str_size = inter-tmp;
        str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
        strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
        tmp = inter+len_sep;
        inter = strstr(inter+len_sep,sep);
    }
    str_size = &str[strlen(str)-1]-tmp;
    str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
    strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
    inter = (char*)NULL;
    return str_array;
}
StringArray* fchlib_str_array_delete(StringArray* str_array) {
    --(str_array->_size);
    while (str_array->_size>-1) {
        free(str_array->strings[str_array->_size]);
        str_array->strings[str_array->_size] = (char*)NULL;
        --(str_array->_size);
    }
    free(str_array);
    str_array = (StringArray*)NULL;
    return (StringArray*)NULL;
}
int fchlib_str_equals(const char* s1,const char* s2,bool ignore_case) {
    if (ignore_case) {
        char* tmp1 = (char*)calloc(strlen(s1)+1,1);
        char* tmp2 = (char*)calloc(strlen(s2)+1,1);
        fchlib_str_to_upper(strcpy(tmp1,s1));
        fchlib_str_to_upper(strcpy(tmp2,s2));
        int result = strcmp(tmp1,tmp2);
        free(tmp1);
        tmp1 = (char*)NULL;
        free(tmp2);
        tmp2 = (char*)NULL;
        return result;
    }
    return strcmp(s1,s2);
}
