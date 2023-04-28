#!/bin/bash

# pretty date
date=$(date +"%m-%d-%H:%M")

# relative paths 
script_dir="$(dirname ${BASH_SOURCE[0]})"

# chapters
path_1=${script_dir}/1_bash
path_2=${script_dir}/2_programming_concepts
path_3=${script_dir}/3_languages
path_4=${script_dir}/4_game_industry
path_5=${script_dir}/5_game_engines
path_6=${script_dir}/6_linux
path_7=${script_dir}/7_vim
path_8=${script_dir}/8_web_development
path_9=${script_dir}/9_computing
path_10=${script_dir}/10_personal_configs
path_11=${script_dir}/11_devops
path_12=${script_dir}/12_Unreal_UdeMy
path_13=${script_dir}/13_kali

# documents
pdf_path=${script_dir}/pdf
latex_path=${script_dir}/latex
intermediate_path=${script_dir}/latex/intermediate

complete_path=${script_dir}/complete
answer_path=${script_dir}/answer

compile_latex() {
    for filename in ${latex_path}/*; do 
        if [ -f "$filename" ];
            then
                pdflatex $filename 
        fi
    done

    rm *.aux && rm *.log
    mv *.pdf pdf

    pdf_files=$(ls ${pdf_path}) 

    cd $pdf_path && pdfunite ${pdf_files} workbook_$date.pdf

    mv workbook* ../$complete_path
}

for i in {1..13}; do
  path="path_$i"
  files=$(ls ${!path})

    for filename in ${files}; do
        ext="${filename##*.}"
        case $ext in
        tex) 
            filepath=${!path}/$filename
            cp $filepath latex;;
        esac
    done
done

compile_latex
