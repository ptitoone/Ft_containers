#!/bin/bash

CC="g++"
FILES=$(ls ./vector)
CLEAN=$1
RED="\033[31m"
GREEN="\033[32m"
RESET="\033[0m"

if [ "$CLEAN" == "clean" ]
then
    rm -rf bin/* diff/* log/* out/*
else
    rm -rf bin/* diff/* log/* out/*
    for FILE in $FILES
    do
        NAME=$(echo $FILE | cut -d . -f 1)
        
        $CC -Wall -Wextra -Werror -std=c++98 -D__FT=0 vector/$FILE base.cpp -o bin/std_$NAME.out 2> log/std_$NAME.log
        $CC -Wall -Wextra -Werror -std=c++98 -D__FT=1 vector/$FILE base.cpp -o bin/ft_$NAME.out 2> log/std_$NAME.log

        if [ -s "log/ft_$NAME.log" ]
        then
            echo -e "$NAME: $RED Does not compile$RESET"
        elif [ -s "log/std_$NAME.log" ]
        then
            echo -e "$NAME: $RED Does not compile$RESET"
        else
            ./bin/std_$NAME.out > out/std_$NAME.output
            ./bin/ft_$NAME.out > out/ft_$NAME.output
            DIFF=$(diff out/std_$NAME.output out/ft_$NAME.output)
            echo "$DIFF" > diff/$NAME.diff

            if [ -z "$DIFF" ]
            then
                echo -e "$NAME: $GREEN OK$RESET"
            else
                echo -e "$NAME: $RED FAILED$RESET"
            fi
        fi
    done
fi