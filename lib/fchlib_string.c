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
bool string_contains(const char* str,const char* search) {
    return (str!=NULL) && (search!=NULL) && strstr(str,search) != (char*)NULL;
}
size_t string_count(const char* str,const char* search) {
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
bool string_ends_with(const char* str,const char* end) {
    if((str==NULL) || (end==NULL)) {
        return false;
    }
    size_t len_str = strlen(str);
    size_t len_end = strlen(end);
    return (len_str>=len_end) && strcmp(&str[len_str-len_end],end)==0;
}
int string_equals(const char* s1,const char* s2,bool ignore_case) {
    if((s1==NULL) || (s2==NULL)) {
        return -2;
    } else if (ignore_case) {
        int result = -3;
        char* tmp1 = (char*)calloc(strlen(s1)+1,1);
        char* tmp2 = (char*)calloc(strlen(s2)+1,1);
        if(tmp1!=NULL && tmp2!=NULL) {
            string_to_upper(strcpy(tmp1,s1));
            string_to_upper(strcpy(tmp2,s2));
            result = strcmp(tmp1,tmp2);
        }
        tmp1 = string_free(tmp1);
        tmp2 = string_free(tmp2);
        return result;
    }
    return strcmp(s1,s2);
}
int string_find(const char* str,const char* search) {
    if((str!=NULL) && (search!=NULL)) {
        char* index = strstr(str,search);
        if (index != (char*)NULL) {
            return (int)(index-str);
        }
    }
    return -1;
}
char* string_free(char* str) {
    if(str!=NULL) {
        free(str);
    }
    return NULL;
}
char* string_remove(char* str,const char* str_rm, size_t maxremove) {
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
        maxremove = string_count(str,str_rm)+1;
    }
    new_string = (char*)calloc(strlen(str)-len_rm*maxremove+1,1);
    if(new_string!=NULL) {
        while (inter != (char*)NULL && maxremove-->0) {
            strncat(new_string,tmp,(unsigned)(inter-tmp));
            tmp = inter+len_rm;
            inter = strstr(inter+len_rm,str_rm);
        }
        if(inter!=NULL) {
            strcat(new_string,tmp);
        }
        if(strlen(new_string)==0) {
            strcpy(new_string,str);
        }
    }
    tmp = (char*)NULL;
    inter = (char*)NULL;
    return new_string;
}
char* string_repeat(const char* str,size_t maxrepeat) {
    char* new_string = NULL;
    if((str!=NULL) && (maxrepeat>0)) {
        new_string = (char*)calloc(maxrepeat*strlen(str)+1,1);
        if (new_string != NULL) {
            strcpy(new_string,str);
            for (; maxrepeat>1; --maxrepeat) {
                strcat(new_string,str);
            }
        }
    }
    return new_string;
}
char* string_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace) {

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
        size_new = strlen(str)+string_count(str,str_rm)*(strlen(str_new)-strlen(str_rm))+1;
        new_string = (char*)calloc(size_new,1);
        if(new_string!=NULL) {
            if (maxreplace==0) {
                maxreplace = string_count(str,str_rm);
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
        }
    } else {
        new_string = (char*)calloc(strlen(str)+1,1);
        if(new_string!=NULL) {
            strcpy(new_string,str);
        }
    }
    return new_string;
}
char* string_reverse(char* str) {
    if(str!=NULL && strlen(str)>0) {
        char* start = str;
        char* end = &str[strlen(str)-1];
        char tmp = '\0';
        for (; start<end; ++start,--end) {
            tmp = *start;
            *start = *end;
            *end = tmp;
        }
    }
    return str;
}
StringArray string_split(char* str,const char* sep,size_t maxsplit) {
    char* tmp = str;
    char* inter = NULL;
    bool fail = false;
    size_t len_sep = 0;
    size_t str_size = 0;
    StringArray str_array = NULL;
    if((str==NULL) || (sep==NULL) || (strlen(str)==0) || (strlen(sep)==0)) {
        return (StringArray)NULL;
    }
    len_sep = strlen(sep);
    str_array = (StringArray)calloc(1,sizeof(struct StringArray));
    if(str_array != NULL) {
        str_array->strings = (char**)calloc(string_count(str,sep)+1,sizeof(char*));
        if(str_array->strings != NULL) {
            inter = strstr(str,sep);
            if (maxsplit==0) {
                maxsplit = string_count(str,sep);
            }
            while (inter != NULL && maxsplit-->0) {
                str_size = inter-tmp;
                str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
                if(str_array->strings[str_array->_size]==NULL) {
                    fail = true;
                    break;
                }
                strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
                tmp = inter+len_sep;
                inter = strstr(tmp,sep);
            }
            if(!fail) {
                str_size = &str[strlen(str)]-tmp;
                str_array->strings[str_array->_size] = (char*)calloc(str_size+1,1);
                if(str_array->strings[str_array->_size]!=NULL) {
                    strncpy(str_array->strings[(str_array->_size)++],tmp,str_size);
                } else {
                    fail = true;
                }
            }
        } else {
            fail=true;
        }
        inter = (char*)NULL;
        tmp = (char*)NULL;
    }
    if(fail) {
        str_array = string_array_delete(str_array);
    }
    return str_array;
}
bool string_start_with(const char* str,const char* start) {
    if((str==NULL) || (start==NULL) || (strlen(str)!=0 && strlen(start)==0)) {
        return false;
    }
    return string_find(str,start)==0;
}
char* string_to_lower(char* str) {
    if(str!=NULL) {
        char* inter = str;
        for (; *inter ; inter++) {
            *inter = (char)tolower(*inter);
        }
    }
    return str;
}
char* string_to_upper(char* str) {
    if(str!=NULL) {
        char* inter = str;
        for (; *inter ; inter++) {
            *inter = (char)toupper(*inter);
        }
    }
    return str;
}
StringArray string_array_delete(StringArray str_array) {
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
char* string_join(StringArray str_array,char* separator) {
    char* new_string = NULL;
    if(str_array!=NULL) {
        unsigned len_string = 0;
        unsigned i = 0;
        unsigned size =  str_array->_size;
        i = size;
        for(; i<size; ++i) {
            len_string += strlen(str_array->strings[i]);
        }
        new_string = (char*)calloc(len_string+1,1);
        if(new_string != NULL) {
            size -= 1;
            for(i=0; i<size; ++i) {
                strcat(new_string,str_array->strings[i]);
                strcat(new_string,separator);
            }
            strcat(new_string,str_array->strings[size]);
        }

    }
    return new_string;
}
