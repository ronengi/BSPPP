/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   vector.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:14 AM
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <iostream>
#include <sstream>
#include <stdexcept>

using std::initializer_list;
using std::copy;
using std::ostream;
using std::ostringstream;
using std::allocator;

//using std::string;
using std::out_of_range;


// template<typename T> T* allocator<T>::allocate(int n);

namespace simplified {

    /**
     * <nobr>
     * <b>An almost real vector of T</b><br><br>
     * <u>Invariant:</u><br>
     * &nbsp;&bull; if 0 &le; n &le; sz,<br>
     * &nbsp;&nbsp;&nbsp;&nbsp;elem[n] is element n<br>
     * &nbsp;&bull; sz &le; space<br>
     * &nbsp;&bull; if sz &lt; space,<br>
     * &nbsp;&nbsp;&nbsp;&nbsp;there is space for (space-sz) T after elem[sz-1]
     * </nobr>
     */
    template<typename T, typename A = allocator<T>>
    class vector {

    public:
        using size_type = unsigned long;
        using value_type = T;
        using iterator = T*;        // T*
        using const_iterator = const T*;


        vector();                               // default constructor
        explicit vector(int s, T dflt = T());   // constructor - avoid implicit int to vector conversion
        vector(initializer_list<T> lst);        // initializer list constructor
        vector(const vector<T, A>& arg);        // copy constructor
        vector(vector<T, A>&& arg);             // move constructor

        ~vector();

        vector<T, A>& operator=(const vector<T, A>& arg);     // copy assignment
        vector<T, A>& operator=(vector<T, A>&& arg);          // move assignment

        T& at(int n);                               // checked access - set
        const T& at(int n) const;                   // checked access - get

        T& operator[](int i);                       // subscription set - unchecked
        const T& operator[](int i) const;           // subscription get - unchecked


        size_type size() const;                     // get size
        size_type capacity() const;                       // amount of space available

        void reserve(int newalloc);                 // add space for new elements
        void resize(int newsize, T dflt = T());     // resize and initialize new elements
        void push_back(const T& val);               // increase size by one; add a new element

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

        iterator erase(iterator p);
        iterator insert(iterator p, const T& val);

    private:
        A alloc;            // use allocate to handle memory for elements
        int sz;             // number of elements
        T *elem;            // address of first element
        int space;          // number of elements + number of free slots
    };


    template<typename T, typename A>
    ostream& operator<<(ostream& os, const vector<T, A>& vv);




    /*************************************************************************
     *                 beginning of template definition                      *
     *************************************************************************/

    // default constructor
    template<typename T, typename A>
    vector<T, A>::vector() :
        sz{0}, elem{nullptr}, space{0}
    { }

    // constructor
    template<typename T, typename A>
    vector<T, A>::vector(int s, T dflt) :
        sz{s}, elem{new T[s]}, space{sz}
    {
            for (int i = 0; i < sz; ++i) {          // re-initialize elements
                alloc.destroy(&elem[i]);            // destroy
                alloc.construct(&elem[i], dflt);    // construct using default
            }
    }

    // initializer list constructor
    template<typename T, typename A>
    vector<T, A>::vector(initializer_list<T> lst) :
        sz{static_cast<int>(lst.size())}, elem{new T[sz]}, space{sz}
    {
            copy(lst.begin(), lst.end(), elem);     // initialize using std::copy()
    }

    // copy constructor
    template<typename T, typename A>
    vector<T, A>::vector(const vector<T, A>& arg) :
        sz{arg.sz}, elem{new T[arg.sz]}, space{sz}
    {
            copy(arg.elem, arg.elem+arg.sz, elem);      // copy elements
    }

    // move constructor
    template<typename T, typename A>
    vector<T, A>::vector(vector<T, A>&& arg) :
        sz{arg.sz}, elem{arg.elem}, space{sz}
    {
            arg.elem = nullptr;
            arg.sz = 0;
            arg.space = 0;
    }

    // destructor
    template<typename T, typename A>
    vector<T, A>::~vector() {
        delete[] elem;
    }

    // TODO: re-implement using an allocator
    // copy assignment
    template<typename T, typename A>
    vector<T, A>& vector<T, A>::operator=(const vector<T, A>& arg) {
        if(this == &arg)         // self assignment, no work needed
            return *this;
        if(arg.sz <= space) {   // enough space, no need for new allocation
            copy(arg.elem, arg.elem+arg.sz, elem);
            sz = arg.sz;
            return *this;
        }

        T* p = new T[arg.sz];               // allocate new space
        copy(arg.elem, arg.elem+arg.sz, p);
        delete[] elem;                      // deallocate old space
        elem = p;                           // set new elements
        space = sz = arg.sz;                // set new size
        return *this;                       // return self reference
    }

