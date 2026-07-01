#!/bin/bash

echo "=== Creating virtual environment ==="

python3 -m venv .venv

source .venv/bin/activate

python -m pip install --upgrade pip

if [ -f requirements/base.txt ]; then
    pip install -r requirements/base.txt
fi

echo ""
echo "Done!"