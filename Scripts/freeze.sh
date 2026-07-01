#!/bin/bash

source .venv/bin/activate

pip freeze > requirements/base.txt

echo "requirements updated."