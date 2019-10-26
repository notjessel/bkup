#!/bin/bash

# Public Domain

# Requirements:
# sed

# Example usage:
#
# ${exec ./getWeatherValue.sh <WEATHERFILE> <VALUE>}
#
# ${exec ./getWeatherValue.sh ./tmp/IWIENWIE4.json temperature_string}

sed -nr "s/\"$2\":\"?([^\"]+)\"?,/\1/p" "$1" | sed "s/^[[:space:]]*//"

