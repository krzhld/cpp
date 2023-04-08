#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

enum Errors {
	ERROR_COMMAND,
	ERROR_QUEUE
};

class TextEditor {
public:
	TextEditor(string file_input, size_t length, string file_output);
	int formateText();
	string getFileInput(void) { return this->file_input; }
	string getFileOutput(void) { return this->file_output; }
private:
	string file_input;
	string file_output;
	size_t length;
	size_t cur_length;
	queue<string> queue;

	int printString(ofstream& output_file);
};
