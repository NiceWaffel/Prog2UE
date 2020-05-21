#include "Inventory.h"

/* Adds a book the the list of books and returns it's assigned ID */
void Inventory::add_item(Lendable item) {

//    do {
//        // Generate new id for item
//    } while(id_exists);

    m_items.push_back(item);
}

/* Removes a book with a given id */
void Inventory::remove_item(unsigned int id) {
    // TODO
}

/* Returns 1 on success and 0 on any
 * error (item was not found or already lent to someone) */
int Inventory::lend_item(unsigned int item_id, Customer *customer) {
    for(int i = 0; i < m_items.size(); i++) {
        if(item_id == m_items[i].get_id()) {
            // Lend item to customer if possible/allowed
            if(customer->get_currently_lent().size() < 2 && m_items[i].lend_to(customer->get_id())) {
                customer->add_item(item_id);
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

/* Getter for the whole list of books */
std::vector<Lendable> Inventory::get_items() {
    return m_items;
}