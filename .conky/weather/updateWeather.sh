#!/bin/bash

# Public Domain

# Requirements:
# http://www.wunderground.com API Key (means, account), curl

# Example usage:
#
# {exec updateWeather.sh <STATION>}
#
# {exec updateWeather.sh IWIENWIE4}

apikey=GETYOUROWN
base=$(dirname $0)
tmp=$base/tmp

if [ ! -d $tmp ]; then
	mkdir $tmp
fi

# Fetch the data
curl -s http://api.wunderground.com/api/$apikey/conditions/q/pws:$1.json > $tmp/$1.json

# Remove the old icon
if [ -e $tmp/$1_current ]; then
	rm $tmp/$1_current
fi

# Get the current weather icon
current=$($base/getWeatherValue.sh $tmp/$1.json icon)

# Link against it
ln $base/weather_icons/day/$current.png $tmp/$1_current
