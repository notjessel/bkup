#!/bin/bash

case $BLOCK_BUTTON in
    1) pavucontrol &>/dev/null &
esac

status=$(amixer get Master | tail -n 1 | grep -wo "on");
if [[ "$status" == "on" ]]; then
    pulseaudio-ctl current;
else
    echo "off";
fi