/* What libnix lacks that LinCity-NG uses.
 * The AmiCradle Team. GPL 2 or later, like LinCity-NG. */
#include <stdlib.h>
#include <string.h>

char *strndup(const char *s, size_t n)
{
	size_t len = 0;
	char *p;
	while (len < n && s[len])
		len++;
	p = malloc(len + 1);
	if (p) {
		memcpy(p, s, len);
		p[len] = '\0';
	}
	return p;
}
