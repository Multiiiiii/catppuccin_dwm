
#!/bin/bash

read -p "Is this a minimal intsall (no wm)? [Y/n]" yn
: ${yn:=y}
if [[ $yn == [Yy]* ]]; then

  echo "Skipping..."

else
 sudo cp dwm.desktop /usr/share/xsessions/
 sudo cp dwm.sh /usr/local/bin/
fi


read -p "Do you have ChaoticAUR? [y/N]" yn
: ${yn:=n}
if [[ $yn == [Yy]* ]]; then

  echo "Skipping..."

else
 echo "
 __  __       _    _
|  \\/  | __ _| | _(_)_ __   __ _
| |\\/| |/ _\` | |/ / | '_ \\ / _\` |
| |  | | (_| |   <| | | | | (_| |
|_|  |_|\\__,_|_|\\_\\_|_| |_|\\__, |
                           |___/
  ____ _                 _   _         _   _   _ ____
 / ___| |__   __ _  ___ | |_(_) ___   / \\ | | | |  _ \\
| |   | '_ \\ / _\` |/ _ \\| __| |/ __| / _ \\| | | | |_) |
| |___| | | | (_| | (_) | |_| | (__ / ___ \\ |_| |  _ <
 \\____|_| |_|\\__,_|\\___/ \\__|_|\\___/_/   \\_\\___/|_| \\_\\
"
sudo ./scripts/ChaoticAUR.sh
fi

 echo "
 ___           _        _ _ _
|_ _|_ __  ___| |_ __ _| | (_)_ __   __ _
 | || '_ \\/ __| __/ _\` | | | | '_ \\ / _\` |
 | || | | \\__ \\ || (_| | | | | | | | (_| |
|___|_| |_|___/\\__\\__,_|_|_|_|_| |_|\\__, |
                                    |___/
                  _
 _ __   __ _  ___| | ____ _  __ _  ___  ___
| '_ \\ / _\` |/ __| |/ / _\` |/ _\` |/ _ \\/ __|
| |_) | (_| | (__|   < (_| | (_| |  __/\\__ \\
| .__/ \\__,_|\\___|_|\\_\\__,_|\\__, |\\___||___/
|_|                         |___/
"
./scripts/pkginstall.sh 

echo "
                 _    _               ____             _    _
 _ __ ___   __ _| | _(_)_ __   __ _  / ___| _   _  ___| | _| | ___  ___ ___
| '_ \` _ \\ / _\` | |/ / | '_ \\ / _\` | \\___ \\| | | |/ __| |/ / |/ _ \\/ __/ __|
| | | | | | (_| |   <| | | | | (_| |  ___) | |_| | (__|   <| |  __/\\__ \\__ \\
|_| |_| |_|\\__,_|_|\\_\\_|_| |_|\\__, | |____/ \\__,_|\\___|_|\\_\\_|\\___||___/___/
                              |___/

"
./scripts/makesuckless.sh
echo "
                      _                   _       _    __ _ _
 _ __ ___   _____   _(_)_ __   __ _    __| | ___ | |_ / _(_) | ___  ___
| '_ \` _ \\ / _ \\ \\ / / | '_ \\ / _\` |  / _\` |/ _ \\| __| |_| | |/ _ \\/ __|
| | | | | | (_) \\ V /| | | | | (_| | | (_| | (_) | |_|  _| | |  __/\\__ \\
|_| |_| |_|\\___/ \\_/ |_|_| |_|\\__, |  \\__,_|\\___/ \\__|_| |_|_|\\___||___/
                              |___/

"
./scripts/configs.sh


read -p "Do you want to use my custom version of the Neo2 Keyboardlayout? [Y/n]" yn

: ${yn:=y}
if [[ $yn == [Yy]* ]]; then
    echo "
 _   _              ____
| \\ | | ___  ___   |___ \\
|  \\| |/ _ \\/ _ \\    __) |
| |\\  |  __/ (_) |  / __/
|_| \\_|\\___|\\___/  |_____|

"
.scripts/neoboard.sh
else
    echo "Skipping the command..."
fi




systemctl enable betterlockscreen@$USER

echo "
  __           _    __      _       _
 / _| __ _ ___| |_ / _| ___| |_ ___| |__
| |_ / _\` / __| __| |_ / _ \\ __/ __| '_ \\
|  _| (_| \\__ \\ |_|  _|  __/ || (__| | | |
|_|  \\__,_|___/\\__|_|  \\___|\\__\\___|_| |_|
"
.scripts/fast.sh

