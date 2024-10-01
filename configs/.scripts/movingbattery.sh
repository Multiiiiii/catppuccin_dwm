#!/bin/bash
battery_level=$(upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep -oP 'percentage:\s*\K\d+' | head -n 1)    

if [ "$battery_level" == "100" ]; then
  # full
  echo "^r0,10,2,4^^r2,7,22,10^^c#a6e3a1^^r3,8,20,8^^d^^f24^"
elif [ "$battery_level" -ge "90" ]; then
  # 90%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#a6e3a1^^r5,8,18,8^^d^^f24^"
elif [ "$battery_level" -ge "80" ]; then
  # 80%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#a6e3a1^^r7,8,16,8^^d^^f24^"
elif [ "$battery_level" -ge "70" ]; then
  # 70%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#a6e3a1^^r9,8,14,8^^d^^f24^"
elif [ "$battery_level" -ge "60" ]; then
  # 60% 
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#ffffff^^r11,8,12,8^^d^^f24^"
elif [ "$battery_level" -ge "50" ]; then
  # 50% 
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#f9e2af^^r13,8,10,8^^d^^f24^"
elif [ "$battery_level" -ge "400" ]; then
  # 40%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#f9e2af^^r16,8,7,8^^d^^f24^"
elif [ "$battery_level" -ge "30" ]; then
  # 30%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#f9e2af^^r18,8,5,8^^d^^f24^"
elif [ "$battery_level" -ge "20" ]; then
  # 20%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#f38ba8^^r19,8,4,8^^d^^f24^"
else
  # 10%
  echo "^r0,10,2,4^^r2,7,22,10^^c#000000^^r3,8,20,8^^c#f38ba8^^r21,8,2,8^^d^^f24^"
fi
