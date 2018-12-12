/**
* iptables API
* iptables API generated from iptables.yang
*
* OpenAPI spec version: 1.0.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */

/*
* SessionTableInterface.h
*
*
*/

#pragma once

#include "../serializer/SessionTableJsonObject.h"


using namespace io::swagger::server::model;

class SessionTableInterface {
public:

  virtual void update(const SessionTableJsonObject &conf) = 0;
  virtual SessionTableJsonObject toJsonObject() = 0;

  /// <summary>
  /// Source IP
  /// </summary>
  virtual std::string getSrc() = 0;

  /// <summary>
  /// Destination IP
  /// </summary>
  virtual std::string getDst() = 0;

  /// <summary>
  /// Level 4 Protocol.
  /// </summary>
  virtual std::string getL4proto() = 0;

  /// <summary>
  /// Source Port
  /// </summary>
  virtual uint16_t getSport() = 0;

  /// <summary>
  /// Destination
  /// </summary>
  virtual uint16_t getDport() = 0;

  /// <summary>
  /// Connection state.
  /// </summary>
  virtual std::string getState() = 0;
};
