# File Organizer 📂✨

A simple yet powerful tool designed to declutter your download folder—or any folder, really—by organizing files into directories based on their file types. Say goodbye to the chaos and hello to a neatly arranged workspace!

## Features 🚀

- **Dry Run Option**: Test the waters with a dry run, seeing exactly what changes will be made without actually moving any files.
- **Extensive File Support**: Whether it's documents, images, or executables, this tool sorts them all into their rightful places.
- **Customizable**: Comes with the flexibility to add more file types and their corresponding directories as needed.
- **Speedy Performance**: Built to process a mountain of files in mere seconds, saving you valuable time.

## Getting Started 🌟

### Prerequisites

- GCC Compiler
- Make (for building the project using the provided `Makefile`)

### Compilation

Compile the project easily with the included `Makefile`:

```bash
make
```

This command generates the executable, which you can run to start organizing your files. Alternatively, you can compile manually:

```bash
gcc -o main main.c extension.c
```

### Running the Program

Execute the program in your target directory:

```bash
./main
```

Follow the on-screen prompts to choose between a dry run or actual file movement. The executable itself is never moved, ensuring the tool is always ready for the next run.

### Customization 🛠

Modify the `extension.c` and `extension.h` files to add support for new file types or to change the destination directories of the current ones.

### Built With 🖥

- C - The programming language used
- GCC - The compiler for compiling the project
- Make - Used to automate the compilation process

### Contributing 🤝

Feel free to fork the repo and submit pull requests with improvements or new features. All contributions are welcome!

### License 📜

This project is licensed under the MIT License - see the LICENSE.md file for details.

### Acknowledgments 🙌

- Hat tip to anyone whose code was used
- Inspiration
- Coffee ☕
