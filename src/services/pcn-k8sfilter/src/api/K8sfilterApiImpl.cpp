/**
* k8sfilter API
* Kubernetes Traffic Filtering Service
*
* OpenAPI spec version: 2.0
*
* NOTE: This class is auto generated by the swagger code generator program.
* https://github.com/polycube-network/swagger-codegen.git
* branch polycube
*/


/* Do not edit this file manually */


#include "K8sfilterApiImpl.h"

namespace io {
namespace swagger {
namespace server {
namespace api {

using namespace io::swagger::server::model;

K8sfilterApiImpl::K8sfilterApiImpl() {}

/*
* These functions include a default basic implementation.  The user could
* extend adapt this implementation to his needs.
*/

std::shared_ptr<K8sfilter> K8sfilterApiImpl::get_cube(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  auto iter = cubes.find(name);
  if (iter == cubes.end()) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }

  return iter->second;
}

void K8sfilterApiImpl::create_k8sfilter_by_id(const std::string &name, const K8sfilterJsonObject &jsonObject) {
  {
    // check if name is valid before creating it
    std::lock_guard<std::mutex> guard(cubes_mutex);
    if (cubes.count(name) != 0) {
      throw std::runtime_error("There is already a cube with name " + name);
    }
  }
  auto ptr = std::make_shared<K8sfilter>(name, jsonObject, jsonObject.getType());
  std::unordered_map<std::string, std::shared_ptr<K8sfilter>>::iterator iter;
  bool inserted;

  std::lock_guard<std::mutex> guard(cubes_mutex);
  std::tie(iter, inserted) = cubes.emplace(name, std::move(ptr));

  if (!inserted) {
    throw std::runtime_error("There is already a cube with name " + name);
  }
}

void K8sfilterApiImpl::replace_k8sfilter_by_id(const std::string &name, const K8sfilterJsonObject &bridge){
  throw std::runtime_error("Method not supported!");
}

void K8sfilterApiImpl::delete_k8sfilter_by_id(const std::string &name) {
  std::lock_guard<std::mutex> guard(cubes_mutex);
  if (cubes.count(name) == 0) {
    throw std::runtime_error("Cube " + name + " does not exist");
  }
  cubes.erase(name);
}

std::string K8sfilterApiImpl::read_k8sfilter_uuid_by_id(const std::string &name) {
  auto m = get_cube(name);
  return m->getUuid();
}

std::vector<K8sfilterJsonObject> K8sfilterApiImpl::read_k8sfilter_list_by_id() {
  std::vector<K8sfilterJsonObject> jsonObject_vect;
  for(auto &i : cubes) {
    auto m = get_cube(i.first);
    jsonObject_vect.push_back(m->toJsonObject());
  }
  return jsonObject_vect;
}

std::vector<nlohmann::fifo_map<std::string, std::string>> K8sfilterApiImpl::read_k8sfilter_list_by_id_get_list() {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  for (auto &x : cubes) {
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = x.first;
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports list related functions
*/
void K8sfilterApiImpl::create_k8sfilter_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  auto m = get_cube(name);
  m->addPortsList(ports);
}

std::vector<PortsJsonObject> K8sfilterApiImpl::read_k8sfilter_ports_list_by_id(const std::string &name) {
  std::vector<PortsJsonObject> vect;
  auto m = get_cube(name);
  for (auto &i : m->getPortsList()) {
    vect.push_back(i->toJsonObject());
  }
  return vect;
}

void K8sfilterApiImpl::replace_k8sfilter_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &ports) {
  throw std::runtime_error("Method not supported");
}

void K8sfilterApiImpl::delete_k8sfilter_ports_list_by_id(const std::string &name) {
  auto m = get_cube(name);
  m->delPortsList();
}

std::vector<nlohmann::fifo_map<std::string, std::string>> K8sfilterApiImpl::read_k8sfilter_ports_list_by_id_get_list(const std::string &name) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
  auto m = get_cube(name);
  for(auto &i : m->getPortsList()){
    nlohmann::fifo_map<std::string, std::string> m;
    m["name"] = i->getName();
    r.push_back(std::move(m));
  }
  return r;
}

/*
* Ports related functions
*/
void K8sfilterApiImpl::create_k8sfilter_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  return m->addPorts(portsName, ports);
}

PortsJsonObject K8sfilterApiImpl::read_k8sfilter_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  return m->getPorts(portsName)->toJsonObject();
}

void K8sfilterApiImpl::replace_k8sfilter_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &ports) {
  auto m = get_cube(name);
  m->replacePorts(portsName, ports);
}

void K8sfilterApiImpl::delete_k8sfilter_ports_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  m->delPorts(portsName);
}

std::string K8sfilterApiImpl::read_k8sfilter_ports_peer_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getPeer();
}

