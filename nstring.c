#include "nstring.h"

nstring_t *
nstring_init(void) {
    nstring_t *nstr;
    nstr = malloc(sizeof (nstring_t));
    nstr->len = 0;
    nstr->buff = malloc(sizeof (char) * nstr->len + 1);
    nstr->buff[0] = '\0';
    return nstr;
}

void
nstring_set(nstring_t *nstr, const char s[]) {
    nstr->len = strlen(s);
    nstr->buff = malloc(sizeof (char) * nstr->len + 1);
    strcpy(nstr->buff, s);
    nstr->buff[nstr->len] = '\0';
}

void
nstring_fill(nstring_t *nstr, char c) {
    for (int i = 0; i < nstr->len; i++) {
        nstr->buff[i] = c;
    }
}

void
nstring_clear(nstring_t *nstr) {
    free(nstr->buff);
    nstr->len = 0;
    nstr->buff = malloc(sizeof (char) * nstr->len + 1);
    nstr->buff[0] = '\0';
}

void
nstring_push_front(nstring_t *nstr, char c) {}

void
nstring_push_back(nstring_t *nstr, char c) {
    nstr->len++;
    nstr->buff = realloc(nstr->buff, nstr->len + 1);
    nstr->buff[nstr->len - 1] = c;
    nstr->buff[nstr->len] = '\0';
}

void
nstring_pop_front(nstring_t *nstr) {}

void
nstring_pop_back(nstring_t *nstr) {
    char *buff = malloc(sizeof (char) * nstr->len);
    for (int i = 0; i < nstr->len - 1; i++) {
        buff[i] = nstr->buff[i];
    }
    nstring_set(nstr, buff);
}

int
nstring_find(nstring_t *nstr, const char s[]) {
    for (int i = 0; i < nstr->len; i++) {
        if (strstr(nstr->buff + i, s) == 0) {
            return i - 1;
        }
    }
    return NSTRING_NOT_FOUND;
}

void
nstring_erase(nstring_t *nstr, int a, int b) {
    char *buff = malloc(sizeof (char) * nstr->len + 1 - (b - a));
    for (int i = 0, j = 0; i < nstr->len; i++) {
        if (i < a || i >= b) {
            buff[j] = nstr->buff[i];
            j++;
        }
    }
    nstring_set(nstr, buff);
}

void
nstring_remove(nstring_t *nstr, int i) {
    nstring_erase(nstr, i, i + 1);
}

void
nstring_insert(nstring_t *nstr, int n, const char s[]) {
    int len = nstr->len + strlen(s);
    char *buff = malloc(sizeof (char) * len + 1);
    for (int i = 0, j = 0; i < nstr->len; i++) {
        if (i == n) {
            // buff = strcat(buff, s);
            // strcpy(buff + j, s);
            // j += strlen(s) + 1;
            for (int k = 0; k < strlen(s); k++) {
                buff[j] = s[k];
                j++;
            }
        }
        buff[j] = nstr->buff[i];
        j++;
    }
    buff[len] = '\0';
    nstring_set(nstr, buff);
}

char
nstring_at(nstring_t *nstr, int i) {
    return nstr->buff[i];
}

int
nstring_len(nstring_t *nstr) {
    return nstr->len;
}

char *
nstring_buff(nstring_t *nstr) {
    return nstr->buff;
}

bool
nstring_compare(nstring_t *nstr1, nstring_t *nstr2) {
    return strcmp(nstr1->buff, nstr2->buff) == 0;
}

void
nstring_free(nstring_t *nstr) {
    free(nstr->buff);
    free(nstr);
}
