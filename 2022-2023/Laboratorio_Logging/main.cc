#include "easylogging++.h"
// https://github.com/abumq/easyloggingpp

INITIALIZE_EASYLOGGINGPP


int main(int arg, char* argv[]){
    el::Configurations conf("logging.conf");    
    el::Loggers::reconfigureLogger("default", conf);
    el::Loggers::reconfigureAllLoggers(conf);
    LOG(INFO) << "Hello World!";
    return 0;
}