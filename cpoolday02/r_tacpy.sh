#!/bin/bash
MY_LINE1=$MY_LINE1
MY_LINE2=$MY_LINE2

sed '1d' | sed -n '1~2p' | cut -d ':' -f '1' | rev | sort -r | sed -n "$MY_LINE1,$MY_LINE2 p" | sed -z 's/\n/, /g' | sed -r 's/(.*), /\1.\n/g'

