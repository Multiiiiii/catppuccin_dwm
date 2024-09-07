
#!/bin/bash

# Check Mullvad VPN connection status and get location if connected
vpn_status=$(mullvad status -v)

if [[ $vpn_status == *"Connected"* ]]; then
    # Extract location from the status output
    location=$(echo "$vpn_status" | awk '/Connected/ {print $6, $7}')
    echo "  $location"
else
    echo ""
fi

