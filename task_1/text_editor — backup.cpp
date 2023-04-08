#include "text_editor.h"

string operator * (string str, size_t size) {
	string output_string = "";
	while (size--)
		output_string += str;
	return output_string;
}

TextEditor::TextEditor(string file_input, size_t length, string file_output) {
	this->file_input = file_input; 
	this->length = length; 
	this->file_output = file_output; 
	this->cur_length = 0;
}

int TextEditor::printString(ofstream &output_file) {
	size_t indent = (length - (cur_length + queue.size() - 1)) / 2;
	output_file << string(" ") * indent;
	while (!queue.empty()) {
		output_file << queue.front() << " ";
		cur_length -= queue.front().size();
		queue.pop();
	}
	output_file << endl;
	if (cur_length) {
		cerr << "Queue error!" << endl;
		return ERROR_QUEUE;
	}
	return 0;
}

int TextEditor::formateText() {
	ifstream input_file_stream(this->getFileInput());
	ofstream output_file_stream(this->getFileOutput());

	string cur_string, buffer_word;

	cur_length = 0;
	while (getline(input_file_stream, cur_string)) {
		stringstream str_stream(cur_string);
		
		while (str_stream >> buffer_word) {
			if (buffer_word.size() >= length) {
				if (cur_length != 0)
					printString(output_file_stream);
				while (buffer_word.size() >= length) {
					output_file_stream << buffer_word.substr(0, length) << endl;
					buffer_word = buffer_word.substr(length);
				}
				queue.push(buffer_word);
				cur_length += buffer_word.size();
			}
			else {
				if (cur_length + buffer_word.size() + queue.size() > length) {
					printString(output_file_stream);
					if (queue.empty()) {
						queue.push(buffer_word);
						cur_length += buffer_word.size();
					}
				}
				else {
					cur_length += buffer_word.size();
					queue.push(buffer_word);
				}
			}
		}
	}
	if (!queue.empty()) {
		printString(output_file_stream);
		if (queue.empty()) {
			queue.push(buffer_word);
			cur_length += buffer_word.size();
		}
	}
	input_file_stream.close();
	output_file_stream.close();
	return 0;
}
