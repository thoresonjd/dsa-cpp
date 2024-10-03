#include <linked-list.h>
#include <logger.h>
#include <sstream>

Logger& logger = Logger::getInstance();

void terminate() {
	logger.warning("Terminating early...");
	std::exit(-1);
}

template<typename ListT>
void checkSize(const LinkedList<ListT>& list, const std::size_t& expected) noexcept {
	std::size_t result = list.getSize();
	std::stringstream ss;
	ss << "Checking for size of " << expected << "...";
	logger.info(ss.view());	
	ss.str("");
	ss << "Size is ";
	if (result == expected) {
		ss << expected;
		logger.success(ss.view());
	} else {
		ss << result;
		logger.error(ss.view());
		terminate();
	}
}

template<typename ListT>
void checkEmpty(const LinkedList<ListT>& list, const bool& shouldRemove) noexcept {
	bool result;
	std::stringstream ss;
	ss << "Checking that list is ";
	if (!shouldRemove)
		ss << "not ";
	ss << "empty...";
	logger.info(ss.view());
	ss.str("");
	ss << "List is ";
	if (!(result = list.isEmpty()))
		ss << "not ";
	ss << "empty";
	if (result == shouldRemove) {
		logger.success(ss.view());
	} else {
		logger.error(ss.view());
		terminate();
	}
}

template<typename ListT>
void checkInsertFront(LinkedList<ListT>& list, const ListT& value) noexcept {
	std::size_t initialSize = list.getSize();
	std::stringstream ss;
	ss << "Inserting " << value << " to front...";
	logger.info(ss.view());	
	list.insertFront(value);
	if (initialSize + 1 == list.getSize()) {
		logger.success("Inserted to front");
	} else {
		logger.error("Failed to insert to front");
		terminate();
	}
}

template<typename ListT>
void checkInsertEnd(LinkedList<ListT>& list, const ListT& value) noexcept {
	std::size_t initialSize = list.getSize();	
	std::stringstream ss;
	ss << "Inserting " << value << " to end...";
	logger.info(ss.view());	
	list.insertEnd(value);
	if (initialSize + 1 == list.getSize()) {
		logger.success("Inserted to end");
	} else {
		logger.error("Failed to insert to end");
		terminate();
	}
}

template<typename ListT>
void checkInsertAt(LinkedList<ListT>& list, const std::size_t& index, const ListT& value, const bool& shouldRemove) noexcept {
	std::size_t initialSize = list.getSize();
	std::stringstream ss;
	ss << "Inserting " << value << " at index " << index << ", expecting to " << (shouldRemove ? "succeed" : "fail");
	logger.info(ss.view());
	try {
		list.insertAt(index, value);
	} catch (std::out_of_range& e) {
		ss.str("");
		ss << "Failed to insert at index: " << e.what();
		if (shouldRemove) {
			logger.error(ss.view());
			terminate();
		} else {
			logger.success(ss.view());
			return;
		}
	}
	if (initialSize + 1 == list.getSize()) {
		logger.success("Inserted at index");
	} else {
		logger.error("Failed to insert at index");
		terminate();
	}
}

template<typename ListT>
void checkRemoveFront(LinkedList<ListT>& list, const ListT& expected, const bool& shouldRemove) noexcept {
	ListT result;
	std::stringstream ss;
	ss << "Removing from front...";
	logger.info(ss.view());
	ss.str("");
	try {
		result = list.removeFront();
	} catch (std::out_of_range& e) {
		ss << "Failed to remove from front; got \"" << e.what() << "\" which was ";
		if (shouldRemove) {
			ss << "not expected";
			logger.error(ss.view());
			terminate();
		} else {
			ss << "expected";
			logger.success(ss.view());
			return;
		}
	}
	ss << "Removed " << result << " from front which was ";
	if (result == expected) {
		ss << "expected";
		logger.success(ss.view());
	} else {
		ss << "not expected";
		logger.error(ss.view());
		terminate();
	}
}

template<typename ListT>
void checkRemoveEnd(LinkedList<ListT>& list, const ListT& expected, const bool& shouldRemove) noexcept {
	ListT result;
	std::stringstream ss;
	ss << "Removing from end...";
	logger.info(ss.view());
	ss.str("");
	try {
		result = list.removeEnd();
	} catch (std::out_of_range& e) {
		ss << "Failed to remove from end; got \"" << e.what() << "\" which was ";
		if (shouldRemove) {
			ss << "not expected";
			logger.error(ss.view());
			terminate();
		} else {
			ss << "expected";
			logger.success(ss.view());
			return;
		}
	}
	ss << "Removed " << result << " from end which was ";
	if (result == expected) {
		ss << "expected";
		logger.success(ss.view());
	} else {
		ss << "not expected";
		logger.error(ss.view());
		terminate();
	}
}

template<typename ListT>
void checkRemoveAt(LinkedList<ListT>& list, const std::size_t& index, const ListT& expected, const bool& shouldRemove) noexcept {
	ListT result;
	std::stringstream ss;
	ss << "Removing from index " << index << "...";
	logger.info(ss.view());
	ss.str("");
	try {
		result = list.removeAt(index);
	} catch (std::out_of_range& e) {
		ss << "Failed to remove from index " << index << "; got \"" << e.what() << "\" which was ";
		if (shouldRemove) {
			ss << "not expected";
			logger.error(ss.view());
			terminate();
		} else {
			ss << "expected";
			logger.success(ss.view());
			return;
		}
	}
	ss << "Removed " << result << " from index " << index << " which was ";
	if (result == expected) {
		ss << "expected";
		logger.success(ss.view());
	} else {
		ss << "not expected";
		logger.error(ss.view());
		terminate();
	}
}

int main(void) {
	LinkedList<int> list;

	// List is empty; removal should fail
	checkEmpty(list, true);
	checkRemoveFront(list, -1, false);
	checkRemoveEnd(list, -1, false);

	// Insert data into front and end of list
	checkInsertFront(list, 3);
	checkInsertFront(list, 2);
	checkInsertFront(list, 1);
	checkInsertEnd(list, 5);
	checkInsertEnd(list, 6);
	checkInsertEnd(list, 7);

	// Insert at index; should fail if index is greater than size
	checkInsertAt(list, 0, 0, true);	// first index
	checkInsertAt(list, 4, 4, true);	// middle index
	checkInsertAt(list, 8, 8, true);	// last index
	checkInsertAt(list, 10, 9, false);	// out of range index
	checkInsertAt(list, 9, 9, true);	// last index

	// List has ten elements
	checkEmpty(list, false);
	checkSize(list, 10);

	// Remove from front and end
	checkRemoveFront(list, 0, true);
	checkRemoveFront(list, 1, true);
	checkRemoveEnd(list, 9, true);
	checkRemoveEnd(list, 8, true);

	// Remove from index; should fail if index is out of range
	checkRemoveAt(list, 0, 2, true);	// first index
	checkRemoveAt(list, 2, 5, true);	// middle index
	checkRemoveAt(list, 3, 7, true);	// last index
	checkRemoveAt(list, 3, -1, false);	// out of range index
	checkRemoveAt(list, 2, 6, true);	// last index
		
	// Leave two elements in the list; will be deallocated via the destructor
	checkSize(list, 2);
	logger.info("Data remains in the list.");
	logger.info("Use Valgrind to check that dynamically allocated memory is freed via the list destructor.");

	return 0;	
}
