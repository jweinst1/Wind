#ifndef LANG_INFO_H
#define LANG_INFO_H

// Header that contains macro string literals for information about the Wind Language

#define LangInfo_VERSION "0.0.1"

#define LangInfo_NAME "Wind"

#define LangInfo_REPL_INS "The Wind Programming Language REPL\nTo exit, simply enter 'exit'.\n"

#define LangInfo_HELP "The Wind Programming Language Help Guide\n \
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
