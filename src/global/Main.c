#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "Exec.h"
#include "WindList.h"

int main(int argc, char const *argv[]) {
        WindObject_INIT(foo);
        WindObject* foop = &foo;
        char* src = "in [ 1 2 3 4 5 6 7 8 9 10 11 ] | + \"rrr\" -> d";
        char* codeSrc = src;
        char** srcad = &codeSrc;
        Translate_cmd(foop, srcad);
        Debug_obj(foop);
        Translate_transition(foop, srcad);
        Exec_exec(foop);
        Debug_obj(foop);
        foop->state = WindState_Translate;
        /*Translate_cmd(foop, srcad);
           Translate_transition(foop, srcad);

           Exec_exec(foop);
           Debug_obj(foop);*/

        return 0;
}
