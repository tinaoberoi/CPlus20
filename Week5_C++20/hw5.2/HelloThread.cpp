#include <iostream>
#include <thread>

void hello_threads() {
    std::cout<<"Hello Concurrent World\n";
}
int
main(){
    // Print in a different thread
    std::jthread t(hello_threads);
    //t.join(); // Removing the join statement for jthreads
}