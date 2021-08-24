#include <stdio.h>

#include "nstring.h"

int
main(void) {
    nstring_t *ns = nstring_init();
    nstring_set(ns, "1234");
    printf("%s\n", nstring_buff(ns));
    nstring_fill(ns, 'a');
    printf("%s\n", nstring_buff(ns));
    nstring_free(ns);

    return EXIT_SUCCESS;
}
