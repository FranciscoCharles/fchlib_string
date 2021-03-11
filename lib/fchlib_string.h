#ifndef _FCHLIB_STRING_
#define _FCHLIB_STRING_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
fchlib_string:
	uma biblioteca simples com algumas funcoes adicionais para manipulacao de
strings em C.

version : 1.0.11032021

para mais informacoes consulte o README.
*/

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
typedef struct StringArray* StringArray;
struct StringArray {
    int _size;
    char** strings;
};

int string_find(const char* str,const char* search);
int string_equals(const char* s1,const char* s2,bool ignore_case);

bool string_contains(const char* str,const char* search);
bool string_ends_with(const char* str,const char* end);
bool string_start_with(const char* str,const char* start);

char* string_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace);
char* string_repeat(const char* str,size_t maxrepeat);
char* string_remove(char* str,const char* str_rm,size_t maxremove);
char* string_reverse(char* str);
char* string_to_upper(char* str);
char* string_to_lower(char* str);

char* string_free(char* str);

size_t string_count(const char* str,const char* search);

StringArray string_array_delete(StringArray str_array);
StringArray string_split(char* str,const char* sep,size_t maxsplit);
char* string_join(StringArray str_array,char* separator);
#endif
