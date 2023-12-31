/**
* Assignment 5: Page replacement algorithms
 * @file replacement.h
 * @author Kenny Liu & Jesus Mendoza
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#pragma once

#include "pagetable.h"
#include <iostream>

/**
 * @brief A base class to simulate page replacement algorithms.
 * A specific page replacement algorithm, e.g. FIFO or LRU, should be subclass of this.
 */
class Replacement
{
protected:      // subclasses can access these members
    // Member variable for the page table
    PageTable page_table;

	  int references; // number of references
    int page_faults; // number of page faults
    int page_replacement; // number of page_replacements
    int frame_count; // counter for frames so it doesn't exceed total

    int total_pages; // total number of pages in page table
    int total_frames; // total number of frames in page table

public:
	/**
	 * @brief 
	 * @param num_pages Total number of logical pages for the simulation.
	 * @param num_frames Total number of available free frames.
	 */
	Replacement(int num_pages, int num_frames);

    /**
     * @brief Destructor
     */
    virtual ~Replacement();


    /**
	 * @brief Simulate a single page access.
     * @details If the page is valid, it calls the touch_page function. 
     *          If the page is not valid but free frames are available, it calls the load_page function.
     *          If the page is not valid and there is no free frame, it calls the replace_page function.
     * @param page_num The logical page number.
	 * @param is_write whether this access a memory write
	 * @return whether it's a page fault: true if it's a page fault
	 */
    virtual bool access_page(int page_num, bool is_write = false);

    /**
	 * @brief Accesss a page alreay in physical memory
	 * It may be overridden in a subclass 
	 * @param page_num The logical page number.
     */
    virtual void touch_page(int page_num) 
    {
      return; // doesn't do anything, no replacement is needed
    }

    /**
     * @brief Access an invalid page, but free frames are available.
     * Assign the page to an available frame, not replacement needed
     * It may be overridden in a subclass 
     * @param page_num The logical page number.
     */
    virtual void load_page(int page_num)
    {
      page_table[page_num].valid = true; 
      page_table[page_num].frame_num = frame_count;
      page_faults++; // invalid page, so it is a page fault
      frame_count++; // adding new page, so increment frame count
      //cout << "added " << frame_count << " to index " << page_num << endl;
    }


    /**
	 * @brief Access an invalid page and no free frame is available.
     * Select a victim page to be replaced.
	 * It is a pure virtual function to be implemented in specific replacement subclasses.
     * @param page_num  The logical page number of the desired page.
	 * @return Selected victim page #
	 */
    virtual int replace_page(int page_num) = 0;

    /**
	 * @brief Get the ith entry of the page table
	 */
    PageEntry getPageEntry(int page_num) {
        return page_table[page_num];
    }

    /**
	 * @brief Print the statistics of simulation
	 */
    void print_statistics() const;
};
