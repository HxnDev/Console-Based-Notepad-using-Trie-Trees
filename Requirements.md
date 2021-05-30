# Develop a Console Based Notepad Application Supported by Trie Tree

Create a notepad that allows the user to write text on the console. For this purpose,
the user should be able to control and track the movement of the cursor. The user
should be able to navigate to any part of console (cursor control) in order to
perform any insertion or deletion of words.

- Upon execution, the program should display a menu prompting the user to
    either create a new text file or load an existing text file.
- To delete text, user would press "BackSpace" button.
- To fetch meaning and synonyms of an entered word, when cursor is right
    at end of word (identified by punctuation like dot (.), comma (,), semi-
    colon (;), colon (:), or spacebar.
- To quit notepad, user would press “Esc” button. Program should ask user
    to enter name of the file.
- To add or delete some text, the user can take the cursor to that location
    (using the arrow keys) and perform the required operation (to insert or
    delete the word). Insertion, deletion, updating & cursor movement
    functionality should be exactly similar to that of Notepad application.
- If you close the program, you should free up all memory occupied by
    linked list.
- You should partition your console screen into 2 distinct segments. One for
    writing text in a notepad (75% of the screen) and one for displaying the
    meaning and synonyms of the entered word (25% of the screen). This is
    the same idea that is used in Visual Studio. Most of the screen is reserved
    for writing code but some part of it is reserved for displaying error list.

Internally, the notepad is composed of four-dimensional linked list (every node
should comprise of data element and 4 pointers for navigating left, right, up, and
down). Its implementation is just like a doubly linked list with an additional
property that it can grow in two dimensions. Since text can be written on multiple


lines, each row of the 4D linked list represents one line. Each line is terminated
when a newline is inserted in the ADT.

Each node contains four links which it uses to connect to the node before,
after, below and above it. In addition each node can store a character. Two
words must be differentiated with a space character.

```
YOU ARE NOT ALLOWED TO DECLARE ANY ARRAY OF ANY KIND
FOR ANY REASON. WHENEVER SUCH FUNCTIONALITY IS
DESIRED, USE LINKED LISTS.
```

## Trie Tree:
You have to implement the functionality of dictionary too.

1. Load the dictionary words from text file (provided to you), construct a Trie
    tree from alphabets of loaded words.
2. Later on whatever word the user enters (terminated by punctuation like dot
    (.), comma (,), semicolon (;), colon (:), or spacebar), the word itself, its
    meaning and synonyms should be displayed in 25% screen portion using
    traversal of Trie tree (directly loading such items from text file and
    displaying is not allowed).
3. If the entered word (e.g., traye) does not exist in dictionary and thus can’t
    be located by traversing the Trie tree, an error message “-traye -- word
    does not exist” should be displayed in 25% screen portion.
4. Upon pressing Esc key, the Trie tree should also be destroyed by freeing
    the occupied memory.

### Hint
 – Use Window.h, or any other header file for cursor movement (navigation).
Students have to learn and implement Cursor navigation control themselves
without consulting instructors. Cursor movement sample code is also attached.


