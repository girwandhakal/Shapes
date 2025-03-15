# C++ Polymorphism Project: 3D Shapes

## Overview
This project explores **polymorphism in C++** by defining a **base class (`Shape`)** and implementing four **derived classes** (`Sphere`, `Cylinder`, `Torus`, and `Box`). The goal is to enable the **main function to work independently** of the actual shape classes by leveraging **virtual functions**.

## Getting Started

### Prerequisites

* A C++ compiler (e.g., g++)
* Make

### Installation

1.  **Clone the repository:**

    ```bash
    git clone <repository_url>
    cd <repository_name>
    ```

2.  **Compile the program:**

    ```bash
    make
    ```

    This will create an executable named `a.out`.

3.  **Run the program:**

    ```bash
    ./a.out shapes.dat
    ```

    (Ensure `shapes.dat` is in the same directory or provide the correct path.)

4.  **Clean the project:**

    ```bash
    make clean
    ```

    This will remove the executable and object files.
