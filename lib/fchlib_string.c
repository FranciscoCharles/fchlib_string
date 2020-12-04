#include "fchlib_string.h"
/*
MIT License

Copyright (c) 2020 FranciscoCharles

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
bool fchlib_str_contains(const char* str,const char* search) {
    return (str!=NULL) && (search!=NULL) && strstr(str,search) != (char*)NULL;
}
size_t fchlib_str_count(const char* str,const char* search) {
    size_t occurrences = 0;
    if((str!=NULL) && (search!=NULL)) {
        size_t len = strlen(search);
        char* inter = strstr(str,search);
        if (strlen(search)>0) {
            while (inter != (char*)NULL) {
                ++occurrences;
                inter = strstr(inter+len,search);
            }
        }
    }
    return occurrences;
}
bool fchlib_str_ends_with(const char* str,const char* end) {
    if((str==NULL) || (end==NULL)) {
        return false;
    }
    size_t len_str = strlen(str);
    size_t len_end = strlen(end);
    return (len_str>=len_end) && strcmp(&str[len_str-len_end],end)==0;
}
int fchlib_str_equals(const char* s1,const char* s2,bool ignore_case) {
    if((s1==NULL) || (s2==NULL)) {
        return -2;
    } else if (ignore_case) {
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
int fchlib_str_find(const char* str,const char* search) {
    if((str!=NULL) && (search!=NULL)) {
        char* index = strstr(str,search);
        if (index != (char*)NULL) {
            return (int)(index-str);
        }
    }
    return -1;
}
char* fchlib_str_free(char* str) {
    if(str!=NULL) {
        free(str);
    }
    return NULL;
}
char* fchlib_str_remove(char* str,const char* str_rm, size_t maxremove) {
    size_t len_rm = 0;
    char* inter = 0;
    char* tmp = str;
    char* new_string = NULL;
    if((str==NULL) || (str_rm==NULL) || (strlen(str)==0) || (strlen(str_rm)==0)) {
        return (char*)NULL;
    }
    len_rm = strlen(str_rm);
    inter = strstr(str,str_rm);
    if (maxremove==0) {
        maxremove = fchlib_str_count(str,str_rm)+1;
    }
    new_string = (char*)calloc(strlen(str)-len_rm*maxremove+1,1);
    while (inter != (char*)NULL && maxremove-->0) {
        strncat(new_string,tmp,(unsigned)(inter-tmp));
        tmp = inter+len_rm;
        inter = strstr(inter+len_rm,str_rm);
    }
    if(inter!=NULL) {
        strcat(new_string,tmp);
    }
    inter = (char*)NULL;
    tmp = (char*)NULL;
    if(strlen(new_string)==0) {
        strcpy(new_string,str);
    }
    return new_string;
}
char* fchlib_str_repeat(const char* str,size_t maxrepeat) {
    char* tmp = NULL;
    if((str!=NULL) && (maxrepeat>0)) {
        tmp = (char*)calloc(maxrepeat*strlen(str)+1,1);
        if (tmp != NULL) {
            strcpy(tmp,str);
            for (; maxrepeat>1; --maxrepeat) {
                strcat(tmp,str);
            }
        }
    }
    return tmp;
}
char* fchlib_str_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace) {

    size_t len_rm = 0;
    size_t size_new = 0;
    char* start = str;
    char* new_string = NULL;
    char* inter = NULL;
    if((str==NULL) || (str_new==NULL) || (str_rm==NULL) || (strlen(str)==0) || (strlen(str_rm)==0)) {
        return NULL;
    }
    len_rm = strlen(str_rm);
    inter = strstr(str,str_rm);
    if (inter != (char*)NULL) {
        size_new = strlen(str)+fchlib_str_count(str,str_rm)*(strlen(str_new)-strlen(str_rm))+1;
        new_string = (char*)calloc(size_new,1);
        if (maxreplace==0) {
            maxreplace = fchlib_str_count(str,str_rm)+1;
        }
        while (inter != NULL && maxreplace-->0) {
            strncat(new_string,start,(unsigned)(inter-start));
            strcat(new_string,str_new);
            start = inter+len_rm;
            inter = strstr(start,str_rm);
        }
        if (*start!='\0') {
            strcat(new_string,start);
        }
    } else {
        new_string = (char*)calloc(strlen(str)+1,1);
        strcpy(new_string,str);
    }
    return new_string;
}
char* fchlib_str_reverse(char* str) {
    if(str!=NULL) {
        unsigned start = 0;
        unsigned end = strlen(str)-1;
        char tmp = '\0';
        for (; start<=end; ++start,--end) {
            tmp = str[start];
            str[start] = str[end];
            str[end] = tmp;
        }
    }
    return str;
}
StringArray fchlib_str_split(char* str,const char* sep,size_t maxsplit) {
    char* tmp = str;
    char* inter = NULL;
    size_t len_sep = 0;
    size_t str_size = 0;
    StringArray str_array = NULL;
    if((str==NULL) || (sep==NULL) || (strlen(str)==0) || (strlen(sep)==0)) {
        return (StringArray)NULL;
    }
    len_sep = strlen(sep);
    str_array = (StringArray)calloc(1,sizeof(struct StringArray));
    if(str_array != NULL) {
        str_array->strings = (char**)calloc(fchlib_str_count(str,sep)+1,sizeof(char*));
        if(str_array->strings != NULL) {
            inter = strstr(str,sep);
            if (maxsplit==0) {
                maxsplit = fchlib_str_count(str,sep);
            }
            while (inter != (char*)NULL && maxsplit-->0) {
                str_size = inter-tmp;
                str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
                strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
                tmp = inter+len_sep;
                inter = strstr(tmp,sep);
            }
            str_size = &str[strlen(str)]-tmp;
            str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
            strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
            inter = (char*)NULL;
        } else {
            str_array = fchlib_str_array_delete(str_array);
        }
    }
    return str_array;
}
bool fchlib_str_start_with(const char* str,const char* start) {
    if((str==NULL) || (start==NULL) || (strlen(str)!=0 && strlen(start)==0)) {
        return false;
    }
    return fchlib_str_find(str,start)==0;
}
char* fchlib_str_to_lower(char* str) {
    if(str!=NULL) {
        char* inter = NULL;
        for (inter = str; *inter ; inter++) {
            *inter = (char)tolower(*inter);
        }
    }
    return str;
}
char* fchlib_str_to_upper(char* str) {
    if(str!=NULL) {
        char* inter = NULL;
        for (inter = str; *inter ; inter++) {
            *inter = (char)toupper(*inter);
        }
    }
    return str;
}
StringArray fchlib_str_array_delete(StringArray str_array) {
    if(str_array!=NULL) {
        while (--(str_array->_size)>-1) {
            free(str_array->strings[str_array->_size]);
            str_array->strings[str_array->_size] = (char*)NULL;
        }
        free(str_array);
        str_array = (StringArray)NULL;
    }
    return (StringArray)NULL;
}
