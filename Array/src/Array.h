
template<class T>
class Array {
	public:
		Array();
		Array(int asize);
		~Array();

		T get(int index);
		void set(int index, T value);
}