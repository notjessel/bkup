#!/bin/sh
dwm_batt () {
    CHARGE=$(cat /sys/class/power_supply/BAT0/capacity)
    STATUS=$(cat /sys/class/power_supply/BAT0/status)

    printf "%s" "$SEP"
    if [ "$IDENTIFIER" = "unicode" ]; then
        if [ "$STATUS" = "Charging" ]; then
            printf "🔌%s%%" "$CHARGE"
        else
            printf "%s%%" "$CHARGE"
        fi
    else
        printf "BAT %s%%" "$CHARGE"
    fi
    printf "%s\n" #"$SEP2"#
}
