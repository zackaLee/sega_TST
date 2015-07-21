#!/bin/bash




#all output from commands in this block sent to ./game_on.sh

echo -n "retroarch -L " >> game_on.sh
grep -m1 -e "/home/emoora/Documents/programming/emu/*" emu_select.txt | tr '\n' '\t' >> game_on.sh
grep -m1 -e "/home/emoora/Downloads/*" game_select.txt >> game_on.sh
chmod a+x game_on.sh

exit 0


