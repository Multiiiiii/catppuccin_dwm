#!/bin/bash

get_random_line() {
    local file_h="$1"
        shuf -n 1 "$file_path"
}

file_path="$HOME/Documents/Zitate/quotes.txt"  # Replace with your file path
get_random_line "$file_path"
