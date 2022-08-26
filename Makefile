main: main.c
	gcc -o main main.c

teach: teacher-sol.c
	gcc -o teach teacher-sol.c

print-ex: print-example.c
	gcc -o print-ex print-example.c

clean:
	rm -rf main teach print-ex