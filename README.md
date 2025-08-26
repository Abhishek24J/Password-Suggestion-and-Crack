# Password-Suggestion-and-Crack
An interactive C++ console app that analyzes password composition, estimates brute-force crack time based on character sets and guessing speeds, 
and generates improved password suggestions. It’s designed for educational use to understand password strength metrics and improve security habits.

## Features
- Analyzes password characters: counts uppercase, lowercase, digits, and special symbols.
- Estimates cracking time assuming offline brute-force at high guess rates (shows times from seconds to decades).
- Generates password suggestions by adding missing character types and length padding.
- Ready-to-run with Visual Studio Code configurations for building and debugging.

## Demo
![App screenshot](assets/Password.png)

## Set up
_Windows (MinGW‑w64 / MSYS2)_

Install MSYS2 MinGW‑w64 toolchain (g++, gdb).

Open this folder in VS Code.

### Build and run:

Using VS Code: 

F5 (uses .vscode/tasks.json and .vscode/launch.json).

Using terminal:
```
g++ -std=c++17 -O2 Password_Suggestion_and_Cracking.cpp -o password_tool.exe
```
```
.\password_tool.exe
```
<br>

_Linux/macOS (Clang or GCC)_

```
g++ -std=c++17 -O2 Password_Suggestion_and_Cracking.cpp -o password_tool
```
```
./password_tool
```

## What the estimate means
Search space: computed from the union of character classes detected (e.g., if lowercase+digits are present, base ≈ 26 + 10).

Crack rate: represents a high offline brute‑force throughput; online systems often throttle heavily.

Scope: educational estimator, not a forensic password audit; different hashes, salts, GPUs, and rate limits can change results by many orders of magnitude.

## Notes
This tool computes a theoretical brute-force cracking time based on detected character sets and a fixed offline guess rate (~2.8 billion guesses/sec). 

Due to this assumption, strong passwords with diverse characters often yield large times, including years or decades.
