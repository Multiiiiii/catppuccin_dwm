if pactl get-sink-mute @DEFAULT_SINK@ | grep -q 'yes'; then
    echo "×"
else
    wpctl get-volume @DEFAULT_AUDIO_SINK@ | awk '{print $2*100 "%"}'
fi

