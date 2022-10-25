build: main.c
	echo "BUILDING"

	mkdir "./Build"
	cc main.c -o "./Build/Big Letter"

	echo "BUILT"

clean:
	rm -rf "./Build"