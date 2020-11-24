#ifndef _FCHLIB_STRING_H_
#define _FCHLIB_STRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
fchlib_string:
	uma biblioteca simples com algumas funcoes adicionais para manipulacao de
strings em C.

version : 1.0.08112020

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

typedef struct StringArray{
	int _size;
	char** strings;
}StringArray;

int fchlib_str_find(const char* str,const char* search);
int fchlib_str_equals(const char* s1,const char* s2,bool ignore_case);

bool fchlib_str_contains(const char* str,const char* search);
bool fchlib_str_ends_with(const char* str,const char* end);
bool fchlib_str_start_with(const char* str,const char* start);

char* fchlib_str_free(char* str);
char* fchlib_str_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace);
char* fchlib_str_repeat(char* str,int maxrepeat);
char* fchlib_str_remove(char* str,const char* str_rm,size_t maxremove);
char* fchlib_str_reverse(char* str);
char* fchlib_str_to_lower(char* str);
char* fchlib_str_to_upper(char* str);

size_t fchlib_str_count(const char* str,const char* search);

StringArray* fchlib_str_array_delete(StringArray* str_array);
StringArray* fchlib_str_split(char* str,const char* sep,size_t maxsplit);
#endif
