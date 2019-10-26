#!/bin/bash
alias q='exit 0'
alias d='clear'
#alias rsync='sudo rsync -r -t -p -o -v --progress -s' 
alias la='ls -Ah'
alias ll='ls -lAh'
alias l.='ls -ld .*'
alias wttr='curl wttr.in/22485'
alias settings='vim ~/.config/xsettingsd/xsettingsd.conf'
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
alias keyconf='vim ~/.config/sxhkd/sxhkdrc'
alias du='du -kh'
alias df='df -kTh'
alias rn='rename'
alias i3conf='vim ~/.config/i3/config'
alias pbconf='vim ~/.config/polybar/master.conf'
alias bsconf='vim ~/.config/bspwm/bspwmrc'
alias yaconf='vim ~/.config/yabar/yabar.conf'
alias baliasRC='vim ~/.bash/aliases.bash'
alias xs=startx
#if hash nvim >/dev/null 2>&1; then
#    alias vim='nvim'
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
alias grep=egrep ps=sps make=gmake
#alias pup='yes | sudo pacman -Syyu' # update
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
alias snap='sudo snap'
#surf aliases
alias *.com='surf *.com'


alias pkg='makepkg --printsrcinfo > .SRCINFO && makepkg -fsrc'
alias spkg='pkg --sign'

alias mk='make && make clean'
alias smk='sudo make clean install && make clean'
alias ssmk='sudo make clean install && make clean && rm -iv config.h'

# aliases inside tmux session
if [[ $TERM == *tmux* ]]; then
    alias :sp='tmux split-window'
    alias :vs='tmux split-window -h'
fi

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
