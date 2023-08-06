#!/bin/bash
./util/docker_build.sh lily58:koopa

MAX_RETRY=15

./util/docker_build.sh lily58:koopa
mkdir -p /tmp/flash


counter=0
until sudo mount /dev/disk/by-label/RPI-RP2 /tmp/flash 2> /dev/null
do
   sleep 1
   [[ counter -eq $MAX_RETRY ]] && echo "Failed, couldn't find any mountable keyboard within $MAX_RETRY attemps!" && exit 1
   echo "There is no mountable keyboard, trying again. Try #$counter"
   ((counter++))
done

sudo cp lily58_rev1_koopa_kb2040.uf2 /tmp/flash
sudo umount /tmp/flash

du -hs lily58_rev1_koopa_kb2040.uf2
