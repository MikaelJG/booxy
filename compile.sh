#!/bin/bash

# pretty date
date=$(date +"%m-%d-%H:%M")

# relative paths 
script_dir="$(dirname ${BASH_SOURCE[0]})"

# chapters
path_1=${script_dir}/chap_1
path_2=${script_dir}/chap_2
path_3=${script_dir}/chap_3
path_4=${script_dir}/chap_4
path_5=${script_dir}/chap_5

# documents
pdf_path=${script_dir}/pdf
latex_path=${script_dir}/latex
complete_path=${script_dir}/complete

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
