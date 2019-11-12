#!/bin/zsh
alias q='exit 0'
alias c='clear'
alias rsync='sudo rsync -r -v --progress -s' 
alias la='ls -Ah'
alias ll='ls -lAh'
alias l.='ls -ld .*'
alias wttr='curl wttr.in/22485'
alias settings='vim ~/.xsettingsd'
alias nc='--noconfirm'
alias updatedb='sudo updatedb'
alias cmatrix='cmatrix -C red'
alias snap='sudo snap'
alias peq=pulseaudio-equalizer
alias shmups='links shmups.com/xenocidefiles.html'
alias mkdir='mkdir -pv'
alias rmdir='rmdir --ignore-fail-on-non-empty'
alias grep='grep --color=auto'
alias debug="set -o nounset; set -o xtrace"
alias x='chmod +x'
alias keyconf='vim ~/.config/sxhkd/dwmrc'
alias du='du -kh'
alias df='df -kTh'
alias rn='rename'
alias i3conf='vim ~/.config/i3/config'
alias pbconf='vim ~/.config/polybar/master.conf'
alias bsconf='vim ~/.config/bspwm/bspwmrc'
alias dconf='vim ~/.config/dwm/config.h'
alias dmwc='~/.config/dmenu/ && sudo make clean install && cd ~/ && clear'
alias dmconf='vim ~/.config/dmenu/config.h'
alias dwc='~/.config/dwm/ && sudo make clean install && cd ~/ && clear'
alias stconf='vim ~/.config/st/config.h'
alias stwc='~/.config/st/ && sudo make clean install && cd ~/ && clear'
alias speedtest='speedtest-cli --server 18376'
alias baliasRC='vim ~/.bash/aliases.bash'
#GIT ALIASES#
alias bkup='/usr/bin/git --git-dir=$HOME/.bkup --work-tree=$HOME'
alias xs=startx
alias trashput=trash-put
alias trashempty='sudo trash-empty'
alias trashlist=trash-list
alias trashrestore=trash-restore
alias sudo='dbus-launch sudo'
alias crontab='sudo crontab'
#if hash nvim >/dev/null 2>&1; then
#    alias v='nvim'
#    alias sv='sudo nvim'
#else
#    alias v='vim'
#    alias sv='sudo vim'
#fi

alias f='ranger'

alias gp='git pull'
alias gf='git fetch'
alias gc='git clone'
alias gs='git stash'
alias gb='git branch'
alias gm='git merge'
alias gch='git checkout'
alias gcm='git commit -m'
alias glg='git log --stat'
alias gpo='git push origin HEAD'
alias gwch='git whatchanged -p --abbrev-commit --pretty=medium'

#aliases
alias grep=egrep make=gmake
#alias pin='sudo pacman -S'    # install
#alias pun='sudo pacman -Rs'   # remove
#alias pcc='sudo pacman -Scc'  # clear cache
#alias pls='pacman -Ql'        # list files
alias prm='sudo pacman -R --nosave --recursive' # really remove, configs and all

#yay and pacman aliases
alias pacman='sudo pacman'
alias pm='sudo pacman'
alias pacman-repair='pacman -Sy archlinux-keyring archlabs-keyring 
&& sudo pacman-key --refresh-keys'
alias killdb='sudo rm /var/lib/pacman/db.lck'
alias yo=yay
alias aur-check=checkupdates-aur
alias yup="yay -Syyuu && pkgupdates"
alias pkg='makepkg --printsrcinfo > .SRCINFO && makepkg -fsrc'
alias spkg='pkg --sign'
alias pup="pkgupdates"
alias mk='make && make clean'
alias smk='sudo make clean install && make clean'
alias ssmk='sudo make clean install && make clean && rm -iv config.h'
alias fmsu="lxqt-sudo dbus-launch --exit-with-session pcmanfm-qt"
# aliases inside tmux session
if [[ $TERM == *tmux* ]]; then
    alias :sp='tmux split-window'
    alias :vs='tmux split-window -h'
fi
alias clock='clear; while true; do echo -e \\b\\b\\b\\b\\b\\b\\b\\b`date +%T`\\c ; sleep 1; done'
alias rmv='rcp --remove-source-files'

alias mir='sudo reflector --score 100 -l 50 -f 10 --sort rate --save /etc/pacman.d/mirrorlist --verbose'

alias gif='byzanz-record -x 1090 -w 750 -y 430 -h 480 -v -d 15 ~/Videos/$(date +%a-%d-%S).gif'
alias rec='ffmpeg -video_size 1920x1080 -framerate 60 -f x11grab -i :0.0 -c:v libx264 -qp 0 -preset ultrafast ~/Videos/$(date +%a-%d-%S).mkv'

alias calc='python -qi -c "from math import *"'
alias brok='sudo find . -type l -! -exec test -e {} \; -print'
alias timer='time read -p "Press enter to stop"'

# shellcheck disable=2142
alias xp='xprop | awk -F\"'" '/CLASS/ {printf \"NAME = %s\nCLASS = %s\n\", \$2, \$4}'"
alias get='curl --continue-at - --location --progress-bar --remote-name --remote-time'
