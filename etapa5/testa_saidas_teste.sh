#!/bin/bash
for teste in entradas/*; 
do
  filename="$(basename $teste)"
  if [ ! -f "saidas_teste/$filename" ]
  then
    touch "saidas_teste/$filename";
  fi
  ./etapa5 < "$teste" > "saidas_teste/$filename";
  echo "$teste"
  diff "saidas_teste/$filename" "saidas/$filename";
done
