/* This program translates words to Bork, a language that is very similar to English.
   To translate a word to Bork, you take the English word and add an 'f' after every 
   vowel in the word. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alloc_str(int len) {
    return malloc((len + 1) * sizeof(char));
}

/* Str helper functions */
typedef struct Str {
    char *data;
    int len;
} Str;

Str make_Str(char *str) {
    /* Below is a designated initializer. It creates a Str struct and initializes
       its data field to str and its len field to strlen(str) */
    int len = strlen(str);
    char *copy = alloc_str(len);
    strcpy(copy, str);
    return (Str){.data=copy,.len=len};
}

void free_Str(Str str) {
    free(str.data);
}

/* concatinates two strings together */
Str concat(Str a, Str b) {
    int new_len = a.len + b.len;
    char *new_str = alloc_str(new_len);
    new_str[new_len] = '\0';
    for (int i = 0; i < a.len; ++i) {
        new_str[i] = a.data[i];
    }
    for (int i = 0; i < b.len; ++i) {
        new_str[i+a.len] = b.data[i];
    }
    if (a.data) free(a.data);
    if (b.data) free(b.data);
    return (Str){.data=new_str, .len=new_len};
}

/* translates a letter to Bork */
Str translate_to_bork(char c) {
    switch(c) {
    case 'a': case 'e': case 'i': case 'o': case 'u': {
        char buf[3] = {c, 'f', '\0'};
        return make_Str(buf);
    }
    }
    char buf[2] = {c, '\0'};
    return make_Str(buf);
}

int main(int argc, char*argv[]) {
    if (argc == 1) {
        printf("Remember to give me a string to translate to Bork!\n");
        return 1;
    }

    Str dest_str={}; // Fancy syntax to zero initialize struct
    Str src_str = make_Str(argv[1]);
    for (int i = 0; i < src_str.len; ++i) {
        Str bork_substr = translate_to_bork(src_str.data[i]);
        dest_str = concat(dest_str, bork_substr);
    }

    printf("Input string: \"%s\"\n", src_str.data);
    printf("Length of translated string: %d\n", dest_str.len);
    printf("Translate to Bork: \"%s\"\n", dest_str.data);
    free_Str(src_str);
    free_Str(dest_str);
    return 0;
}
