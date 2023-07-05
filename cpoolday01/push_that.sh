#!/bin/bash
comment=$1

if [[ -z "$1" ]]; then
	echo "vous devez mettre un commentaire."
else
	if [[ -n $(git status -s) ]]; then 
		git add .
		git commit -m "$1"
		git push -u origin main
	else
		echo "il n'y a rien a pousser"
	fi
fi
