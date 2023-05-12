compile_latex() {
    # .log in log ; .pdf in pdf
    mv *.aux log ; mv *.log log ; mv *.pdf pdf

    pdf_files=$(ls ${pdf_path}) 

    cd $pdf_path && pdfunite ${pdf_files} workbook_$date.pdf

    mv workbook* ../$complete_path
}

# loop over number of chapters
for i in {1..5}; do
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
