/* LinCity-NG's config.h (CMake makes it from src/config.h.in) for AmigaOS:
 * the program is in its own drawer, with its data in the drawer's data/.
 * INSTALL_BINDIR starts with "/", PhysicsFS's separator, so main.cpp does
 * not work an install prefix out of the program's directory and mounts
 * INSTALL_FULL_APPDATADIR. The write directory, PhysicsFS's pref dir, is
 * the drawer too (amiga/physfs/physfs_platform_amiga.c).
 * The AmiCradle Team. GPL 2 or later, like LinCity-NG. */
#pragma once

#define HAVE_DIRENT_H

#define PACKAGE_NAME "lincity-ng"
#define PACKAGE_VERSION "2.12.0"

#define INSTALL_PREFIX "PROGDIR:"
#define INSTALL_BINDIR "/"
#define INSTALL_DATADIR "data"
#define INSTALL_APPDATADIR "data"
#define INSTALL_FULL_BINDIR "PROGDIR:"
#define INSTALL_FULL_DATADIR "PROGDIR:data"
#define INSTALL_FULL_APPDATADIR "PROGDIR:data"
