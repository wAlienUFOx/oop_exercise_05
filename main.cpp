#include <iostream>
#include <algorithm>
#include "rectangle.h"
#include "containers/stack.h"

int main() {
    size_t N;
    float S;
    char option = '0';
    containers::stack<Rectangle<int>> st;
    Rectangle<int> *rec = nullptr;
    while (option != 'q') {
        std::cout << "choose option (m - man)" << std::endl;
        std::cin >> option;
        switch (option) {
            case 'q':
                break;
            case 'm':
                std::cout << "1) push new element into stack\n"
                          << "2) insert element into chosen position\n"
                          << "3) pop element from the stack\n"
                          << "4) delete element from the chosen position\n"
                          << "5) print stack\n"
                          << "6) count elements with area less then chosen value\n"
                          << "7) print top element\n"
                          << "q) - quit" << std::endl;
                break;
            case '1': {
                try{
                    rec =  new Rectangle<int>(std::cin);
                }catch(std::logic_error& err){
                    std::cout << err.what() << std::endl;
                    break;
                }
                st.push(*rec);
                break;
            }
            case '2': {
                std::cout << "enter position to insert" << std::endl;
                std::cin >> N;
                std::cout << "enter rectangle" << std::endl;
                try{
                    rec =  new Rectangle<int>(std::cin);
                }catch(std::logic_error& err){
                    std::cout << err.what() << std::endl;
                    break;
                }
                st.insert_by_number(N + 1, *rec);
                break;
            }
            case '3': {
                st.pop();
                break;
            }
            case '4': {
                std::cout << "enter position to delete" << std::endl;
                std::cin >> N;
                st.delete_by_number(N + 1);
                break;
            }
            case '5': {
                std::for_each(st.begin(), st.end(), [](Rectangle<int> &REC) { REC.Print(std::cout); });
                break;
            }
            case '6': {
                std::cout << "enter max area" <<std::endl;
                std::cin >> S;
                std::cout << std::count_if(st.begin(), st.end(), [=](Rectangle<int> &X) { return X.Area() < S; })
                          << std::endl;
                break;
            }
            case '7' : {
                st.top().Print(std::cout);
                break;
            }
            default:
                std::cout << "Wrong. Try m - manual" << std::endl;
                break;
        }
    }
    return 0;
}
