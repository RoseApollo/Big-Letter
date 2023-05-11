build: main.c
	@echo "Building executable"

	@mkdir -p "./Build"

	@clang main.c carg-parse/carg-parse.c -o "./Build/BigLetter"

	@echo "Finished building executable"
	@echo "Executable is located at './Build/BigLetter'"

usage:
	@echo "BigLetter Usage:"
	@echo "Location: ./Build/BigLetter"
	@echo "Arguments:"
	@echo "Required: Input Text"
	@echo "Optional: Replacement True and False Characters"
	@echo "Optional: Verbose"
	@echo "'./Build/BigLetter' 'INPUT TEXT' -trueC 'TRUE CHAR' -falseC 'FALSE CHAR' -v

example:
	@"./Build/BigLetter" "Hello, World!"

test: ./Build/BigLetter
	@echo "If any of these tests segfault, or do not output Hello, World!, then either revert your changes or open an issue"
	@"./Build/BigLetter" "Hello, World!"
	@"./Build/BigLetter" "Hello, World!" -v
	@"./Build/BigLetter" "Hello, World!" -trueC @
	@"./Build/BigLetter" "Hello, World!" -falseC @
	@"./Build/BigLetter" "Hello, World!" -trueC @ -falseC y
	@"./Build/BigLetter" "Hello, World!" - trueC @ -falseC y -v

clean:
	@echo "Cleaning build directory"

	@rm -rf "./Build"

	@echo "Finished cleaning build directory"