/******************************************************************************
 * Simon Fraser University
 * ENSC-151 – Introduction to Software Development for Engineers
 * assign10.cpp
 * Description: This program reads  datasets from input files: which has A list
 * of words and sorts them using two different sorting algorithms: Quick Sort
 * (fast method) and Selection Sort (baseline method). It measures and compares
 * the time taken
 *
 * Input:
 *      - data5k.txt  : contains ,5000 words
 * Output:
 *      - Sorted list of words in alphabetical order
 * Author:      Krishang Sarkar
 * Date:        December 12th  2025
 *****************************************************************************/
// libraies and preprocessor directives used in the program
#include <algorithm>         //stl algorithm library
#include <chrono>            //chrono library for time measurement
#include <fstream>           //file stream
#include <iostream>          //input and output stream
#include <string>            //string library
#include <vector>            //vector library
using namespace std;         // std namespace
using namespace std::chrono; // chrono namespace
/* ======================== FUNCTION PROTOTYPES ======================== */
// uses pass by refrences when accessing employee vectors to avoid making copies
// File reading
void readWordsFromFile(vector<string> &words);
// Sorting algorithms
// Sorting algorithms for WORDS
void quickSortWords(vector<string> &words, int start, int end);
int partitionWords(vector<string> &words, int start, int end);
void selectionSortWords(vector<string> &words);
/******************************************************************
 * main -- controls overall program flow
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 * Returns: 0 upon successful completion
 *******************************************************************/
int main()
{
    // Vector to store data as they  allows dynamic resizing as data is
    // are read from files
    // vector to store words
    vector<string> words;

    // Read words from file
    readWordsFromFile(words);
    if (words.empty())
    {
        cerr << "Program terminated: No words were loaded." << endl;
        return 1;
    }

    // Make copies for fair comparison
    vector<string> wordsQuick = words;
    vector<string> wordsSelection = words;

    // Indicate console/terminal that data has been loaded
    cout << "Loaded " << words.size() << " words from data5k.txt\n"
         << endl;

    // --- Algorithm A: Quick Sort (Fast Method) ---
    cout << "Running Quick Sort..." << endl;
    auto startA = high_resolution_clock::now();
    // Sort the wordsQuick copy
    quickSortWords(wordsQuick, 0, wordsQuick.size() - 1);
    auto stopA = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(stopA - startA);

    // --- Algorithm B: Selection Sort (Baseline Method) ---
    cout << "\nRunning Selection Sort..." << endl;
    auto startB = high_resolution_clock::now();
    // Sort the wordsSelection copy
    selectionSortWords(wordsSelection);
    auto stopB = high_resolution_clock::now();
    auto durationSelection = duration_cast<microseconds>(stopB - startB);

    // Print sorted words
    // PRINT SORTED OUTPUT (required)
    for (const string &val : wordsQuick)
    {
        cout << val << " ";
    }

    cout << "\n\n";

    // output statement for quick sort time
    cout << "Quick Sort Time:     " << durationQuick.count() << " microseconds"
         << endl;
    cout << "Quick Sort Completed.\n"
         << endl;
    // output statement for selection sort time
    cout << "Selection Sort Time: " << durationSelection.count()
         << " microseconds" << endl;
    cout << "Selection Sort Completed.\n"
         << endl;

    return 0;
}
// function implementations for the program
/******************************************************************
 * readWordsFromFile -- reads employee timesheet data from file
 *
 * Parameters:
 *   words vector<string> &words- dynamic array to store words
 * Modifies:
 *   employees vector - adds data from data5k.txt file
 * Returns:
 *   Nothing (void)
 *******************************************************************/
void readWordsFromFile(vector<string> &words)
{
    // using ifstream to read data from file
    ifstream inputFile;
    inputFile.open(
        "data5k.txt"); //.open lets the the compiler know which file to open

    // check if the file opened successfully
    if (!inputFile)
    {
        // I Used cerr for error messages because cerr is unbuffered and outputs
        // immediately, ensuring errors are shown even if the program crashes or
        // the output buffer is not flushed.
        cerr << "Error opening data5k.txt" << endl;
        return;
    }
    // variable to store each word read from the file
    string word;
    // the loops reads each word from the file until the end of the file is
    // reached
    while (inputFile >> word)
    {
        // using push back function
        //  it increase an element by one to the end of the vector
        words.push_back(word);
    }
    // closes the file which was opened for reading
    inputFile.close();
}

// functions for sorting algorithms
// algorithm A: Quick Sort
/******************************************************************
 * quickSortWords -- Sorts a vector of strings using the Quick Sort
 *                  algorithm. It employs the picot and partitioning
 *                  strategy, recursively partitioning the array
 *                   around a pivot element.
 * Parameters: vector<string> &words - The vector of words (passed by reference)
 *             int start  - The starting index of the sub-array to be sorted.
 *              int end    - The ending index of the sub-array to be sorted.
 * Modifies:
 * The 'words' vector is modified in-place to be sorted lexicographically
 * between the 'start' and 'end' indices.
 * Returns:
 * Nothing (void).
 *******************************************************************/
void quickSortWords(vector<string> &words, int start, int end)
{
    if (start < end)
    {
        int pivIdx = partitionWords(words, start, end);

        quickSortWords(words, start, pivIdx - 1);
        quickSortWords(words, pivIdx + 1, end);
    }
}

/******************************************************************
 * partitionWords -- partition helper for quickSortWords
 * Parameters: vector<string> &words - The vector of words (passed by reference)
 *            int start  - The starting index of the sub-array to be
 * partitioned. int end    - The ending index of the sub-array to be
 * partitioned.
 *
 * \Modifies:
 * The 'words' vector is modified in-place to rearrange elements around the
 * pivot. Returns: int - The final index position of the pivot element after
 * partitioning.
 *******************************************************************/
int partitionWords(vector<string> &words, int start, int end)
{
    string pivot = words[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (words[j] <= pivot)
        {
            i++;
            swap(words[i], words[j]);
        }
    }

    swap(words[i + 1], words[end]);
    return i + 1;
}
// Algorithm B: Baseline method
/******************************************************************
 * selectionSortWords  -- sorts a vector of words alphabetically
 * Parameters: vector<string> &words -- list of words
 * Modifies:  words -- sorts alphabetically (A → Z)
 * Returns:   nothing
 *******************************************************************/
void selectionSortWords(vector<string> &words)
{
    int n = words.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (words[j] < words[minIndex])
            {
                minIndex = j;
            }
        }

        swap(words[i], words[minIndex]);
    }
}
