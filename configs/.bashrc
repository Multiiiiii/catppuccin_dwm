#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export QT_QPA_PLATFORMTHEME=qt5ct
shopt -s autocd

alias ls='ls --color=auto'
alias la='ls -A'
alias ..='cd ..'
alias ...='cd ../..'
alias grep='grep --color=auto'
alias rm='rm -i'
alias mv='mv -i'
alias sl='sl | lolcat'
alias p='sudo pacman'
alias vim='nvim'
alias svim='sudo nvim'
alias noorphans='sudo pacman -Rns $(pacman -Qtdq)'
alias ytdl='yt-dlp -o "~/Videos/%(title)s.%(ext)s"'
alias ytdlm='yt-dlp -x --audio-format opus -o "/home/m/Music/%(title)s.%(ext)s"'
alias vifm='$HOME/.config/vifm/scripts/vifmrun'
alias gitconf='git config user.name && git config user.email'
alias syncplay='QT_STYLE_OVERRIDE=kvantum-dark syncplay'
alias dolphin='QT_STYLE_OVERRIDE=kvantum-dark dolphin'
alias cowsay='cowsay -W $(tput cols)'
alias figlet='figlet -w $(tput cols)'
alias toilet='toilet -w $(tput cols) -f smblock'
source /usr/share/autojump/autojump.bash

export MANPAGER='nvim +Man!'
export PATH="$PATH:$HOME/.scripts"
export HISTCONTROL=ignoreboth
HISTSIZE=10000
HISTFILESIZE=500000
 
#if [ "$(tty)" = "/dev/tty1" ]; then 
#  pgrep -x dwm || exec startx
#fi

PS1='[\u@\h][\w]\$ '
if [ $(tput cols) -gt 200 ]; then
    fastfetch --load-config default.jsonc
    quote | toilet 
elif [ $(tput cols) -gt 124 ]; then
    wttr 
elif [ $(tput cols) -gt 92 ] && [ $(tput lines) -gt 32 ]; then
    fastfetch --load-config default.jsonc
    quote | cowsay -f tux
elif [ $(tput lines) -gt 25 ]; then
    fastfetch --load-config default.jsonc
    quote
else
   quote
fi
