# Home and School scoreCalc Program

## Overview

The Home and School scoreCalc program is a comprehensive tool designed for students and educators to easily calculate averages, standard deviations, and grades for various subjects using the Linux console. This program, built with the C11 standard, provides a user-friendly interface and robust functionalities to simplify score calculations.

## Features

- **Calculate Averages** Compute average scores for individual subjects, a combination of major subjects (Korean, Math, English), and all subjects.
- **Standard Deviation** Determine the standard deviation of scores for each student.
- **Grade Calculation** Provide absolute evaluation grades based on average scores.
- **Splash Screen** Display random motivational or informational messages on startup.
- **User Interface** Easy-to-follow prompts for inputting scores and names.

## Program Information

- **Author** Myungjae Lee
- **Version** 2.6
- **License** LGPL (Linux GNU)
- **Built with** Replit IDE, C11 standard
- **Libraries used** `stdio.h`, `stdlib.h`, `unistd.h`, `time.h`, `math.h`

## Changelog

- **v1.0 (2023.12):** Initial release
- **v2.0 (2024.07.04):** Changed to view multiple scores at once
- **v2.1 (2024.07.04):** Added Korean, Math, English average calculation
- **v2.1.1 (2024.07.04):** Added important subjects average
- **v2.2 (2024.07.05):** Added standard deviation calculation
- **v2.3 (2024.07.05):** Added splash screen and enhanced loading screen
- **v2.4 (2024.07.05):** Added absolute evaluation grade
- **v2.5 (2024.07.05):** Bug fixes and enhanced start screen
- **v2.5.1 (2024.07.05):** Enhanced loading screen and added graphical title
- **v2.5.2 (2024.07.05):** Added program information
- **v2.6 (2024.07.10):** Bug fixes

## Installation and Usage

### Prerequisites

- Linux operating system
- C compiler (e.g., GCC)

### Installation

1. **Clone the Repository** Download the source code or clone the repository.

   ```sh
   git clone https://github.com/mj2010lee/scoreCalc.git
   ```

2. **Navigate to the Directory** Change to the directory where the source code is located.

   ```sh
   cd scoreCalc
   ```

3. **Compile the Program** Use a C compiler to compile the source code.

   ```sh
   gcc -o scoreCalc scoreCalc.c -lm
   ```

### Running the Program

1. **Execute the Program** Run the compiled program in the terminal.

   ```sh
   ./scoreCalc
   ```

2. **Follow the Prompts** The program will guide you through the following steps:
   - Enter the number of students.
   - Input the names and scores for each subject for each student.
   - Review the calculated averages, standard deviations, and grades.

### Input Guidelines

- If a student has not taken a particular subject, input `-1` for their score in that subject.
- The program supports up to 10 students and 10 different subjects.

## Detailed Program Structure

### 1. Include Necessary Libraries

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
```

### 2. Initialize Variables

```c
int num;
char name[10][20];
int kor[10], math[10], soc[10], hist[10], sci[10], han[10], homeec[10], moral[10], eng[10];
float avga[];
```

### 3. Functions

#### Splash Text Function

Randomizes and displays a splash text message.

```c
void splashText() {
	// Implementation
}
```

#### Standard Deviation Calculation

Calculates and displays the standard deviation for the scores.

```c
void stDev() {
	// Implementation
}
```

#### Absolute Evaluation Grade Calculation

Calculates and displays the absolute evaluation grades based on the average scores.

```c
void absEval() {
	// Implementation
}
```

#### Average Calculation Functions

Calculates and displays the average scores for:
- Korean, Math, and English (`avgImp`)
- Major subjects (`avgFive`)
- All subjects (`avgAll`)

```c
void avgImp() {
	// Implementation
}

void avgFive() {
	// Implementation
}

void avgAll() {
	// Implementation
}
```

#### Title and Loading Screen

Displays the program title and loading screen, and initializes the number of students.

```c
void title() {
	// Implementation
}
```

#### Score Input

Prompts the user to input the scores for each subject for each student.

```c
void scan() {
	// Implementation
}
```

### 4. Main Function

Executes all the functions in the proper order.

```c
void main() {
	title();
	scan();
	avgImp();
	avgFive();
	avgAll();
	stDev();
	absEval();
	return;
}
```

## Contact

For any issues or suggestions, please contact the author:

- **Author:** Myungjae Lee
- **Email:** [mj2010lee@gmail.com](mailto:mj200lee@gmail.com)

---

This README provides a comprehensive guide to using the Home and School scoreCalc program. Follow the instructions carefully to install, compile, and run the program successfully.