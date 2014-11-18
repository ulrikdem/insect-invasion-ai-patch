AI Patch for Insect Invasion
============================

Introduction
------------

When the Insect Invasion mod was released for Impossible Creatures, the
developers did not update the AI and the option to add a computer-controlled
player in a multiplayer game was removed. However the AI still works, ignoring
the new abilities, in singleplayer games.

This patch allows you to add computer-controlled players in multiplayer again,
but they still ignore the new abilities. It is only necessary for the player who
will host the game to install the patch.

Installing
----------

Before running any of the scripts, ensure that the file `path.txt` contains the
correct path to your Impossible Creatures installation. Note that you should
already have Insect Invasion installed.

Run the script `install.bat` to install the patch. The script `uninstall.bat`
restores your Insect Invasion installation to its state before the patch was
installed. Both these scripts should be run as an administrator.

Building
--------

These steps are only necessary if you have modified the patch's source code. To
build the patch, you will need Visual C++ 2010, though you may get other
versions or even other compilers to work. You will also need the RDN SDK for
Impossible Creatures.

First, run the script `fix.bat` as an administrator. This script requires Python
(version 2 or 3 should work) and patches the STL implementation in the RDN SDK
to compile with Visual C++ 2010.

The script `build.bat` compiles the patch so that you can install it using the
steps above. Before running this script, edit it to ensure that it contains the
correct path to Visual Studio's `vcvarsall.bat` script.

License
-------

Copyright (c) 2014 Ulrik de Muelenaere (github.com/ulrikdem)

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the
use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim
that you wrote the original software. If you use this software in a product,
an acknowledgment in the product documentation would be appreciated but is
not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
