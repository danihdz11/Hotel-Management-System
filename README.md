# Hotel Management System in C++

A C++-based hotel management simulation showcasing core object-oriented programming concepts such as inheritance, encapsulation, and polymorphism.

## Project Overview

This project simulates the basic functionality of a hotel system using classes and inheritance in C++. It includes different types of rooms (junior, suite, deluxe), and allows the user to interact with them via a command-line interface.

Key features:
- Class hierarchy with inheritance for room types
- Polymorphic behavior for displaying room information
- Encapsulated data for room attributes and hotel details
- Menu-driven interaction

---

## Core Functionalities

- **Check-in**: Assigns a guest to a room and marks it as occupied.
- **Check-out**: Releases a room and resets its state.
- **Add Charges**: Adds custom charges to a room’s account.
- **Generate Occupancy Report**: Lists the status of all rooms (occupied or available).
- **Dynamic Menu**: Text-based menu for interaction and input handling.

---

## Project Structure

The project is organized into the following folders:

- `include/` – Contains all header (`.h`) files defining classes and interfaces.
- `src/` – Contains the implementation files (`.cpp`) for each class.
- `main.cpp` – The entry point of the program, containing the menu and execution flow.
- `.gitignore` – File specifying ignored files/folders for Git.

---

## How to Compile

From the root of the project, compile with:

```bash
g++ src/*.cpp main.cpp -Iinclude -o hotelApp
```
If main.cpp is moved into src/, use:
```bash
g++ src/*.cpp -Iinclude -o hotelApp
```
