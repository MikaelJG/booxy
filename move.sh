#!/bin/bash

# script directory
script_dir=$(dirname ${BASH_SOURCE[0]})

# book paths
CHAP_ONE_PATH="${script_dir}/chap_1"
CHAP_TWO_PATH="${script_dir}/chap_2"
CHAP_THREE_PATH="${script_dir}/chap_3"
CHAP_FOUR_PATH="${script_dir}/chap_4"

# document paths
PDF_PATH="${script_dir}/pdf"
LATEX_PATH="${script_dir}/latex"
COMPLETE_PATH="${script_dir}/complete"
LOG_PATH="${script_dir}/log"

if_path_exists_move() {
    [ -d "$1" ] && cd $1 ; clear
}

case $1 in
    one|first_chap_title)
        if_path_exists_move $CHAP_ONE_PATH;;
    two|second_chap_title)
        if_path_exists_move $CHAP_TWO_PATH;;
    three|third_chap_title)
        if_path_exists_move $CHAP_THREE_PATH;;
    four|fourth_chap_title)
        if_path_exists_move $CHAP_FOUR_PATH;;
    pdf)
        if_path_exists_move $PDF_PATH;;
    latex)
        if_path_exists_move $LATEX_PATH;;
    complete)
        if_path_exists_move $COMPLETE_PATH;;
    log)
        if_path_exists_move $LOG_PATH;;
    *)
        echo "Keyword doesn't exist";;
esac
