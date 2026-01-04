/******************************************************************************
 * File:        main.cpp
 * Author:      Krishang Sarkar
 * Date:        December 2025
 *
 * Description:
 *      This program reads two datasets from input files:
 *      1) A list of numbers
 *      2) A list of words
 *
 *      The program stores each dataset into separate vectors, sorts the vectors
 *      using a chosen sorting algorithm (Selection Sort / Quick Sort), and 
 *      prints the sorted results to the console.
 *
 * Input:
 *      - numbers.txt : contains integers, one per line
 *      - words.txt   : contains strings/words, one per line
 *
 * Output:
 *      - Sorted list of numbers
 *      - Sorted list of words
 *****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* ======================== FUNCTION PROTOTYPES ======================== */
// File reading
void readWordsFromFile(vector<string> &words);

// Sorting algorithms for WORDS
void quickSortWords(vector<string> &words, int start, int end);
int partitionWords(vector<string> &words, int start, int end);
void selectionSortWords(vector<string> &words);

/******************************************************************
 * main -- controls overall program flow
 *******************************************************************/
int main()
{
    vector<double> numbers;   // (not used yet)
    vector<string> words;     // vector to store words

    // Read words from file
    readWordsFromFile(words);

    // Sort words using Quick Sort
    quickSortWords(words, 0, words.size() - 1);

    // Sort words using Selection Sort (optional)
    // selectionSortWords(words);

    // Print sorted words
    cout << "Sorted Words:\n";
    for (const auto &w : words)
        cout << w << endl;

    return 0;
}

/******************************************************************
 * readWordsFromFile -- loads words into a vector
 *******************************************************************/
void readWordsFromFile(vector<string> &words)
{
    ifstream file("words.txt");

    if (!file)
    {
        cout << "Error: Could not open words.txt\n";
        return;
    }

    string word;
    while (getline(file, word))
    {
        if (!word.empty())
            words.push_back(word);
    }

    file.close();
}

/******************************************************************
 * quickSortWords -- Quick Sort for strings
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
 * partitionWords -- partition helper for Quick Sort
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

/******************************************************************
 * selectionSortWords -- Selection Sort for strings
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
                minIndex = j;
        }

        swap(words[i], words[minIndex]);
    }
}