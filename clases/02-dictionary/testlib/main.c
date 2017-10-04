#include <stdio.h>
#include <string.h>
#include "dict.h"

typedef struct a{
  char *name;
  int semestre;
} Student;

// TODO: Pedir como argumento la matrícula y regrese el nombre del estudiante
int main(int argc, char **argv){
  Dict *students;
  Student st;
  Student *newStudent;
  int errorCode;
  students = initDictionary(100, &errorCode);

  st.name = strdup("Miguel Perez");
  st.semestre = 7;
  upsertDictionary(students, "0202", (void *) &st, sizeof(Student), &errorCode);

  st.name = strdup("Christoforo El Fosforo");
  st.semestre = 10;
  upsertDictionary(students, "0101", (void *) &st, sizeof(Student), &errorCode);

  newStudent = (Student *) getDictonary(students, "0101", sizeof(Student), &errorCode);
  printf("name: %s, semestre: %d\n", newStudent->name, newStudent->semestre);

  return 0;
}
