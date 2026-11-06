/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 2 or later, like LinCity-NG. */
unsigned long __stack = 1024 * 1024;
static const char version[] __attribute__((used)) = "$VER: LinCity-NG 2.12.0 Amiga (06.11.2026)";
