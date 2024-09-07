#!/bin/bash
sudo pacman -Syu
# Read the package list
while IFS= read -r package; do
    # Check if the package is available in the official repositories
    if pacman -Si "$package" >/dev/null 2>&1; then
        echo "Installing $package with pacman..."
        sudo pacman -S --needed --noconfirm "$package"
    else
        echo "Installing $package with paru..."
        paru -S --needed --noconfirm "$package"
    fi
done < packages.txt
