#!/bin/zsh
if [[ ! $DISPLAY && $XDG_VTNR -eq 1  ]]; then
    exec startx
fi
export XCURSOR_PATH=${$XCURSOR_PATH}:~/.local/share/icons
