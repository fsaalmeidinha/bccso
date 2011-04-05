# by Heredia, Eduardo (C) 2011

.PHONY: all clean

all: pi_proc pi_proc.pdf

pi_proc: pi_proc.c
	gcc pi_proc.c -o pi_proc -Wall -std=c99

pi_proc.pdf: pi_proc.tex
	pdflatex pi_proc.tex
	@rm -f pi_proc.aux
	@rm -f pi_proc.log

clean:
	@rm -f pi_proc
	@rm -f pi_proc.pdf
	@rm -f pi_proc.aux
	@rm -f pi_proc.log
