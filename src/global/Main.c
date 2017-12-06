#include <stdio.h>
#include "Translate.h"
#include "Debug.h"
#include "Exec.h"
#include "WindList.h"
int main(int argc, char const *argv[]) {
        /*WindObject_INIT(foo);
           WindObject* foop = &foo;
           char* src = "in 50 -> / 5 -> d";
           char* codeSrc = src;
           char** srcad = &codeSrc;
           Translate_cmd(foop, srcad);
           Translate_transition(foop, srcad);
           Exec_exec(foop);
           foop->state = WindState_Translate;
           Translate_cmd(foop, srcad);
           Translate_transition(foop, srcad);
           Debug_obj(foop);
           Exec_exec(foop);
           Debug_obj(foop);*/

        WindList* lst = WindList_new(6);
        printf("mark is set as beg %d\n", lst->begin == lst->mark);
        WindList_free(lst);
        return 0;
}
