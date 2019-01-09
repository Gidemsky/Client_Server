#include <iostream>
#include "Separator.h"

#define FILE_NAME_INDEX 1

/**
 * Run the program
 * @param file_name is the file name to read from.
 */
void run(string file_name) {
    Separater *separater = new Separater(file_name);
    //string lexer_data = separater->getFlightUserInput();
    //Interpreter *parser = new Interpreter(lexer_data);
}

/**
 * Main
 * @param argc
 * @param argv includes the file name of the script.
 */
int main(int argc, char *argv[]) {
    // notify that we start to run the program
    run(argv[FILE_NAME_INDEX]);
    // delete allocated memory from the data
    // close the pthread
    //pthread_exit(nullptr);
}