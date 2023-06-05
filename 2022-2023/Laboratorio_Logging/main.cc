#define _ELPP_THREAD_SAFE
#include "easylogging++.h"
// https://github.com/abumq/easyloggingpp

INITIALIZE_EASYLOGGINGPP


int main(int arg, char* argv[]){
    el::Loggers::configureFromGlobal("logging.conf");
    LOG(INFO) << "Hello World!";
    return 0;
}