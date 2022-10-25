build: main.c font.h
	echo "Building executable"
	
	mkdir -p "./Build"

	cc main.c -o "./Build/Big Letter"

	echo "Finished building executable"
	echo "Executable is located at './Build/Big Letter'"

usage:
	echo "Big Letter Usage:"
	echo "Location: ./Build/Big Letter"
	echo "Arguments:"
	echo "Required: Input Text"
	echo "Optional: Replacement True and False Characters"
	echo "Optional: Verbose"
	echo "'./Build/Big Letter' 'INPUT TEXT' 'TRUE CHAR' 'FALSE CHAR' 'v FOR VERBOSE"

clean:
	echo "Cleaning build directory"

	rm -rf "./Build"

	echo "Finished cleaning build directory"