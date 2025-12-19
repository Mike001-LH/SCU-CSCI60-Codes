// pre:  h and t resp. address the first and last nodes in a linked list
// post: returns number of times val occurs in (unchanged) list
template <typename T>
size_t list_count(const node<T>* h, const node<T>* t, const T& val);

// µœ÷£∫
template <typename T>
size_t list_count(const node<T>* h, const node<T>* t, const T& val) {
	size_t count = 0;
	node<T>* current = h;
	while (current != nullptr) {
		if(current -> data() == val) {
			count++;
		}
		current = current->link();
	}
	return count;
}
