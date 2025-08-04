# **Final Project: Block Letter Plotter**

**Author:** Ryan Hueseman

**Course:** CSCI 101

**Date:** August 3, 2025

## **1\. Project Description**

This C++ program reads a set of coordinates in the form of characters from a comma-separated input file called input.txt. The program is designed to handle a specific data array of x-coordinates, Characters, and y-coordinates and automatically skips the header row. This is done to reveal a message in the data.

The program processes the data in two main passes:

1. **Sizing:** It reads the entire file to determine the maximum x and y coordinates. This information is used to create a 2D character grid of the precise size needed.  
2. **Plotting:** It reads the file again, this time plotting each character onto the 2D grid at its specified (x, y) location.

Then, the program prints the entire grid to the console, revealing a hidden message formed by the plotted characters. 

**2\. How to Compile and Run**

This project was developed using Visual Studio and the C++ Standard Library.

### **Steps to Run:**

1. **Open the Project:** Open the Visual Studio Solution file (.sln).  
2. **Ensure Files are Included:** Make sure both the source code file (main.cpp) and the data file (input.txt) are included in the project's Solution Explorer.   
3. **Build and Run:** Press the **F5** key or click the green "Local Windows Debugger" button at the top of the screen. The program will compile and run, and the output message will be displayed in the console window.

## **3\. Files Included**

* main.cpp: The C++ source code file containing all the logic for the program.  
* input.txt: The plain text data file containing the comma-separated coordinate and character data.
