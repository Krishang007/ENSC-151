/******************************************************************************
 * File:        main.cpp
 * Author:      Krishang Sarkar
 * Date:        December 2025
 *
 * Description:
 *      This program reads a dataset of words from a file, sorts them using
 *      different sorting algorithms (Quick Sort and Selection Sort), and
 *      prints the sorted output.
 *****************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* ======================== FUNCTION PROTOTYPES ======================== */
void readWordsFromFile(vector<string> &words);
void quickSortWords(vector<string> &words, int start, int end);
int partitionWords(vector<string> &words, int start, int end);
void selectionSortWords(vector<string> &words);

/******************************************************************
 * main -- controls overall program flow
 *******************************************************************/
int main()
{
    vector<string> words;

    // Read dataset
    readWordsFromFile(words);

    if (words.empty())
    {
        cout << "No words loaded. Exiting.\n";
        return 0;
    }

    // Make copies for fair comparison
    vector<string> wordsQuick = words;
    vector<string> wordsSelection = words;

    // Algorithm A: Quick Sort
    quickSortWords(wordsQuick, 0, wordsQuick.size() - 1);

    // Algorithm B: Selection Sort
    selectionSortWords(wordsSelection);

    // PRINT SORTED OUTPUT (required)
    for (const string &val : wordsQuick)
    {
        cout << val << "\n";
    }

    return 0;
}

/******************************************************************
 * readWordsFromFile -- loads words from data5K.txt
 *******************************************************************/
void readWordsFromFile(vector<string> &words)
{
    ifstream inputFile("data5K.txt");
    string word;

    if (!inputFile)
    {
        cerr << "Error opening data5K.txt\n";
        return;
    }

    while (inputFile >> word)
    {
        words.push_back(word);
    }

    inputFile.close();
}

/******************************************************************
 * Quick Sort
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
 * Selection Sort (Baseline)
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