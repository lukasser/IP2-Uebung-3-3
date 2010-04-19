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

int 
main(void)
{
    int num_rands = 10000000;
    char choice;
    
    tree *nums = new tree;
    int  *arr = new int[num_rands]; // array for searching    
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
        
    // Insert random numbers into tree:
    start_insert_tree = get_time();
    insert_rands(nums, num_rands);
    stop_insert_tree = get_time();
    
    // Copy the numbers from tree into the array
    start_insert_array = get_time();
    flatten(nums->root, arr, &n);
    stop_insert_array = get_time();

    
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
                
                cout << "Bitte die zu suchende Zahl eingeben: ";
                cin >> search;
                
                start_seq_search = get_time();
                res_seq = seq_search(arr, search, num_rands);
                stop_seq_search = get_time();

                start_bin_search = get_time();
                res_bin = bin_search(arr, search, num_rands);
                stop_bin_search = get_time();
                
                // Results
                cout << "\n\tErgebnisse\n"
                << "\t-----------\n"
                << "\tZufallszahlen erzeugen & einfuegen: " << stop_insert_tree - start_insert_tree  << "s\n"
                << "\tZahlen ins Array kopieren: " << stop_insert_array - start_insert_array << "s\n"
                << "\tSequentielle Suche: " << stop_seq_search - start_seq_search << "s. Gefunden an Stelle: " << res_seq << endl
                << "\tBinaere Suche: " << stop_bin_search - start_bin_search << "s. Gefunden an Stelle: " << res_bin << endl;
            
                break;
			            
            case 'Q':
            case 'q': break;
				
            default: cout << "Fehlerhafte Wahl!\n";
        }
		
    } while (choice != 'q' && choice != 'Q');
    
    destroy(nums);
    delete nums;
    delete [] arr;
    return 0;
}
