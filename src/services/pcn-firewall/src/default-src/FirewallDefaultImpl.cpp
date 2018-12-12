/**
* firewall API
* Firewall Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


// These methods have a default implementation. Your are free to keep it or add your own


#include "../Firewall.h"
#include "../Firewall_dp.h"




std::string Firewall::getName(){
  // This method retrieves the name value.
  return Cube::get_name();
}


std::string Firewall::getUuid(){
  // This method retrieves the uuid value.
  return Cube::get_uuid().str();
}


CubeType Firewall::getType(){
  // This method retrieves the type value.
  return Cube::get_type();
}


FirewallLoglevelEnum Firewall::getLoglevel(){
  // This method retrieves the loglevel value.
    switch(Cube::get_log_level()){
      case polycube::LogLevel::TRACE:
        return FirewallLoglevelEnum::TRACE;
      case polycube::LogLevel::DEBUG:
        return FirewallLoglevelEnum::DEBUG;
      case polycube::LogLevel::INFO:
        return FirewallLoglevelEnum::INFO;
      case polycube::LogLevel::WARN:
        return FirewallLoglevelEnum::WARN;
      case polycube::LogLevel::ERR:
        return FirewallLoglevelEnum::ERR;
      case polycube::LogLevel::CRITICAL:
        return FirewallLoglevelEnum::CRITICAL;
      case polycube::LogLevel::OFF:
        return FirewallLoglevelEnum::OFF;
    }
}

void Firewall::setLoglevel(const FirewallLoglevelEnum &value){
  // This method sets the loglevel value.
    switch(value){
      case FirewallLoglevelEnum::TRACE:
        Cube::set_log_level(polycube::LogLevel::TRACE);
        break;
      case FirewallLoglevelEnum::DEBUG:
        Cube::set_log_level(polycube::LogLevel::DEBUG);
        break;
      case FirewallLoglevelEnum::INFO:
        Cube::set_log_level(polycube::LogLevel::INFO);
        break;
      case FirewallLoglevelEnum::WARN:
        Cube::set_log_level(polycube::LogLevel::WARN);
        break;
      case FirewallLoglevelEnum::ERR:
        Cube::set_log_level(polycube::LogLevel::ERR);
        break;
      case FirewallLoglevelEnum::CRITICAL:
        Cube::set_log_level(polycube::LogLevel::CRITICAL);
        break;
      case FirewallLoglevelEnum::OFF:
        Cube::set_log_level(polycube::LogLevel::OFF);
        break;
    }
}

std::shared_ptr<Ports> Firewall::getPorts(const std::string &name){
  return Ports::getEntry(*this, name);
}

std::vector<std::shared_ptr<Ports>> Firewall::getPortsList(){
  return Ports::get(*this);
}

void Firewall::addPorts(const std::string &name, const PortsJsonObject &conf){
  Ports::create(*this, name, conf);
}

void Firewall::addPortsList(const std::vector<PortsJsonObject> &conf){
  for(auto &i : conf){
    std::string name_ = i.getName();
    Ports::create(*this, name_,  i);
  }
}

void Firewall::replacePorts(const std::string &name, const PortsJsonObject &conf){
  Ports::removeEntry(*this, name);
  std::string name_ = conf.getName();
  Ports::create(*this, name_, conf);

}

void Firewall::delPorts(const std::string &name){
  Ports::removeEntry(*this, name);
}

void Firewall::delPortsList(){
  Ports::remove(*this);
}






std::shared_ptr<SessionTable> Firewall::getSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport){
  return SessionTable::getEntry(*this, src, dst, l4proto, sport, dport);
}

std::vector<std::shared_ptr<SessionTable>> Firewall::getSessionTableList(){
  return SessionTable::get(*this);
}

void Firewall::addSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport, const SessionTableJsonObject &conf){
  SessionTable::create(*this, src, dst, l4proto, sport, dport, conf);
}

void Firewall::addSessionTableList(const std::vector<SessionTableJsonObject> &conf){
  for(auto &i : conf){
    std::string src_ = i.getSrc();
    std::string dst_ = i.getDst();
    std::string l4proto_ = i.getL4proto();
    uint16_t sport_ = i.getSport();
    uint16_t dport_ = i.getDport();
    SessionTable::create(*this, src_, dst_, l4proto_, sport_, dport_,  i);
  }
}

void Firewall::replaceSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport, const SessionTableJsonObject &conf){
  SessionTable::removeEntry(*this, src, dst, l4proto, sport, dport);
  std::string src_ = conf.getSrc();
  std::string dst_ = conf.getDst();
  std::string l4proto_ = conf.getL4proto();
  uint16_t sport_ = conf.getSport();
  uint16_t dport_ = conf.getDport();
  SessionTable::create(*this, src_, dst_, l4proto_, sport_, dport_, conf);

}

void Firewall::delSessionTable(const std::string &src, const std::string &dst, const std::string &l4proto, const uint16_t &sport, const uint16_t &dport){
  SessionTable::removeEntry(*this, src, dst, l4proto, sport, dport);
}

void Firewall::delSessionTableList(){
  SessionTable::remove(*this);
}

std::shared_ptr<Chain> Firewall::getChain(const ChainNameEnum &name){
  return Chain::getEntry(*this, name);
}

std::vector<std::shared_ptr<Chain>> Firewall::getChainList(){
  return Chain::get(*this);
}

void Firewall::addChain(const ChainNameEnum &name, const ChainJsonObject &conf){
  Chain::create(*this, name, conf);
}

void Firewall::addChainList(const std::vector<ChainJsonObject> &conf){
  for(auto &i : conf){
    ChainNameEnum name_ = i.getName();
    Chain::create(*this, name_,  i);
  }
}

void Firewall::replaceChain(const ChainNameEnum &name, const ChainJsonObject &conf){
  Chain::removeEntry(*this, name);
  ChainNameEnum name_ = conf.getName();
  Chain::create(*this, name_, conf);

}

void Firewall::delChain(const ChainNameEnum &name){
  Chain::removeEntry(*this, name);
}

void Firewall::delChainList(){
  Chain::remove(*this);
}