    // move assignment
    template<typename T, typename A>
    vector<T, A>& vector<T, A>::operator=(vector<T, A>&& arg) {
        delete[] elem;
        elem = arg.elem;
        sz = arg.sz;
        space = sz;
        arg.elem = nullptr;
        arg.sz = 0;
        arg.space = 0;
        return *this;
    }

    // checked access - set
    template<typename T, typename A>
    T& vector<T, A>::at(int n) {
        if(n < 0 || sz <= n) {
            ostringstream os;
            os << "invalid access: [" << n << "]";
            throw out_of_range(os.str());
        }
        return elem[n];
    }

    // checked access - get
    template<typename T, typename A>
    const T& vector<T, A>::at(int n) const {
        if(n < 0 || sz <= n) {
            ostringstream os;
            os << "invalid access: [" << n << "]";
            throw out_of_range(os.str());
        }
        return elem[n];
    }

    // subscription set
    template<typename T, typename A>
    T& vector<T, A>::operator[](int i) {
        return elem[i];
    }

    // subscription get
    template<typename T, typename A>
    const T& vector<T, A>::operator[](int i) const {
        return elem[i];
    }


    // get size
    template<typename T, typename A>
    typename vector<T, A>::size_type vector<T, A>::size() const {
        return sz;
    }

    // get amount of space available
    template<typename T, typename A>
    typename vector<T, A>::size_type vector<T, A>::capacity() const {
        return space;
    }


    // add space for new elements
    template<typename T, typename A>
    void vector<T, A>::reserve(int newalloc) {
        if(newalloc <= space)               // never decrease allocation
            return;

        T* p = alloc.allocate(newalloc);        // allocate new space

        for(int i = 0; i < sz; ++i)
            alloc.construct(&p[i], elem[i]);    // copy old element to new location

        for(int i = 0; i < sz; ++i)
            alloc.destroy(&elem[i]);            // destroy old element

        alloc.deallocate(elem, space);          // deallocate old space

        elem = p;
        space = newalloc;
    }

    // resize and initialize new elements with default value
    template<typename T, typename A>
    void vector<T, A>::resize(int newsize, T dflt) {
        reserve(newsize);

        for(int i = sz; i < newsize; ++i)
            alloc.construct(&elem[i], dflt);    // construct new element with default

        for(int i = newsize; i < sz; ++i)
            alloc.destroy(&elem[i]);            // destroy in case newsize < sz

        sz = newsize;                           // resize
    }

    // increase size by one; add a new element
    template<typename T, typename A>
    void vector<T, A>::push_back(const T& val) {
        if(space == 0)                      // start with space for 8 elements
            reserve(8);
        else if(sz == space)                // get more space
            reserve(2 * space);
        alloc.construct(&elem[sz], val);    // add val at the end
        ++sz;                               // increase the size
    }


    template<typename T, typename A>
    typename vector<T, A>::iterator vector<T, A>::begin() {
        return elem;
    }

    template<typename T, typename A>
    typename vector<T, A>::const_iterator vector<T, A>::begin() const {
        return elem;
    }

    template<typename T, typename A>
    typename vector<T, A>::iterator vector<T, A>::end() {
        return (elem + sz);
    }

    template<typename T, typename A>
    typename vector<T, A>::const_iterator vector<T, A>::end() const {
        return (elem + sz);
    }

    template<typename T, typename A>
    typename vector<T, A>::iterator vector<T, A>::erase(iterator p) {
        if(p == end())
            return p;
        for(auto pos = p + 1; pos != end(); ++pos)
            *(pos-1) = *pos;            // move all elements afrer pos
        alloc.destroy(&*(end()-1));     // destroy last element
        --sz;
        return p;
    }

    template<typename T, typename A>
    typename vector<T, A>::iterator vector<T, A>::insert(iterator p, const T& val) {
        int index = p - begin();    // elements may be moved if reserve() is used
        if(size() == capacity())
            reserve(size() == 0 ? 8 : 2 * size());
        alloc.construct(elem + sz, *(end()-1));     // last element is copied into un-initialized space
        ++sz;
        iterator pp = begin() + index;      // the place to put val
        for(auto pos = end()-1; pos != pp; --pos)
            *pos = *(pos - 1);              // move elements after pp
        *(begin() + index) = val;           // insert val
        return pp;
    }


    /*************************************************************************
     *                   end of template definition                          *
     *************************************************************************/


    // output stream representation
    template<typename T, typename A>
    ostream& operator<<(ostream& os, const vector<T, A>& vv) {
        ostringstream ss("");
        ss << "simplified::vector(" << vv.size() << ")";
        for(const auto& x : vv)
            ss << "\t[" << x << "]";
        return os << ss.str();
    }



    template<typename C>
    using Iterator = typename C::iterator;  // Iterator<C> means typename C::iterator


} // namespace simplified


#endif /* VECTOR_HPP */
