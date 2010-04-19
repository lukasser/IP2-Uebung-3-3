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

using namespace std;

void search_number(tree*, int);

int 
main(void)
{
    tree *nums = new tree;
    int num_rands = 100000;
    const int max = 1000000;
    char choice;
    
    /*  Main Menu loop */
    do {
        cout << "\n----- Menu -----\n"
        << "\t(a) Anzahl von zufaelligen Zahlen eingeben (Default: 100 000)\n"
        << "\t(b) Zahl suchen\n"
        << "\t(q) Program beenden\n   >> ";
        cin >> choice;
		
        switch (choice) {
            case 'A':
            case 'a':
                cout << "\t>> ";
                cin >> num_rands;
                if (num_rands > max) {
                    cout << "Zu viel, " << max << " Elemente gewaehlt\n";
                    num_rands = max;
                }
				break;
				
            case 'B':
            case 'b':
                search_number(nums, num_rands);
                break;
			            
            case 'Q':
            case 'q': break;
				
            default: cout << "Fehlerhafte Wahl!\n";
        }
		
    } while (choice != 'q' && choice != 'Q');
    
    destroy(nums);
    delete nums;
    
    return 0;
    
}

/* search_numbers: Main functionality of Uebung3_3
 * Ask user for number to search.
 */
void
search_number(tree *nums, int num_rands)
{
    long search, res_seq, res_bin;
    long *arr = new long[num_rands]; // array for searching
    
    /* Timing variables */
    double start_insert_tree,
           stop_insert_tree,
           start_insert_array,
           stop_insert_array,
           start_bin_search,
           stop_bin_search,
           start_seq_search,
           stop_seq_search = 0.0;
    
    cout << "\n\tBitte die zu suchende Zahl eingeben: ";
    cin >> search;
    
    // Insert random numbers into tree:
    cout << "Schritt 1/4: Zufallszahlen generieren und in Baum einfuegen\n";
    start_insert_tree = get_time();
    insert_rands(nums, num_rands); 
    stop_insert_tree = get_time();
    
    // Copy the numbers from tree into the array
    cout << "Schritt 2/4: Zufallszahlen von Baum nach Array kopieren\n";
    start_insert_array = get_time();
    inorder(nums->root, arr);
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
         << "\tSchritt 1: " << stop_insert_tree - start_insert_tree  << " s\n"
         << "\tSchritt 2: " << stop_insert_array - start_insert_array << " s\n"
         << "\tSchritt 3: " << stop_seq_search - start_seq_search << " s. Gefunden an Stelle: " << res_seq << endl
         << "\tSchritt 4: " << stop_bin_search - start_bin_search << " s. Gerunden an Stelle: " << res_bin << endl;
}
