# VoidC~ Programming Language

🌟 What is VoidC~?
VoidC~ (pronounced "Void-C-Wave") is a modern programming language designed to be simpler than C++ but just as powerful. It combines familiar C-style syntax with modern conveniences, making it perfect for beginners and experienced programmers alike.
Why VoidC~?

✨ Clean Syntax - Easy to read and write
🚀 Fast Execution - Compiles to native code
🎯 Simple to Learn - If you know C, you know VoidC~
🔧 Powerful - Build anything from CLI tools to complex applications
🎨 VS Code Support - Full syntax highlighting and IntelliSense


📦 Features

Familiar C-style syntax with modern improvements
Static typing for safety and performance
Functions with parameters and return values
Pointers for low-level memory manipulation
Control flow (if/else, while, for loops)
Easy output with print() function
VS Code extension with syntax highlighting


🚀 Installation
Prerequisites

MinGW-w64 (GCC for Windows)
Git (optional)

Quick Install
bash# Clone the repository
git clone https://github.com/FSOCIETYTTKil1l/voidc-extension.git
cd voidc

# Add to PATH (Windows)
setx PATH "%PATH%;%CD%\bin"

# Verify installation
voidc --version
VS Code Extension
Install the VoidC~ extension from the VS Code Marketplace:

Open VS Code
Press Ctrl+Shift+X
Search for "VoidC~"
Click Install


⚡ Quick Start
Hello World
Create a file hello.c~:
cfunc main() {
    print("Hello, World!");
}
Compile and run:
bashvoidc hello.c~
./hello.exe
Variables and Math
cfunc main() {
    int a = 10;
    int b = 20;
    int sum = a + b;
    print("Sum: ");
    print(sum);
}
Functions
cfunc add(int a, int b) {
    return a + b;
}

func main() {
    int result = add(5, 7);
    print("5 + 7 = ");
    print(result);
}
Control Flow
cfunc main() {
    int x = 10;
    
    if (x > 5) {
        print("x is greater than 5");
    } else {
        print("x is 5 or less");
    }
    
    int i = 0;
    while (i < 5) {
        print(i);
        i = i + 1;
    }
}

📚 Language Syntax
Data Types

int - Integer numbers
float - Floating-point numbers
char - Single characters
ptr - Pointers

Keywords

func - Function declaration
return - Return from function
if / else - Conditional statements
while - While loop
for - For loop (coming soon)
print - Output to console

Operators
Arithmetic: +, -, *, /, %
Comparison: ==, !=, <, >, <=, >=
Logical: &&, ||, !
Pointers: & (address-of), * (dereference)


🎯 Examples
1. Calculator
cfunc add(int a, int b) { return a + b; }
func sub(int a, int b) { return a - b; }
func mul(int a, int b) { return a * b; }
func div(int a, int b) { return a / b; }

func main() {
    int x = 15;
    int y = 3;
    
    print("Addition: ");
    print(add(x, y));
    
    print("Multiplication: ");
    print(mul(x, y));
}
2. Fibonacci Numbers
cfunc fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

func main() {
    int i = 0;
    while (i < 10) {
        print(fibonacci(i));
        i = i + 1;
    }
}
3. Pointers Example
cfunc main() {
    int value = 42;
    ptr p = &value;
    
    print("Value: ");
    print(value);
    
    print("Pointer address: ");
    print(p);
    
    print("Dereferenced: ");
    print(*p);
}
More examples in the examples/ folder!

🛠️ Building from Source
bash# Clone repository
git clone https://github.com/FSOCIETYTTKil1l/voidc-extension.git
cd voidc

# Build compiler
cd compiler
g++ -o voidc main.cpp transpiler.cpp -std=c++17

# Run tests
cd ../tests
./run_tests.sh

📖 Documentation
Full documentation is available in the docs/ folder:

Language Specification
Standard Library
Compiler Guide
Tutorial
FAQ


🤝 Contributing
Contributions are welcome! Here's how you can help:

🐛 Report bugs - Open an issue
💡 Suggest features - Share your ideas
📝 Improve docs - Fix typos, add examples
🔧 Submit PRs - Fix bugs, add features

See CONTRIBUTING.md for guidelines.


🗺️ Roadmap
Version 1.0 (Current)

✅ Basic syntax and compiler
✅ VS Code extension
✅ Core language features

Version 1.5 (Planned)

 For loops
 Arrays
 Strings as first-class type
 Standard library functions
 Better error messages

Version 2.0 (Future)

 Structs and classes
 Memory management improvements
 Package manager
 Cross-platform support
 Debugger integration


📜 License
VoidC~ is released under the MIT License. See LICENSE for details.


🙏 Acknowledgments

Inspired by C, C++, and modern programming languages
Built with passion by the VoidC~ community
Special thanks to all contributors



📞 Contact & Community

GitHub: https://github.com/FSOCIETYTTKil1l/voidc-extension
Discord: [Join our community](https://discord.gg/mhTyRphd)
Email: VoiidC@proton.me
Discord: @kil1l


Made with ❤️ by the VoidC~ Team
⭐ Star us on GitHub if you like VoidC~!


<img width="475" height="525" alt="no_bg_c~" src="https://github.com/user-attachments/assets/89b17567-803a-48cc-873d-5add5ee91a45" />





