@echo off

gcc  main.c           ^
    -std=c99          ^
    -o randomizer.exe ^
    -Wall             ^
    -Wextra           ^
    -Werror           ^
    -fmax-errors=5

if NOT ERRORLEVEL 1 (
    randomizer.exe ../EUR_15min.json output.json
)

