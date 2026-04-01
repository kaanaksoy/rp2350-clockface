#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
UF2_FILE="$SCRIPT_DIR/app/build/src/RP2350Clockface.uf2"

VOLUME_NAME=RP2350
BOOTSEL_WAIT_SECS=5

if [[ ! -f "$UF2_FILE" ]]; then
    echo "Error: UF2 file not found at $UF2_FILE"
    echo "Have you built the project?"
    exit 1
fi

if [[ ! -d "/Volumes/$VOLUME_NAME" ]]; then
    SERIAL_DEV=$(ls /dev/tty.usbmodem* 2>/dev/null | head -n1 || true)

    if [[ -z "$SERIAL_DEV" ]]; then
        echo "Error: No $VOLUME_NAME volume or USB serial device found."
        echo "Make sure the board is connected."
        exit 1
    fi

    echo "Board is running. Triggering BOOTSEL via $SERIAL_DEV ..."
    stty -f "$SERIAL_DEV" 1200

    echo -n "Waiting for $VOLUME_NAME volume to appear "
    for ((i = 0; i < BOOTSEL_WAIT_SECS * 2; i++)); do
        if [[ -d "/Volumes/$VOLUME_NAME" ]]; then
            echo " found! Waiting for volume to settle ..."
            sleep 1
            break
        fi
        echo -n "."
        sleep 0.5
    done

    if [[ ! -d "/Volumes/$VOLUME_NAME" ]]; then
        echo ""
        echo "Error: $VOLUME_NAME volume did not appear after ${BOOTSEL_WAIT_SECS}s."
        echo "Try holding BOOTSEL and resetting manually."
        exit 1
    fi
fi

echo "Found device at /Volumes/$VOLUME_NAME"
echo "Copying $(basename "$UF2_FILE") ..."
cp "$UF2_FILE" "/Volumes/$VOLUME_NAME/"
echo "Done. Device will reboot automatically."
