# Simple Line Editor - User Guide

Welcome to the **Simple Line Editor**!

This program lets you create and edit a text document directly from the terminal.
You control the document using simple commands.

## Getting Started

When you see:

```text
editor>
```

type a command and press **Enter**.

If you are not sure what to do, type:

```text
help
```

---

## Commands

### 1. Insert a Line

Adds a new line at the position you choose.

**Format:**

```text
insert <line number>
```

**Example:**

```text
editor> insert 1
Enter text: Hello World
```

This adds "Hello World" as line 1.

---

### 2. Delete a Line

Removes a line from the document.

**Format:**

```text
delete <line number>
```

**Example:**

```text
editor> delete 2
```

Line 2 will be removed and the lines below it will move up.

---

### 3. Display the Document

Shows all the lines currently in the document.

```text
display
```

**Example output:**

```text
1 | Hello World
2 | Welcome to our project
3 | We are learning C
```

---

### 4. Save the Document

Saves your current document to a text file.

**Format:**

```text
save <filename>
```

**Example:**

```text
editor> save document.txt
```

---

### 5. Load a Document

Opens a previously saved text file.

**Format:**

```text
load <filename>
```

**Example:**

```text
editor> load document.txt
```

---

### 6. Search for Text

Finds the lines that contain a particular word or text.

**Format:**

```text
search <text>
```

**Example:**

```text
editor> search C
```

The editor will show the line numbers where `C` is found.

---

### 7. Find and Replace

Replaces one word with another throughout the document.

**Format:**

```text
replace <old text> <new text>
```

**Example:**

```text
editor> replace hello hi
```

This changes `hello` to `hi`.

---

### 8. Show Statistics

Shows basic information about your document.

```text
stats
```

It displays:

* Number of lines
* Number of words
* Number of characters

---



### 10. Help

Shows the list of available commands.

```text
help
```

---

### 11. Quit

Closes the editor.

```text
quit
```

You can also use:

```text
exit
```

---

## Important Tips

* Line numbers start from **1**.
* Use `display` to see your document at any time.
* Save your work regularly using `save`.
* Use `undo` if you accidentally make a change.
* If you forget a command, type `help`.
* Make sure the file name is correct when using `save` or `load`.

**Enjoy using the Simple Line Editor!**
