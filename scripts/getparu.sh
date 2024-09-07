#!/usr/bin/env bash
git clone https://aur.archlinux.org/paru-bin.git
cd paru-bin && makepkg -sri --noconfirm
cd ~
