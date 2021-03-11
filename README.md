<p align="center">
  <img src="name.png" width="500">
</p>
  
Bem vindo ao README da **fchlib_string**.  

# VERSION
versão atual: <h3><b>1.0.11032021</b></h3>
versões anteriores:

~~1.0.08112020~~

 
# DESCRIÇÃO
 
A **fchlib_string** é uma biblioteca escrita em C que implementa algumas
funções básicas para manipulação de strings. Ela é composta pelas seguintes funções:
 
- [**string_contains**](#string_contains)
- [**string_count**](#string_count)
- [**string_ends_with**](#string_ends_with)
- [**string_equals**](#string_equals)
- [**string_find**](#string_find)
- [**string_free**](#string_free)
- [**string_join**](#string_join)
- [**string_remove**](#string_remove)
- [**string_repeat**](#string_repeat)
- [**string_replace**](#string_replace)
- [**string_reverse**](#string_reverse)
- [**string_split**](#string_split)
- [**string_start_with**](#string_start_with)
- [**string_to_lower**](#string_to_lower)
- [**string_to_upper**](#string_to_upper)
- [**string_array_delete**](#string_array_delete)

# **<a name=string_contains>string_contains</a>**

Esta função verifica se uma string está contida dentro de outra.

- ## protótipo da função :

```c  
bool string_contains(const char* str,const char* search);
```
- ## parâmetros :
  - str `(const char*)` : string de origem.
  - search `(const char*)` : string para ser verificada se pertence a **str**.
  
- ## retorno:
  - `(bool)`: retorna `true` se **search** é uma substring de **str**.

# **<a name=string_count>string_count</a>**
Esta função retorna a quantidade de ocorrências de uma string em outra string.

- ## protótipo da função :  

```c
size_t string_count(const char* str,const char* search);
```
   
- ## parâmetros :
  - str `(const char*)` : string de origem.
  - search `(const char*)` : string a ser contada.
 
- ## retorno:
  - occurences `(size_t)` : retorna o número de ocorrencias de **search** em **str**.

# **<a name=string_ends_with>string_ends_with</a>**

Esta função verifica se um string termina com uma determinda string.

- ## protótipo da função :  
  
```c
bool string_ends_with(const char* str,const char* end);
```
  
- ## parâmetros :
  - str `(const char*)` : string de origem.
  - end `(const char*)` : string a ser verificada no final de **str**.

- ## retorno:
  - `(bool)` : retorna se **str** termina com **end**.

# **<a name=string_equals>string_equals</a>**
Esta função verifica se duas strings são iguais.

- ## protótipo da função :  
   
```c
int string_equals(const char* s1,const char* s2,bool ignore_case);
```

- ## parâmetros :
  - s1 `(const char*)` : primeira string.
  - s2 `(const char*)` : segunda string.
  - ignore_case `(bool)`: flag para ignorar o caso.

- ## retorno:
  - `(int)` : -1 se **s1** é menor que **s2**. 0 se forem iguais e 1 se **s1** for maior que **s2**. caso **s1** 
ou **s2** sejam `NULL`, esta função retorna -2. Caso não seja possivel realizar alguma alocação interna esta função retorna -3.

# **<a name=string_find>string_find</a>**
Esta função realiza a busca por uma string.

- ## protótipo da função :  
  
```c
int string_find(const char* str,const char* search);
```

- ## parâmetros :
  - str `(const char*)` : string de origem.
  - search `(const char*)` : string a ser buscada.

- ## retorno:
  - `(int)` : retorna o index da primeira ocorrencia da string **search** ou -1 caso não seja encontrada.

# **<a name=string_free>string_free</a>**
esta função libera a memoria alocada por uma string.

- ## protótipo da função :  
  
```c
char* string_free(char* str);
```
- ## parâmetros :
  - str `(const char*)` : string a ser liberada.

- ## retorno:
  - `(`NULL`)` : libera **str** caso esta não seja `NULL` e retorna `NULL`.

# **<a name=string_join>string_join</a>**
Esta função converte um `StringArray` em uma string.

- ## protótipo da função :  
   
```c
char* string_join(StringArray str_array,char* separator);
```

- ## parâmetros :
  - str_array `(StringArray)` : `StringArray` de origem.
  - separator `(const char*)` : string usada para separar a string resultante da concatenação.

- ## retorno:
  - `(char*)` : retorna uma nova string alocada com o resultado da concatenação ou `NULL` caso uma nova string nao possa ser alocada.

# **<a name=string_remove>string_remove</a>**
Esta função remove uma substring de uma string.

- ## protótipo da função :  
   
```c
char* string_remove(char* str,const char* str_rm,size_t maxremove);
```

- ## parâmetros :
  - str `(char*)` : string de origem.
  - str_rm `(const char*)` : string a ser removida.
  - maxremove `(size_t)` : quantidade de remoções. use 0 para remover todas as ocorrencias de **str_rm**.

- ## retorno:
  - `(char)` : retorna uma nova string alocada com a **str_rm** removida ou retorna `NULL` no
caso de uma das variaveis **str** e **str_rm** sejam `NULL` ou uma nova string nao possa ser alocada.

# **<a name=string_repeat>string_repeat</a>**
Esta função repete uma string.

- ## protótipo da função :  

```c
char* string_repeat(char* str,size_t maxrepeat);
```

- ## parâmetros :
  - str `(char*)` : string a ser repetida.
  - maxrepeat `(size_t)` : quantidade de repetições de **str**.

- ## retorno:
  - `(char*)` : retorna a uma nova string alocada com **str** repetida.

# **<a name=string_replace>string_replace</a>**
Esta função que realiza a substituição de uma substring por outra.

- ## protótipo da função :  

```c
char* string_replace(char* str,const char* str_rm,const char* str_new,size_t maxreplace);
```

- ## parâmetros :
  - str `(char*)` : string de origem.
  - str_rm `(const char*)` : string a ser substituida.
  - str_new `(const char*)` : nova string no lugar de **str_rm**.
  - maxreplace `(size_t)` : quantidade de substituições em **str**. use 0 para realizar todas as substituições possiveis.

- ## retorno:
  - `(char*)` : retorna a uma nova string alocada com as substituções. 
caso uma das variaveis **str**,**str_rm** e **str_new** sejam `NULL` esta função retorna `NULL`.

# **<a name=string_reverse>string_reverse</a>**
Esta função inverte uma string.

- ## protótipo da função :  

```c
char* string_reverse(char* str);
```

- ## parâmetros :
  - str `(char*)` : string à ser invertida.

- ## retorno:
  - `(char*)` : retorna a mesma string invertida.

# **<a name=string_split>string_split</a>**
Esta função quebra um string em partes.

- ## protótipo da função :  
   
```c
StringArray string_split(char* str, const char* sep, size_t maxsplit);
```

- ## parâmetros :
  - str `(char*)` : string de origem.
  - sep `(const char*)` : string de separação.
  - maxsplit `(size_t)` : quantidade maxima de quebras. use 0 para realizar todas as quebras possiveis.

- ## retorno:
  - `(StringArray)` : retorna um **StringArray** contendo todas as quebras.
- ## nota:
  Caso **str** ou **sep** sejam `NULL`, string vazia ou não seja possivel alocar espaço para o StringArray e seus dados esta função retorna `NULL`.

# **<a name=string_start_with>string_start_with</a>**

Esta função verifica se um string começa com uma determinda string.

- ## protótipo da função :  
  
```c
bool string_start_with(const char* str,const char* start);
```
  
- ## parâmetros :
  - str `(const char*)` : string de origem.
  - start `(const char*)` : string a ser verificada no começo de **str**.

- ## retorno:
  - `(bool)` : retorna se **str** começa com **start**.

# **<a name=string_to_lower>string_to_lower</a>**
Esta função converte uma string para minusculas.

- ## protótipo da função :  
  
```c
char* string_to_lower(char* str);
```

- ## parâmetros :
  - str `(char*)` : string à ser convertida.

- ## retorno:
  - `(char*)` : retorna a mesma string convertida para minusculas.

# **<a name=string_to_upper>string_to_upper</a>**
Esta função converte uma string para maiusculas.

- ## protótipo da função :  

```c
char* string_to_upper(char* str);
```

- ## parâmetros :
  - str `(char*)` : string à ser convertida.

- ## retorno:
  - `(char*)` : retorna a mesma string convertida para maiusculas.

# **<a name=string_array_delete>string_array_delete</a>**
Esta função libera a memoria alocado por um **StringArray**.

- ## protótipo da função :  
   
```c
StringArray string_array_delete(StringArray str_array);
```

- ## parâmetros :
  - str_array `(StringArray)` : string array a ser liberado.

- ## retorno:
  - `(StringArray)` : retorna **`NULL`**.