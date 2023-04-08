#include "text_editor.h"

int main(int argc, char** argv) {
	if (argc != 4)
		return ERROR_COMMAND;
	TextEditor text_editor = TextEditor(string(argv[1]), (size_t)atoi(argv[2]), string(argv[3]));
	text_editor.formateText();
	return 0;
}
