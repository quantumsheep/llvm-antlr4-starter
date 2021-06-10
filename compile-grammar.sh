#!/bin/bash

current_directory="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"

grammar_directory="$current_directory/src/grammar"

java -jar "$current_directory/bin/antlr-4.9.1-complete.jar" -Dlanguage=Cpp -no-listener -visitor -o "$grammar_directory/runtime" "$grammar_directory/FooLexer.g4" "$grammar_directory/FooParser.g4"

for file in $grammar_directory/runtime/*; do
    if [[ $file == *.h ]]; then
        sed -i.bak '1,3d' "$file"
    elif [[ $file == *.cpp ]]; then
        sed -i.bak '1,4d' "$file"
    fi
done

rm $grammar_directory/runtime/*.bak
