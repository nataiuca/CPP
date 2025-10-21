#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string filename, std::string s1, std::string s2)
    : filename(filename), s1(s1), s2(s2) {}

bool FileReplacer::replace() {
    // ⚠️ Validar s1 vacío
    if (s1.empty()) {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return false;
    }

    // ⚠️ Abrir archivo original
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file '" << filename << "'." << std::endl;
        return false;
    }

    // ⚠️ Comprobar si el archivo está vacío
    inputFile.seekg(0, std::ios::end);
    if (inputFile.tellg() == 0) {
        std::cerr << "Warning: input file '" << filename << "' is empty. Nothing to replace." << std::endl;
        inputFile.close();
        return false;
    }
    inputFile.seekg(0, std::ios::beg);

    // ⚠️ Crear archivo de salida
    std::string outputFilename = filename + ".replace";
    if (outputFilename == filename) {
        std::cerr << "Error: output filename cannot be the same as input file." << std::endl;
        inputFile.close();
        return false;
    }

    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: could not create output file '" << outputFilename << "'." << std::endl;
        inputFile.close();
        return false;
    }

    // 🧠 Procesar línea a línea
    std::string line;
    bool replacedSomething = false;

    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
            replacedSomething = true;
        }
        outputFile << line;
        if (!inputFile.eof())
            outputFile << '\n';
    }

    inputFile.close();
    outputFile.close();

    if (replacedSomething)
        std::cout << "✅ Replacement complete! File saved to '" << outputFilename << "'." << std::endl;
    else
        std::cout << "ℹ️ No occurrences of '" << s1 << "' found in file '" << filename << "'." << std::endl;

    return true;
}
