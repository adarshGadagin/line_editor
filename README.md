# Line Editor in C

A lightweight, command-line text editor written in C for the **Portfolio Building Studio Course (3rd Semester Coding Competition)**. This project implements an in-memory document editor supporting core line manipulation, file I/O operations, and text search/replace capabilities.

---

## 👥 Team Members

| Name | SRN / Register No. |
| :--- | :--- |
| **Adarsh Patil** | R25EF007 |
| **Abhinav Prasad E P** | R25EF004 |
| **Adarsh Gadagin** | R25EF009 |

---

## ✨ Features Implemented

### **Core Features**
* **Insert Line (`insert<line number>`)**: Inserts text at a specific line number, automatically shifting subsequent lines down.
* **Delete Line (`delete<line number>`)**: Removes text at a specific line number and shifts remaining lines up.
* **Display Document (`display`)**: Prints the full document with line numbers.
* **Save File (`save<file>`)**: Writes current in-memory lines to a text file.
* **Load File (`load<file>`)**: Loads lines from a text file directly into memory.

### **Bonus Features**
* **Search (`search<text>`)**: Locates and lists line numbers containing a specified search phrase or keyword.
* **Find & Replace (`replace<old><new>`)**: Replaces target phrases across the document with new text.
* **Stats(`stats`)**: Displays number of lines, words and characters.
* **Help (`help`)**: Displays all commands. 
---

## 🏗️ Data Structure Choice

* **Static 2D Character Array (`char lines[MAX_LINES][MAX_LENGTH]`)**: Provides $O(1)$ instant random access to any line by index while simplifying memory management without heap allocation overhead.
* **Trade-off**: Requires pre-defined line and length bounds (`MAX_LINES` and `MAX_LENGTH`), using fixed row-shifting via `strcpy()` for insertion and deletion operations.
---

## 🛠️ Compilation & Execution

### **Prerequisites**
* `gcc` compiler installed.

### **Building the Project**
Compile the source code using `gcc`:

```bash
gcc -o line_editor line_editor.c
