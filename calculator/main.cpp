#include <boost/program_options.hpp>
#include <iostream>  
#include <cmath> 
#include <string> 
namespace po = boost::program_options;
#define PI 3.14159265
double tg(double x){
    return (tan(x)*180.0)/(PI);
    }
double ctg(double x){
    return ((PI/2 - tan(x))*180.0)/(PI);
    }
int main(int argc,char * argv[]) 
{ 
    po::options_description desc("end");
    desc.add_options()
    ("help,h","Помощь")
    ("operation,o",po::value<std::string>()->required(),"Тип операции:tg или ctg")
    ("Parametrs,p",po::value<double>()->required(),"Переменные для подсчётов")
    ;
    po::variables_map vm;
    try{
        po::store(po::parse_command_line(argc,argv,desc),vm);
        po::notify(vm);
        }
    catch(po::error& e){
        std::cout<<e.what()<<std::endl;
        
        }
    if(vm.count("help")){
        std::cout<<desc<<std::endl;
        return 1;
        }
    if(vm.count("Parametrs")){
        double temp = vm["Parametrs"].as<double>();
        if(vm.count("operation") and vm["operation"].as<std::string>()=="tg"){
            std::cout<<"Тангенс "<<temp<<" равен: "<<tg(temp)<<std::endl;
            }
        else if (vm.count("operation") and vm["operation"].as<std::string>()=="ctg"){
            std::cout<<"Котангенс "<<temp<<" равен: "<<arccotan(temp)<<std::endl;
            }
        else{
            std::cout<<"Ошибочное название параметра"<<std::endl;
            std::cout<<desc<<std::endl;
            }
        }
    return 0; 
}