#include "habit.h"

 Habit::Habit(std::string _description,std::string _name,std::string _repeatPeriod):description(_description),name(_name),repeatPeriod(_repeatPeriod){

 };

 Habit::~Habit(){

 }

 std::string Habit::getDetails()
 {
     return name + ": " + description;
 }

 bool Habit::hasExpired()
 {
    return false;
 }

 std::string Habit::getDescription(){
     return description;
 }
 std::string Habit::getName() const {
return name;
 }
 std::string Habit::getRepeatPeriod(){
return repeatPeriod;
 }
 void Habit::setDescription(std::string _description){
description=_description;
 }
 void Habit::setName(std::string _name){
     name=_name;

 }
 void Habit::setRepeatPeriod(std::string _repeatPeriod){
repeatPeriod=_repeatPeriod;
 }
