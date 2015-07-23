#!/bin/bash


echo -n "retroarch -L " > /home/mini/programs/of_v0.8.4_linux64_release/apps/myApps/sega_TST/bin/data/game_on.sh
grep -m1 -e "/usr/lib/libretro/*" emu_select.txt | tr '\n' '\t' >> /home/mini/programs/of_v0.8.4_linux64_release/apps/myApps/sega_TST/bin/data/game_on.sh
grep -m1 -e " " game_select.txt >> /home/mini/programs/of_v0.8.4_linux64_release/apps/myApps/sega_TST/bin/data/game_on.sh
chmod a+x /home/mini/programs/of_v0.8.4_linux64_release/apps/myApps/sega_TST/bin/data/game_on.sh

exit 0
