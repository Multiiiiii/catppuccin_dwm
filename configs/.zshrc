# Path to your oh-my-zsh installation.
ZSH=/usr/share/oh-my-zsh/

# Path to powerlevel10k theme
source /usr/share/zsh-theme-powerlevel10k/powerlevel10k.zsh-theme

# List of plugins used
plugins=( git sudo zsh-256color zsh-autosuggestions zsh-syntax-highlighting )
source $ZSH/oh-my-zsh.sh

# In case a command is not found, try to find the package that has it
function command_not_found_handler {
    local purple='\e[1;35m' bright='\e[0;1m' green='\e[1;32m' reset='\e[0m'
    printf 'zsh: command not found: %s\n' "$1"
    local entries=( ${(f)"$(/usr/bin/pacman -F --machinereadable -- "/usr/bin/$1")"} )
    if (( ${#entries[@]} )) ; then
        printf "${bright}$1${reset} may be found in the following packages:\n"
        local pkg
        for entry in "${entries[@]}" ; do
            local fields=( ${(0)entry} )
            if [[ "$pkg" != "${fields[2]}" ]] ; then
                printf "${purple}%s/${bright}%s ${green}%s${reset}\n" "${fields[1]}" "${fields[2]}" "${fields[3]}"
            fi
            printf '    /%s\n' "${fields[4]}"
            pkg="${fields[2]}"
        done
    fi
    return 127
}

# Detect the AUR wrapper
if pacman -Qi yay &>/dev/null ; then
   aurhelper="yay"
elif pacman -Qi paru &>/dev/null ; then
   aurhelper="paru"
fi

function in {
    local -a inPkg=("$@")
    local -a arch=()
    local -a aur=()

    for pkg in "${inPkg[@]}"; do
        if pacman -Si "${pkg}" &>/dev/null ; then
            arch+=("${pkg}")
        else 
            aur+=("${pkg}")
        fi
    done

    if [[ ${#arch[@]} -gt 0 ]]; then
        sudo pacman -S "${arch[@]}"
    fi

    if [[ ${#aur[@]} -gt 0 ]]; then
        ${aurhelper} -S "${aur[@]}"
    fi
}

# Helpful aliases
alias  c='clear' # clear terminal
alias  l='eza -lh  --icons=auto' # long list
alias ls='eza -1   --icons=auto' # short list
alias ll='eza -lha --icons=auto --sort=name --group-directories-first' # long list all
alias ld='eza -lhD --icons=auto' # long list dirs
alias lt='eza --icons=auto --tree' # list folder as tree
alias un='$aurhelper -Rns' # uninstall package
alias up='$aurhelper -Syu' # update system/package/aur
alias pl='$aurhelper -Qs' # list installed package
alias pa='$aurhelper -Ss' # list availabe package
alias pc='$aurhelper -Sc' # remove unused cache
alias po='$aurhelper -Qtdq | $aurhelper -Rns -' # remove unused packages, also try > $aurhelper -Qqd | $aurhelper -Rsu --print -
alias p='sudo pacman'
# Example usage
alias vc='code' # gui code editor
alias vim='nvim'
alias sl='sl | lolcat'

# Handy change dir shortcuts
alias ..='cd ..'
alias ...='cd ../..'
alias .3='cd ../../..'
alias .4='cd ../../../..'
alias .5='cd ../../../../..'

alias grep='grep --color=auto'
alias rm='rm -i'
alias mv='mv -i'
alias vim='nvim'
alias svim='sudo nvim'
alias noorphans='sudo pacman -Rns $(pacman -Qtdq)'
alias ytdl='yt-dlp -o "~/Videos/%(title)s.%(ext)s"'
alias alias ytdlm='yt-dlp -x --audio-format opus \
  --embed-metadata --add-metadata --embed-thumbnail \
  -o "%(title)s.%(ext)s"'
alias vifm='$HOME/.config/vifm/scripts/vifmrun'
alias gitconf='git config user.name && git config user.email'
alias syncplay='QT_STYLE_OVERRIDE=kvantum-dark syncplay'
alias dolphin='QT_STYLE_OVERRIDE=kvantum-dark dolphin'
alias wttr='curl https://wttr.in'
alias hibernate='swaylock && systemctl hibernate'
alias polkit='/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &'
alias quote='$HOME/.scripts/quote.sh'
alias cowsay='cowsay -W $(tput cols)'
alias figlet='figlet -w $(tput cols)'
alias toilet='toilet -w $(tput cols) -f smblock'
source /usr/share/autojump/autojump.zsh

export PATH="$PATH:$HOME/.scripts"
export MANPAGER='nvim +Man!'

# Always mkdir a path (this doesn't inhibit functionality to make a single dir)
alias mkdir='mkdir -p'

# To customize prompt, run `p10k configure` or edit ~/.p10k.zsh.
[[ ! -f ~/.p10k.zsh ]] || source ~/.p10k.zsh

if [ $(tput cols) -gt 200 ]; then
    fastfetch
    quote | toilet 
elif [ $(tput cols) -gt 124 ]; then
    wttr 
elif [ $(tput cols) -gt 92 ] && [ $(tput lines) -gt 32 ]; then
    fastfetch
    quote | cowsay -f tux
elif [ $(tput lines) -gt 25 ]; then
    fastfetch
    quote
else
   quote
fi
