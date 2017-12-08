#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "Exec.h"
#include "WindList.h"

int main(int argc, char const *argv[]) {
        /*WindObject_INIT(foo);
           WindObject* foop = &foo;
           char* src = "in [ \"50\" ] -> + \"rrr\" -> d";
           char* codeSrc = src;
           char** srcad = &codeSrc;
           Translate_cmd(foop, srcad);
           Debug_obj(foop);
           Translate_transition(foop, srcad);
           Exec_exec(foop);
           foop->state = WindState_Translate;
           Translate_cmd(foop, srcad);
           Translate_transition(foop, srcad);
           Debug_obj(foop);
           Exec_exec(foop);
           Debug_obj(foop);*/


        WindList* doo = NULL;
        WindList_INIT(doo, 10);
        WindList_EXPAND_2(doo);
        printf("space is %lu\n", WindList_SPACE(doo));

        return 0;
}