PortsStatusEnum K8sfilterApiImpl::read_k8sfilter_ports_status_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getStatus();
}

std::string K8sfilterApiImpl::read_k8sfilter_ports_uuid_by_id(const std::string &name, const std::string &portsName) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  return p->getUuid();
}

void K8sfilterApiImpl::update_k8sfilter_ports_peer_by_id(const std::string &name, const std::string &portsName, const std::string &peer) {
  auto m = get_cube(name);
  auto p = m->getPorts(portsName);
  p->setPeer(peer);
}


/**
* @brief   Read k8sfilter by ID
*
* Read operation of resource: k8sfilter*
*
* @param[in] name ID of name
*
* Responses:
* K8sfilterJsonObject
*/
K8sfilterJsonObject
K8sfilterApiImpl::read_k8sfilter_by_id(const std::string &name) {
  return get_cube(name)->toJsonObject();

}




/**
* @brief   Read loglevel by ID
*
* Read operation of resource: loglevel*
*
* @param[in] name ID of name
*
* Responses:
* K8sfilterLoglevelEnum
*/
K8sfilterLoglevelEnum
K8sfilterApiImpl::read_k8sfilter_loglevel_by_id(const std::string &name) {
  auto k8sfilter = get_cube(name);
  return k8sfilter->getLoglevel();

}




/**
* @brief   Read nodeport-range by ID
*
* Read operation of resource: nodeport-range*
*
* @param[in] name ID of name
*
* Responses:
* std::string
*/
std::string
K8sfilterApiImpl::read_k8sfilter_nodeport_range_by_id(const std::string &name) {
  auto k8sfilter = get_cube(name);
  return k8sfilter->getNodeportRange();

}




/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
*
* Responses:
* PortsTypeEnum
*/
PortsTypeEnum
K8sfilterApiImpl::read_k8sfilter_ports_type_by_id(const std::string &name, const std::string &portsName) {
  auto k8sfilter = get_cube(name);
  auto ports = k8sfilter->getPorts(portsName);
  return ports->getType();

}




/**
* @brief   Read type by ID
*
* Read operation of resource: type*
*
* @param[in] name ID of name
*
* Responses:
* CubeType
*/
CubeType
K8sfilterApiImpl::read_k8sfilter_type_by_id(const std::string &name) {
  auto k8sfilter = get_cube(name);
  return k8sfilter->getType();

}




/**
* @brief   Update k8sfilter by ID
*
* Update operation of resource: k8sfilter*
*
* @param[in] name ID of name
* @param[in] value k8sfilterbody object
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_by_id(const std::string &name, const K8sfilterJsonObject &value) {
  auto k8sfilter = get_cube(name);

  k8sfilter->update(value);
}




/**
* @brief   Update k8sfilter by ID
*
* Update operation of resource: k8sfilter*
*
* @param[in] value k8sfilterbody object
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_list_by_id(const std::vector<K8sfilterJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8sfilterApiImpl::update_k8sfilter_list_by_id_get_list(const std::vector<K8sfilterJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


/**
* @brief   Update loglevel by ID
*
* Update operation of resource: loglevel*
*
* @param[in] name ID of name
* @param[in] value Defines the logging level of a service instance, from none (OFF) to the most verbose (TRACE)
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_loglevel_by_id(const std::string &name, const K8sfilterLoglevelEnum &value) {
  auto k8sfilter = get_cube(name);

  k8sfilter->setLoglevel(value);
}




/**
* @brief   Update nodeport-range by ID
*
* Update operation of resource: nodeport-range*
*
* @param[in] name ID of name
* @param[in] value Port range used for NodePort services
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_nodeport_range_by_id(const std::string &name, const std::string &value) {
  auto k8sfilter = get_cube(name);

  k8sfilter->setNodeportRange(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] portsName ID of ports_name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_ports_by_id(const std::string &name, const std::string &portsName, const PortsJsonObject &value) {
  auto k8sfilter = get_cube(name);
  auto ports = k8sfilter->getPorts(portsName);

  ports->update(value);
}




/**
* @brief   Update ports by ID
*
* Update operation of resource: ports*
*
* @param[in] name ID of name
* @param[in] value portsbody object
*
* Responses:
*
*/
void
K8sfilterApiImpl::update_k8sfilter_ports_list_by_id(const std::string &name, const std::vector<PortsJsonObject> &value) {
  throw std::runtime_error("Method not supported");
}


#ifdef IMPLEMENT_POLYCUBE_GET_LIST
std::vector<nlohmann::fifo_map<std::string, std::string>> K8sfilterApiImpl::update_k8sfilter_ports_list_by_id_get_list(const std::string &name, const std::vector<PortsJsonObject> &value) {
  std::vector<nlohmann::fifo_map<std::string, std::string>> r;
}
#endif


}
}
}
}
