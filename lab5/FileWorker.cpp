#include "FileWorker.h"

TextFileWorker::TextFileWorker() {
    currentFilename = "";
}

TextFileWorker::~TextFileWorker() {
    CloseFile();
}

void TextFileWorker::OpenFile(const string& filename, ios::openmode mode) {
    currentFilename = filename;
    fileStream.open(currentFilename, mode);
    if (!fileStream.is_open()) {
        throw runtime_error("Error: Could not open file: " + currentFilename);
    }
}

void TextFileWorker::WriteData(const string& data) {
    if (!fileStream.is_open()) {
        throw runtime_error("Error: File is not open for writing");
    }
    fileStream << data << endl;
}

void TextFileWorker::ReadData() {
    if (fileStream.is_open()) {
        fileStream.close();
    }

    fileStream.open(currentFilename, ios::in);
    if (!fileStream.is_open()) {
        throw runtime_error("Error: Could not open file for reading: " + currentFilename);
    }

    cout << "\n- Reading data from text file (" << currentFilename << ")-" << endl;
    string line;
    while (getline(fileStream, line)) {
        cout << line << endl;
    }

    fileStream.close();
}

void TextFileWorker::CloseFile() {
    if (fileStream.is_open()) {
        fileStream.close();
    }
}