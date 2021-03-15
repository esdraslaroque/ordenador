#!/bin/bash
for a in insertion quick bucket; do
	for n in 100 1000 10000 100000; do
		for j in ale inv sord ord; do
			echo "Gerando dados para $a no estado $j"
			for i in 1 2 3 4 5 6 7 8 9 10; do
				echo "$a $j $n$(./ordenador --tamanho $n --estado $j --algoritmo $a | grep Compara | awk -F':' '{print $2}')" >> $a.dat
			done
		done
	done
done
