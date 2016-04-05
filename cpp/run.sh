#!/bin/bash
if [ "$#" -ne 4 ]; then
    echo "Usage: $0 WIDTH HEIGHT SPEED FILE"
    exit 1
fi

./bin/conway-engine $1 $2 $4 | python scripts/conway-player.py $1 $2 $3