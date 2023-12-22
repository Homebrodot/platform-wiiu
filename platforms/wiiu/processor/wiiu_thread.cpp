#include "wiiu_thread.h"



void wiiu_thread_set_name(const String thrname){

}

void wiiu_thread_set_priority(Thread::Settings settings){
    
    if (settings.priority == Thread::Priority::PRIORITY_HIGH) {

    }
    else if (settings.priority == Thread::Priority::PRIORITY_NORMAL) {

    }
    else if (settings.priority == Thread::Priority::PRIORITY_LOW){
        
    }
    
}

void wiiu_thread_init(){

}

void wiiu_thread_call_wrap(Thread::Callback, void *){

}

void wiiu_thread_term(){

}