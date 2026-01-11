#!/usr/bin/bash
# Run at the root of the project

BIN_DIR="./bin"

if [ ! -d "$BIN_DIR" ]; then
	echo "Test binary directory ($BIN_DIR) not found"
	echo "Ensure that the binaries have been compiled and this scripts is run from the root of the project"
	exit
fi

echo "========================================"
echo "Running all tests"
echo "========================================"

COUNT=0;

for FILE in "$BIN_DIR"/*; do
	if [ -f "$FILE" ]; then
        echo -e "\n========================================"
        echo    "Executing test binary $FILE"
        echo    "========================================"
		./$FILE
		((COUNT++));
	fi
done

echo -e "\n========================================"
echo    "Ran $COUNT test binaries"
echo    "========================================"

