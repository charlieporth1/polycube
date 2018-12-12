/**
* nat API
* NAT Service
*
* OpenAPI spec version: 1.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


// These methods have a default implementation. Your are free to keep it or add your own


#include "../NattingTable.h"


nlohmann::fifo_map<std::string, std::string>  NattingTable::getKeys() {
  nlohmann::fifo_map<std::string, std::string>  r;

  r["internalSrc"] = getInternalSrc();

  r["internalDst"] = getInternalDst();

  r["internalSport"] = std::to_string(getInternalSport());

  r["internalDport"] = std::to_string(getInternalDport());

  r["proto"] = getProto();

  return r;
}











