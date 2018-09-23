# vbibcompl - Create vim omnicopletion data for citations in LaTeX

vbibcompl is a small utuility to create the necessary data for vim omnicomplition
in LaTeX citation contexts.

Consider you want to trigger completion in a LaTeX file at

    Lorem Ipsum~\cite{|....

vbibcompl traverses all Bibtex files in the current directory and subdirectories and 
generates a dictonary structure as required by vim.

## Usage

Run
     
     vbibcompl -h

For usage options

## Example usage

Create e.g., an autocommand in vim, when you save a bib file (in your ~/.vimrc):

    augroup bibcompl
    au!
    au BufWrite *.bib <silent>:call system('vbibcompl -o bibcompl.txt')
    augroup end

This will run the program, each time a Bibtex file is saved and store the results in 
bibcompl.txt.

Now in your completion function, when you have decided a bibtex key is due (I do this with
a regex).

    let l:compl_data = {}
    let l:raw_data = readfile('bibcompl.txt')[0]
    call execute('let l:compl_data = ' . l:raw_data)

    return l:compl_data

That's it.

## Build / Install

vbibcompl requires non extra libraries, just C++17 including the standard filesystem library,
so any recent C++ compiler should do. For the build, cmake and make are required. 
To build vbibcompl, run the following

    mkdir build
    cd build/
    cmake ..
    make

Copy the resulting build/src/vbibcompl binary somewhere to you path (e.g., /usr/local/bin/).

## Version / Maturity

It's a very pre-alpha, only tested on my machine (Fedora Linux 28) with some Bibtex files.




