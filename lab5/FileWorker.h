#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class FileWorker {
public:
    virtual ~FileWorker() {}

    virtual void OpenFile(const string& filename, ios::openmode mode) = 0;
    virtual void WriteData(const string& data) = 0;
    virtual void ReadData() = 0;
    virtual void CloseFile() = 0;
};

class TextFileWorker : public FileWorker {
private:
    fstream fileStream;
    string currentFilename;

public:
    TextFileWorker();
    virtual ~TextFileWorker();

    void OpenFile(const string& filename, ios::openmode mode) override;
    void WriteData(const string& data) override;
    void ReadData() override;
    void CloseFile() override;
};