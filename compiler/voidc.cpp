#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <cstdlib>

using namespace std;

class VoidCCompiler {
private:
    string sourceCode;
    string cppCode;
    
    void transpile() {
        cppCode = "#include <iostream>\n";
        cppCode += "#include <string>\n";
        cppCode += "using namespace std;\n\n";
        
        string code = sourceCode;
        
        code = regex_replace(code, regex(R"(print\s*\(\s*\"([^\"]*)\"\s*\))"), 
                            R"(cout << "$1" << endl)");
        code = regex_replace(code, regex(R"(print\s*\(\s*([^\)]+)\s*\))"), 
                            R"(cout << $1 << endl)");
        
        code = replaceFuncKeyword(code);
        
        code = regex_replace(code, regex(R"(ptr\s+)"), "int* ");
        
        cppCode += code;
    }

    string replaceFuncKeyword(string code) {
        regex funcPattern(R"(func\s+(\w+)\s*\(([^\)]*)\)\s*\{)");
        smatch match;
        string result = code;
        string::const_iterator searchStart(code.cbegin());
        
        while (regex_search(searchStart, code.cend(), match, funcPattern)) {
            string funcName = match[1];
            string params = match[2];
            
            string returnType = "void";
            size_t funcStart = match.position(0);
            size_t funcEnd = findMatchingBrace(code, funcStart + match.length(0));
            
            if (funcEnd != string::npos) {
                string funcBody = code.substr(funcStart, funcEnd - funcStart);
                if (funcBody.find("return") != string::npos) {
                    returnType = "int"; 
                }
            }
            
            string replacement = returnType + " " + funcName + "(" + params + ") {";
            result.replace(funcStart, match.length(0), replacement);
            
            searchStart = result.cbegin() + funcStart + replacement.length();
        }
        
        return result;
    }
    
    size_t findMatchingBrace(const string& code, size_t start) {
        int depth = 1;
        for (size_t i = start; i < code.length(); i++) {
            if (code[i] == '{') depth++;
            if (code[i] == '}') depth--;
            if (depth == 0) return i;
        }
        return string::npos;
    }
    
public:
    bool loadSource(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file '" << filename << "'" << endl;
            return false;
        }
        
        sourceCode = string((istreambuf_iterator<char>(file)),
                           istreambuf_iterator<char>());
        file.close();
        return true;
    }
    
    bool saveCpp(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not write to '" << filename << "'" << endl;
            return false;
        }
        
        file << cppCode;
        file.close();
        return true;
    }
    
    bool compile(const string& cppFile, const string& exeFile) {
        string command = "g++ \"" + cppFile + "\" -o \"" + exeFile + "\" -std=c++11";
        
        cout << "Compiling: " << command << endl;
        
        int result = system(command.c_str());
        
        if (result != 0) {
            cerr << "Error: Compilation failed!" << endl;
            return false;
        }
        
        return true;
    }
    
    bool build(const string& sourceFile) {
        cout << "VoidC~ Compiler v1.0.0" << endl;
        cout << "======================" << endl;
        cout << endl;
        
        cout << "[1/4] Loading " << sourceFile << "..." << endl;
        if (!loadSource(sourceFile)) {
            return false;
        }
        
        cout << "[2/4] Transpiling to C++..." << endl;
        transpile();
        
        string baseName = sourceFile.substr(0, sourceFile.find_last_of("."));
        string cppFile = baseName + ".cpp";
        string exeFile = baseName + ".exe";
        
        cout << "[3/4] Saving " << cppFile << "..." << endl;
        if (!saveCpp(cppFile)) {
            return false;
        }
        
        cout << "[4/4] Compiling to executable..." << endl;
        if (!compile(cppFile, exeFile)) {
            return false;
        }
        
        cout << endl;
        cout << "Success! Created " << exeFile << endl;
        cout << "Run with: ./" << exeFile << endl;
        
        return true;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "VoidC~ Compiler v1.0.0" << endl;
        cout << "Usage: voidc <input.c~>" << endl;
        cout << endl;
        cout << "Example:" << endl;
        cout << "  voidc hello.c~" << endl;
        return 1;
    }
    
    string sourceFile = argv[1];
    
    VoidCCompiler compiler;
    if (!compiler.build(sourceFile)) {
        return 1;
    }
    
    return 0;
}