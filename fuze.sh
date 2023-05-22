#!/bin/bash

# relative paths 
script_dir="$(dirname ${BASH_SOURCE[0]})"
path_1=${script_dir}/3_languages/cpp
path_2=${script_dir}/3_languages/go
path_3=${script_dir}/3_languages/rust
path_4=${script_dir}/3_languages/ruby
path_5=${script_dir}/3_languages/typescript
path_6=${script_dir}/3_languages/javascript
path_7=${script_dir}/3_languages/lua
path_8=${script_dir}/3_languages/html
path_9=${script_dir}/3_languages/asm
path_10=${script_dir}/3_languages/csharp

# documents
all_language_path=${script_dir}/3_languages/all
language_path=${script_dir}/3_languages

for i in {1..10}; do
# for all paths in complex language chapter
    path="path_$i"
    files=$(ls ${!path})

    for file in $files; do

        ext="${file##*.}"

        case $ext in
            tex) 
                filepath=${!path}/$file
                cp $filepath $all_language_path
                echo "Done with: --  $filepath";;
        esac

        sed -i '/documentclass{arti/d' ${!path}/$file || echo 'sed cmd failed'
        sed -i '/usepacka/d' ${!path}/$file || echo 'sed cmd failed'
        sed -i '/author{/d' ${!path}/$file || echo 'sed cmd failed'

        # don't lose the section's title
        sed -i 's/title{/section{/g' ${!path}/$file || echo 'sed cmd failed'
        sed -i '/begin{do/d' ${!path}/$file || echo 'sed cmd failed'
        sed -i '/maketit/d' ${!path}/$file || echo 'sed cmd failed'
        sed -i '/end{do/d' ${!path}/$file || echo 'sed cmd failed'

        sed -i '/^$/N;/^\n$/D' ${!path}/$file || echo 'sed cmd failed'

        cat ${!path}/$file >> 3_languages/3_languages.tex 
    done
done
    
    sed -i '/end{do/d' 3_languages/3_languages.tex || echo 'sed cmd failed'
    # end doc in chapter.tex
    echo "\\end{document}" >> 3_languages/3_languages.tex

