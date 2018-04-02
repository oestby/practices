#ifndef LINKEDLISTS_HPP 
#define LINKEDLISTS_HPP

#include <memory>
#include <utility>
#include <ostream>
#include <string>


/* NOTE: This function is NOT part of the curriculum, but is necessary
 * to make the code work in XCode and older compiler versions */
#if (defined(_MSC_VER) && _MSC_VER < 1900) || (!defined(_MSC_VER) && __cplusplus < 201402L)
namespace std {
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
}
#endif
/* the code above this line is not part of the curriculum */

class Node {
private:
    const std::string value;
    std::unique_ptr<Node> next;
public:
    Node() : value(), next(nullptr) {}
    // construct a node with string value, a unique_ptr to the next node, and a pointer to the previous node
    Node(const std::string& value, std::unique_ptr<Node> next)
        : value(value)
        , next(std::move(next))
    {}
    // We can use the default constructor, since unique_ptr takes care of deleting memory
    ~Node() = default;
    // return the value of the node
    std::string getValue() const { return value; }
    // return a raw pointer to the next node
    Node* getNext() const { return next.get(); }

    // write the value of the node to the ostream
    friend std::ostream & operator<<(std::ostream & os, const Node & node);

    friend class LinkedList;
};

class LinkedList {
private:
    // ptr to the first node
    std::unique_ptr<Node> head;
    // a raw pointer to the last node, the last node is always a dummy node
    // this is declared as a const ptr to a Node, so that tail never can
    // point anywhere else
    Node* const tail;
public:
    //create the dummy node, and make tail point to it
    LinkedList()
        : head(std::make_unique<Node>())
        , tail(head.get())
    {}
    ~LinkedList() = default;

    //if next is a nullptr (i.e. head is the dummy node), the list is emtpy
    bool isEmpty() const { return !head->next; }


    //return a pointer to first element
    Node* begin() const { return head.get(); }
    //return a pointer to beyond-end element
    Node* end() const { return tail; }

    // The insert function takes a pointer to node (pos) and a string (value). It creates a new
    // node which contains value. The new node is inserted into the LinkedList BEFORE the
    // node pointed to by pos.
    Node* insert(Node *pos, const std::string& value){
        for (auto it = this->begin(); it != this->end(); it = it->getNext()) {
            if (it->getNext() == pos) {
                it->next = std::make_unique<Node>(value, std::move(it->next));
                break;
            }
        }
        return pos->getNext();
    }

    // The find function traverses the linked list and returns a pointer to the first node
    // that contains the value given.
    // If the value isn't in the list, find returns a pointer to the dummy node at the end
    // of the list.
    Node* find(const std::string& value) {
        for (auto it = this->begin(); it != this->end(); it = it->getNext()) {
            if (it->getValue() == value) {
                return it; 
            }
        }
        return end();
    }

    // The remove function takes a pointer to a node, and removes the node from the list. The
    // function returns a pointer to the element after the removed node.
    Node* remove(Node* pos) {
        Node* next = pos->getNext();
        for (auto it = this->begin(); it != this->end(); it = it->getNext()) {
            if (it->getNext() == pos) {
                std::unique_ptr<Node> next = std::move(it->next->next);
                std::string value = it->next->value;
                it->next.release();
                it->next = std::make_unique<Node>(value, std::move(next));
                break;
            }
        return next;
        }
    }

    // The remove function takes a string and removes the first node which contains the value.
    void remove(const std::string& value) {
        for (auto it = this->begin(); it != this->end(); it = it->getNext()) {
            if (it->getValue() == value) {
                remove(it);
            }
        }
    }

    // write a string representation of the list to the ostream
    friend std::ostream & operator<<(std::ostream & os, const LinkedList& list);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    for (auto it = list.begin(); it != list.end(); it = it->getNext()) {
        os << it->getValue() << std::endl;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.getValue();
    return os;
}

#endif

