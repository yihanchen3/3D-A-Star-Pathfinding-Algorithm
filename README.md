# 3D A* Path Finding Algoritnm

This project implements a three-dimensional visual scene platform for aerial cruise using the A* path planning algorithm.

## Project Structure

Three-Dimensional-Visual-Scene-Platform-for-Aerial-Cruise/

├── **include**/

│ ├── Star.h

│ ├── Node3D.h

│ └── stdafx.h

├── **src**/

│ ├── **main.cpp**

│ ├── Star.cpp

│ ├── Node3D.cpp

│ └── stdafx.cpp

├── **input**/

│ └── input.txt

├── **bin**/

│ └── **main.exe**

├── .vscode/

│ └── task.json

├── **Path_Planning_Program_Description.pdf**

└── README.md

### Files and Directories

- **src/main.cpp**

  - This is the main application source file.
- **include/Star.h, src/Star.cpp**

  - Header file for the `Star` class, which contains declarations for the methods used in the A* path planning algorithm. Source file for the `Star` class, which contains the implementation of the methods declared in `Star.h`.
- **include/stdafx.h, src/stdafx.cpp**

  - These files are used to generate the precompiled header (PCH) file and the precompiled type file.
- **.vscode/task.json**

  - Define tasks to automate various development workflows, including building project and running tests.
- **input/input.txt**

  - Numerical matrix that defines the 200 x 200 x 30 map where 1 is walkable, 0 is not walkable.

### Build Instructions

1. Navigate to the project directory
2. Build the `main.cpp`
3. **Run the executable: `./bin/main.exe`**
4. Enter the start point and end point, return the found path if one exists. Example: 

   ```
   | Description                    | Coordinates |
   |--------------------------------|-------------|
   | Please input the start point:  | 1 1 1       |
   | Please input the end point:    | 20 20 20    |
   | **PATH FOUND:**                |             |
   |                                | 1 1 1       |
   |                                | 2 2 2       |
   |                                | 3 3 3       |
   |                                | 4 4 4       |
   |                                | 5 5 5       |
   |                                | 6 6 6       |
   |                                | 7 7 7       |
   |                                | 8 8 8       |
   |                                | 9 9 9       |
   |                                | 10 10 10    |
   |                                | 11 11 11    |
   |                                | 12 12 12    |
   |                                | 13 13 13    |
   |                                | 14 14 14    |
   |                                | 15 15 15    |
   |                                | 16 16 16    |
   |                                | 17 17 17    |
   |                                | 18 18 18    |
   |                                | 19 19 19    |
   |                                | 20 20 20    |
   ```
