#!/bin/sh
if [ -d /etc/X11/xinit/xinitrc.d ]; then
  for f in /etc/X11/xinit/xinitrc.d/*; do
    [ -x "$f" ] && . "$f"
  done
  unset f
fi
parcellite -n &
start-pulseaudio-x11
lxqt-policykit-agent &
[ -f ~/.Xresources ] && xrdb -merge ~/.Xresources
xset +fp /usr/share/fonts/
export XDG_CONFIG_HOME="$HOME/.config"
export QT_QPA_PLATFORMTHEME="qt5ct"
export XDG_RUNTIME_DIR=/var/run/user/1000
[ -d /sbin ] && PATH="$PATH:/sbin"
[ -d /usr/sbin ] && PATH="$PATH:/usr/sbin"
[ -d "$HOME/.bin" ] && PATH="$HOME/bin:$PATH"
[ -d "$HOME/.cargo/bin" ] && PATH="$HOME/.cargo/bin:$PATH"
[ -d "$HOME/.scripts/bin" ] && PATH="$HOME/.scripts/bin:$PATH"
[ -d "$HOME/.config/polybar/bin" ] && PATH="$HOME/.config/polybar/bin:$PATH"
/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
usr/bin/gnome-keyring-daemon --start --components=secrets &
pulseeffects --gapplication-service --load-preset freeqy &
/usr/lib/at-spi-bus-launcher --launch-immediately &
gnome-keyring-daemon --start --components=pkcs11 &
when-changed -r1q /var/log/pacman.log pkgupdates &
when-changed -r1q ~/.config/mpd/log mpd-conky &
xmodmap -e "keycode 135 = Super_R"
xsetroot -cursor_name left_ptr
amixer set channel 0% mute &
notification-daemon -r &
unclutter --timeout 2 &
rfkill block bluetooth
whenchanged &
xsettingsd &
beep -l 0 &
dwmblocks &
compton &
xset -b
wal -R
sleep 3 &&
pkgupdates &
dwm-wttr &

exec dwm
