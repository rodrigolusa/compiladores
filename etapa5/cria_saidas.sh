#!/bin/bash
for entrada in entradas/*;
do
  filename="$(basename $entrada)"
  if [ ! -f "saidas/$filename" ]
  then
    touch "saidas/$filename";
  fi
  ./etapa5 < "$entrada" > "saidas/$filename";
done
