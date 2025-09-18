#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Course {
    int id;
    char *name;
};

struct Course *make_course(int id, char *name) {
    struct Course *new_course = malloc(sizeof(struct Course));
    new_course->id = id;
    // 这里的有错误
    new_course->name = name;

    // 这里应该返回一个地址
    return new_course;
}
int main() {
    struct Course *cs161 = make_course(161, "Computer Security");
    printf("Welcome to CS%d: %s!\n", cs161->id, cs161->name);

    return 0;
}
