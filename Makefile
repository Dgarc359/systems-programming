main: main.c
	gcc -o main main.c

teach: teacher-sol.c
	gcc -o teach teacher-sol.c

clean:
	rm -rf main teach