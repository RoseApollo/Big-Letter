build: main.c
	echo "Building executable"
	
	mkdir -p "./Build"

	clang main.c -o "./Build/BigLetter"

	echo "Finished building executable"
	echo "Executable is located at './Build/BigLetter'"

usage:
	echo "BigLetter Usage:"
	echo "Location: ./Build/BigLetter"
	echo "Arguments:"
	echo "Required: Input Text"
	echo "Optional: Replacement True and False Characters"
	echo "Optional: Verbose"
	echo "'./Build/BigLetter' 'INPUT TEXT' 'TRUE CHAR' 'FALSE CHAR' 'v FOR VERBOSE"

example: ./build/BigLetter
	"./Build/BigLetter" "Hello, World"

clean:
	echo "Cleaning build directory"

	rm -rf "./Build"

	echo "Finished cleaning build directory"