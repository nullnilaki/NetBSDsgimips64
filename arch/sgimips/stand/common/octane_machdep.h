#include <sys/param.h>

/* iris_start.S */
void octanerestart(void);

#define DELAY(n)							\
do {									\
        register int __N = (400) / 2 * n;				\
        do {								\
                __asm("addiu %0,%1,-1" : "=r" (__N) : "0" (__N));	\
        } while (__N > 0);						\
} while (/* CONSTCOND */ 0)
