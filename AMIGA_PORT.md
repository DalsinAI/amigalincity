LinCity-NG 2.12.0 for AmigaOS 3.x
=================================

LinCity-NG (the LinCity-NG developers, https://github.com/lincity-ng/lincity-ng),
the city-building game: lay out homes, farms, industry, roads and rails,
power and water, keep the people fed, employed and housed, and grow a
village into a city that can launch its people to the stars, or live
sustainably. For AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG
screen, on OpenGPU's SDL 2.

Base: upstream's GitHub tag lincity-ng-2.12.0 (the archive, sha256
c9ca345a77c42c31ec569af6ca7b81acf39d61291caaaeb449b6bebfd30457e0), the
last LinCity-NG on SDL 2 with plain libxml2 (2.13 on needs libxml++,
2.15 SDL 3). Branch team2/lincity-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): the main menu, a new temperate game with its village (the map
scrolling, the simulation running, the Stats panel), a track built
through the woods, Save into a slot and the current game written in the
drawer, Load of that save, and Quit back to the Shell. The lab is muted,
so the music and sounds were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab). Building a new map takes a minute or two in the lab.
- GFOpenUp 0.8.18 or later: LIBS:OpenGPU/SDL2.module, SDL2_image.module,
  SDL2_mixer.module and SDL2_ttf.module.
- About 65 MB of disk.


How to play
-----------

Open the LinCity-NG icon, or run LinCity-NG from a Shell. The game reads
its data from the drawer's data/ and keeps its settings (userconfig.xml)
and saved games in the drawer. It opens a full screen the size of the
Workbench's; Options can change that, or turn on OpenGL (OpenGPU's GL,
slower here than SDL's own drawing, which is the Amiga default). Help is
in the game (the question-mark button).



Standard keys
-------------

Every AmiCradle game has the same keys on Right Amiga (GFOpenUp's
SDL2.module, after 0.8.26):

- Right Amiga + F: window or full screen, remembered for next time
- Right Amiga + P: pause (Right Amiga + P again goes on)
- Right Amiga + Q: quit
- Right Amiga + M: free the mouse pointer, or let the game take it again
- Right Amiga + S: a screenshot in the drawer's Screenshots
- Help: this game's keys (the drawer's Controls file)
- Right Amiga + F1, F2: F11, F12; Right Amiga + cursor keys: Page Up,
  Page Down, Home, End

The FULLSCREEN tooltype on the game's icon (take the brackets off) starts
it full screen.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static libxml2 and zlib (see the Makefile's head). The drawer
is dist/LinCity-NG (and dist/LinCity-NG.info).


What was changed
----------------

- amiga/Makefile.amigaos builds what upstream's CMake does (both painters,
  OpenGL and SDL), with amiga/config.h for the one CMake makes: the data
  is PROGDIR:data.
- src/lincity-ng/main.cpp: SDL is started for video, audio and the timer
  only (OpenGPU's SDL 2 has no sensors, which SDL_INIT_EVERYTHING asks
  for); the write directory (the drawer) loses its trailing "/", since
  the game adds one and "//" is the parent drawer to AmigaDOS.
- src/lincity-ng/Config.cpp: OpenGL off by default.
- PhysicsFS 3.2.0 with the Team's AmigaOS platform (amiga/physfs, from the
  DXX-Rebirth port: the pref dir is the program's drawer) and SDL2_gfx
  1.0.4's primitives and rotozoom (amiga/sdl2_gfx) are built in.
- amiga/amiga_prefix.hpp: the C++ streams first in every file (the
  toolchain's pthread.h wraps read() in a macro once <unistd.h> is in),
  and libnix's missing strndup (amiga/amiga_compat.c). amiga/stack.c:
  1 MB of stack.
- The drawer has what upstream installs, not the 3D models (data/models,
  120 MB of Blender files) or the editors' sources. The gui XMLs are
  copied as they are: upstream's xsltproc pass over them is an identity
  transform.


Licences
--------

LinCity-NG: GPL 2 or later (COPYING.txt). Its pictures, sounds, music and
XML data: GPL or CC BY-SA 2.0 (COPYING-data.txt). The font: DejaVu Sans
(COPYING-fonts.txt). PhysicsFS (COPYING-PhysicsFS.txt) and SDL2_gfx
(COPYING-SDL2_gfx.txt): zlib licence. The Amiga files (amiga/): GPL 2 or
later, the AmiCradle Team.
