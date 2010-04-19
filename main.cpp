/* Uebung3_3: Random numbers, tree traversal, searching
 *  
 * Created by Stefan Lukasser on 4/19/10.
 *  Copyright 2010. All rights reserved.
 *
 */

#include <iostream>
#include "binary_tree.h"
#include "random.h"
#include "timing.h"
#include "search.h"

#define MAX 10

using namespace std;

void search_number(int);

int 
main(void)
{
    int num_rands = MAX;
    char choice;
    
    /*  Main Menu loop */
    do {
        cout << "\t----- Menu -----\n"
        << "\t(a) Zahl suchen\n"
        << "\t(q) Program beenden\n   >> ";
        cin >> choice;
		
        switch (choice) {
            case 'A':
            case 'a':
                cout << "\tAnzahl Elemente: " << num_rands << endl;
                search_number(num_rands);
                break;
			            
            case 'Q':
            case 'q': break;
				
            default: cout << "Fehlerhafte Wahl!\n";
        }
		
    } while (choice != 'q' && choice != 'Q');
    
    
    return 0;
}

/* search_numbers: Main functionality of Uebung3_3
 * Ask user for number to search.
 */
void
search_number(int num_rands)
{
    tree *nums = new tree;
    //int  *arr = new int[num_rands]; // array for searching
    int arr[MAX];
    
    int search, res_seq, res_bin, n=0;
    
    /* Timing variables */
    double start_insert_tree,
           stop_insert_tree,
           start_insert_array,
           stop_insert_array,
           start_bin_search,
           stop_bin_search,
           start_seq_search,
           stop_seq_search;
    
    cout << "Bitte die zu suchende Zahl eingeben: ";
    cin >> search;
    
    // Insert random numbers into tree:
    cout << "\nSchritt 1/4: Zufallszahlen generieren und in Baum einfuegen\n";
    start_insert_tree = get_time();
    insert_rands(nums, num_rands);
    stop_insert_tree = get_time();

    // Copy the numbers from tree into the array
    cout << "Schritt 2/4: Zufallszahlen von Baum nach Array kopieren\n";
    start_insert_array = get_time();
    flatten(nums->root, arr, &n);
    stop_insert_array = get_time();
  
    // Seq Search
    cout << "Schritt 3/4: Sequentielle Suche nach Zahl\n";
    start_seq_search = get_time();
    res_seq = seq_search(arr, search, num_rands);
    stop_seq_search = get_time();
    
    // Bin Search
    cout << "Schritt 4/4: Binaere Suche nach Zahl\n";
    start_bin_search = get_time();
    res_bin = bin_search(arr, search, num_rands);
    stop_bin_search = get_time();
    
    // Results
    cout << "\n\tErgebnisse\n"
         << "\t-----------\n"
         << "\tSchritt 1: " << stop_insert_tree - start_insert_tree  << "s\n"
         << "\tSchritt 2: " << stop_insert_array - start_insert_array << "s\n"
         << "\tSchritt 3: " << stop_seq_search - start_seq_search << "s. Gefunden an Stelle: " << res_seq << endl
         << "\tSchritt 4: " << stop_bin_search - start_bin_search << "s. Gefunden an Stelle: " << res_bin << endl;
    
    
    destroy(nums);
    nums = NULL;
  //  delete arr;
}
