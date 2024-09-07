
#!/bin/bash

# Query the mute status of source #1539
MUTE_STATUS=$(pactl list sources | grep -A 10 'input' | grep 'Mute:' | awk '{print $2}')

# Check if the mute status is 'yes' or 'no'
if [ "$MUTE_STATUS" == "yes" ]; then
    # If muted, output the Unicode symbol for muted ()
    echo "  "
else
    # If not muted, output the Unicode symbol for unmuted ()
    echo ""
fi
