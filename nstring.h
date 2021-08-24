#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NSTRING_NOT_FOUND  -1

typedef struct {
    int len;
    char *buff;
} nstring_t;

nstring_t * nstring_init       (void);

void        nstring_set        (nstring_t *nstr, const char s[]);
void        nstring_fill       (nstring_t *nstr, char c);
void        nstring_clear      (nstring_t *nstr);

void        nstring_push_front (nstring_t *nstr, char c);
void        nstring_push_back  (nstring_t *nstr, char c);
void        nstring_pop_front  (nstring_t *nstr);
void        nstring_pop_back   (nstring_t *nstr);

int         nstring_find       (nstring_t *nstr, const char s[]);
void        string_erase       (nstring_t *nstr, int a, int b);
void        nstring_remove     (nstring_t *nstr, int i);
void        nstring_insert     (nstring_t *nstr, int i, const char s[]);
char        nstring_at         (nstring_t *nstr, int i);

int         nstring_len        (nstring_t *nstr);
char *      nstring_buff       (nstring_t *nstr);

bool        nstring_compare    (nstring_t *nstr1, nstring_t *nstr2);

void        nstring_free       (nstring_t *nstr);
