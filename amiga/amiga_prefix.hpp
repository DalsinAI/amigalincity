/* Included before every C++ file (-include): the C++ streams first, since
 * the toolchain's pthread.h wraps read() and close() in cancellation
 * macros once <unistd.h> is in, which breaks <istream> and <fstream> read
 * after it; and libnix's missing strndup (amiga/amiga_compat.c).
 * The AmiCradle Team. GPL 2 or later, like LinCity-NG. */
#include <iostream>
#include <fstream>
#include <sstream>
#include <stddef.h>
extern "C" char *strndup(const char *s, size_t n);
