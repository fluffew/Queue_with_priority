#include <iostream>
#include <stdlib.h>
#include <exception>
#include "Queue.h"

using std::cin;
using std::cout;
using std::endl;

void check_fail() {
    if (cin.fail()) {
        cin.clear();
        throw std::exception("ERROR: Wrong input");
    }
}


int main()
{
    int option;
    bool stop = false;
    Queue queue;
    cout << "Enter the number of option:" << endl;
    try {
        while (!stop) {
            cout << "1. To define a number of all elements and a number of elements with current priority;\n"
                << "2. To check emptiness of queue;\n"
                << "3. To push an element with current value and priority;\n"
                << "4. To pop an element;\n"
                << "5. To get a value and a priority of the front element;\n"
                << "6. To clear the console;\n"
                << "7. Exit\n";
            cin >> option;
            check_fail();
            switch (option) {
            case 1: {
                cout << "The amount of elements is " << queue.size()
                    << ", including: HIGH - " << queue.size_high()
                    << ", MEDIUM - " << queue.size_medium()
                    << ", LOW - " << queue.size_low() << endl;
                break;
            }
            case 2: {
                cout << "The queue is " << (queue.empty() ? "empty" : "not empty") << endl;
                break;
            }
            case 3: {
                int value, priority;
                cout << "Enter the value: ";
                cin >> value;
                check_fail();
                cout << "Enter the priority:\n\t1) HIGH\n\t2) MEDIUM\n\t3) LOW\n";
                cin >> priority;
                switch (priority) {
                case 1: {
                    queue.push(value, Priority::high);
                    break;
                }
                case 2: {
                    queue.push(value, Priority::medium);
                    break;
                }
                case 3: {
                    queue.push(value, Priority::low);
                    break;
                }
                default: {
                    cout << "ERROR: Invalid parameter" << endl;
                }
                }
                cout << "The queue is " << queue << endl;
                break;
            }
            case 4: {
                queue.pop();
                cout << "The queue is " << queue << endl;
                break;
            }
            case 5: {
                cout << "Front element: value is " << queue.front_value()
                    << ", priority is " << queue.front_priority() << endl;
                break;
            }
            case 6: {
                system("cls");
                cout << queue << endl;
                break;
            }
            case 7: {
                stop = true;
                break;
            }
            default: {
                cout << "ERROR: Invalid option" << endl;
            }
            }
        }
    }
    catch (std::exception& error) {
        std::cerr << error.what() << endl;
    }

    return 0;
}