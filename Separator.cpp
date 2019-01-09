//
// Created by gideon on 08/01/19.
//

#include "Separator.h"

#include <algorithm>
#include <list>

#define INPUT_SPLIT ","
#define FILE_SPACE " "
#define CMD_SPLIT "#"
#define LINE_SPLITER "|"

/**
 * Ctor
 * @param userFileName
 */
Separater::Separater(string userFileName) {
    this->matrix_client_input = fileReader(&client_input_file, userFileName);
}

/**
 * Function Name: lexer
 * @param line - the line for lexing
 * @param split - the split sign between the commands
 * @return - a string that ready to be add to all commands string (commandsFileLine)
 */
string Separater::lexer(string line, string split) {
    //int sub_pos; changed
    bool tab_begin = false;
    size_t pos, sub_pos;
    string dataTaken, final_line;
    bool is_converted = false;
    //run the loop as far as it has space bars before the line string
    while (line.at(0) == ' ') {
        line.erase(0, 1);
    }

    while ((pos = line.find(split)) != string::npos) {
        while (line.at(0) == ' ') {
            line.erase(0, 1);
            tab_begin = true;
        }
        //clears the space bar before the string.
        if (tab_begin) {
            sub_pos = line.find(split);
            if (sub_pos < 0) {
                sub_pos = line.length();
                dataTaken += line.substr(0, sub_pos);
                line.erase(0, sub_pos + split.length());
            } else {
                dataTaken += line.substr(0, sub_pos);
                line.erase(0, sub_pos + split.length());
            }
            tab_begin = false;
        } else {
            dataTaken += line.substr(0, pos);
            line.erase(0, pos + split.length());
        }
    }

    //adds the last string left in the line
    //deletes the number in the begging of the line
    dataTaken += line.substr(0, pos) + LINE_SPLITER;

    /*
     * this block responsible to locolize the (-) sign and rearange
     * the string for correct shunting yard progress
     * example: -5400 = (0-5400)
     * example: -54*-100 = (0-5400)*(0-100)
     */
    while ((pos = dataTaken.find('-')) != string::npos) {
        if (dataTaken.at(pos - 1) == '*' || dataTaken.at(pos - 1) == '|'
            || dataTaken.at(pos - 1) == '+' || dataTaken.at(pos - 1) == '/'
            || (dataTaken.at(pos - 1) == ' ' &&
                (dataTaken.at(pos - 1) != ')' || dataTaken.at(pos - 1) != '('))) {
            dataTaken.insert(pos, "(0");
            final_line += dataTaken.substr(0, pos + 3);
            dataTaken.erase(0, pos + 3);
            //adding the rest string to the rearranged one
            while ((isdigit(dataTaken.at(0)) || isalpha(dataTaken.at(0)))
                   || dataTaken.at(0) == '.') {
                final_line += dataTaken.substr(0, 1);
                dataTaken.erase(0, 1);
            }
            final_line.insert(final_line.size(), ")");
            is_converted = true;
        } else {
            //finish the loop
            break;
        }
    }
    //return the converted string
    if (is_converted) {
        final_line += dataTaken;
        return final_line;
    }
    return dataTaken;
}

/**
 * Function Name: FileReader
 * @param dataFile - A pointer to the user's flight commands file
 * @param fileName - The user's flight commands file name as.txt. sends via the register
 * @return all the commands as one string splited by the sign '|'
 */
string Separater::fileReader(fstream *dataFile, string &fileName) {
    string line, data_line;
    dataFile->open(fileName);
    //checks if the file has been opened successfully
    if (!dataFile->is_open()) {
        throw "ERROR: CAN'Node OPEN THE FILE";
    }
    /*
     * runs the lexer functions as far as there is a non empty line.
     * in addition, it fix the line in order to make the space bars to be
     * in the right place
     */
    unsigned long pos;
    while (getline(*dataFile, line)) {
//        if (line.find(',') != string::npos) {
//            pos = line.find(',');
//            if (line.at(pos - 1) != ' ' && line.at(pos + 1) != ' ') {
//                line.insert(pos + 1, " ");
//                line.erase(pos, 1);
//            } else if (line.at(pos - 1) == ' ' && line.at(pos + 1) != ' ') {
//                line.insert(pos + 1, " ");
//                line.erase(pos, 1);
//            } else {
//                line.insert(pos, " ");
//                line.erase(pos + 1, 1);
//            }
//        } else if (line.find('=') != string::npos) {
//            pos = line.find('=');
//            if (line.at(pos - 1) != ' ' && line.at(pos + 1) != ' ') {
//                line.insert(pos + 1, " ");
//                line.insert(pos, " ");
//            } else if (line.at(pos - 1) == ' ' && line.at(pos + 1) != ' ') {
//                line.insert(pos + 1, " ");
//            } else {
//                line.insert(pos, " ");
//            }
//        }
        //make lexer for the fixed line from the file
        data_line += lexer(line, INPUT_SPLIT);
    }
    dataFile->close();
    return (data_line);
}
