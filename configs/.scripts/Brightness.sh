
echo "$(brightnessctl get | awk '{print int(100*($1/255))}')"
