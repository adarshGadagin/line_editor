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
* **Insert Line (`I`)**: Inserts text at a specific line number, automatically shifting subsequent lines down.
* **Delete Line (`D`)**: Removes text at a specific line number and shifts remaining lines up.
* **Display Document (`P`)**: Prints the full document with line numbers.
* **Save File (`S`)**: Writes current in-memory lines to a text file.
* **Load File (`O`)**: Loads lines from a text file directly into memory.

### **Bonus Features**
* **Search (`F`)**: Locates and lists line numbers containing a specified search phrase or keyword.
* **Find & Replace (`R`)**: Replaces target phrases across the document with new text.

---

## 🏗️ Data Structure Choice

* **Dynamic Array of Strings (`char **lines`)**:
  * **Justification**: Allows fast $O(1)$ random access to lines by index/line number, making print and targeted edits efficient. Dynamic memory reallocation (`realloc`) ensures memory scales seamlessly as lines are added.

---

## 🛠️ Compilation & Execution

### **Prerequisites**
* `gcc` compiler installed.

### **Building the Project**
Compile the source code using `gcc`:

```bash
gcc -o line_editor line_editor.c