#!/bin/bash

# Set the source and destination paths
SOURCE_DIR="/home/anadi/Programs/pico/RP2040/cmake-build-debug"
DEST_DIR="/media/anadi/RPI-RP2"

# Check if any .uf2 files are present in the source directory
if ! ls "$SOURCE_DIR"/*.uf2 1> /dev/null 2>&1; then
    echo "No .uf2 file found in $SOURCE_DIR."
    exit 1
fi

# Check if the RPI-RP2 flash drive is mounted
if [ ! -d "$DEST_DIR" ]; then
    echo "The RPI-RP2 drive is not mounted."
    exit 1
fi

# Copy the .uf2 file to the flash drive
cp "$SOURCE_DIR"/*.uf2 "$DEST_DIR/"
if [ $? -eq 0 ]; then
    echo "File copied successfully to $DEST_DIR."
else
    echo "Failed to copy the file."
    exit 1
fi
