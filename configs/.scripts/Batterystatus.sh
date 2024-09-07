if [[ $(cat /sys/class/power_supply/BAT0/status) == "Charging" ]]; then
    echo "  "
fi
