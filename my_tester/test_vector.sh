#!/bin/bash

CC="g++"
FILES=$(ls ./vector)
CLEAN=$1

if [ "$CLEAN" == "clean" ]
then
    rm -rf bin/* diff/* out/*
else
    for FILE in $FILES
    do
        $CC -Wall -Wextra -Werror -std=c++98 -D__FT=0 vector/$FILE base.cpp -o bin/std_$FILE.out
        ./bin/std_$FILE.out > out/std_$FILE.output

        $CC -Wall -Wextra -Werror -std=c++98 -D__FT=1 vector/$FILE base.cpp -o bin/ft_$FILE.out
        ./bin/ft_$FILE.out > out/ft_$FILE.output

        DIFF=$(diff out/std_$FILE.output out/ft_$FILE.output)
        echo $DIFF > diff/$FILE.diff

        if [ "$DIFF" == "" ]
        then
            echo $FILE: "TEST OK"
        else
            echo $FILE: "TEST FAILED"
        fi
    done
fi