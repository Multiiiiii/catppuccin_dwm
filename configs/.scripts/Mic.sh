#!/bin/bash

# Get the default source (microphone)
default_source=$(pactl get-default-source)

# Get the mute status of the default source
mute_status=$(pactl get-source-mute "$default_source" | awk '{print $2}')

# Output the result
if [ "$mute_status" = "yes" ]; then
    echo " "
else
    echo ""
fi
