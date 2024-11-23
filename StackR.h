#pragma once
#include<iostream>
#include<exception>

template <typename T>
class StackR
{
    private:

    //узел списка (элемент стэка)
    template <typename T>
    struct Node
    {
        T m_data;
        Node<T>* m_next;
    };

    //голова стэка и размер
    Node<T> *m_head;
    unsigned int m_size;

    
    ///служебные методы

    //копирование стека
    void copy(Node<T> *head);

    //освобождение памяти и очистка стэка
    void free();
    
    public:
    
    //при создании пустой стэк
    StackR();

    //кк
    StackR(const StackR<T> &other);

    ~StackR();

    //оператор копирования
    StackR<T> &operator=(const StackR<T> &right);

    //вставить элемент
    void push(const T& item);

    //вставить меньшее значение на стек
    void pushLessValue(const T& item);

    //вставить уникальное значение на стек
    void pushUnique(const T& item);

    //снять со стэка
    T pop();

    //показ стэка
    void show(std::string msg) const;

    bool isEmpty() const;

    int size() const;

    bool contains(const T &value) const;

};

template <typename T>
void StackR<T>::copy(Node<T> *head){
    
    //проверка параметра
    if(head == nullptr)
        return;

    Node<T> *ptr = head;
    bool first = true;
    Node<T> *ptr2 = nullptr;
    Node<T> *ptr3 = nullptr;

    m_size = 0;
    while(ptr != nullptr) {
        try {
            
            ptr2 = new Node<T>;
            ptr2->m_data = ptr->m_data;
            ptr2->m_next = nullptr;

            if(first) {
                m_head = ptr2;
                ptr3 = ptr2;
                first = false;
            } else {
                ptr3->m_next = ptr2;
                ptr3 = ptr3->m_next;
            }

            ++m_size;

            ptr = ptr->m_next;
        }
        catch(std::bad_alloc error) {
            std::cout << error.what() << '\n';
        }
    }
}

template<typename T>
inline void StackR<T>::free()
{
    Node<T> *ptr = m_head;
    while(ptr != nullptr) {
        m_head = m_head->m_next;
        delete ptr;
        ptr = m_head;
        --m_size;
    }
}

template<typename T>
inline StackR<T>::StackR()
{
    m_head = nullptr;
    m_size = 0;
}

template<typename T>
inline StackR<T>::StackR(const StackR<T> &other)
{
    copy(other.m_head);
}

template<typename T>
inline StackR<T>::~StackR()
{
    free();
}

template<typename T>
inline StackR<T> &StackR<T>::operator=(const StackR<T> &right)
{
    if(this != &right) {
        if(m_size > 0)
            free();

        copy(right.m_head);
    }

    return *this;
}

template<typename T>
inline void StackR<T>::push(const T &item)
{
    try {
        if(m_size == 0) {
            
            m_head = new Node<T>;
            m_head->m_data = item;
            m_head->m_next = nullptr;
            
        } else {
            Node<T> *ptr2 = new Node<T>;
            ptr2->m_data = item;
            ptr2->m_next = nullptr;

            ptr2->m_next = m_head;
            m_head = ptr2;
        }

        ++m_size;
    } catch(std::bad_alloc error){
        std::cout << error.what() << '\n';
    }
}

template<typename T>
inline void StackR<T>::pushLessValue(const T &item)
{
    if(m_head->m_data > item)
        push(item);
}

template<typename T>
inline void StackR<T>::pushUnique(const T &item)
{
    if(!contains(item))
        push(item);
}

template<typename T>
inline T StackR<T>::pop()
{
    if(m_size == 0)
        return 0;

    T item = m_head->m_data;
    Node<T> *ptr = m_head;

    m_head = m_head->m_next;

    delete ptr;
    --m_size;

    return item;
}

template<typename T>
inline void StackR<T>::show(std::string msg) const
{
    Node<T>* element = m_head;

    std::cout << msg << " elements => ";

    while(element != nullptr) {
        std::cout << element->m_data << ' ';
        element = element->m_next;
    }

    std::cout << '\n';
}

template<typename T>
inline bool StackR<T>::isEmpty() const
{
    return m_size == 0;
}

template<typename T>
inline int StackR<T>::size() const
{
    return m_size;
}

template<typename T>
inline bool StackR<T>::contains(const T &value) const
{
    Node<T> *element = m_head;

    while(element != nullptr) {
        if(element->m_data == value)
            return true;

        element = element->m_next;
    }

    return false;
}
