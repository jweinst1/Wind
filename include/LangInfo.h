#ifndef LANG_INFO_H
#define LANG_INFO_H

// Header that contains macro string literals for information about the Wind Language

#define LangInfo_VERSION "0.0.1"

#define LangInfo_NAME "Wind"

#define LangInfo_REPL_INS "The Wind Programming Language REPL\nTo exit, simply enter 'exit'.\n"

#define LangInfo_HELP "The Wind Programming Language Help Guide\n \
         save command: \n \
              The save command allows you to save the current active data \n \
              to a file path. This file is written in the Wind binary format.\n \
              Using this allows you to save and load an infinite amount of states\n \
              that Wind can operate and run from.\n \
              __example__: push 3 5 -> map ** 4 | + 4 -> save \"nums\"\n \
              Saved at: nums\n \
              _______________________ \n \
              A file named 'nums.bwind' will appear on disk. \n \
         load command: \n \
              The load command allows you to load binary wind files into the current active data. \n \
              This command permits Wind to load data from an infinite number of sources, \n \
              and expand it's processing capabilities to an immense degree. \n \
              __example__: push 3 5 -> map ** 4 | + 4 -> save \"nums\" ->\n \
                          clr -> load \"nums\" -> out\n \
              [ 85 629 ] \n \
         reduce command: \n \
              The reduce command fuses data through a flow of operations. \n \
              It can be used with operations like +.\n \
              __example__: push 3 3 3 3 3 -> reduce + -> out\n \
              [ 15 ] \n \
         filter command: \n \
              The filer command restricts data through a flow of operations. \n \
              It can be used with operations like < or > or !. \n \
              __example__: push 5 4 -> map + 3 | * 3 -> out -> filter > 22 -> out \n \
              [ 24 21 ]\n \
              [ 24 ]\n \
          map command: \n \
              The map command transforms data through a flow of operations. \n \
              It can be used with operations like +, - and more. \n \
              __example__: push 5 5 -> map + 3 | * 3 -> out \n \
              [ 24 24 ]\n \
          push command: \n \
              The push command appends data to the end of the active data. \n \
              __example__: push 5 6 7 -> out \n \
             [ 5 6 7 ]\n \
          out command: \n \
              The out command prints the entire active data to stdout. \n \
          clr command: \n \
              The clr command resets the active data.\n"

#endif
